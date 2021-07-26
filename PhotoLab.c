/*********************************************************************/
/* PhotoLab.c: assignment 2 for EECS 22, Fall 2018                 */
/*                                                                   */
/* modifications: Mihnea Chirila                            */
/* 09/27/17 RD	adjusted for lecture usage                           */
/* 10/1/18 MC	 adjusted for F18                           */
/*********************************************************************/
/* Enter your name, last name and UCInet ID below:
 *
 * *****************************
 * First Name : Edward
 * Last Name: Ou
 * UCInet ID: 15561434
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Constants.h"
#include "FileIO.h"
#include "DIPs.h"
#include "Advanced.h"


void PrintMenu();

/* Test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

int main() {
    unsigned char   R[WIDTH][HEIGHT];	/* use three 2-D arrays to store R, G, B components */
    unsigned char   G[WIDTH][HEIGHT];
    unsigned char   B[WIDTH][HEIGHT];

#ifdef DEBUG
    AutoTest(R, G, B);
#endif

#ifndef DEBUG
    int option;			/* user input option */
    int brg;                    /* user input brightness */
    float rad;                  /*user input angle */
    char fname[SLEN];		/* input file name */

    PrintMenu();
    printf("Please make your choice: ");
    scanf("%d", &option);

    int rc = -1;			/* return code of LoadImage() */

    while (option != EXIT) {
        if (option == 1) {
            printf("Please input the file name to load: ");
            scanf("%s", fname);
            rc = LoadImage(fname, R, G, B);
        }
        /* menu item 2 - 10 requires image is loaded first */
        else if (option >= 2 && option <= 8) {
            if (rc != SUCCESS)	 {
                printf("No image is read.\n");
            }
            /* now image is loaded */
            else {
                switch(option) {
                    case 2:
                        printf("Please input the file name to save: ");
                        scanf("%s", fname);
                        SaveImage(fname, R, G, B);
                        break;
                    case 3:
                        BlackNWhite(R, G, B);
                        printf("\"Black & White\" operation is done!\n");
                        break;
                    case 4:
                        Edge(R, G, B);
                        printf("\"Edge\" operation is done!\n");
                        break;
                    case 5:
                        Shuffle(R, G, B);
                        printf("\"Shuffle\" operation is done!\n");
                        break;
                    case 6:
                        do{
                            printf("Please enter a number between -255 and 255: ");
                            scanf("%d", &brg);
                            if(brg < -255 || brg > 255){
                                printf("Input is out of range!\n");
                            }
                        }while(brg < -255 || brg > 255);
                        Brightness(R, G, B, brg);
                        printf("\"Brightness\" operation is done!\n");
                        break;
                    case 7:
                        HMirror(R, G, B);
                        printf("\"HMirror\" operation is done!\n");
                        break;
                    case 8:
                        printf("Please enter a radian: ");
                        scanf("%f", &rad);
                        HueRotate(R, G, B, rad);
                        printf("\"HueRotate\" operation is done!\n");
                        break;
                    default:
                        break;
                }
            }
        }
        else if (option == 9) {
            AutoTest(R, G, B);
            rc = SUCCESS;	/* set returned code SUCCESS, since image is loaded */
        }
        else {
            printf("Invalid selection!\n");
        }

        /* Process finished, waiting for another input */
        PrintMenu();
        printf("Please make your choice: ");
        scanf("%d", &option);
    }
    printf("You exit the program.\n");
#endif
    return 0;
}

/*******************************************/
/* Function implementations should go here */
/*******************************************/


void PrintMenu() {
    printf("\n----------------------------\n");
    printf(" 1: Load a PPM image\n");
    printf(" 2: Save an image in PPM and JPEG format\n");
    printf(" 3: Change a color image to Black & White\n");
    printf(" 4: Sketch the edge of an image\n");
    printf(" 5: Shuffle an image\n");
    printf(" 6: Change the brightness of an image\n");
    printf(" 7: Horizontally Mirror an image\n");
    printf(" 8: Hue rotate an image\n");
    printf(" 9: Test all functions\n");
    printf("10: Exit the program\n");
}

/* Test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]) {
    char fname[SLEN] = "HSSOE";
    char sname[SLEN];
    int brightness = 200;
    float angle = -1.5;

    LoadImage(fname, R, G, B);
    BlackNWhite(R, G, B);
    strcpy(sname, "bw");
    SaveImage(sname, R, G, B);
    printf("Black & White tested!\n\n");

    LoadImage(fname, R, G, B);
    Edge(R, G, B);
    strcpy(sname, "edge");
    SaveImage(sname, R, G, B);
    printf("Edge Detection tested!\n\n");

    LoadImage(fname, R, G, B);
    Shuffle(R, G, B);
    strcpy(sname, "shuffle");
    SaveImage(sname, R, G, B);
    printf("Shuffle tested!\n\n");

    LoadImage(fname, R, G, B);
    Brightness(R, G, B, brightness);
    strcpy(sname, "brightness");
    SaveImage(sname, R, G, B);
    printf("Brightness tested!\n\n");

    LoadImage(fname, R, G, B);
    HMirror(R, G, B);
    strcpy(sname, "hmirror");
    SaveImage(sname, R, G, B);
    printf("HMirror tested!\n\n");

    LoadImage(fname, R, G, B);
    HueRotate(R, G, B, angle);
    strcpy(sname, "hue");
    SaveImage(sname, R, G, B);
    printf("HueRotate tested!\n\n");
}

/* EOF */
