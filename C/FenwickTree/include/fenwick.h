/**********************************
 * Name: Santiago Rodriguez
 * Email: srodri25@nd.edu
 * File Name: fenwick.h
 * Date Created: 2/12/2022
 * File Contents: This file contains the function declarations for Programming Challenge 03
 **********************************/

#include <stdio.h>
#include <stdlib.h>

int get_num_inputs(const int);
int* create_array( const char* argv[], long unsigned int num_inputs );
void print_menu(); // print menu options
void print_array( int* the_array, long unsigned int array_len );
int get_choice(); // get user's choice and returns it
int* make_fenwick( int* array, long unsigned int length );
void update_fenwick(int * array, int* fenwick, long unsigned int array_len);
void sum_vals( int* fenwick, long unsigned int array_len ); // This is the function where you calculate the sum between two indicies

