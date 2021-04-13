#include "parser.h"
#include "morphology.h"
#include "Dilation/dilation.h"
#define N_THREADS 5

int main()
{
    BW *image;
    char* address = "../data/image_test.pbm";
    image = open_pbm(address);

    printPixels(image);
    
    BW *newImage;

    newImage = dilation(image, newImage);
    prepare_algorithm(4, image, newImage);
    
    return EXIT_SUCCESS;

}