/*
 * texture.cpp
 *
 *  Created on: 10 de dez de 2017
 *      Author: davi
 */

#include "texture.h"
#include <cassert>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_img.h"

Texture::Texture(const std::string& path) {
	int width, height,numComponents;
	textureId = 0;
	unsigned char* imageData = stbi_load(path.c_str(), &width, &height, &numComponents, (int)4);
	if(imageData == NULL){
		std::cerr << "Boo! Textura nao carregada" << std::endl;
	}
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	stbi_image_free(imageData);

}

Texture::~Texture() {
	glDeleteTextures(1, &textureId);
}

void Texture::bind(unsigned int unit){
	assert(unit >=0 && unit <= 31);

	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, textureId);
}
