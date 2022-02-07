#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            int average = round((blue + green + red) / 3);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            int sepiared = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepiagreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepiablue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            if (sepiared > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiared;
            }


            if (sepiagreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiagreen;
            }


            if (sepiablue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiablue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = blue;
            image[i][width - j - 1].rgbtGreen = green;
            image[i][width - j - 1].rgbtRed = red;
        }
    }
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //declaring a few variables
    int sumBlue;
    int sumGreen;
    int sumRed;
    //create a temporary table
    RGBTRIPLE temp[height][width];

//starting with loop on width and height
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            //Top row
            if (i == 0)
            {
                //top row left corner
                if (j == 0)
                {
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i][j + 1].rgbtBlue
                                         + image[i + 1][j].rgbtBlue
                                         + image[i + 1][j + 1].rgbtBlue) / 4);
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          + image[i][j + 1].rgbtGreen
                                          +  image[i + 1][j].rgbtGreen
                                          +  image[i + 1][j + 1].rgbtGreen) / 4);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        + image[i][j + 1].rgbtRed
                                        + image[i + 1][j].rgbtRed
                                        + image[i + 1][j + 1].rgbtRed) / 4);

                }

                else if (j == width - 1) //top row right corner
                {
                    //calculating pixels
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i][j - 1].rgbtBlue
                                         + image[i + 1][j].rgbtBlue
                                         + image[i + 1][j - 1].rgbtBlue) / 4);
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          + image[i][j - 1].rgbtGreen
                                          + image[i + 1][j].rgbtGreen
                                          + image[i + 1][j - 1].rgbtGreen) / 4);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        + image[i][j - 1].rgbtRed
                                        + image[i + 1][j].rgbtRed
                                        + image[i + 1][j - 1].rgbtRed) / 4);
                }

                else //top row middle pixel
                {
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i][j - 1].rgbtBlue
                                         + image[i][j + 1].rgbtBlue
                                         + image[i + 1][j].rgbtBlue
                                         + image[i + 1][j - 1].rgbtBlue
                                         + image[i + 1][j + 1].rgbtBlue) / 6);
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          + image[i][j - 1].rgbtGreen
                                          + image[i][j + 1].rgbtGreen
                                          + image[i + 1][j].rgbtGreen
                                          + image[i + 1][j - 1].rgbtGreen
                                          + image[i + 1][j + 1].rgbtGreen) / 6);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        + image[i][j - 1].rgbtRed
                                        + image[i][j + 1].rgbtRed
                                        + image[i + 1][j].rgbtRed
                                        + image[i + 1][j - 1].rgbtRed
                                        + image[i + 1][j + 1].rgbtRed) / 6);
                }

            }
            //Bottom row of image
            else if (i == height - 1)
            {
                if (j == 0) //left side pixel of bottom row
                {
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i][j + 1].rgbtBlue
                                         + image[i - 1][j].rgbtBlue
                                         + image[i - 1][j + 1].rgbtBlue) / 4);
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          + image[i][j + 1].rgbtGreen
                                          + image[i - 1][j].rgbtGreen
                                          + image[i - 1][j + 1].rgbtGreen) / 4);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        + image[i][j + 1].rgbtRed
                                        + image[i - 1][j].rgbtRed
                                        + image[i - 1][j + 1].rgbtRed) / 4);
                }

                else if (j == width - 1) //right side pixel of last row
                {
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i][j - 1].rgbtBlue
                                         + image[i - 1][j].rgbtBlue
                                         + image[i - 1][j - 1].rgbtBlue) / 4);
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          + image[i][j - 1].rgbtGreen
                                          + image[i - 1][j].rgbtGreen
                                          + image[i - 1][j - 1].rgbtGreen) / 4);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        + image[i][j - 1].rgbtRed
                                        + image[i - 1][j].rgbtRed
                                        + image[i - 1][j - 1].rgbtRed) / 4);
                }

                else //middle pixels of last row
                {
                    //calculating pixels
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i][j - 1].rgbtBlue
                                         + image[i][j + 1].rgbtBlue
                                         + image[i - 1][j].rgbtBlue
                                         + image[i - 1][j - 1].rgbtBlue
                                         + image[i - 1][j + 1].rgbtBlue) / 6);
                    //calculating pixels
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          + image[i][j - 1].rgbtGreen
                                          + image[i][j + 1].rgbtGreen
                                          + image[i - 1][j].rgbtGreen
                                          + image[i - 1][j - 1].rgbtGreen
                                          + image[i - 1][j + 1].rgbtGreen) / 6);
                    //calculating pixels
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        + image[i][j - 1].rgbtRed
                                        + image[i][j + 1].rgbtRed
                                        + image[i - 1][j].rgbtRed
                                        + image[i - 1][j - 1].rgbtRed
                                        + image[i - 1][j + 1].rgbtRed) / 6);
                }

            }

            else
            {
                //left side of image
                if (j == 0)
                {
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i - 1][j].rgbtBlue
                                         + image[i + 1][j].rgbtBlue
                                         + image[i][j + 1].rgbtBlue
                                         + image[i - 1][j + 1].rgbtBlue
                                         + image[i + 1][j + 1].rgbtBlue) / 6); //6 pixels surrounding the left side of the image
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          +  image[i - 1][j].rgbtGreen
                                          +  image[i + 1][j].rgbtGreen
                                          +  image[i][j + 1].rgbtGreen
                                          +  image[i - 1][j + 1].rgbtGreen
                                          +  image[i + 1][j + 1].rgbtGreen) / 6);
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        +  image[i - 1][j].rgbtRed
                                        +  image[i + 1][j].rgbtRed
                                        +  image[i][j + 1].rgbtRed
                                        +  image[i - 1][j + 1].rgbtRed
                                        +  image[i + 1][j + 1].rgbtRed) / 6);
                }

                //Right side of image
                else if (j == width - 1)
                {
                    //calculate for blue pixels
                    sumBlue = round(ceil(image[i][j].rgbtBlue
                                         + image[i - 1][j].rgbtBlue
                                         + image[i + 1][j].rgbtBlue
                                         + image[i][j - 1].rgbtBlue
                                         + image[i - 1][j - 1].rgbtBlue
                                         + image[i + 1][j - 1].rgbtBlue) / 6);
                    //calculate for green pixels
                    sumGreen = round(ceil(image[i][j].rgbtGreen
                                          +  image[i - 1][j].rgbtGreen
                                          +  image[i + 1][j].rgbtGreen
                                          +  image[i][j - 1].rgbtGreen
                                          +  image[i - 1][j - 1].rgbtGreen
                                          +  image[i + 1][j - 1].rgbtGreen) / 6);
                    //calculate for red pixels
                    sumRed = round(ceil(image[i][j].rgbtRed
                                        +  image[i - 1][j].rgbtRed
                                        +  image[i + 1][j].rgbtRed
                                        +  image[i][j - 1].rgbtRed
                                        +  image[i - 1][j - 1].rgbtRed
                                        +  image[i + 1][j - 1].rgbtRed) / 6);
                }

                else //middle pixels of middle rows
                {
                    //calculate for blue pixels
                    sumBlue = round(ceil(image[i - 1][j - 1].rgbtBlue
                                         + image[i - 1][j].rgbtBlue
                                         + image[i - 1][j + 1].rgbtBlue
                                         + image[i][j - 1].rgbtBlue
                                         + image[i][j].rgbtBlue
                                         + image[i][j + 1].rgbtBlue
                                         + image[i + 1][j - 1].rgbtBlue
                                         + image[i + 1][j].rgbtBlue
                                         + image[i + 1][j + 1].rgbtBlue) / 9);
                    //calculate for green pixels
                    sumGreen = round(ceil(image[i - 1][j - 1].rgbtGreen
                                          + image[i - 1][j].rgbtGreen
                                          + image[i - 1][j + 1].rgbtGreen
                                          + image[i][j - 1].rgbtGreen
                                          + image[i][j].rgbtGreen
                                          + image[i][j + 1].rgbtGreen
                                          + image[i + 1][j - 1].rgbtGreen
                                          + image[i + 1][j].rgbtGreen
                                          + image[i + 1][j + 1].rgbtGreen) / 9); // 9 pixels surrounding the middle one
                    //calculate for red pixels
                    sumRed = round(ceil(image[i - 1][j - 1].rgbtRed
                                        + image[i - 1][j].rgbtRed
                                        + image[i - 1][j + 1].rgbtRed
                                        + image[i][j - 1].rgbtRed
                                        + image[i][j].rgbtRed
                                        + image[i][j + 1].rgbtRed
                                        + image[i + 1][j - 1].rgbtRed
                                        + image[i + 1][j].rgbtRed
                                        + image[i + 1][j + 1].rgbtRed) / 9);
                }
            }

            //assign temp values with the calculated values
            temp[i][j].rgbtBlue = round((sumBlue));
            temp[i][j].rgbtGreen = round((sumGreen));
            temp[i][j].rgbtRed = round((sumRed));

        }
    }

    //copies values from temporary table and assigns to original image
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            //assiging temp value to original image
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}