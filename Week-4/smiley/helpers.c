#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Define the color to be used for colorization (in this case, red)
    RGBTRIPLE color;
    color.rgbtRed = 255;
    color.rgbtGreen = 0;
    color.rgbtBlue = 0;

    // Iterate over each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // If the pixel is black, change its color to the desired color
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                image[i][j] = color;
            }
        }
    }
}
