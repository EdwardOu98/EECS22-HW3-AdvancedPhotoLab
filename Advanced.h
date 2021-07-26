/* This file is the header file
 * for the three new DIP filters. 
 * File Created by: Edward Ou*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "Constants.h"

#ifndef ADVANCED_H
#define ADVANCED_H
/* Brightness Function
 * This function adjusts the
 * brightness of a picture
 * using user's input. */
void Brightness(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], int brightness);

/* HMirror Function
 * This function horizontally
 * mirror an image. */
void HMirror(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* HMirror Function
 * This function applies
 * hue rotate effect to
 * an image. */
void HueRotate(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], float angle);

#endif
