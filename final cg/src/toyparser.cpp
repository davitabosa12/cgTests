/*
 * ToyParser.cpp
 *
 *  Created on: 7 de dez de 2017
 *      Author: davi
 */

#include <toyparser.h>

ToyParser::ToyParser() {
	// TODO Auto-generated constructor stub

}

ToyParser::~ToyParser() {
	// TODO Auto-generated destructor stub
}

IndexedTriangleMesh ToyParser::parse(std::string objPath){

	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< Vec3 > temp_vertices;
	std::vector< Vec2 > temp_uvs;
	std::vector< Vec3 > temp_normals;
	FILE *f = fopen(objPath,"r");

}
