/*
 ============================================================================
 Name        : NKuckuckTestScoreStats.c
 Author      : Nicholas Kuckuck
 Version     :
 Copyright   : Simplified BSD License
 Description :
 ============================================================================
 */
#include <stdio.h>      // standard input/output library functions                                  [doc]=man 3 stdio
#include <stdlib.h>     // standard library definitions, EXIT_SUCCESS and EXIT_FAILURE constants    [doc]=man stdlib.h
#include <math.h>       // mathematical declarations (pi sqrt tan...)                               [doc]=man math.h

int main(void) {
	float std_dev;
	float score;
	float sum = 0;
	float sum_squares = 0;
	float min = -1;
	float max = -1;
	int i = 0;
	float avg;

	setvbuf(stdout, NULL, _IONBF, 0); // Turn off output buffering. Required for automated testing.
	char buffer[BUFSIZ + 1]; // Reusable keyboard input buffer
	printf(
			"Enter scores, one per line.  Press <ENTER> on a blank line to end.\n");

	do {
		score = atof(gets(buffer));
		if (buffer[0] == '\0')
			break;
		++i;
		if (max == -1)
			max = score;
		if (min == -1)
			min = score;
		if (score > max)
			max = score;
		if (score < min)
			min = score;
		sum = sum + score;
		sum_squares = sum_squares + (score * score);
	} while (buffer[0] != '\0');

	avg = (sum / i);
	std_dev = sqrt((sum_squares - ((sum * sum) / i)) / i);

	if (i == 0) {
		min = 0;
		max = 0;
		avg = 0;
		std_dev = 0;
	}

	printf("%d\t%f\t%f\t%f\t%f\n", i, min, max, avg, std_dev);

	return EXIT_SUCCESS;
}
