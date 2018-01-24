#ifndef IMPORTER_H
#define IMPORTER_H
//=============================
#include "DllExportDefine.h"
#include <string>

using namespace std;
//=============================
class Importer
{
public:
	DllExport Importer();
	DllExport ~Importer();

	DllExport bool importMesh(string filePath);
};
//=============================
#endif
