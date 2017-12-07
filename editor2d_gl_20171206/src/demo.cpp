#include <GL/glut.h>

#include <cmath>
#include <iostream>
#include <algorithm>

#include <map>

#include "drawingTool.h"
#include "pixelTool.h"

#define PIXEL_SIZE 20

static void meuPintaCena();

static void trataTeclado(unsigned char key, int x, int y);
static void trataMouseClick( int button, int state, int x, int y);
static void trataMouseMove( int x, int y);

// NOVO: imagem a ser renderizada
static Image img( 0xAC, 32, 16 );
static Image preview;

typedef std::map<unsigned char, DrawingTool* > ToolMap;
static ToolMap drawingTools;
static DrawingTool *tool = nullptr;

unsigned char colorA = 0;
unsigned char colorB = 255;


void flipH()
{
	const int W = img.getWidth();
	const int halfW = img.getWidth()/2;

	for( int r=0 ; r<img.getHeight() ; ++r  )
	{
		for( int c=0 ; c<halfW ; ++c  )
		{
			std::swap( img[r][c], img[r][W-c-1] );
		}
	}
}

void flipV()
{
	const int H = img.getHeight();
	const int halfH = img.getHeight()/2;

	for( int r=0 ; r<halfH ; ++r  )
	{
		for( int c=0 ; c<img.getWidth() ; ++c  )
		{
			std::swap( img[r][c], img[H-r-1][c] );
		}
	}
}


void noise()
{
	// novo: preenchimento da imagem com padrão aleatório e uma linha diagonal		
	for( int i=0 ; i<img.getPixelCount() ; ++i  )
		img.getPixels()[i] = rand() & 0xFF;
}

void invert()
{
	// novo: preenchimento da imagem com padrão aleatório e uma linha diagonal
	for( int i=0 ; i<img.getPixelCount() ; ++i  )
		img.getPixels()[i] = ~img.getPixels()[i];
}

void multiply( float f )
{
	// novo: preenchimento da imagem com padrão aleatório e uma linha diagonal
	for( int i=0 ; i<img.getPixelCount() ; ++i  )
	{
		img.getPixels()[i] = std::max( (pixel)0, (pixel)std::min( (int)0xFF, (int)(img.getPixels()[i]*f)) );
	}
}

int main( int argc, char** argv )
{
	glutInit( &argc, argv );
	glutInitWindowSize( img.getWidth()*PIXEL_SIZE, img.getHeight()*PIXEL_SIZE );
	glutInitWindowPosition(10,10);
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL );
	
	glutCreateWindow( "Editor de Imagens 2D - Pressione 'A' para Ajuda" );	
	glutDisplayFunc( meuPintaCena );	
	glutKeyboardFunc( trataTeclado );
	glutMouseFunc( trataMouseClick );
	glutMotionFunc( trataMouseMove );
	

	PenTool penTool;
	PixelTool pixelTool;
	LineTool lineTool;

	drawingTools[ '7' ] = &pixelTool;
	drawingTools[ '8' ] = &penTool;
	drawingTools[ '9' ] = &lineTool;



	/*
	// TODO se alguém quiser, pode criar uma janela secundária para lidar com as ferramentas
	glutCreateWindow( "Ferramentas" );
	glutDisplayFunc( meuPintaCena );
	glutKeyboardFunc( trataTeclado );
	glutMouseFunc( trataMouseClick );
	glutMotionFunc( trataMouseMove );
	*/

	glutMainLoop();
	
	
	return 0;
}

static void meuPintaCena()
{	
	// =======================================================
	glClearColor(0,0,0,0);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );
	
	// =======================================================
	glLoadIdentity();	
	
	// gera a imagem com ruído
	//noise();
	// exibe a imagem
	if( tool && tool->isMouseDown() )
		preview.display();
	else
		img.display();
	
	glutSwapBuffers();
	//glutPostRedisplay(); // reservado para jogos
}

void trataTeclado( unsigned char key, int x, int y)
{
	ToolMap::iterator it = drawingTools.find(key);
	if( it != drawingTools.end() )
	{
		tool = it->second;
		tool->reset();
		return;
	}else
	{
		tool = nullptr;
	}

	switch(key)
	{
	case '1':
	{
		static int cy = 0;
		//img.hline( 196, cy++, 0, img.getWidth()-1 );
		img.hline( 196, cy++, +100, -50 );
		break;
	}
	case '2':
	{
		static int cx = 0;
		img.vline( 64, cx++, -20, 40 );
		break;
	}
	case '4':
	{
		static int px = 0;
		img.drawRect( 64, px, px, img.getWidth()-px-1, img.getHeight()-px-1 );
		px++;
		break;
	}
	case '5':
	{
		img.fillRect( 64, -2000000000,-2000000000,+2000000000,+2000000000 );
		img.fillRect( 80, 1,1, img.getWidth()-2,+img.getHeight()-2 );


		img.fillRect( 96, -2000000000,-2000000000, img.getWidth()/4,+img.getHeight()/4 );
		img.fillRect( 96, +2000000000,-2000000000, img.getWidth()/4,+img.getHeight()/4 );

		img.fillRect( 96, -2000000000,+img.getHeight()/4, img.getWidth()/4,+img.getHeight() );
		img.fillRect( 96, +2000000000,+2000000000, img.getWidth()/4,+img.getHeight()/4 );


		img.fillRect( 128, img.getWidth()/4,-200000, 3*img.getWidth()/4,+20000);
		img.fillRect( 128, -20000,img.getHeight()/4,+200000, 3*img.getHeight()/4);

		break;
	}
	case '6':
	{
		img.lineMidPoint( 64, rand()%img.getWidth(), rand()%img.getHeight(),
							  rand()%img.getWidth(), rand()%img.getHeight()
							 );
		break;
	}


	case 'A': case 'a': 
		std::cout << std::endl << "Comandos do Editor:" << std::endl;
		std::cout << "\tW para limpar a imagem com branco" << std::endl;
		std::cout << "\tB para limpar a imagem com branco" << std::endl;
		std::cout << "\tN para uma imagem com ruído" << std::endl;
		std::cout << "\t+ e - para alterar a cor principal" << std::endl;
		break;
	case '-':
		colorA -= 1;
		break;
	case '+':
		colorA += 1;
		break;
	case 'h': case 'H':
		flipH();
		break;
	case 'r': case 'R':
	{
		Image rot( '@', img.getHeight(), img.getWidth() );


		for( int i=0; i<img.getHeight(); ++i )
			for( int j=0; j<img.getWidth(); ++j )
			{
				rot[j][i] = img[i][ img.getWidth() - 1 - j];
			}

		img = rot;

		glutReshapeWindow(img.getWidth()*PIXEL_SIZE, img.getHeight()*PIXEL_SIZE );
		break;
	}
	case 'v': case 'V':
		flipV();
		break;
	case 'w': case 'W': 
		img.clear( 255 );		
		break;
	case 'b': case 'B': 
		img.clear(0);
		break;
	case 'n':  case 'N':
		noise();
		break;
	case 'i':  case 'I':
		invert();
		break;
	case 'z':  case 'Z':
		multiply(1.1f);
		break;
	case 'x':  case 'X':
		multiply(0.9f);
		break;
	// Tecla "ESC"
	case 27:
		exit(-1);
		break; 	
	}

	glutPostRedisplay();
}

int color = -1;

void trataMouseClick( int button, int state, int x, int y)
{
	x/=PIXEL_SIZE, y/=PIXEL_SIZE;
	
	if( state == GLUT_DOWN )
	{
		/*color = (button==0)?  colorA : colorB;
		img.setPixelSafe( color, x, y );
		*/

		if( tool )
		{
			preview = img;
			if( tool->onMouseDown( preview, x, y ) )
			{
				img = preview;
			}
		}


	}else
	if( state == GLUT_UP )
	{
		color = -1;

		if( tool )
		{
			tool->onMouseUp( img, x, y );
		}
	}

	glutPostRedisplay();
}

void trataMouseMove( int x, int y)
{
	x/=PIXEL_SIZE, y/=PIXEL_SIZE;

	if( tool )
	{
		preview = img;
		if( tool->onMouseMove( preview, x, y ) )
		{
			img = preview;
		}
	}

	glutPostRedisplay();
}

