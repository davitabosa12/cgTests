#include "mesh.h"

#include <GL/gl.h>

// --------------------------------------------------------------------------
RawTriangleMesh::RawTriangleMesh()
	: TriangleMesh()
{
}
// --------------------------------------------------------------------------
RawTriangleMesh::~RawTriangleMesh()
{
}
// --------------------------------------------------------------------------
void RawTriangleMesh::_drawTriangles(void) const
{
	glBegin( GL_TRIANGLES );
		iterateVertices();
	glEnd();
}
// --------------------------------------------------------------------------
void RawTriangleMesh::_drawEdges(void) const
{
	// NOTA: line loops não são portáveis
	glBegin( GL_LINES );
		for( size_t i=0; (i+2)< vertices.size() ; i+=3 )
		{
			const Vertex& p0 = vertices[i+0];
			const Vertex& p1 = vertices[i+1];
			const Vertex& p2 = vertices[i+2];

			glVertex3fv( &p0.x );
			glVertex3fv( &p1.x );

			glVertex3fv( &p1.x );
			glVertex3fv( &p2.x );

			glVertex3fv( &p2.x );
			glVertex3fv( &p0.x );
		}
	glEnd();
}
// --------------------------------------------------------------------------
void RawTriangleMesh::_drawVertices(void) const
{
	glBegin( GL_POINTS );
		iterateVertices();
	glEnd();
}
// --------------------------------------------------------------------------
void RawTriangleMesh::iterateVertices(void) const
{
	for( const auto& v : vertices )
	{
		glVertex3fv( &v.x );
	}
}
// --------------------------------------------------------------------------
unsigned int RawTriangleMesh::getTriangleCount(void) const
{
	return vertices.size()/3;
}
// --------------------------------------------------------------------------
unsigned int RawTriangleMesh::getVertexCount(void) const
{
	return vertices.size();
}
// --------------------------------------------------------------------------
