/*
 * texture.h
 *
 *  Created on: 10 de dez de 2017
 *      Author: davi
 */

#include <GL/gl.h>
#include <string>

#ifndef TEXTURE_H_
#define TEXTURE_H_

class Texture {
public:
	Texture(const std::string& path);
	~Texture();
	void bind(unsigned int uint);

private:
	GLuint textureId;
	Texture(const Texture& other) {}
	void operator=(const Texture& other) {}

};

#endif /* TEXTURE_H_ */
