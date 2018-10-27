#include "rand.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(){
	int file = open("file.txt",O_CREAT | O_WRONLY,S_IRUSR | S_IWUSR);
	int i;
	int *ranum = calloc(10,4);
	int *ranum2 = calloc(10,4);
	for(i=0;i<10;i++)
		ranum[i] = generateRand(4);
	printNums(ranum);
	printf("WRITING NUMBERS\n"); write(file,ranum,40);
	printf("%s\n",strerror(errno));
	close(file);

	file = open("file.txt",O_RDONLY);
	printf("READING NUMBERS\n"); read(file,ranum2,40);
	printf("%s\n",strerror(errno));
	printNums(ranum2);
	close(file);
	return 0;
}