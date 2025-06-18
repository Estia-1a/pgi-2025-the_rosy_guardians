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
    int result=read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result==1) {
        printf("%s%d%s%d", "dimension: ", width, ", " , height);
    }
    else {
        printf("Erreur, aucune image trouvée ");
    }

}

void first_pixel (char *source_path) {
    int width, height, channel_count;
    unsigned char *data;
    int result=read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result==1) {
        printf("first pixel: %d %d %d ", data[0],  data[1],  data[2]);
    }
    else {
        printf("Erreur, aucune image trouvée ");
    }

    
}

void tenth_pixel (char *source_path) {
    int width, height, channel_count;
    unsigned char *data;
    int result=read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result==1) {
        printf("%s%d%s%d%s%d", "tenth pixel: ", data[27], ", ", data[28], ", ",  data[29]);
    }
    else {
        printf("Erreur, aucune image trouvée ");
    }

    
}

void second_line (char *source_path) {
    int width, height, channel_count;
    unsigned char *data;
    int result=read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result==1) {
        printf("%s%d%s%d%s%d", "second line: ", data[width*3], ", ", data[width*3+1], ", ",  data[width*3+2]);
    }
    else {
        printf("Erreur, aucune image trouvée ");
    }
}

void max_pixel(char *source_path) {
    int width, height,channel_count;
    unsigned char *data;
    int result=read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result != 1){
        printf("Erreur,aucune image trouvée\n");
        return 0;
    }
    
}


