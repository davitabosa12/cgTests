#include <GL/glut.h>
#include "mesh.h"
#include "toyparser.h"


void ler(IndexedTriangleMesh &myMesh){
	ToyParser parser;

	parser.parse("models/plz.obj",myMesh,ToyParser::MODEL_NO_TEXTURE);




}
void desenhe(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	static IndexedTriangleMesh myMesh;
	static bool parsed =false;
	static float ang = 0.0f;
	if(!parsed){
		ler(myMesh);
		std::cout << "Leu mesh" << std::endl;
		parsed = true;
	}

	glTranslatef(0,-0.5f,0);
	glRotatef(ang, 0.0f, 1.0f, 0.0f);
	glScalef(0.5f,0.5f,0.5f);

	ang += 0.5f;

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
	//glutKeyboardFunc( trataTeclado );
	//glutMouseFunc( trataMouseClick );
	//glutMotionFunc( trataMouseMove );
	glutMainLoop();



	return 0;
}
