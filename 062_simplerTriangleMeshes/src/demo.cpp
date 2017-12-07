// Presentes: Arthur e Vitor

#include <GL/gl.h>
#include <GL/glut.h>

#include <cmath>
#include <iostream>
#include <algorithm>

#include "mesh.h"


static bool editingIndexedMesh = true;
static IndexedTriangleMesh itm;
static std::vector<unsigned int> pickedVertices;
static RawTriangleMesh rtm;
static int width = 800, height = 600;

static void meuPintaCena();

static void trataEventosDeTeclado(unsigned char key, int x, int y);
static void trataEventosDeMouse( int button, int state, int x, int y);
static void trataRedimensionamentoDeJanela( int w, int h);


int main( int argc, char** argv )
{
	glutInit( &argc, argv );
	glutInitWindowSize( width, height );
	//glutInitWindowSize( 800, 800 );
	glutInitWindowPosition(10,10);
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL );
	
	glutCreateWindow( "Malhas Ainda Mais Simples" );
	glutReshapeFunc( trataRedimensionamentoDeJanela );
	glutDisplayFunc( meuPintaCena );	
	glutKeyboardFunc( trataEventosDeTeclado );
	glutMouseFunc( trataEventosDeMouse );
	

	/*struct S1{ float x,y,z; };
	struct S2{ virtual ~S2(){} virtual void doit(){}  float x,y,z; };

	std::cout << sizeof(S1) << std::endl;
	std::cout << sizeof(S2) << std::endl;*/

	glutMainLoop();
	
	
	return 0;
}

void trataRedimensionamentoDeJanela( int w, int h)
{
	width = w, height = h;

	glViewport( 0,0, w, h );
}

static void meuPintaCena()
{	
	// =======================================================
	glClearColor(0,0,0,0);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );
	
	// =======================================================
	glLoadIdentity();	
	
	//
	glPointSize( 8.0f );
	glLineWidth( 1.5f );

	if( editingIndexedMesh )
	{

		itm.setDrawMode(   TriangleMesh::DRAW_TRIANGLES
				         | TriangleMesh::DRAW_EDGES
						 | TriangleMesh::DRAW_VERTICES

		);
		itm.draw();

		glColor3f(0,0,0.5f);
		glBegin(GL_POINTS);
			for( unsigned int i : pickedVertices )
			{
				glVertex3fv( &itm.getVertices()[i].x );
			}
		glEnd();
	}
	else
	{

		rtm.setDrawMode(   TriangleMesh::DRAW_TRIANGLES
						         | TriangleMesh::DRAW_EDGES
								 | TriangleMesh::DRAW_VERTICES

				);
		rtm.draw();
	}


	
	glutSwapBuffers();
	glutPostRedisplay();	
}

void trataEventosDeTeclado( unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'i': case 'I':
		editingIndexedMesh = true;
		glutSetWindowTitle("Modo de Edição: Malha Indexada");
		break;
	case 'r': case 'R':
		editingIndexedMesh = false;
		glutSetWindowTitle("Modo de Edição: Malha Crua");
		pickedVertices.clear();
		break;
	case 'c': case 'C':
		itm.clear();
		rtm.clear();
		pickedVertices.clear();
		break;
	case 's': case 'S':
		std::cout << "TODO: salvar malha!" << std::endl;
		break;
	case 'l': case 'L':
		std::cout << "TODO: carregar malha!" << std::endl;
		break;
	// Tecla "ESC"
	case 27:
		exit(-1);
		break; 	
	}
}


void trataEventosDeMouse( int button, int state, int x, int y)
{
	// conversão de coordenadas de Janela para NDC
	Vertex window( x, y );

	// NDC: canto superior esquerdo em (-1, +1) e canto inferior direito em (+1,-1)
	Vertex ndc;
	ndc.x = 2.0f*window.x/ float(width) -1.0f;
	ndc.y = 1.0f - 2.0f*window.y/ float(height);
	//
	

	if( state == GLUT_DOWN )
	{
		if( editingIndexedMesh )
		{
			// botão esquerdo adiciona vértices, botão direito os une até formar um triângulo
			switch( button )
			{
			case GLUT_LEFT_BUTTON:
				itm.addVertex( ndc.x, ndc.y );
			break;
			// o botão do meio descarta o último ponto capturado
			case GLUT_MIDDLE_BUTTON:
				if( pickedVertices.size() )
					pickedVertices.pop_back();
			break;
			case GLUT_RIGHT_BUTTON:
				for( size_t i=0 ; i<itm.getVertices().size() ; ++i )
				{
					const Vertex& v = itm.getVertices()[i];
					if( v.distance2(ndc) < 3.0f/float(width) )
					{
						std::cout << "\tpicked " << i << "-th vertex" << std::endl;
						pickedVertices.push_back(i);

						unsigned int t = pickedVertices.size();
						if( t && !(t% 3) )
						{
							std::cout << "tri: " <<
									pickedVertices[t-3] << ", " << pickedVertices[t-2] << ", " << pickedVertices[t-1]
									<< std::endl;

							itm.addTriangle( pickedVertices[t-3],pickedVertices[t-2],pickedVertices[t-1]  );
							pickedVertices.clear();
						}
						break;
					}
				}
				break;
			}
		}
		else
		{
			// edição de vértices. Simples assim na malha "crua"
			rtm.addVertex( ndc.x, ndc.y );
		}
	}
}
