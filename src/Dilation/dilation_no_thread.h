#ifndef __DILATION_NO_THREAD__
#define __DILATION_NO_THREAD__
#include "../Image_struct/image_struct.h"
#include "../Image_struct/pbm.h"
#include "stdio.h"
#include "stdlib.h"

int min(int a, int b);
int max(int a, int b);
BW* selectColor(BW* image, BW* newImage, int x, int y);
BW* DWT (BW* image);
BW* CNI (int width, int height);
void printNewImage(BW* image);

#endif