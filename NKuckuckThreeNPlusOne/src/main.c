/*
 ============================================================================
 Name        : NKuckuckThreeNPlusOne.c
 Author      : Nicholas Kuckuck
 Version     :
 Copyright   : Simplified BSD License
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//===========Function Declarations===========================================

int computeMaxSequenceLength(int first, int last);
int computeSequenceLength(int i);
int computeNextValue(int v);

//===========================================================================

int main(void) { //prompt for output filename, get range from stdin, print out to file
	setvbuf(stdout, NULL, _IONBF, 0); // Turn off output buffering. Required for automated testing.
	int first_value, last_value;
	int MaxSequenceLength;
	char out[200];
	char buffer[BUFSIZ + 1]; // Reusable keyboard input buffer
	FILE *output;
	printf("Enter the output filename:\n");
	gets(out);
	output = fopen(out, "w");
	while (1) {

		first_value = atoi(gets(buffer));
		if (strlen(buffer) == 0) {
			fclose(output);
			printf("Complete\n");
			return EXIT_SUCCESS;

		}
		last_value = atoi(gets(buffer));

		//printf("%d, %d", first_value, last_value);

		MaxSequenceLength = computeMaxSequenceLength(first_value, last_value);

		fprintf(output, "%d\t%d\t%d\n", first_value, last_value,
				MaxSequenceLength);

	}
	fclose(output);
	return EXIT_SUCCESS;
}

int computeMaxSequenceLength(int first, int last) { // takes range first - last, returns max sequence
	int i;
	int Seq_Len = 0;
	int lastSeqLen;
	int max = 0;
	//printf("%d, %d", first, last);

	for (i = first; i < last; i++) {
		//max = Seq_Len;
		Seq_Len = computeSequenceLength(i);
		if (Seq_Len > max)
			max = Seq_Len;
		//lastSeqLen = computeSequenceLength(++i);
		//if (Seq_Len > lastSeqLen)
		//	max = Seq_Len;
		//printf("%d\n", Seq_Len);
	}
	//printf("%d, %d\n", Seq_Len, max);
	return max;
}

int computeSequenceLength(int i) { //takes number i, return sequence len of i
	int Seq_Len = 1;
	while (i != 1) {
		i = computeNextValue(i);
		++Seq_Len;
	}
	return Seq_Len;
}

int computeNextValue(int v) { //takes number v returns nxt number in sequence

	if (v % 2) {
		v = (v * 3) + 1;
	} else
		v = v / 2;
	return v;
}
