#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#include "erosion.h"
#define N_THREADS 5

int main()
{
    BW *image;
    image = open_pbm("./data/image_test.pbm");

    printf("altura: %u largura: %u\n", image->size.height, image->size.width);

    for (int i = 0; i < image->size.height; i++)
    {
        for (int j = 0; j < image->size.width; j++)
        {
            printf("%d ", image->pixels[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    BW *result;
    result = apply_erosion(image,0,0,image->size.width,image->size.height,1);
    
    printf("\n\n");

    return EXIT_SUCCESS;
}