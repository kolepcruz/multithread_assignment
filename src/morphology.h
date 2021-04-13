#ifndef __DILATION_H__
#define __DILATION_H__
#define NDEBUG 
#include<pthread.h>
#include<unistd.h>
#include "image_utils.h"
#include "stdio.h"
#define MAX_OP(a,b) (a>b)?a:b
#define MIN_OP(a,b) (a<b)?a:b 

typedef struct ME_args{
    BW* image;
    BW* kernel;
    BW* result;
    uint32_t starting_y;
    uint32_t extraleny;
}ME_args;

bool prepare_algorithm(uint32_t kernel_size, BW *image, BW* result);

// BW* apply_dilation ( BW* image, uint32_t starting_x,uint32_t starting_y,
//                     uint32_t extralenx, uint32_t extraleny, uint32_t kernel_size);

void *apply_erosion(void* args);


#endif //__DILATION_H__

