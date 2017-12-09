/*
 * ToyParser.cpp
 *
 *  Created on: 7 de dez de 2017
 *      Author: davi
 */

#include <GL/gl.h>
#include "mesh.h"
#include <cstring>
#include<fstream>
#include <toyparser.h>


ToyParser::ToyParser() {
	// TODO Auto-generated constructor stub

}

ToyParser::~ToyParser() {
	// TODO Auto-generated destructor stub
}

void ToyParser::parse(std::string objPath, IndexedTriangleMesh &myMesh, ModelType modelType){
	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< Vertex > temp_vertices;
	std::vector< Vertex > temp_textures;
	std::vector< Vertex > temp_normals;
	std::string line;
	std::ifstream myfile (objPath);
	char tipo[128];
	if(myfile.is_open()){
		while(getline(myfile,line)){
			sscanf(line.c_str(),"%s",tipo);
			if(strcmp(tipo,"v") == 0){ //as coordenadas sao de vertice
							Vertex v;
							sscanf(line.c_str(),"%*s %f %f %f\n", &v.x, &v.y, &v.z);
							temp_vertices.push_back(v);
							myMesh.addVertex(v.x,v.y,v.z);
							//std::cout << "Vertex: x = " << v.x << " y = " << v.y << " z = " << v.z  << std::endl;
						}
						else if(strcmp(tipo, "vt") == 0){ //coordenadas de textura
							Vertex vt;
							sscanf(line.c_str(),"%*s %f %f\n", &vt.x, &vt.y);
							temp_textures.push_back(vt);
						}
						else if(strcmp(tipo, "vn") == 0){ //coordenadas de normal
							Vertex vn;
							sscanf(line.c_str(),"%*s %f %f %f\n", &vn.x, &vn.y, &vn.z);
							myMesh.addNormal(vn.x, vn.y, vn.z);
							//std::cout << "Vertex: x = " << vn.x << " y = " << vn.y << " z = " << vn.z  << std::endl;
							temp_normals.push_back(vn);
						}
						else if(strcmp(tipo, "f") == 0){ //indice de face
							unsigned int vIndex[3], vtIndex[3], vnIndex[3];
							if(modelType == MODEL_NO_TEXTURE)
							sscanf(line.c_str(),"%*s %d%*c%*c%d %d%*c%*c%d %d%*c%*c%d\n", &vIndex[0],&vnIndex[0],
																	 	 	 	&vIndex[1],&vnIndex[1],
																				&vIndex[2],&vnIndex[2]);
							myMesh.addTriangle(vIndex[0] -1,vnIndex[0]-1,
											   vIndex[1]-1,vnIndex[1]-1,
											   vIndex[2]-1,vnIndex[2]-1);
							/*std::cout << "vIndex: " << vIndex[0] << " "<< vIndex[1] << " "<< vIndex[2] << " "
									<<  " vnIndex: " << vnIndex[0] << " "<< vnIndex[1] << " "<< vnIndex[2] << " "
									<<std::endl;*/
						}
						else if(strcmp(tipo, "#") == 0){


							//std::cout << "Comment says: " << line << std::endl;
						}
						else{
							//std::cout << "Random" << std::endl;
						}
		}
		myfile.close();
	}
	else
		std::cout << "Nao consegui abrir" << std::endl;
	return;

}
