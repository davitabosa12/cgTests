#ifndef IMAGE2D_CLASS_H
#define IMAGE2D_CLASS_H

typedef unsigned char pixel;
typedef pixel* pixel_row;

class Image
{
public:

	Image();
	Image( pixel bg, int width, int height );
	
	~Image();
	
	void clear( pixel bgColor =0 );
	void display() const;
	void setPixel( pixel cor, int i, int j );
	void setPixelSafe( pixel cor, int i, int j );
	pixel getPixel( int i, int j ) const;
	pixel getPixelSafe( int i, int j ) const;
	
	pixel* getPixels();
	const pixel* getPixels() const;
	
	int getWidth() const;
	int getHeight() const;
	int getPixelCount() const;
	
	/*pixel* operator[] (size_t i)
	{
		return pixels[i];
	}
	const pixel* operator[] (size_t i) const
	{
		return pixels[i];
	}*/

private:
	pixel_row* pixels;
	pixel_row  buffer;
	int width;
	int height;
};

#endif

