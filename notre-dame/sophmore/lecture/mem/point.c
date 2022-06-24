#include <stdlib.h>
#include <stdio.h>

typedef struct Point {
	int x;
	int y;
} Point;


int main(int argc, char * argv[])
{

	Point p0 = {0};
	Point p1 = {1, 2};


	printf("Size of Point: %ld\n", sizeof(Point));
	printf("&p0          : 0x%lx\n", &p0);
	printf("&p0.x        : 0x%lx\n", &p0.x);
	printf("&p0.y        : 0x%lx\n", &p0.y);


	return EXIT_SUCCESS;
}
