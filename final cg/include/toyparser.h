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
	IndexedTriangleMesh parse(std::string objPath);
};

#endif /* TOYPARSER_H_ */
