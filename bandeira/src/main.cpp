/*
 * main.cpp
 *
 *  Created on: 14 de nov de 2017
 *      Author: aluno
 */
#include <cmath>
#include <GL/glut.h>
#include <iostream>

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


void desenhaBandeira(){
	GLfloat ndc2window[16] = {
			2.0f/800,         0, 0, 0,
				   0, -2.0f/600, 0, 0,
				   0,         0, 1, 0,
				  -1,         1, 0, 1
		};
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(ndc2window);

	//BANDEIRA

	glBegin(GL_TRIANGLE_STRIP);

		for(int x = 200; x < 500; x += 20){
			glColor3f(0,1,0);
			glVertex3f(x,100,0);
			glColor3f(0,0,1);
			glVertex3f(x,300,0);
		}

	glEnd();
}


void minhaCena(){
	desenhaBG();
	desenhaBandeira();



	glutSwapBuffers();
	glutPostRedisplay();
}

int main( int argc, char** argv ){
		glutInit( &argc, argv );
		glutInitWindowSize( 800, 600 );
		glutInitWindowPosition(10,10);
		glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL );
		glutCreateWindow("Bandeira");
		glutDisplayFunc(minhaCena);



		glutMainLoop();
	return 0;
}



