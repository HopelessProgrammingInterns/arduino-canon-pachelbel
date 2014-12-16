#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
	int counter = 0;
	int numbers[100];
	int result = 0;
	for(;counter!=argc;counter++){
		result += atoi(argv[counter]);
	}
	printf("result: %d\n",result);
}
