#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i <  height; i++) {
        for (int j = 0; j < width; j++)
        {
            BYTE avg = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i <  height; i++) {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //temp array to keep original pixel
    RGBTRIPLE temp = image;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float redSum = 0;
            float blueSum = 0;
            float greenSum = 0;
            float n = 0;
            //loop through surround pixels
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    //check if row or column in range
                    if ((i + k) < 0 || (i + k) >= height || (j + l) < 0 || (j + l) >= width)
                    {
                        break;
                    }
                    redSum += temp[i+k][j+l].rgbtRed;
                    blueSum += temp[i+k][j+l].rgbtBlue;
                    greenSum += temp[i+k][j+l].rgbtGreen;
                    n++;
                }
            }
            image[i][j].rgbtRed = redSum / n;
            image[i][j].rgbtBlue = blueSum / n;
            image[i][j].rgbtGreen = greenSum / n;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
