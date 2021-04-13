#ifndef __IMG_UTILS__
#define __IMG_UTILS__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include "Image_struct/image_struct.h"

#define WHITE 0
#define BLACK 1

BW *copy_image(BW *image);
BW *init_kernel(uint32_t size);
void print_image(BW *image);
void save_image(char *destination, BW *image);

#endif //__IMG_UTILS__