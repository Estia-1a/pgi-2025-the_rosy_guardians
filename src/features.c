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
        printf("first_pixel: %d%s%d%s%d ", data[0], ", ",  data[1], ", ", data[2]);
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
        printf("%s%d%s%d%s%d", "tenth_pixel: ", data[27], ", ", data[28], ", ",  data[29]);
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
        printf("%s%d%s%d%s%d", "second_line: ", data[width*3], ", ", data[width*3+1], ", ",  data[width*3+2]);
    }
    else {
        printf("Erreur, aucune image trouvée ");
    }
}

void print_pixel (char *source_path, const unsigned int x, const unsigned int y) {
    int width, height, channel_count;
    unsigned char *data;
    int result=read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result==1) {
        pixelRGB * pixel = get_pixel(data, width, height, channel_count, x, y);
        printf("%s%d%s%d%s%d%s%d%s%d", "print pixel (", x, ", ", y, "): ", pixel->R, ", ", pixel->G, ", ", pixel->B);
    }
    else {
        printf("Erreur, aucune image trouvée ");
    }

}
    