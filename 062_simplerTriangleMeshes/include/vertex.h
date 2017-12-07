#ifndef VERTEX_CLASS_H
#define VERTEX_CLASS_H

class Vertex
{
public:
	
	Vertex( float X=0, float Y=0, float Z=0 )
	 : x(X), y(Y), z(Z)
	{}

	~Vertex(){}

	float distance2( const Vertex& v ) const
	{
		const float dx = x - v.x;
		const float dy = y - v.y;

		return dx*dx + dy*dy;
	}

	Vertex& operator /=(float f)
	{
		x /= f;
		y /= f;
		z /= f;

		return *this;
	}


	float x, y, z;
};

#endif

