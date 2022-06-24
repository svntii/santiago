CFLAGS= -g -Wall -fPIC -std=gnu99
CC= gcc
LD= gcc
AR= ar
ARFLAGS= rcs

all: greet.dyn greet.stc

library.o:		library.c
	$(CC) $(CFLAGS) -c -o library.o library.c

main.o:		main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

libgreet.so:	library.o
	$(LD) -sharedd -o libgreet.so library.o

libgreet.a:		library.o
	$(AR) $(ARFLAGS) libgreet.a library.o

greet.dyn:	main.o	libgreet.so

