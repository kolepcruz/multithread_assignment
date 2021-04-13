#include "parser.h"
#include "morphology.h"
#include "Dilation/dilation.h"
#define N_THREADS 5

int main()
{
    BW *image;
    char *address = "../data/image_test_erosion_dilation.pbm";
    image = open_pbm(address);

    print_image(image);

    BW *image_erosion = new_BW_fast_image(image->size.width, image->size.height);
    BW *image_dilation = new_BW_fast_image(image->size.width, image->size.height);
    // BW *newImage;

    image_erosion = prepare_algorithm(1, image, image_erosion);
    image_dilation = dilation(image_erosion, image_dilation);

    print_image(image_erosion);
    print_image(image_dilation);

    return EXIT_SUCCESS;
}