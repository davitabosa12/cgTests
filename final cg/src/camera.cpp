/*
 * camera.cpp
 *
 *  Created on: 9 de dez de 2017
 *      Author: davi
 */

#include "camera.h"
#include <iostream>

Camera::Camera(): position(0,0,0),viewDirection(0,0,0),oldMousePos(0,0) {
	// TODO Auto-generated constructor stub
	goingLeft = false;
	goingRight = false;
	goingForward = false;
	goingBackward = false;
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

const glm::vec3& Camera::getPosition() const {
	return position;
}

const glm::vec3& Camera::getViewDirection() const {
	return viewDirection;
}

void Camera::setViewDirection(const glm::vec3& obj) {
	this->viewDirection = obj;
}

void Camera::setPosition(const glm::vec3& position) {
	this->position = position;
}

void Camera::resetStates(){
	goingLeft = false;
	goingRight = false;
	goingForward = false;
	goingBackward = false;
}

void Camera::move(){
	if(goingLeft){
		position = position + (glm::vec3(-0.1,0,0));
	}
	if(goingRight){
		position = position + (glm::vec3(0.1,0,0));
	}
	if(goingForward){
		position = position + (glm::vec3(0,0,0.1));
	}
	if(goingBackward){
		position = position + (glm::vec3(0,0,-0.1));
	}
}
 void Camera::mouseMove(int x, int y){
	 glm::vec2 newMousePos = glm::vec2(x,y);


	 glm::vec2 delta = newMousePos - glm::vec2(300,300);


	 //std::cout << "Delta x: " << delta.x << " Delta y: " << delta.y << std::endl;
	 //std::cout << "Old x: " << oldMousePos.getX() << " Old y: " << oldMousePos.getY() << std::endl;

	 viewDirection += glm::vec3(-delta.x, delta.y, 0);
	 if(viewDirection.y > 180){
		 viewDirection.y = 180;
	 }
	 if(viewDirection.y < -180){
		 viewDirection.y = -180;
	 }


	 oldMousePos = newMousePos;




 }
