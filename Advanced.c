/* This is contains the function definition
 * for the three new DIP filters
 * File Created by: Edward Ou*/

#include "Advanced.h"

void Brightness(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], int brightness)
{
    int x, y;
    int tmp;

    for(y = 0; y < HEIGHT; y++)
    {
        for(x = 0; x < WIDTH; x++)
        {
            tmp = R[x][y] + brightness;
            if(tmp > 255){
                R[x][y] = 255;
            }
            else if(tmp < 0){
                R[x][y] = 0;
            }
            else{
                R[x][y] = tmp;
            }

            tmp = G[x][y] + brightness;
            if(tmp > 255){
                G[x][y] = 255;
            }
            else if(tmp < 0){
                G[x][y] = 0;
            }
            else{
                G[x][y] = tmp;
            }

            tmp = B[x][y] + brightness;
            if(tmp > 255){
                B[x][y] = 255;
            }
            else if(tmp < 0){
                B[x][y] = 0;
            }
            else{
                B[x][y] = tmp;
            }
        }
    }

}

void HMirror(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    int x, y;
    int i;

    /* Go through every pixel on the left of the center line
     * and copy their RGB values to their symetric pixels*/ 
    for(y = 0; y < HEIGHT; y++)
    {
        i = WIDTH - 1;
        for(x = 0; x < WIDTH/2; x++)
        {
            R[i][y] = R[x][y];
            G[i][y] = G[x][y];
            B[i][y] = B[x][y];
            
            i--;
        }
    }
}

void HueRotate(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], float angle)
{
    int x, y;
    float tmp;
    float new_R[WIDTH][HEIGHT], new_G[WIDTH][HEIGHT], new_B[WIDTH][HEIGHT];
    float Y[WIDTH][HEIGHT], I[WIDTH][HEIGHT], Q[WIDTH][HEIGHT];
    float tempY[WIDTH][HEIGHT], tempI[WIDTH][HEIGHT], tempQ[WIDTH][HEIGHT];
    float t1[3][3] = {{0.299, 0.587, 0.114}, 
                      {0.596, -0.274, -0.321}, 
                      {0.211, -0.523, 0.311}};
    float t2[3][3] = {{1.0, 0.956, 0.621}, 
                      {1.0, -0.272, -0.647},
                      {1.0, -1.107, 1.705}}; 

    /*Normalize RGB value by deviding the current RGB value by 255.0*/
    for(y = 0; y < HEIGHT; y++)
    {
        for(x = 0; x < WIDTH; x++)
        {
            new_R[x][y] = R[x][y] / 255.0;
            new_G[x][y] = G[x][y] / 255.0;
            new_B[x][y] = B[x][y] / 255.0;
        }
    } 

    /*Find the corresponding YIQ values by multiplying the RGB value by a matrix*/
    for(y = 0; y < HEIGHT; y++)
    {
        for(x = 0; x < WIDTH; x++)
        {
            tempY[x][y] = new_R[x][y] * t1[0][0] + new_G[x][y] * t1[0][1] + new_B[x][y] * t1[0][2];
            tempI[x][y] = new_R[x][y] * t1[1][0] + new_G[x][y] * t1[1][1] + new_B[x][y] * t1[1][2];
            tempQ[x][y] = new_R[x][y] * t1[2][0] + new_G[x][y] * t1[2][1] + new_B[x][y] * t1[2][2];
        }
    } 

    /*Apply the angle of rotation(unit: radian)*/
    for(y = 0; y < HEIGHT; y++)
    {
        for(x = 0; x < WIDTH; x++)
        {
            Y[x][y] = tempY[x][y];
            I[x][y] = tempI[x][y] * cos(angle) - tempQ[x][y] * sin(angle);
            Q[x][y] = tempI[x][y] * sin(angle) + tempQ[x][y] * cos(angle);
        }
    }

    /*Convert the YIQ value back to normalized RGB value by multiplying a matrix*/
    for(y = 0; y < HEIGHT; y++)
    {
        for(x = 0; x < WIDTH; x++)
        {
            new_R[x][y] = Y[x][y] + I[x][y] * t2[0][1] + Q[x][y] * t2[0][2];
            new_G[x][y] = Y[x][y] + I[x][y] * t2[1][1] + Q[x][y] * t2[1][2];
            new_B[x][y] = Y[x][y] + I[x][y] * t2[2][1] + Q[x][y] * t2[2][2];
        }
    }

   /*Convert normalized RGB value back to actual RGB value by multilying 255*/
    for(y = 0; y < HEIGHT; y++)
    {
        for(x = 0; x < WIDTH; x++)
        {
            tmp = new_R[x][y] * 255;
            if(tmp > 255)
            {
                R[x][y] = 255;
            }
            else if(tmp < 0)
            {
                R[x][y] = 0;
            }
            else
            {
                R[x][y] = (int)tmp;
            }

            tmp = new_G[x][y] * 255;
            if(tmp > 255)
            {
                G[x][y] = 255;
            }
            else if(tmp < 0)
            {
                G[x][y] = 0;
            }
            else
            {
                G[x][y] = (int)tmp;
            }

            tmp = new_B[x][y] * 255;
            if(tmp > 255)
            {
                B[x][y] = 255;
            }
            else if(tmp < 0)
            {
                B[x][y] = 0;
            }
            else
            {
                B[x][y] = (int)tmp;
            }
        }
    }
}
