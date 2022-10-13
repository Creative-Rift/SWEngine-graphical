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
    private:
        std::string directory;

        void processNode(aiNode *node, const aiScene *scene);
        void loadModel(std::string path);
        std::shared_ptr<Mesh> processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<std::shared_ptr<Texture>> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
    };
}

#endif //SHIPWRECK_ENGINE_MODEL_HPP
