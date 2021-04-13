#include "image_utils.h"

BW *copy_image(BW *image)
{
    if (image == NULL)
    {
        perror("Received Null Pointer");
        exit(EXIT_FAILURE);
    }
    printf("Allocating memory for result ...\n");
    BW *result_image = malloc(sizeof(RGB));

    result_image->pixels = malloc(image->size.height * sizeof(Channel_type *));
    for (uint32_t i = 0; i < image->size.height; ++i)
    {
        result_image->pixels[i] = malloc(image->size.width * sizeof(Channel_type));
    }
    printf("Copying original image ...\n");
    for (uint32_t i = 0; i < image->size.height; ++i)
        for (uint32_t j = 0; j < image->size.width; ++j)
            result_image->pixels[i][j] = image->pixels[i][j];
    result_image->size.height = image->size.height;
    result_image->size.width = image->size.width;
    return result_image;
}

BW *init_kernel(uint32_t size)
{ //generates a square kernel
    printf("Initializing square kernel of size %d\n", size);
    BW *kernel;
    kernel = malloc(sizeof(RGB));
    kernel->size.width = kernel->size.height = 2 * size + 1; //kernel is n*n for this implementation
    kernel->pixels = malloc((2 * size + 1) * sizeof(Channel_type *));
    for (uint32_t i = 0; i < 2 * size + 1; ++i)
    {
        kernel->pixels[i] = malloc((2 * size + 1) * sizeof(Channel_type));
        for (uint32_t j = 0; j < 2 * size + 1; ++j)
            kernel->pixels[i][j] = BLACK;
    }
    return kernel;
}

void save_image(char *destination, BW *image)
{
    FILE *fp = fopen(destination, "w+");
    fprintf(fp, "P1\n");
    fprintf(fp, "%u %u\n", image->size.width, image->size.height);
    for (int i = 0; i < image->size.height; i++)
    {
        for (int j = 0; j < image->size.width; j++)
        {
            fprintf(fp, "%u", image->pixels[i][j]);
        }
        fprintf(fp, "\n");
    }
}

void print_image(BW *image)
{
    printf("height: %u width: %u\n", image->size.height, image->size.width);
    for (int i = 0; i < image->size.height; i++)
    {
        for (int j = 0; j < image->size.width; j++)
        {
            printf("%d", image->pixels[i][j]);
        }
        printf("\n");
    }
}