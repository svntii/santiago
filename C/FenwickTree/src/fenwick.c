/**********************************
 * Name: Santiago Rodriguez
 * Email: srodri25@nd.edu
 * File Name: fenwick.c
 * Date Created: 2/12/2022
 * File Contents: This file contains the function definitions for Programming Challenge 03
 **********************************/

#include "../include/fenwick.h"
#include <stdio.h>

int* create_array( const char* argv[], long unsigned int num_inputs ){
	
	int * arr = (int * )malloc(sizeof(int)* num_inputs); // statically allocating array
	arr[0] = 0; // initialize first array value
	long unsigned int iter;
	for(iter = 1 ; iter < num_inputs; iter++)
	{
		arr[iter] = atoi(argv[iter]);
	}
	return arr;
}

int get_num_inputs(const int argc)
{
    int val = argc;
    return val;
}

void print_menu()
{
	fprintf(stdout,"\n1: Print Array and Fenwick Tree\n2: Calculate range sum\n3: Update array and Fenwick Tree\n0: To quit\n\nEnter your selection: ");
}

void print_array( int* the_array, long unsigned int array_len )
{
    for(long unsigned int iter = 0; iter < array_len; iter++)
    {
        fprintf(stdout, "%d ", the_array[iter]);
    }
    fprintf(stdout, "\n");

}

int get_choice()
{
	int user_selection;
    print_menu();
	fscanf(stdin,"%d", &user_selection);
	
    return user_selection;
}

int* make_fenwick( int* array, long unsigned int length )
{
    int * fenwick = (int *)malloc(sizeof(int) * (length));
    long unsigned int iter;
	long unsigned int current;
    for(iter = 0; iter < length; iter++) // copy initial array to fenwick tree
    {
        fenwick[iter] = array[iter];
    }

    for(iter = 0; iter < length; iter++)
    {
		current = iter + (iter & - iter);
		if (current < length)
		{
			fenwick[current] = fenwick[current] + fenwick[iter];
		}
    }

    return fenwick;
}

void update_fenwick(int * array, int * fenwick, long unsigned int array_len )
{
	int location, new_val;
	fprintf(stdout,"Enter the location and value to update the intial array: ");
	fscanf(stdin, "%d %d", &location, &new_val);
	
	int diff = new_val - array[location];
	array[location] = new_val;
    
	while (location < (int)array_len)
    {
        fenwick[location] += diff; 
        location += location & -location;
    }
}

void sum_vals(int * fenwick, long unsigned int array_len)
{
    int left, right;
    int sumL = 0, sumR = 0;
   
	fprintf(stdout, "Please enter the range to calculate, between 1 and %lu (L R): ", array_len - 1);
    fscanf(stdin, "%d %d", &left, &right);
	int left1 = left;
	int right1 = right;
    
	left = left - 1;
    
   
    while( right > 0)
    {
        sumR = sumR + fenwick[right];
        right = right - (right & -right);
    }
    
	while( left > 0)
    {
        sumL = sumL + fenwick[left];
        left = left - (left & -left);
    }

    
    fprintf(stdout,"The sum from %d to %d is %d\n",left1 ,right1 ,sumR - sumL);
}
