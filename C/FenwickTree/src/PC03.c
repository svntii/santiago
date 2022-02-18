/**********************************
 * Name: Santiago Rodriguez
 * Email: srodri25@nd.edu
 * File Name: PC03.c
 * Date Created: 2/12/2022
 * File Contents: This file contains the main component for Programming Challenge 03
 **********************************/

#include "../include/fenwick.h"

int main(const int argc, const char* argv[] )
{
    if (argc > 1)
    {
        long unsigned int length = (long unsigned int) get_num_inputs(argc);
        int * array =  create_array(argv, length); 
        int * fenwick = make_fenwick(array, length);
        int input;
        do
        {
            input = get_choice();
            switch(input)
            {
                case 1:
                    //print array and tree
                    print_array(array, length);
                  	print_array(fenwick, length);
					break;
                case 2:
                    // calculate a range sum
					sum_vals(fenwick, length);
                    break;
                case 3:
                    // update array and tree
                    update_fenwick(array, fenwick, length);
					break;
                default:
                    continue;
            }
        }
        
        while(input != 0);
		free(array);
		free(fenwick);
        return 0;
    }
    else
    { 
        fprintf(stderr, "Error 1: Incorrect amount of inputs.\n");
        return 1;
    }
}
