/**********************************
 * Name: Santiago Rodriguez
 * Email: srodri25@nd.edu
 * File Name: PC02.c
 * Date Created: 1/27/2022
 * File Contents: This file contains main portion for Programming Challenge 02
 **********************************/

#define _BSD_SOURCE
#include "../include/life.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(const int argc, const char *argv[])
{
    if (argc == 4)
    {
        char board[BOARD_HEIGHT][BOARD_WIDTH];
        int exit_code = read_file(board, argv[1]);
        
		if (exit_code != 0) // does file exist
        {
            return exit_code;
        }
        
        int numPlays = get_num_plays(argv[2]);
        if (numPlays == -1) // is number of plays valid
        {
            return 3;
        }
        int i;

        for (i = 1; i <= numPlays; i++)
        {
            play_generation(board);
			print_board(board, i);
      		usleep(25000); 
		}
		
	print_to_file(board, argv[3]);	

    }
    else
    {
        fprintf(stderr, "Missing arguments. Syntax should be something like:\n\t'./executable read-in.txt #ofplays output.txt'\n");
        return 1;
    }
}
