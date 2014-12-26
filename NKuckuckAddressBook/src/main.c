/*
 ============================================================================
 Name        : NKuckuckAddressBook.c
 Author      : Nicholas Kuckuck
 Version     :
 Copyright   : Simplified BSD License
 Description :
 ============================================================================
 */

#include <stdio.h> // standard input/output library functions
#include <stdlib.h> // standard input/output library functions
#include <string.h> // string functions on null-terminated strings
#include <ctype.h>
#include "address_book.h"

int main(void) {
	char letter;
	static int size = 0;
	Contact ContactArray[1000];

	setvbuf(stdout, NULL, _IONBF, 0); // Turn off output buffering. Required for automated testing.

	printf("Ready\n"); // ready

	do {
		//letter = fgetc(stdin); // command [a]dd [d]elete [g]et [f]ield [n]umber [l]oad [s]ave [q]uit
		letter = getchar();
		getchar();

		switch (letter) {
		case 'a':
			add_new_contact(ContactArray, size); //add a
			++size;

			break;
		case 'd':
			delete_contact(ContactArray); // delete a
			--size;
			break;

		case 'g':
			get_contact(ContactArray); //get a
			break;

		case 'f':
			get_field(ContactArray); // get field
			break;
		case 'n':
			number_of_contacts(ContactArray);
			printf("%i\n", size);
			break;
		case 'l':
			load_file(ContactArray); // load a
			break;
		case 's':
			save_file(ContactArray); // save a
			break;

		case 'q':
			printf("Complete\n"); // done a
			return EXIT_SUCCESS; // return a
			break;
		}
	} while (1);

	return EXIT_SUCCESS;
}


