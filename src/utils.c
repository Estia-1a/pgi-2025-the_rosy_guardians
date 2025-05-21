#include <estia-image.h>
#include <stddef.h>
#include "utils.h"
#include <stdio.h>

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB * getPixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y) {

    if (x>width || y>height || data == NULL){
        printf("NULL");
    } 
    
    else {
        return (pixelRGB *) &data [y*width*n+x*n];
    }
}