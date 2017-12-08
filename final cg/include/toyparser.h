/*
 * ToyParser.h
 *
 *  Created on: 7 de dez de 2017
 *      Author: davi
 */

#ifndef TOYPARSER_H_
#define TOYPARSER_H_
#include<cstdio>
#include<string>
#include<iostream>
#include<vector>

class ToyParser {
public:
	ToyParser();
	~ToyParser();
	enum ModelType{
		MODEL_COMPLETE = 0x00,
		MODEL_VERTEX_ONLY = 0x01,
		MODEL_NO_NORMALS = 0x02,
		MODEL_NO_TEXTURE = 0x04,
		MODEL_VERTEX_NORMALS = 0x08

	};
	void parse(std::string objPath, IndexedTriangleMesh &myMesh, ModelType modelType);
};

#endif /* TOYPARSER_H_ */
