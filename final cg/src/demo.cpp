#include <GL/glut.h>
#include "mesh.h"
#include "toyparser.h"
#include "camera.h"

Camera c;
float remap(float value, float low1, float high1, float low2, float high2){
	return low2 + (value - low1) * (high2 - low2) / (high1 - low1);
}

void ler(IndexedTriangleMesh &myMesh){
	ToyParser parser;

	parser.parse("models/macaco.obj",myMesh,ToyParser::MODEL_NO_TEXTURE);
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
	float posx = remap(x,0.0f,600.0f, -2.0f, 2.0f);
	float posy = remap(y,0.0f,600.0f, 2.0f, -2.0f);

	c.mouseMove(x,y);



}

void desenhe(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glShadeModel(GL_FLAT);
	GLfloat light_position[] = { 0, 0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);


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
	gluPerspective(45,1,1,100);
	//gluLookAt(-c.getPosition().x,c.getPosition().y,c.getPosition().z, -c.getViewDirection().x,-c.getViewDirection().y,0,  0,1,0);
	glRotatef(-c.getViewDirection().x * 0.05,  0,1,0);
	glRotatef(-c.getViewDirection().y * 0.05,  1,0,0);
	glTranslatef(-c.getPosition().x,c.getPosition().y,c.getPosition().z);
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
	gluLookAt(0,0,1,  0,0,0,  0,1,0);
	glutKeyboardFunc( trataTeclado );
	//glutMouseFunc( trataMouseClick );
	//glutMotionFunc( trataMouseMove );
	glutMainLoop();



	return 0;
}
