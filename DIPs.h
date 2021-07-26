/*This file is the header file and
 * function declaration for the 
 * DIP filters.
 * File created by: Edward Ou */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Constants.h"

#ifndef DIPS_H
#define DIPS_H
/* edge detection */
void Edge(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* change color image to black & white */
void BlackNWhite(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* shuffle the image */
void Shuffle(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

#endif
