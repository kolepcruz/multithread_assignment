#ifndef __DILATION__
#define __DILATION__
#include <pthread.h>
#include "../Image_struct/image_struct.h"
#include "../Image_struct/pbm.h"
#include "stdio.h"
#include "stdlib.h"

// properties of thre thread (e.g. image, newImage...)
// defines the beginning and the end of lines analysed in the pixel matrix. 
struct thr_props
{
  BW* old;
  BW* curr;
  int begin;
  int end;
};

int min(int a, int b);
int max(int a, int b);
BW* dilation (BW* image, BW* newImage);
void* SLP (void* input);
BW* selectColor(BW* image, BW* newImage, int x, int y);

#endif