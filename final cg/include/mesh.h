#ifndef TRIANGLEMESH_CLASS_H
#define TRIANGLEMESH_CLASS_H

#include "vertex.h"
#include <vector>


typedef std::vector<Vertex>        VertexArray;
typedef std::vector<unsigned int>  IndexArray;


struct Color
{
	Color()
		: r(0),g(0),b(0),a(1)
	{
	}
	Color( float R, float G, float B, float A=1 )
		: r(R),g(G),b(B),a(A)
	{
	}

	float r,g,b,a;
};


class TriangleMesh
{
public:

	enum DrawMode
	{
		DRAW_TRIANGLES = 0x01,
		DRAW_EDGES     = 0x02,
		DRAW_VERTICES  = 0x04
	};

	TriangleMesh(const TriangleMesh& ) = delete;
	TriangleMesh& operator=(const TriangleMesh& ) = delete;

	TriangleMesh(void);
	virtual ~TriangleMesh(void);

	const VertexArray& getVertices() const;

	void setDrawMode( unsigned char drawMode = TriangleMesh::DRAW_TRIANGLES );

	void addVertex( float x, float y, float z=0.0f );
	void addNormal( float x, float y, float z=0.0f );

	virtual void clear();

	virtual void draw(void) const;
	virtual unsigned int getTriangleCount(void) const = 0;
	virtual unsigned int getVertexCount(void) const = 0;


	Color triangleColor;
	Color edgeColor;
	Color vertexColor;

protected:

	virtual void _drawTriangles(void) const = 0;
	virtual void _drawEdges(void) const = 0;
	virtual void _drawVertices(void) const = 0;

	unsigned char drawModes;
	VertexArray vertices;
	VertexArray normals;
};

class RawTriangleMesh : public TriangleMesh
{
public:

	RawTriangleMesh(void);
	~RawTriangleMesh(void);

	virtual unsigned int getTriangleCount(void) const override;
	virtual unsigned int getVertexCount(void) const override;

protected:

	virtual void _drawTriangles(void) const override;
	virtual void _drawEdges(void) const override;
	virtual void _drawVertices(void) const override;

	/// Utilitário: entrega todos os vértices ao OpenGL via glVertex3f()
	void iterateVertices(void) const;


};

class IndexedTriangleMesh : public TriangleMesh
{
public:

	IndexedTriangleMesh(void);
	~IndexedTriangleMesh(void);

	virtual void clear() override;

	void addTriangle( unsigned int a,unsigned int na, unsigned int b,unsigned int nb, unsigned int c, unsigned int nc);

	virtual unsigned int getTriangleCount(void) const override;
	virtual unsigned int getVertexCount(void) const override;

protected:
	
	virtual void _drawTriangles(void) const override;
	virtual void _drawEdges(void) const override;
	virtual void _drawVertices(void) const override;

	IndexArray indices;
	IndexArray normalIndices;
};

#endif

