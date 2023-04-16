/************************************************************************
**
** NAME:        steganography.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**				Justin Yokota - Starter Code
**				YOUR NAME HERE
**
** DATE:        2020-08-23
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "imageloader.h"

//Determines what color the cell at the given row/col should be. This should not affect Image, and should allocate space for a new Color.
Color *evaluateOnePixel(Image *image, int row, int col)
{
	if((row > image->rows) || (row < 0) || (col > image->cols) || (col < 0))
	{
		perror("row and col 输入错误\n");
		return NULL;
	}
	Color *color = malloc(sizeof(Color));

	if(image->image[row][col].B >> 7)
	{
		color->R = 255;
		color->G = 255;
		color->B = 255;
	}
	else
	{
		color->R = 0;
		color->G = 0;
		color->B = 0;
	}
	return color;
}

//Given an image, creates a new image extracting the LSB of the B channel.
Image *steganography(Image *image)
{
	// Image* newImage = malloc(sizeof(Image));
	// newImage->rows = image->rows;
	// newImage->cols = image->cols;

	// newImage->image = malloc(newImage->rows * sizeof(Color *));

	// for(int i = 0; i < newImage->rows; ++i)
	// {
	// 	newImage->image[i] = malloc(newImage->cols * sizeof(Color));
	// 	for(int j = 0; j < newImage->cols; ++j)
	// 	{
	// 		newImage->image[i][j].R = image->image[i][j].R;
	// 		newImage->image[i][j].G = image->image[i][j].G;
	// 		newImage->image[i][j].B = image->image[i][j].B;
	// 	}
	// }
	for(int i = 0; i < image->rows; ++i)
	{
		for(int j = 0; j < image->cols; ++j)
		{
			if(image->image[i][j].B >> 7)
			{
				image->image[i][j].G = 255;
				image->image[i][j].R = 255;
				image->image[i][j].B = 255;
			}
			else
			{
				image->image[i][j].G = 0;
				image->image[i][j].R = 0;
				image->image[i][j].B = 0;
			}
		}
	}

	return image;
}

/*
Loads a file of ppm P3 format from a file, and prints to stdout (e.g. with printf) a new image, 
where each pixel is black if the LSB of the B channel is 0, 
and white if the LSB of the B channel is 1.

argc stores the number of arguments.
argv stores a list of arguments. Here is the expected input:
argv[0] will store the name of the program (this happens automatically).
argv[1] should contain a filename, containing a file of ppm P3 format (not necessarily with .ppm file extension).
If the input is not correct, a malloc fails, or any other error occurs, you should exit with code -1.
Otherwise, you should return from main with code 0.
Make sure to free all memory before returning!
*/
int main(int argc, char **argv)
{
	//YOUR CODE HERE
	Image* img = readData(argv[1]);

	steganography(img);

	writeData(img);

	freeImage(img);
	return 0;
}
