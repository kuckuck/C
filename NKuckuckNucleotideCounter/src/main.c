/*
 ============================================================================
 Name        : NKuckuckNucleotideCounter.c
 Author      : Nicholas Kuckuck
 Version     :
 Copyright   : Simplified BSD License
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0); // Turn off output buffering. Required for automated testing.
	char in[100];
	char out[100];
	char letter;
	int a = 0, c = 0, g = 0, t = 0;

	FILE *input, *output;

	printf("Enter input filename:\n");
	gets(in);
	printf("Enter output filename:\n");
	gets(out);

	input = fopen(in, "r");
	output = fopen(out, "w");

	while (letter = fgetc(input), !feof(input)) {
		switch (letter) {
		case 'A':
			++a;
			break;
		case 'C':
			++c;
			break;
		case 'G':
			++g;
			break;
		case 'T':
			++t;
			break;
		case '\n':
			fprintf(output, "%d %d %d %d\n", a, c, g, t);
			a = 0; c = 0; g = 0; t = 0;
			break;

		}

	}

	fclose(input);
	fclose(output);

	printf("Complete\n");

	return EXIT_SUCCESS;
}
