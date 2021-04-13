#include "image_struct.h"

BW *new_BW_fast_image(uint32_t width, uint32_t height)
{
    BW *image = malloc(sizeof(RGB));
    image->size.height = height;
    image->size.width = width;

    image->pixels = malloc(image->size.height * sizeof(Channel_type *));
    for (int i = 0; i < image->size.height; i++)
    {
        image->pixels[i] = malloc(image->size.width * sizeof(Channel_type));
    }
    return image;
}

BW *new_BW_image(uint32_t width, uint32_t height)
{
    BW *image = malloc(sizeof(RGB));
    image->size.height = height;
    image->size.width = width;

    image->pixels = malloc(image->size.height * sizeof(Channel_type *));
    for (int i = 0; i < image->size.height; i++)
    {
        image->pixels[i] = calloc(image->size.width, sizeof(Channel_type));
    }
    return image;
}

void delete_image(BW *image)
{
    printf("height: %u width: %u\n", image->size.height, image->size.width);
    for (int i = 0; i < image->size.height; i++)
    {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}
