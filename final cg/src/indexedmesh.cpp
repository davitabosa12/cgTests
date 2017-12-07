#include "mesh.h"

#include <GL/gl.h>

// --------------------------------------------------------------------------
IndexedTriangleMesh::IndexedTriangleMesh()
	: TriangleMesh(), indices()
{
}
// --------------------------------------------------------------------------
IndexedTriangleMesh::~IndexedTriangleMesh()
{
}
// --------------------------------------------------------------------------
void IndexedTriangleMesh::clear()
{
	TriangleMesh::clear();
	indices.clear();
}
// --------------------------------------------------------------------------
void IndexedTriangleMesh::addTriangle( unsigned int a, unsigned int b, unsigned int c )
{
	indices.push_back( a );
	indices.push_back( b );
	indices.push_back( c );
}
// --------------------------------------------------------------------------
void IndexedTriangleMesh::_drawTriangles(void) const
{
	// TODO perigo: cuidado com índices fora do array de vértices. Ex: índice 8 com 4 vértices.
	glBegin( GL_TRIANGLES );
		for( size_t t=0 ; (t+2)<indices.size() ; t+=3 )
		{
			const unsigned int i0 = indices[t+0];
			const unsigned int i1 = indices[t+1];
			const unsigned int i2 = indices[t+2];

			glVertex3fv( &vertices[i0].x );
			glVertex3fv( &vertices[i1].x );
			glVertex3fv( &vertices[i2].x );
		}
	glEnd();
}
// --------------------------------------------------------------------------
void IndexedTriangleMesh::_drawEdges(void) const
{
	// TODO perigo: cuidado com índices fora do array de vértices. Ex: índice 8 com 4 vértices.
	glBegin( GL_LINES );
		for( size_t t=0 ; (t+2)<indices.size() ; t+=3 )
		{
			const unsigned int i0 = indices[t+0];
			const unsigned int i1 = indices[t+1];
			const unsigned int i2 = indices[t+2];

			glVertex3fv( &vertices[i0].x );
			glVertex3fv( &vertices[i1].x );

			glVertex3fv( &vertices[i1].x );
			glVertex3fv( &vertices[i2].x );

			glVertex3fv( &vertices[i2].x );
			glVertex3fv( &vertices[i0].x );
		}
	glEnd();
}
// --------------------------------------------------------------------------
void IndexedTriangleMesh::_drawVertices(void) const
{
	// NOTA: que sintaxe mais "doce", não?
	glBegin( GL_POINTS );
		for( const auto& v : vertices )
		{
			glVertex3fv( &v.x );
		}
	glEnd();
}
// --------------------------------------------------------------------------
unsigned int IndexedTriangleMesh::getTriangleCount(void) const
{
	return indices.size()/3;
}
// --------------------------------------------------------------------------
unsigned int IndexedTriangleMesh::getVertexCount(void) const
{
	return vertices.size();
}
// --------------------------------------------------------------------------
