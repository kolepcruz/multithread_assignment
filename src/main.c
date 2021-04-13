#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#include "Dilation/dilation.h"
#define N_THREADS 5

void printPixels(BW *image)
{
  printf("altura: %u largura: %u\n", image->size.height, image->size.width);

    for (int i = 0; i < image->size.height; i++)
    {
        for (int j = 0; j < image->size.width; j++)
        {
            printf("%d", image->pixels[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    BW *image;
    // char* address = "/home/kenji/UNICAMP/MC504/multithread_assignment/data/image_test.pbm";
    char* address = "/home/ianloron00/Desktop/Unicamp/2021_1s/OS/multithread_assignment/data/image_test.pbm";
    image = open_pbm(address);

    printPixels(image);
    
    BW *newImage;

    newImage = dilation(image, newImage);
    
    printPixels(newImage);
    
    return EXIT_SUCCESS;

}