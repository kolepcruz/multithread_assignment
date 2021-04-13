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