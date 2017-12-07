#include "mesh.h"

#include <GL/gl.h>

// --------------------------------------------------------------------------
TriangleMesh::TriangleMesh()
	:
		triangleColor(1,1,1),
		edgeColor(0,0,1),
		vertexColor(1,0,0),
		drawModes( TriangleMesh::DRAW_TRIANGLES ),
		vertices()
{
}
// --------------------------------------------------------------------------
TriangleMesh::~TriangleMesh()
{
}
// --------------------------------------------------------------------------
void TriangleMesh::setDrawMode( unsigned char dm )
{
	drawModes = dm;
}
// --------------------------------------------------------------------------
void TriangleMesh::clear()
{
	vertices.clear();
}
// --------------------------------------------------------------------------
const VertexArray& TriangleMesh::getVertices() const
{
	return vertices;
}
// --------------------------------------------------------------------------
void TriangleMesh::addVertex( float x, float y, float z )
{
	vertices.push_back( Vertex(x,y,z) );
}
// --------------------------------------------------------------------------
void TriangleMesh::draw(void) const
{
	if( drawModes & TriangleMesh::DRAW_TRIANGLES )
	{
		const Color& c = triangleColor;
		glColor4f( c.r, c.g, c.b, c.a );

		_drawTriangles();
	}

	if( drawModes & TriangleMesh::DRAW_EDGES )
	{
		const Color& c = edgeColor;
		glColor4f( c.r, c.g, c.b, c.a );

		_drawEdges();
	}

	if( drawModes & TriangleMesh::DRAW_VERTICES )
	{
		const Color& c = vertexColor;
		glColor4f( c.r, c.g, c.b, c.a );

		_drawVertices();
	}
}
// --------------------------------------------------------------------------
