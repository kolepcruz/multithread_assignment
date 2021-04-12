#include "parser.h"
#include "morphology.h"

int main()
{
    BW *image;
    image = open_pbm("./data/dilation.pbm");

    printf("altura: %u largura: %u\n", image->size.height, image->size.width);

    printf("\n\n");

    BW *result;
    bool deubom = prepare_algorithm(4, image, result);

    printf("\n\n");

    return EXIT_SUCCESS;
}