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

void print_pixel (char *source_path, const unsigned int x, const unsigned int y) {
    int width, height, channel_count;
    unsigned char *data;
    int result=read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result==1) {
        pixelRGB * pixel = get_pixel(data, width, height, channel_count, x, y);
        printf("%s%d%s%d%s%d%s%d%s%d", "print_pixel (", x, ", ", y, "): ", pixel->R, ", ", pixel->G, ", ", pixel->B);
    }
    else {
        printf("Erreur, aucune image trouvée ");
    }

}

void color_red (char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    int i=0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    while (i<width*height*channel_count) {
        data[i+1]=0;
        data[i+2]=0;
        i+=channel_count;
    }
    
    write_image_data("image_out.bmp", data, width, height); 

    if (write_image_data("image_out.bmp", data, width, height) !=0) {
        fprintf(stderr, "Erreur : Impossible d'écrire l'image rouge.\n");
    }

}

void invert_color (char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    int i=0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    while (i<width*height*channel_count) {
        data[i]=255-data[i];
        i+=1;
    }
    
    write_image_data("image_inverted.bmp", data, width, height); 

    if (write_image_data("image_inverted.bmp", data, width, height) !=0) {
        fprintf(stderr, "Erreur : Impossible d'écrire l'image inversée.\n");
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
 


void max_component (char *source_path, char c) {
	
    int M, x, y, start;
    M = 0;
    int width, height, channel_count; 
    unsigned char *data;
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);   
    if (result==1) {

        if (c == 'R'||'r'){
            start = 0;}
        else if (c== 'G'||'g'){
            start = 1;}
        else if (c == 'B'||'b'){
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
        printf("max_component %c (%d, %d): %d", c, x, y, M);
        }
    else {
        printf("error");
    } 
}
void min_component (char *source_path, char c) {
	
    int Min, x, y, start;
    Min = 255;
    int width, height, channel_count; 
    unsigned char *data;
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);   
    if (result==1) {

        if (c == 'R'||'r'){
            start = 0;}
        else if (c== 'G'||'g'){
            start = 1;}
        else if (c == 'B'||'b'){
            start = 2;}
        else {
        printf("error");
    } 
            
        for (int i=0 ; i < height ; i++){
            for (int j=0; j < (width); j ++){
                
                if (Min > data[i*channel_count*width+j*channel_count+start]){
                Min = data[i*channel_count*width+j*channel_count+start];
                x = j;
                y = i;
                }	
            }		
        }
        printf("min_component %c (%d, %d): %d", c, x, y, Min);
        }
    else {
        printf("error");
    } 
}


void color_gray (char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    int i=0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    while (i<width*height*channel_count) {
        data[i]=(data[i]+data[i+1]+data[i+2])/3;
        data[i+1]=data[i];
        data[i+2]=data[i];
        i+=channel_count;
    }
    
    write_image_data("image_grayscale.bmp", data, width, height); 

    if (write_image_data("image_greyscale.bmp", data, width, height) ==0) {
        fprintf(stderr, "Erreur : Impossible d'écrire l'image en greyscale.\n");
    }
}
void color_gray_luminance (char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    int i=0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    while (i<width*height*channel_count) {
        data[i]=(0.21*data[i]+0.72*data[i+1]+0.07*data[i+2]);
        data[i+1]=data[i];
        data[i+2]=data[i];
        i+=channel_count;
    }
    
    write_image_data("image_grayscale_luminance.bmp", data, width, height); 

    if (write_image_data("image_grayscale_luminance.bmp", data, width, height) ==0) {
        fprintf(stderr, "Erreur : Impossible d'écrire l'image en grayscale luminance.\n");
    }
}

void max_pixel (char *source_path) {
	
    int Max, x, y,somme;
    somme = 0;
    Max = 0;
    int R = 0;
    int G = 0;
    int B = 0;
    int width, height, channel_count; 
    unsigned char *data;
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);   
    if (result==1) {
        
        for (int i=0 ; i < height ; i++){
            for (int j=0; j < (width); j ++){
                somme = data[i*channel_count*width+j*channel_count] + data[i*channel_count*width+j*channel_count+1] + data[i*channel_count*width+j*channel_count+2];
                if (Max < somme){
                Max = somme;
                R = data[i*channel_count*width+j*channel_count];
                G = data[i*channel_count*width+j*channel_count+1];
                B = data[i*channel_count*width+j*channel_count+2];
                x = j;
                y = i;
                }	
            }		
        }
        printf("max_pixel (%d, %d): %d, %d, %d", x, y, R, G, B);
        }
    else {
        printf("error");
    } 
}

void max_pixel (char *source_path) {
	
    int Max, x, y,somme;
    somme = 0;
    Max = 0;
    int R = 0;
    int G = 0;
    int B = 0;
    int width, height, channel_count; 
    unsigned char *data;
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);   
    if (result==1) {
        
        for (int i=0 ; i < height ; i++){
            for (int j=0; j < (width); j ++){
                somme = data[i*channel_count*width+j*channel_count] + data[i*channel_count*width+j*channel_count+1] + data[i*channel_count*width+j*channel_count+2];
                if (Max < somme){
                Max = somme;
                R = data[i*channel_count*width+j*channel_count];
                G = data[i*channel_count*width+j*channel_count+1];
                B = data[i*channel_count*width+j*channel_count+2];
                x = j;
                y = i;
                }	
            }		
        }
        printf("max_pixel (%d, %d): %d, %d, %d", x, y, R, G, B);
        }
    else {
        printf("error");
    } 
}

void rotate_cw(char *source_path) {
    int width, height, nbChannels;
    unsigned char *source_data;
    unsigned char *target_data;

    if (read_image_data(source_path, &source_data, &width, &height, &nbChannels)) {
        target_data = (unsigned char *)malloc(width * height * nbChannels * sizeof(unsigned char));

        int target_width = height;
        int target_height = width;

        int y, x;
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                int source_pixel_index = (y * width + x) * nbChannels;
                int target_pixel_index = ((x * target_width) + (target_width - 1 - y)) * nbChannels;

                target_data[target_pixel_index] = source_data[source_pixel_index];
                target_data[target_pixel_index + 1] = source_data[source_pixel_index + 1];
                target_data[target_pixel_index + 2] = source_data[source_pixel_index + 2];

                if (nbChannels == 4) {
                    target_data[target_pixel_index + 3] = source_data[source_pixel_index + 3];
                }
            }
        }
        write_image_data("image_out.bmp", target_data, target_width, target_height);

        free(source_data);
        free(target_data);
    }
}