#ifndef UTILS_H
#define UTILS_H


typedef struct _pixelRGB {
  unsigned char R ; 
  unsigned char G ; 
  unsigned char B ; 
} pixelRGB ;

//@brief Here, you have to define pixelRGB struct and its functions:
 pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y );
 void setPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB* pixel);
 



typedef struct {
  int x,y,r,g,b;

}PixelInfo;
PixelInfo find_max_pixel(unsigned char *data, int width, int height, int channels);

#endif
