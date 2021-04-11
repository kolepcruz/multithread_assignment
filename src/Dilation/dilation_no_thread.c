#include "dilation_no_thread.h"
// defines the distance between the pixel and the borders that we will analyse
#define SQR 2
#define MIN 1

int min(int a, int b) { if (a > b) return b; else return a; }
int max(int a, int b) { if (a < b) return b; else return a; }

void printNewImage(BW* image)
{
  printf("NEW IMAGE\n");
  printf("height %d, width: %d\n", image->size.height, image->size.width);
  for(int i = 0; i < image->size.height; i++)
  {
    for (int j = 0; j < image->size.width; j++)
      printf("%d", image->pixels[i][j]);
    printf("\n");
  }
}

BW* selectColor(BW* image, BW* newImage, int y, int x)
{
  newImage->pixels[y][x] = MIN;
  // somehow, *_x and *_y are changed. It brings no problem, tough.
  int up_y = max(0, y-SQR), down_y = min(y+SQR, newImage->size.height); 
  int l_x = max(0,x-SQR), r_x = min(x+SQR, newImage->size.width);
  for (int i = up_y; i < down_y; i++) 
  {
    for (int j = l_x; j < r_x; j++)
    {
      if (image->pixels[i][j] < newImage->pixels[y][x])
      {
        newImage->pixels[y][x] = image->pixels[i][j];
        return newImage;
      } 
    }
  }
  // printf("%d",newImage->pixels[x][y]);
  return newImage;
}

// Dilation Without Threads
BW* DWT (BW* image)
{
  BW* newImage = CNI(image->size.width, image->size.height);

  // the procedure repeats for each line
  for (int i = 0; i<image->size.height; i++)
  {
    for(int j = 0; j<image->size.width; j++)
    {
      newImage = selectColor(image, newImage, i, j);
    }
  }
  return newImage;
}

// Create New Image
BW* CNI (int width, int height)
{
  BW* newImage = malloc(sizeof(RGB));
  newImage->pixels = malloc(height*sizeof(BW));
  for (int i = 0; i < height; i++)
  {
    newImage->pixels[i] = malloc(width*sizeof(BW));
  }
  newImage->size.height = height;
  newImage->size.width = width;
  return newImage;
}