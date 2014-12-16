#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int counter, sum, min, num;

	if (argc < 2) {
		fprintf(stderr, "No numbers given, aborting.");
		return 1;
	}

	sum = min = atoi(argv[1]);

	for (counter = 2; counter != argc; counter++) {
		num = atoi(argv[counter]);

		sum += num;

		if (num < min)
			min = num;
	}

	printf("Sum: %d\nAvg: %lf\nMin: %d\n", sum, (double) sum / (argc - 1), min);
}

