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

void helloWorld() {
    printf("Man I'm sorry!!!!!");
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
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);   
        if (result==1) {
        printf("first_pixel : %d, %d, %d",data[0],data[1],data[2]);
    } else {
        printf("error");
    }     
}

void tenth_pixel (char *source_path){
    int width, height, channel_count; 
    unsigned char *data;
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);   
        if (result==1) {
        printf("first_pixel : %d, %d, %d",data[27],data[28],data[29]);
    } else {
        printf("error");
    } 
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
