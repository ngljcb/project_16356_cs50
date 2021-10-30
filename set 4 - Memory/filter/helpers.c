#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each pixel
    for (int i = 0; height > i; i++)
    {
        for (int j = 0; width > j; j++)
        {
            // Fetch color values
            int r = image[i][j].rgbtRed;
            int b = image[i][j].rgbtBlue;
            int g = image[i][j].rgbtGreen;

            // Calculate average color value
            int a = round((r + b + g) / 3.00);

            // Save average color value to the pixel
            image[i][j].rgbtRed = a;
            image[i][j].rgbtBlue = a;
            image[i][j].rgbtGreen = a;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each pixel
    for (int i = 0; height > i; i++)
    {
        for (int j = 0; width > j; j++)
        {
            // Fetch color values
            int r = image[i][j].rgbtRed;
            int b = image[i][j].rgbtBlue;
            int g = image[i][j].rgbtGreen;

            // Calculate sepia color value for red & save to pixel
            int sr = round((r * 0.393) + (g * 0.769) + (b * 0.189));
            image[i][j].rgbtRed = (sr < 256) ? sr : 255;

            // Calculate sepia color value for green & save to pixel
            int sg = round((r * 0.349) + (g * 0.686) + (b * 0.168));
            image[i][j].rgbtGreen = (sg < 256) ? sg : 255;

            // Calculate sepia color value for blue & save to pixel
            int sb = round((r * 0.272) + (g * 0.534) + (b * 0.131));
            image[i][j].rgbtBlue = (sb < 256) ? sb : 255;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each pixel
    for (int i = 0; height > i; i++)
    {
        for (int j = 0; (width / 2) > j; j++)
        {
            // Init temp variable
            RGBTRIPLE tmp = image[i][j];

            // Swap pixel colors
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Declare temp var
    RGBTRIPLE tmp[height][width];

    // Create a copy of the image
    for (int i = 0; height > i; i++)
    {
        for (int j = 0; width > j; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }

    // Declare variables
    int tr, tg, tb;

    // Declare counter var
    float c;

    // Iterate and calculate average color value of pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Init vars
            tr = tg = tb = 0;
            c = 0.00;

            // Get values of top left corner
            if (i - 1 >= 0 && j >= 0)
            {
                tr += tmp[i - 1][j].rgbtRed;
                tg += tmp[i - 1][j].rgbtGreen;
                tb += tmp[i - 1][j].rgbtBlue;
                c++;
            }

            // Get values of top right corner
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                tr += tmp[i - 1][j - 1].rgbtRed;
                tg += tmp[i - 1][j - 1].rgbtGreen;
                tb += tmp[i - 1][j - 1].rgbtBlue;
                c++;
            }

            // Get values of top edge
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                tr += tmp[i - 1][j + 1].rgbtRed;
                tg += tmp[i - 1][j + 1].rgbtGreen;
                tb += tmp[i - 1][j + 1].rgbtBlue;
                c++;
            }

            // Get values of left edge
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                tr += tmp[i + 1][j].rgbtRed;
                tg += tmp[i + 1][j].rgbtGreen;
                tb += tmp[i + 1][j].rgbtBlue;
                c++;
            }

            // Get values of middle pixel
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                tr += tmp[i + 1][j + 1].rgbtRed;
                tg += tmp[i + 1][j + 1].rgbtGreen;
                tb += tmp[i + 1][j + 1].rgbtBlue;
                c++;
            }

            // Get values of right edge
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                tr += tmp[i + 1][j - 1].rgbtRed;
                tg += tmp[i + 1][j - 1].rgbtGreen;
                tb += tmp[i + 1][j - 1].rgbtBlue;
                c++;
            }

            // Get values of bottom right
            if (i >= 0 && j >= 0)
            {
                tr += tmp[i][j].rgbtRed;
                tg += tmp[i][j].rgbtGreen;
                tb += tmp[i][j].rgbtBlue;
                c++;
            }

            // Get values of bottom left
            if (i >= 0 && j - 1 >= 0)
            {
                tr += tmp[i][j - 1].rgbtRed;
                tg += tmp[i][j - 1].rgbtGreen;
                tb += tmp[i][j - 1].rgbtBlue;
                c++;
            }

            // Get values of bottom edge
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                tr += tmp[i][j + 1].rgbtRed;
                tg += tmp[i][j + 1].rgbtGreen;
                tb += tmp[i][j + 1].rgbtBlue;
                c++;
            }

            // Calculate average color & save to image
            image[i][j].rgbtRed = round(tr / c);
            image[i][j].rgbtGreen = round(tg / c);
            image[i][j].rgbtBlue = round(tb / c);
        }
    }
    return;
}
