/*
 ============================================================================
 Name        : NKuckuckHtmlSrcList.c
 Author      : Nicholas Kuckuck
 Version     :
 Copyright   : Simplified BSD License
 Description :
 ============================================================================
 */
#include <stdio.h>      // standard input/output library functions                                      [doc]=man 3 stdio
#include <stdlib.h>     // standard library definitions, EXIT_SUCCESS and EXIT_FAILURE constants        [doc]=man stdlib.h
#include <string.h>     // string functions on null-terminated strings                                  [doc]=man 3 string
#include <ctype.h>
//===========Function Declarations===========================================

void Read_URL(char buffer[]);
//void Get_Command_to_Execute();
void complete();

//===========================================================================

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0); // Turn off output buffering. Required for automated testing.
	char buffer[BUFSIZ + 1]; // Reusable keyboard input buffer

	printf("URL:\n");
	sprintf(buffer, "curl -s "); // print command into buffer
	fgets(buffer + strlen(buffer), BUFSIZ, stdin); // append url after command in buffer

	//printf("%s", buffer);
	Read_URL(buffer); //pass url into Read_URL func.
	complete();

	return EXIT_SUCCESS;
}

void Read_URL(char buffer[]) { //read url src code line by line into buffer3
	FILE *fp, *output, *freq;
	char *psrc;
	char *psrc2;
	char *pQ1;
	char *pQ2;
	char letter;
	char buffer2[BUFSIZ + 1];
	char buffer3[5000000];
	char buffer4[BUFSIZ + 1];
	char buffer5[BUFSIZ + 1];
	char temp[BUFSIZ + 1];
	char buffer6[BUFSIZ + 1];
	char buffer7[BUFSIZ + 1];
	//char buffer4[BUFSIZ + 1];
	int q = 0;
	fp = popen(buffer, "r");
	while (fgets(buffer2, BUFSIZ, fp)) {
		sprintf(buffer3 + strlen(buffer3), buffer2);
	}

	//printf("%s", buffer3);
	pclose(fp);
	printf("Ready\n");
	output = fopen("out.txt", "w");
	fprintf(output, buffer3); //write buffer3 to file
	fclose(output);

	do {
		letter = fgetc(stdin); // command c t u f q

		switch (letter) {
		case 'c':
			sprintf(buffer4, "grep -o -e ' src=\"' -e '	src=\"' %s | wc -l",
					"out.txt"); //
			fp = popen(buffer4, "r");
			fgets(buffer5, BUFSIZ, fp);
			printf("%s", buffer5);
			printf("Ready\n");
			break;
		case 't':
			freq = fopen("freq.txt", "w");
			psrc2 = buffer3;
			while (1) {
				psrc2 = strstr(psrc2, "src=\""); //
				if (!psrc2)
					break;
				if (!isspace(psrc2[-1]))
					goto INCREASE_psrc2_PTR;
				if (psrc2) {
					psrc = psrc2;
					while (psrc[0] != '<')
						psrc--;

					psrc++;

					while (!isspace(psrc[0])) {
						fprintf(freq, "%c", psrc[0]);
						printf("%c", psrc[0]);
						psrc++;
					}
					printf("\n");
					fprintf(freq, "\n");
					INCREASE_psrc2_PTR: ++psrc2;
				} else
					break;

			}
			//	strncpy(temp, psrc, 30);
			//puts(temp);
			printf("Ready\n");
			fclose(freq);
			break;
		case 'u':
			psrc2 = buffer3;
			while (1) {
				psrc2 = strstr(psrc2, "src=\"");
				if (!psrc2)
					break;
				if (!isspace(psrc2[-1]))
					goto INCREASE_psrc2_PTR2;

				if (psrc2) {
					pQ1 = psrc2;
					while (pQ1[0] != '\"') {
						pQ1++;

					}
					pQ2 = (pQ1 + 1);
					while (pQ2[0] != '\"') {
						pQ2++;
					}
					int numChar = ((pQ2 - pQ1) - 1);
					strncpy(temp, (pQ1 + 1), numChar);
					temp[strlen(temp) + 1] = '\0';
					printf("%s\n", temp);
					memset(&temp[0], 0, sizeof(temp));
					INCREASE_psrc2_PTR2: psrc2++;
				} else
					break;
			}
			printf("Ready\n");
			break;
		case 'f':
			freq = fopen("freq.txt", "w");
			psrc2 = buffer3;
			while (1) {
				psrc2 = strstr(psrc2, "src=\""); //
				if (!psrc2)
					break;
				if (!isspace(psrc2[-1]))
					goto INCREASE_psrc3_PTR;
				if (psrc2) {
					psrc = psrc2;
					while (psrc[0] != '<')
						psrc--;

					psrc++;

					while (!isspace(psrc[0])) {
						fprintf(freq, "%c", psrc[0]);
						//	printf("%c", psrc[0]);
						psrc++;
					}
					//		printf("\n");
					fprintf(freq, "\n");
					INCREASE_psrc3_PTR: ++psrc2;
				} else
					break;

			}

			fclose(freq);
			fp = popen("sort freq.txt | uniq -c", "r");
			while (fgets(buffer6, BUFSIZ, fp)) {
				sprintf(buffer7 + strlen(buffer7), buffer6);
			}

			printf("%s", buffer7);
			pclose(fp);

			printf("Ready\n");
			break;
		case 'q':
			q = 1;
			break;

		}

	} while (q != 1);

}

void complete() {
	printf("Complete\n");
}
