#include <stdlib.h>
#include <stdio.h>

int main (int argc, char** argv)
{
	int year;

	if (argc < 2) {
		fprintf (stderr, "No year given, aborting\n");
		return 1;
	}

	year = atoi (argv[1]);

	printf ("%i is %s leap year.\n", year, (!(year % 4) && (year % 100)) || !(year % 400) ? "a" : "no");

	return 0;
}
