#ifndef __PARSER_H__
#define __PARSER_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> // https://www.geeksforgeeks.org/error-handling-c-programs/
#include "Image_struct/image_struct.h"
#include "Image_struct/pbm.h"


BW* open_pbm(char *image_name);

#endif //__PARSER_H__