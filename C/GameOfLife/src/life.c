/**********************************
 * Name: Santiago Rodriguez
 * Email: srodri25@nd.edu
 * File Name: PC02.c
 * Date Created: 1/27/2022
 * File Contents: This file contains function definitions for Programming Challenge 02
 **********************************/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/life.h"

int col_add(int col_index) // calculate x position bound logic is embedded within the function width is col
{
    while (col_index < 0)
    {
        col_index = col_index + BOARD_WIDTH;
    }

    while (col_index >= BOARD_WIDTH)
    {
        col_index = col_index - BOARD_WIDTH;
    }

    return col_index;
}

int row_add(int row_index) // calculate position row is height
{
    while (row_index < 0)
    {
        row_index = row_index + BOARD_HEIGHT;
    }

    while (row_index >= BOARD_HEIGHT)
    {
        row_index = row_index - BOARD_HEIGHT;
    }

    return row_index;
}

int adjacent_to(char board[][BOARD_WIDTH], int row_index, int col_index) // used very similar logic in fundamental's of computing assignment from last year
{
    int row, col, rowNew, colNew; // max possible places to check are 8
    int partners = 0;

    for (row = row_index - 1; row <= row_index + 1; row++) // using a double for loop to go through the 3 x 3 partner range
    {
        for (col = col_index - 1; col <= col_index + 1; col++)
        {
            // recalculation of index just in case it is off the board
            colNew = col_add(col); // offset is not needed already calculated
            rowNew = row_add(row); // offset is not needed already calculated

            if (rowNew == row_index && colNew == col_index) // ignore if it is in the current position
            {
                continue; // does not check that position
            }
            else
            {
                if (board[rowNew][colNew] == PLAY) // if the current position = play
				{
                    partners = partners +  1;
             	}
            }
        }
    }
    return partners;
}

int get_num_plays(const char *num_plays)
{
    
	int plays = atoi(num_plays);
    if (plays < 0)
        return -1;
    return plays;
}

void play_generation(char board[][BOARD_WIDTH])
{
    int neighbor, r, c;
    char nextGen[BOARD_HEIGHT][BOARD_WIDTH];

    for (r = 0; r < BOARD_HEIGHT; r++)
    {
        for (c = 0; c < BOARD_WIDTH; c++)
        {
            neighbor = adjacent_to(board, r, c);
            
            if (neighbor == 3)
            {
                nextGen[r][c] = PLAY;
            }
            else if (neighbor < 2 || neighbor > 3)
            {
                nextGen[r][c] = BLANK;
            }
            else
            {
                nextGen[r][c] = board[r][c];
            }
        }
    }
	
    swapValue(board, nextGen);
}

void print_board(char board[][BOARD_WIDTH], int gen)
{
    fprintf(stdout, "\033[H\033[J"); // clears screen
	fprintf(stdout,"Generation %d\n", gen);
    
	int r, c;
    for (r = 0; r < BOARD_HEIGHT; r++)
    {
        for (c = 0; c < BOARD_WIDTH; c++)
        {
            fprintf(stdout, "%c", board[r][c]);
        }
        fprintf(stdout, "\n");
    }
}

int read_file(char board[][BOARD_WIDTH], const char *name)
{
    FILE *filepointer; // similar syntax to example from cplusplus.org/reference/cstdio/fopen/?kw=fopen
    filepointer = fopen(name, "r");
    if (filepointer == NULL) // check to see if file exists, if not returns error statement
    {
        fprintf(stderr, "File Does Not Exist! Please put in a valid file\n");
        return 2;
    }
    int row = 0;
	
	for(row = 0; row < BOARD_HEIGHT; row++)
	{
		fscanf(filepointer,"%s",board[row]);
	}
	fclose(filepointer);
    return 0;
}

void print_to_file(char board[][BOARD_WIDTH], const char *name)
{
    FILE *output = fopen(name, "w");

    int row, col;

    for (row = 0; row < BOARD_HEIGHT; row++)
    {
		for( col = 0; col < BOARD_WIDTH; col++)
		{
			fprintf(output, "%c",board[row][col]);
		}
		fprintf(output,"\n");
    }
	fclose(output);
}

void swapValue(char board[][BOARD_WIDTH], char board1[][BOARD_WIDTH])
{
    int row, col;

    for (row = 0; row < BOARD_HEIGHT; row++)
    {
        for (col = 0; col < BOARD_WIDTH; col++)
        {
            board[row][col] = board1[row][col];
        }
    }
}
