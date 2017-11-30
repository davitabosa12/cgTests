/*
 * main.cpp
 *
 *  Created on: 14 de nov de 2017
 *      Author: aluno
 */

#include <GL/glut.h>

void desenhaBG(){
	glLoadIdentity();
	glDepthMask(GL_FALSE);
	glDisable(GL_LIGHTING);

	glBegin(GL_QUADS);
				glColor3f(0.3f,0.35f,0.89f);
				glVertex2f(-1.0f,1.0f);
				glVertex2f(1.0f,1.0f);
				glColor3f(0.7f,0.4f,0.1f);
				glVertex2f(1.0f,-1.0f);
				glVertex2f(-1.0f,-1.0f);
	glEnd();
	glDepthMask(GL_TRUE);

}


void desenhaBarco(){
	static float ang = 0.0f;
	GLfloat ndc2window[16] = {
		2.0f/800,         0, 0, 0,
			   0, -2.0f/600, 0, 0,
			   0,         0, 1, 0,
			  -1,         1, 0, 1
	};
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(ndc2window);
	glTranslatef(100,0,0);
	ang+= 0.01f;
		glRotatef(ang,0,0,1);

	glColor3f(1,1,1);
	//parte de baixo
	glBegin(GL_TRIANGLE_STRIP);
	//ponta do barco

		glVertex2f(100,300);
		glVertex2f(150,300);
		glVertex2f(150,350);
	//CORPO
		glVertex2f(200,300);
		glVertex2f(200,350);

		glVertex2f(250,300);
		glVertex2f(250,350);

		glVertex2f(300,300);
		glVertex2f(300,350);
	//PONTA FINAL
		glVertex2f(350,300);


	glEnd();
glColor3f(0.8f,0.8f,0.8f);
//bandeira
	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(190,300);
		glVertex2f(225,270);//meio
		glVertex2f(260,300);
	glEnd();

}


void minhaCena(){
	desenhaBG();
	desenhaBarco();



	glutSwapBuffers();
	glutPostRedisplay();
}

int main( int argc, char** argv ){
		glutInit( &argc, argv );
		glutInitWindowSize( 800, 600 );
		glutInitWindowPosition(10,10);
		glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL );
		glutCreateWindow("Barquin");
		glutDisplayFunc(minhaCena);



		glutMainLoop();
	return 0;
}



