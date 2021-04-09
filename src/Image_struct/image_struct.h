#ifndef __IMG_STRUCT_H__
#define __IMG_STRUCT_H__
#include <stdint.h>

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

#endif //__IMG_STRUCT_H__