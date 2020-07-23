#include <stdio.h>
#include <stdlib.h>
void bugfunction(){

	int * intptr;

	intptr = (int *) malloc(sizeof(int));

	*intptr=55;

	free(intptr); //MEMORY LEAK
//	*intptr=99; //COMMON ERROR !!!
}

int main(){

	bugfunction();

	return 0;
}
