#ifndef __IMG_STRUCT_H__
#define __IMG_STRUCT_H__
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef uint32_t Channel_type;
typedef Channel_type **Channel;

typedef struct Size
{
    uint32_t height;
    uint32_t width;
} Size;

typedef struct BW
{
    Size size;
    Channel pixels;
} BW;

typedef struct Gray
{
    Size size;
    Channel pixels;
} Gray;

typedef struct RGB
{
    Size size;
    Channel R;
    Channel G;
    Channel B;

} RGB;

/**
 * @brief This function allocates the memory for a black and white image, but doesn't garantee that it will have any default or uniform collor. Should only be used when all pixels will be replaced
 * 
 * @param width 
 * @param height 
 * @return BW* 
 */
BW *new_BW_fast_image(uint32_t width, uint32_t height);

/**
 * @brief This function allocates the memory for a black and white image, and garantees that it will be a white canvas
 * 
 * @param width 
 * @param height 
 * @return BW* 
 */
BW *new_BW_image(uint32_t width, uint32_t height);

void delete_image(BW *image);

#endif //__IMG_STRUCT_H__