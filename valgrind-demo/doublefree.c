#include <stdio.h>
#include <stdlib.h>

void func(int *p){
	p[0]=10;
	printf("%d \n",*p);
	free(p);
}

int main(){
	int *ptr;
	ptr = (int *) malloc(4);
	func(ptr);
	free(ptr);	//Double free
}
