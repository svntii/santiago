#include <stdio.h>
#include <stdlib.h>

int main(void){
	char buf[BUFSIZ];
	
	while(fgets(buf, BUFSIZ, stdin))
	{
		int x, y;
		sscanf(buf, "%d %d", &x, &y);
		printf("%d %d\n", x, y);
		
	}
	
	return EXIT_SUCCESS;
}
