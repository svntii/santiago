#include <stdio.h>
#include <stdlib.h>


typedef struct {int i; int *p;} St;
typedef union  {int i; int *p;} Un;

St S = {0};

int main(void){
	Un u = {sizeof(St)};
	St *p = calloc(u.i, sizeof(St));

	printf("%ld\n", sizeof(St));
	printf("%d\n", u.i);
	return 0;

}
