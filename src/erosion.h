#ifndef __EROSION_H__
#define __EROSION_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include "Image_struct/image_struct.h"

typedef struct Element
{
    uint32_t apothema;
    uint32_t value;
}Element;
BW *copy_image(BW *image);
BW* iterate_center(BW *image,Element *B,BW *result);
BW* clean_edges(BW* image);
BW* apply_erosion ( BW* image, uint32_t starting_x,uint32_t starting_y,
                    uint32_t extralenx, uint32_t extraleny, uint32_t apothema);
Element* init_element(uint32_t apothema);
#endif //__EROSION_H__

