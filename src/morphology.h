#ifndef __DILATION_H__
#define __DILATION_H__
#define NDEBUG 
#include<pthread.h>
#include<unistd.h>
#include "image_utils.h"
#include "stdio.h"
#define MAX_OP(a,b) (a>b)?a:b
#define MIN_OP(a,b) (a<b)?a:b 

bool prepare_algorithm(uint32_t kernel_size, BW *image, BW* result);

// BW* apply_dilation ( BW* image, uint32_t starting_x,uint32_t starting_y,
//                     uint32_t extralenx, uint32_t extraleny, uint32_t kernel_size);

bool *apply_erosion(BW *image,uint32_t starting_y, uint32_t extraleny, BW *kernel,BW* result);


#endif //__DILATION_H__

