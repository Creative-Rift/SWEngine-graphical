/*
** ShipWreck Engine , 2022
** Model.cpp
*/

#include <memory>
#include "Model.hpp"
#include "OpenResources.hpp"

sw::Model::Model(std::string path) :
shader("./resources/shaders/model_fs.glsl", "./resources/shaders/model_vs.glsl"),
meshes()
{
    loadModel(path);
}

sw::Model::~Model() noexcept
= default;

void sw::Model::loadModel(std::string path)
{
    Assimp::Importer import;
    const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
        return;
    }
    directory = path.substr(0, path.find_last_of('/'));

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

std::shared_ptr<sw::Mesh> sw::Model::processMesh(aiMesh *mesh, const aiScene *scene)
{
    std::vector<sw::Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<std::shared_ptr<sw::Texture>> textures;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        sw::Vertex vertex;
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
            //vertex.tangent.x = mesh->mTangents[i].x;
            //vertex.tangent.y = mesh->mTangents[i].y;
            //vertex.tangent.z = mesh->mTangents[i].z;
            //vertex.bitangent.y = mesh->mBitangents[i].y;
            //vertex.bitangent.x = mesh->mBitangents[i].x;
            //vertex.bitangent.z = mesh->mBitangents[i].z;
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

    return std::make_shared<sw::Mesh>(vertices, indices, textures);
}

std::vector<std::shared_ptr<sw::Texture>> sw::Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName)
{
    std::vector<std::shared_ptr<sw::Texture>> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        std::string fullPath = std::string("./resources/model/") + str.C_Str();
        if (!sw::OpenResources::m_ntext.contains(fullPath))
            sw::OpenResources::m_ntext.emplace(fullPath, std::make_shared<sw::Texture>(fullPath));
        auto ye = sw::OpenResources::m_ntext[fullPath];
        ye->type = typeName;
        textures.push_back(ye);
    }
    return textures;
}