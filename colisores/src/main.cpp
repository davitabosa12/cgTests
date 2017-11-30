/*
 * main.cpp
 *
 *  Created on: 30 de nov de 2017
 *      Author: aluno
 */

#include<GL/glut.h>
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

void desenhaBandeira(int numQuads){
	glColor3f(1,1,1);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	GLfloat ndc2window[16] = {
			2.0f/800,         0, 0, 0,
				   0, -2.0f/600, 0, 0,
				   0,         0, 1, 0,
				  -1,         1, 0, 1
		};
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(ndc2window);
	float initX = 0, initY = 0;
	float width = 100;
	float stepX = width / numQuads;

	glBegin(GL_TRIANGLE_STRIP	);
		glVertex2f(initX,0);
		glVertex2f(initX,100);
		for(int x = 1; x <= numQuads; x++){

			glVertex2f(initX + (stepX * x),0);
			glVertex2f(initX + (stepX * x),100);

		}


	glEnd();
}

void minhaCena(){
	desenhaBG();

	desenhaBandeira(30);
	glutSwapBuffers();
	glutPostRedisplay();
}

int main( int argc, char** argv ){
		glutInit( &argc, argv );
		glutInitWindowSize( 800, 600 );
		glutInitWindowPosition(10,10);
		glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL );
		glutCreateWindow("Bandeirinha");
		glutDisplayFunc(minhaCena);



		glutMainLoop();
	return 0;
}



