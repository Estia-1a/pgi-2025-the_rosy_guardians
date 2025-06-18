#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() 
{
    printf("Hello World !");
}
void dimension (char *source_path) {
    int width, height, channel_count; 
    unsigned char *data;
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result==1) {
        printf("dimension : %d, %d",width,height);
    } else {
        printf("error");
    }    
}

void first_pixel (char *source_path){
    int width, height, channel_count; 
    unsigned char *data;
    int result=read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result==1) {
        printf("first_pixel: %d%s%d%s%d ", data[0], ", ",  data[1], ", ", data[2]);
    }
    else {
        printf("Erreur, aucune image trouvée ");
    }

    
}

void tenth_pixel (char *source_path){
    int width, height, channel_count; 
    unsigned char *data;
    int result=read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result==1) {
        printf("%s%d%s%d%s%d", "tenth_pixel: ", data[27], ", ", data[28], ", ",  data[29]);
    }
    else {
        printf("Erreur, aucune image trouvée ");
    }

void second_line (char *source_path){
    int width, height, channel_count; 
    unsigned char *data;
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);   
        if (result==1) {
        printf("second_line : %d, %d, %d",data[width*3],data[width*3+1],data[width*3+2]);
    } else {
        printf("error");
}     



}


void color_blue (char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    int x,y;
    for(y=0;y<height;y++){
        for(x=0;x<width;x++){
            data[y * width * 3 + x * 3]=0;
            data[y * width * 3 + x * 3+1]=0;
        }
    }

    write_image_data("image_out.bmp", data, width, height);

   }

void color_green (char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    int x,y;
    for(y=0;y<height;y++){
        for(x=0;x<width;x++){
            data[y * width * 3 + x * 3]=0;
            data[y * width * 3 + x * 3+2]=0;
        }
    }

    write_image_data("image_out.bmp", data, width, height);

   }
 
 void color_red (char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    int x,y;
    for(y=0;y<height;y++){
        for(x=0;x<width;x++){
            data[y * width * 3 + x * 3+1]=0;
            data[y * width * 3 + x * 3+2]=0;
        }
    }

    write_image_data("image_out.bmp", data, width, height);

   }

void max_component (char *source_path, char c) {
	
    int M, x, y, start;
    M = 0;
    int width, height, channel_count; 
    unsigned char *data;
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);   
    if (result==1) {

        if (c == 'R'){
            start = 0;}
        else if (c== 'G'){
            start = 1;}
        else if (c == 'B'){
            start = 2;}
        else {
        printf("error");
    } 
            
        for (int i=0 ; i < height ; i++){
            for (int j=0; j < (width); j ++){
                
                if (M < data[i*channel_count*width+j*channel_count+start]){
                M = data[i*channel_count*width+j*channel_count+start];
                x = j;
                y = i;
                }	
            }		
        }
        printf ("(%i, %i) : %i",x,y,M);
        }
    else {
        printf("error");
    } 
}


