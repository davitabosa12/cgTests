/*
 * camera.h
 *
 *  Created on: 9 de dez de 2017
 *      Author: davi
 */

#ifndef CAMERA_H_
#define CAMERA_H_


#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
class Camera {
public:
	Camera();
	~Camera();
	void move();
	void mouseMove(int x, int y);

	bool goingForward;
	bool goingBackward;
	bool goingLeft;
	bool goingRight;
	void resetStates();
	const glm::vec3& getPosition() const;
	void setPosition(const glm::vec3& position);
	const glm::vec3& getViewDirection() const;
	void setViewDirection(const glm::vec3& obj);

protected:
	glm::vec3 position;
	glm::vec3 viewDirection;
	glm::vec2 oldMousePos;


};

#endif /* CAMERA_H_ */
