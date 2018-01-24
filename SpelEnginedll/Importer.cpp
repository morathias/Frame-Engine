#include "Importer.h"
#include "Assimp\Importer.hpp"
#include "Assimp\scene.h"
#include "Assimp\postprocess.h"

Importer::Importer()
{
}

Importer::~Importer()
{
}

bool Importer::importMesh(string filePath)
{
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(filePath, aiProcess_Triangulate | aiProcess_ConvertToLeftHanded);
	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) return false;

	return true;
}