# Author: Santiago Rodriguez
# Email: srodri25@nd.edu
# File Name: Makefile
# Date Created: 2/12/2022
# File Contents: This is the Makefile for compilation of Programming Challenge 03

# gcc is for the compiler for C
PP := gcc

# CFLAGS are the compiler flages (-O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm)
FLAGS := -lm
CFLAGS := -std=c11 $(FLAGS)

# Folder Variables
SRC := src
INC := include
OBJ := objects
EXE := exe

#Initialize the folders for the objects and executables
initialize:
		mkdir $(OBJ) $(EXE)

# making object files
$(OBJ)/fenwick.o: $(SRC)/fenwick.c
		$(PP) $(CFLAGS) -c $(SRC)/fenwick.c -o $@

# Producing PC01.o
$(OBJ)/PC03.o: $(SRC)/PC03.c
		$(PP) $(CFLAGS) -c $(SRC)/PC03.c -o $@

fenwick_objs := $(OBJ)/fenwick.o $(OBJ)/PC03.o

# converting the  output to an executable (makes object)
PC03: $(fenwick_objs)
		$(PP) $(CFLAGS) -o $(EXE)/PC03 $(fenwick_objs)

#Make Clean
clean:
		rm -rf $(OBJ)/* $(EXE)/*
