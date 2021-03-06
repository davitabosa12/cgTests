#include <GL/glut.h>
#include "mesh.h"
#include "toyparser.h"
#include "camera.h"
#include "texture.h"

Camera c;

float remap(float value, float low1, float high1, float low2, float high2){
	return low2 + (value - low1) * (high2 - low2) / (high1 - low1);
}

void ler(IndexedTriangleMesh &myMesh){
	ToyParser parser;

	parser.parse("models/cena.obj",myMesh,ToyParser::MODEL_NO_TEXTURE);


}
void lerTextura(){
	//skybox = Texture("textures/img_cheryl.jpg");
}
void trataTeclado(unsigned char key, int x, int y){
	c.resetStates();
	switch(key){
		case 'w': case 'W':
			c.goingForward = true;
			break;
		case 'a': case 'A':
			c.goingLeft = true;
			break;
		case 's': case 'S':
			c.goingBackward = true;
			break;
		case 'd': case 'D':
			c.goingRight = true;
			break;
	}
	c.move();
}

void myPassiveMotionFunc(int x, int y){
	c.mouseMove(x,y);

}
//DESENHOS
void drawSkybox(float size){
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	glDepthMask(GL_FALSE);
	static bool lido = false;
	if(!lido){


		lido = true;
	}
	//TOP
	Texture skybox("textures/img_test.png");
	skybox.bind(0);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f,1.0f);
		//glColor3f(0.0f,0.5f,0.5f);
		glVertex3f( size, size, -size); // Top Right Of The Quad (Top)
		glTexCoord2f(0.0f,1.0f);
		glVertex3f(-size, size, -size); // Top Left Of The Quad (Top)
		//glColor3f(0.0f,0.0f,0.2f);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-size, size, size); // Bottom Left Of The Quad (Top)
		glTexCoord2f(1.0f,0.0f);
		glVertex3f( size, size, size); // Bottom Right Of The Quad (Top)
	glEnd();
	//BOTTOM
	glBegin(GL_QUADS);
		//glColor3f(0.0f,0.5f,0.5f);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f( size, -size,-size); // Top Right Of The Quad (Top)
		glVertex3f(-size, -size,-size); // Top Left Of The Quad (Top)
		//glColor3f(1.0f,0.0f,0.2f);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-size, -size, size); // Bottom Left Of The Quad (Top)
		glVertex3f( size, -size, size); // Bottom Right Of The Quad (Top)
	glEnd();
	//FRONT
	glBegin(GL_QUADS);
		//glColor3f(0.0f,0.5f,0.5f);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f( size, size, size); // Top Right Of The Quad (FRONT)
		glTexCoord2f(0.0f,1.0f);
		glVertex3f(-size, size, size); // Top Left Of The Quad (FRONT)
		//glColor3f(1.0f,0.0f,0.2f);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-size,-size,size); // Bottom Left Of The Quad (FRONT)
		glTexCoord2f(1.0f,0.0f);
		glVertex3f( size,-size,size); // Bottom Right Of The Quad (FRONT)
	glEnd();
	//BACK
	glBegin(GL_QUADS);
		//glColor3f(0.0f,0.5f,0.5f);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f( size,-size,-size); // Top Right Of The Quad (BACK)
		glTexCoord2f(0.0f,1.0f);
		glVertex3f(-size,-size,-size); // Top Left Of The Quad (BACK)
		//glColor3f(1.0f,0.0f,0.2f);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-size, size,-size); // Bottom Left Of The Quad (BACK)
		glTexCoord2f(1.0f,0.0f);
		glVertex3f( size, size,-size); // Bottom Right Of The Quad (BACK)
	glEnd();
	//LEFT
	glBegin(GL_QUADS);
		//glColor3f(0.0f,0.5f,0.5f);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(-size, size,-size); // Top Right Of The Quad (LEFT)
		glTexCoord2f(0.0f,1.0f);
		glVertex3f(-size,-size,-size); // Top Left Of The Quad (LEFT)
		//glColor3f(1.0f,0.0f,0.2f);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-size,-size, size); // Bottom Left Of The Quad (LEFT)
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(-size, size, size); // Bottom Right Of The Quad (LEFT)
	glEnd();
	//RIGHT
	glBegin(GL_QUADS);
		//glColor3f(0.0f,0.5f,0.5f);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f( size, size, -size); // Top Right Of The Quad (RIGHT)
		glTexCoord2f(0.0f,1.0f);
		glVertex3f( size, size,  size); // Top Left Of The Quad (RIGHT)
		//glColor3f(1.0f,0.0f,0.2f);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f( size,-size, size); // Bottom Left Of The Quad (RIGHT)
		glTexCoord2f(1.0f,0.0f);
		glVertex3f( size,-size,-size); // Bottom Right Of The Quad (RIGHT)
	glEnd();


	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
}
void desenhe(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	drawSkybox(50.0f);

	glEnable(GL_TEXTURE_2D);

	//glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);


	glEnable(GL_CULL_FACE);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHT0);
	GLfloat light_position[] = { 0.5, 1, 0.5, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHT1);
	GLfloat light2_position[] = { 0, 0, 1, 0.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, light2_position);

	glEnable(GL_LIGHT2);
	GLfloat light3_position[] = { 1, 0, 0, 0.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, light3_position);

	static IndexedTriangleMesh myMesh;
	static bool parsed =false;
	static float ang = 0.0f;
	if(!parsed){
		ler(myMesh);
		std::cout << "Leu mesh" << std::endl;
		parsed = true;
	}
	glutWarpPointer( 300, 300 );
	//================PROJECAO=======================
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-1,1, -1,1, -1,1);
	gluPerspective(45,1,0.5f,100);
	glRotatef(-c.getViewDirection().x * 0.05,  0,1,0);
	glRotatef(-c.getViewDirection().y * 0.05,  1,0,0);
	glTranslatef(-c.getPosition().x,c.getPosition().y -2.0f,c.getPosition().z);
	//================MODELVIEW=======================
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0,-0.5f,1);
	glRotatef(ang, 0.0f, 1.0f, 0.0f);
	glScalef(0.5f,0.5f,0.5f);


	//ang += 0.5f;

	myMesh.setDrawMode(TriangleMesh::DRAW_TRIANGLES);
	myMesh.draw();





	glutSwapBuffers();
	glutPostRedisplay();
}
int main( int argc, char** argv )
{
	glutInit( &argc, argv );
	glutInitWindowSize(600,600);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL );

	glutCreateWindow( "Cena" );
	glutDisplayFunc( desenhe );
	glutPassiveMotionFunc( myPassiveMotionFunc );
	//gluLookAt(0,0,1,  0,0,0,  0,1,0);
	glutKeyboardFunc( trataTeclado );
	//glutMouseFunc( trataMouseClick );
	//glutMotionFunc( trataMouseMove );
	glutMainLoop();



	return 0;
}
