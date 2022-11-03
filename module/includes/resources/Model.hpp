/*
** ShipWreck Engine , 2022
** Model.hpp
*/

#ifndef SHIPWRECK_ENGINE_MODEL_HPP
#define SHIPWRECK_ENGINE_MODEL_HPP

#include <string>

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include "utils/Shader.hpp"
#include "components/Mesh.hpp"
#include "BoneInfo.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Model
    {
    public:
        Model() = delete;
        Model(Model const&) = delete;
        Model(Model&&) = delete;
        Model& operator=(Model const&) = delete;
        Model& operator=(Model&&) = delete;
        explicit Model(std::string path);
        ~Model();

        std::vector<std::shared_ptr<Mesh>> meshes;
        std::shared_ptr<Shader> shader;
        void compileModel();
        [[nodiscard]] bool isLoaded() const noexcept;
        [[nodiscard]] std::map<std::string, BoneInfo>& getBones();
        [[nodiscard]] int& getBonesNumber();
    private:
        std::map<std::string, BoneInfo> m_bones;
        int m_boneCounter;
        std::string m_directory;
        bool m_loaded;

        void processNode(aiNode *node, const aiScene *scene);
        void loadModel(std::string path);
        std::shared_ptr<Mesh> processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<std::shared_ptr<Texture>> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
        void ExtractBoneWeightForVertices(std::vector<Vertex>& vertices, aiMesh* mesh, const aiScene* scene);
    };
}

#endif //SHIPWRECK_ENGINE_MODEL_HPP
