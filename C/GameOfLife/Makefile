# Author: Santiago
# E-mail: srodri25@nd.edu
# File Contents: This is the Makefile for compilation of Programming Challenge 02
#######################################

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
life := $(OBJ)/life.o $(OBJ)/PC02.o

#Initialize the folders for the objects and executables
initialize:
	mkdir $(OBJ) $(EXE)

$(OBJ)/life.o: $(SRC)/life.c
	$(PP) $(CFLAGS) -c $(SRC)/life.c -o $@

# Producing PC02.o
$(OBJ)/PC02.o: $(SRC)/PC02.c
	$(PP) $(CFLAGS) -c $(SRC)/PC02.c -o $@

# converting the  output to an executable
PC02: $(life)
	$(PP) $(CFLAGS) -o $(EXE)/PC02 $(life)


#Make Clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
