/************************************************************************
**
** NAME:        imageloader.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**              Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-15
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "imageloader.h"

//Opens a .ppm P3 image file, and constructs an Image object. 
//You may find the function fscanf useful.
//Make sure that you close the file with fclose before returning.
Image *readData(char *filename) 
{
	FILE* f = fopen(filename, "r");
	
	int col, row;
	fscanf(f,"%*[^\n]%*c%d%*c%d%*c%*[^\n]%*c",&col, &row);
	
	Image *p = malloc(sizeof(Image));
	p->cols = col;
	p->rows = row;
	// printf("%d \n", col);
	// printf("%d \n", row);
	p->image = malloc(row * sizeof(Color *));


	for(int i = 0; i < row; ++i)
	{
		p->image[i] = malloc(col * sizeof(Color));
		for(int j = 0; j < col; ++j)
		{

			fscanf(f,"%hhu",&(p->image[i][j].R));
			fscanf(f,"%hhu",&(p->image[i][j].G));
			fscanf(f,"%hhu",&(p->image[i][j].B));
		}
	}
	fclose(f);
	return p;

}

//Given an image, prints to stdout (e.g. with printf) a .ppm P3 file with the image's data.
void writeData(Image *image)
{
	//YOUR CODE HERE
	printf("P3\n%u %u\n255\n",image->cols, image->rows);
	for(int i = 0; i < image->rows; ++i)
	{
		// Color *temp = (image->image)[i];
		for(int j = 0; j < image->cols; ++j)
		{
			printf("%3hhu %3hhu %3hhu", image->image[i][j].R, image->image[i][j].G, image->image[i][j].B);
			if(j != image->cols - 1)
			{
				printf("   ");
			}
		}
		printf("\n");
	}
}

//Frees an image
void freeImage(Image *image)
{
	if(image)
	{
		for(int i = 0; i < image->rows; ++i)
		{
			free(image->image[i]);
		}
		free(image->image);
		free(image);
	}
}