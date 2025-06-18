#include <estia-image.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
 
#include "utils.h"
 
pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ) {
    if (x>width || y>height || data==NULL) {
        printf("NULL");
        return (NULL);
    }
    else {
        return (pixelRGB *) &data[y*(width)*n+((x)*n)] ;
 
    }
 
}