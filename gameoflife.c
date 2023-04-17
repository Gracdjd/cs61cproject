/************************************************************************
**
** NAME:        gameoflife.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-23
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "imageloader.h"

//Determines what color the cell at the given row/col should be. This function allocates space for a new Color.
//Note that you will need to read the eight neighbors of the cell in question. The grid "wraps", so we treat the top row as adjacent to the bottom row
//and the left column as adjacent to the right column.
Color *evaluateOneCell(Image *image, int row, int col, uint32_t rule)
{
	//YOUR CODE HERE

}

//The main body of Life; given an image and a rule, computes one iteration of the Game of Life.
//You should be able to copy most of this from steganography.c
Image *life(Image *image, uint32_t rule)
{
//确定周围的九个元素，判断有几个是1，如果自己是1并且有两个或三个bumber
	int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
	int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
	if(rule == 0x1808)
	{
		for(int i = 0; i < image->rows; ++i)
		{
			for(int j = 0; j < image->cols; ++j)
			{
				int count = 0;
				for(int t = 0; t < 8; ++t)
				{
					int t1 = i + dx[t];
					int t2 = i + dy[t];
					
					if(t1 < 0)
					{
						t1 = image->cols - 1;
					}
					else if(t1 >= image->cols)
					{
						t1 = 0;
					}
					if(t2 < 0)
					{
						t2 = image->rows - 1;
					}
					else if(t2 >= image->cols)
					{
						t2 = 0;
					}
					
					// if(image)

				}
			}
		}
		
	}
}

/*
Loads a .ppm from a file, computes the next iteration of the game of life, then prints to stdout the new image.

argc stores the number of arguments.
argv stores a list of arguments. Here is the expected input:
argv[0] will store the name of the program (this happens automatically).
argv[1] should contain a filename, containing a .ppm.
argv[2] should contain a hexadecimal number (such as 0x1808). Note that this will be a string.
You may find the function strtol useful for this conversion.
If the input is not correct, a malloc fails, or any other error occurs, you should exit with code -1.
Otherwise, you should return from main with code 0.
Make sure to free all memory before returning!

You may find it useful to copy the code from steganography.c, to start.
*/
int main(int argc, char **argv)
{
	if(argc != 3)
	{
		perror("usage: ./gameOfLife filename rule\nfilename is an ASCII PPM file (type P3) with maximum value 255.\nrule is a hex number beginning with 0x; Life is 0x1808.");
	}
	
}
