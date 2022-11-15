/*
** ShipWreck Engine , 2022
** Model.cpp
*/

#include <memory>
#include "Model.hpp"
#include "OpenGLModule.hpp"

glm::mat4 ConvertMatrixToGLMFormatu(const aiMatrix4x4& from)
{
    glm::mat4 to;
    //the a,b,c,d in assimp is the row ; the 1,2,3,4 is the column
    to[0][0] = from.a1; to[1][0] = from.a2; to[2][0] = from.a3; to[3][0] = from.a4;
    to[0][1] = from.b1; to[1][1] = from.b2; to[2][1] = from.b3; to[3][1] = from.b4;
    to[0][2] = from.c1; to[1][2] = from.c2; to[2][2] = from.c3; to[3][2] = from.c4;
    to[0][3] = from.d1; to[1][3] = from.d2; to[2][3] = from.d3; to[3][3] = from.d4;
    return to;
}

sw::Model::Model(std::string path) :
meshes(),
shader(sw::OpenResources::m_nshader["model"]),
m_bones(),
m_boneCounter(0),
m_directory(),
m_loaded(false)
{
    loadModel(path);
}

void SetVertexBoneDataToDefault(sw::Vertex& vertex)
{
    for (int i = 0; i < MAX_BONE_INFLUENCE; i++) {
        vertex.m_bonesId[i] = -1;
        vertex.m_weight[i] = 0.0f;
    }
}

void SetVertexBoneData(sw::Vertex& vertex, int boneID, float weight)
{
    for (int i = 0; i < MAX_BONE_INFLUENCE; ++i) {
        if (vertex.m_bonesId[i] < 0) {
            vertex.m_weight[i] = weight;
            vertex.m_bonesId[i] = boneID;
            break;
        }
    }
}

void sw::Model::ExtractBoneWeightForVertices(std::vector<sw::Vertex>& vertices, aiMesh* mesh, const aiScene* scene)
{
    for (int boneIndex = 0; boneIndex < mesh->mNumBones; ++boneIndex)
    {
        int boneID = -1;
        std::string boneName = mesh->mBones[boneIndex]->mName.C_Str();
        if (m_bones.find(boneName) == m_bones.end())
        {
            sw::BoneInfo newBoneInfo;
            newBoneInfo.m_id = m_boneCounter;
            newBoneInfo.m_offset = ConvertMatrixToGLMFormatu(mesh->mBones[boneIndex]->mOffsetMatrix);
            m_bones[boneName] = newBoneInfo;
            boneID = m_boneCounter;
            m_boneCounter++;
        }
        else
        {
            boneID = m_bones[boneName].m_id;
        }
        assert(boneID != -1);
        auto weights = mesh->mBones[boneIndex]->mWeights;
        int numWeights = mesh->mBones[boneIndex]->mNumWeights;

        for (int weightIndex = 0; weightIndex < numWeights; ++weightIndex)
        {
            int vertexId = weights[weightIndex].mVertexId;
            float weight = weights[weightIndex].mWeight;
            assert(vertexId <= vertices.size());
            SetVertexBoneData(vertices[vertexId], boneID, weight);
        }
    }
}

sw::Model::~Model() noexcept
= default;

void sw::Model::loadModel(std::string path)
{
    Assimp::Importer import;
    const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        throw sw::Error("ERROR::ASSIMP::" + std::string(import.GetErrorString()), "");
    m_directory = path.substr(0, path.find_last_of('/'));

    processNode(scene->mRootNode, scene);
}

void sw::Model::processNode(aiNode *node, const aiScene *scene)
{
    for(unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }
    for(unsigned int i = 0; i < node->mNumChildren; i++)
        processNode(node->mChildren[i], scene);
}

sw::Mesh sw::Model::processMesh(aiMesh *mesh, const aiScene *scene)
{
    std::vector<sw::Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<std::shared_ptr<sw::Texture>> textures;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        sw::Vertex vertex;

        SetVertexBoneDataToDefault(vertex);

        // positions
        vertex.position.x = mesh->mVertices[i].x;
        vertex.position.y = mesh->mVertices[i].y;
        vertex.position.z = mesh->mVertices[i].z;
        // normals
        if (mesh->HasNormals()) {
            vertex.normal.x = mesh->mNormals[i].x;
            vertex.normal.y = mesh->mNormals[i].y;
            vertex.normal.z = mesh->mNormals[i].z;
        }
        // texture coordinates
        if(mesh->mTextureCoords[0]) {
            vertex.textureCoord.x = mesh->mTextureCoords[0][i].x;
            vertex.textureCoord.y = mesh->mTextureCoords[0][i].y;
            if (mesh->HasTangentsAndBitangents()) {
                vertex.tangent.x = mesh->mTangents[i].x;
                vertex.tangent.y = mesh->mTangents[i].y;
                vertex.tangent.z = mesh->mTangents[i].z;
                vertex.bitangent.y = mesh->mBitangents[i].y;
                vertex.bitangent.x = mesh->mBitangents[i].x;
                vertex.bitangent.z = mesh->mBitangents[i].z;
            }
        }
        else
            vertex.textureCoord = sw::Vector2f (0.0f, 0.0f);

        vertices.push_back(vertex);
    }
    // process indices
    for(unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }
    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

    // 1. diffuse maps
    std::vector<std::shared_ptr<sw::Texture>> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
    //// 2. specular maps
    //std::vector<std::shared_ptr<sw::Texture>> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
    //textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    //// 3. normal maps
    //std::vector<std::shared_ptr<sw::Texture>> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
    //textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
    //// 4. height maps
    //std::vector<std::shared_ptr<sw::Texture>> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
    //textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

    ExtractBoneWeightForVertices(vertices, mesh, scene);

    return {vertices, indices, textures};
}

std::vector<std::shared_ptr<sw::Texture>> sw::Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName)
{
    std::vector<std::shared_ptr<sw::Texture>> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        auto ye = sw::OpenResources::m_ntext[str.C_Str()];
        ye->type = typeName;
        textures.push_back(ye);
    }
    return textures;
}

void sw::Model::compileModel()
{
    for (auto& mesh : meshes)
        mesh.setupMesh();
}

bool sw::Model::isLoaded() const noexcept
{
    return (m_loaded);
}

std::map<std::string, sw::BoneInfo> &sw::Model::getBones()
{
    return (m_bones);
}

int& sw::Model::getBonesNumber()
{
    return (m_boneCounter);
}