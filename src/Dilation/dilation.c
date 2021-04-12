/*
  * Code built to be easily compatible with both Black&White and Gray parser approach.
  Therefore, its eficiency is slower than an Optimized Algorithm, though still 
  efficient for this application. It runs in O(H*W*(DIST)**2). 
    The idea is to search for the brightest pixel from a distance "DIST" around a
  specific pixel. 
*/

#include "dilation.h"

// defines the distance between the pixel and the borders that we will analyse.
#define DIST 2
// defines standard max value (black).
#define BLACK 1
// defines how many lines of the image matrix each thread solves. 
#define N_LINES 7

int min(int a, int b) { if (a > b) return b; else return a; }
int max(int a, int b) { if (a < b) return b; else return a; }

// Dilation Using Threads
BW* dilation (BW* image, BW* newImage)
{
  newImage = CNI(newImage, image->size.width, image->size.height);

  int n_thr = newImage->size.height/N_LINES+1;
  pthread_t* threads = (pthread_t*)malloc(n_thr*sizeof(pthread_t));
  for(int i = 0; i < n_thr; i++)
  {
    struct thr_props *prop = (struct thr_props *)malloc(sizeof(struct thr_props));
    prop->old = image;
    prop->curr = newImage;
    prop->begin = i*N_LINES;
    prop->end = min((i+1)*N_LINES, newImage->size.height); 
    if (pthread_create(&threads[i],NULL,SLP,prop))
      fprintf(stderr, "Erro na criação da thread. \n");
  }
  for(int i = 0; i < n_thr; i++)
    pthread_join(threads[i], NULL);
  return newImage;
}

// search light pixels. 
// Auxiliates the threads' worflow.
void* SLP (void* input)
{
  BW* image = ((struct thr_props*)input)->old;
  BW* newImage = ((struct thr_props*)input)->curr;
  int begin = ((struct thr_props*)input)->begin;
  int end = ((struct thr_props*)input)->end;
  for (int y = begin; y < end; y++)
  {
    for(int x = 0; x < newImage->size.width; x++)
    {
      newImage = selectColor(image, newImage, y, x);
    }
  }
  return newImage;
}

// searches for a brighter color around a certain pixel.
BW* selectColor(BW* image, BW* newImage, int y, int x)
{
  newImage->pixels[y][x] = BLACK;
  int up_y = max(0, y-DIST), down_y = min(y+DIST, newImage->size.height); 
  int l_x = max(0,x-DIST), r_x = min(x+DIST, newImage->size.width);
  for (int i = up_y; i < down_y; i++) 
  {
    for (int j = l_x; j < r_x; j++)
    {
      if (image->pixels[i][j] < newImage->pixels[y][x])
      {
        newImage->pixels[y][x] = image->pixels[i][j];
        // if we use for gray scale, remove 'return'.
        return newImage; 
      } 
    }
  }
  return newImage;
}

// Create New Image
BW* CNI (BW* newImage, int width, int height)
{
  newImage = malloc(sizeof(RGB));
  newImage->pixels = malloc(height*sizeof(BW));
  for (int i = 0; i < height; i++)
  {
    newImage->pixels[i] = malloc(width*sizeof(BW));
  }
  newImage->size.height = height;
  newImage->size.width = width;
  return newImage;
}


// this function is only for personal help. 
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