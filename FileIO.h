/*This file is the header file
 * for FileIO.c, which includes
 * the LoadImage and SaveImage
 * function
 * File Created by: Edward Ou*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constants.h"

#ifndef FILEIO_H
#define FILEIO_H
/* load image from a file */
int LoadImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* save a processed image */
int SaveImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);
#endif
