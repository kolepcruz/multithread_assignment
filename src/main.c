#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#define N_THREADS 5

int main()
{
    BW *image;
    image = open_pbm("/home/kenji/UNICAMP/MC504/multithread_assignment/data/image_test.pbm");

    printf("altura: %u largura: %u\n", image->size.height, image->size.width);

    for (int i = 0; i < image->size.height; i++)
    {
        for (int j = 0; j < image->size.width; j++)
        {
            printf("%d ", image->pixels[i][j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;

}