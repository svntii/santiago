/**********************************
 * Name: Santiago Rodriguez
 * Email: srodri25@nd.edu
 * File Name: PC02.c
 * Date Created: 1/27/2022
 * File Contents: This file contains function declarations for Programming Challenge 02
 **********************************/

// read in board
// print board
// clear screen   fprintf (stdout, "\033[H\033[J");
// play one round
// Print the final board

#define BOARD_WIDTH 70
#define BOARD_HEIGHT 30
#define BLANK '.'
#define PLAY 'X'


int col_add(int);
int row_add(int);
int adjacent_to(char board[][BOARD_WIDTH], int, int);
int get_num_plays(const char *);
void play_generation(char board[][BOARD_WIDTH]);
void print_board(char board[][BOARD_WIDTH], int);
int read_file(char board[][BOARD_WIDTH], const char *);
void print_to_file(char board[][BOARD_WIDTH], const char *);

void swapValue(char board[][BOARD_WIDTH], char board1[][BOARD_WIDTH]);
