#include <GL/glut.h>
#include "mesh.h"
#include "toyparser.h"


void ler(IndexedTriangleMesh &myMesh){
	ToyParser parser;

	parser.parse("models/macaco2.obj",myMesh,ToyParser::MODEL_NO_TEXTURE);




}
void desenhe(){

	IndexedTriangleMesh myMesh;
	static bool parsed =false;
	if(!parsed){
		ler(myMesh);
		glTranslatef(0,-0.5f,0);
		glScalef(0.5f,0.5f,0.5f);

		myMesh.setDrawMode(TriangleMesh::DRAW_EDGES);
		myMesh.draw();
		parsed = true;
	}



	glutSwapBuffers();
	//glutPostRedisplay();
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
