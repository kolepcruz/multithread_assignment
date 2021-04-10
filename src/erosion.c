#include "erosion.h"


BW *apply_erosion(BW *image, uint32_t startx, uint32_t starty,
                  uint32_t extralenx, uint32_t extraleny, uint32_t apothema)
{
    if (image == NULL)
    {
        perror("Received Null Pointer");
        exit(EXIT_FAILURE);
    }
    assert(extralenx * extralenx >= 2 * apothema &&
           startx + extralenx <= image->size.width &&
           starty + extraleny <= image->size.height);

    printf("Applying erosion algorithm\n");

    
    Element *p_element;
    p_element = init_element(apothema);

    BW *result;
    

    result = copy_image(image);
    result = clean_edges(result);
    result = iterate_center(image, p_element, result);


    printf("SUCESS!!!\nPRINTING RESULT ...\n\n");
    for (uint32_t i = 0; i < image->size.height; i++)
    {
        for (uint32_t j = 0; j < image->size.width; j++)
        {
            printf("%u ", result->pixels[i][j]);
        }
        printf("\n");
    }

    return result;
}


BW *iterate_center(BW *image, Element *B, BW *result)

{
    printf("Eroding image center\n");
    //  for (uint32_t i = 0; i < image->size.height; i++)
    // {
    //     for (uint32_t j = 0; j < image->size.width; j++)
    //     {
    //         printf("%u ", result->pixels[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    int32_t radius = (int32_t)B->apothema; 

    for (int32_t y = 1; y < image->size.height - 1; ++y)
    {
        for (int32_t x = 1; x < image->size.width - 1; ++x)
        {
            for (int32_t y_offset = -(radius); y_offset < radius; ++y_offset)
            {
                for (int32_t x_offset = -(radius); x_offset < radius; ++x_offset)
                {
                    // printf("[%d %d]\n",y,x);
                    if (!(B->value & image->pixels[y + y_offset][x + x_offset]))
                    {
                        for (int32_t i = -radius; i < radius; ++i)
                        {
                            for (int32_t j = -radius; j < radius; ++j)
                            {
                                // printf("mudarei o valor de %d %d que tá :%d\n",y + i,x + j,result->pixels[y + i][x + j]);
                                result->pixels[y + i][x + j] &= !B->value ;
                                // printf("mudei o valor de %d %d para :%d\n",y + i,x + j,result->pixels[y + i][x + j]);
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

BW *clean_edges(BW *image)
{
    printf("Eroding Image edges ...\n");
    for (uint32_t y = 0; y < image->size.height; ++y)
    {
            image->pixels[y][image->size.width - 1] = 0;
            image->pixels[y][0] = 0;
    }
    for (uint32_t x = 0; x < image->size.width; ++x)
    {
        image->pixels[0][x] = 0;
        image->pixels[image->size.height - 1][x] = 0;
    }
    return image;
}

Element *init_element(uint32_t apothema)
{
    printf("Generating Square Element ...\n");
    Element *p_element = malloc(sizeof(Element));
    p_element->apothema = apothema;
    p_element->value = 1;
    return p_element;
}

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
