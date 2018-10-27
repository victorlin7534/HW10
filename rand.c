#include "rand.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int generateRand(int bytes){
	int *num;
	int f = open("/dev/random",O_RDONLY);
	read(f,num,bytes);
	close(f);
	return abs(*num);
}

void printNums(int *arr){
	int i;
	for(i=0;i<10;i++)
		printf("random number %d: %d\n",i,arr[i]);
}