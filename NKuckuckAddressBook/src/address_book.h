/*
 * address_book.h
 *
 *  Created on: May 9, 2014
 *      Author: nick
 */

#ifndef ADDRESS_BOOK_H_
#define ADDRESS_BOOK_H_

#include <stdio.h> // standard input/output library functions
#include <stdlib.h> // standard input/output library functions
#include <string.h> // string functions on null-terminated strings
#include <ctype.h>

typedef struct contact Contact;

struct contact{ //struct for contact
	char last_name[255];
	char first_name[255];
	char email[255];
	char phone_number[255];

	Contact *prev;
	Contact *next;
} ;

void add_new_contact(Contact *ContactArray, int size); //noodles a
void delete_contact(Contact *ContactArray); // domain an
void get_contact(Contact *ContactArray); // guit and
void get_field(Contact *ContactArray); // ford lol
void number_of_contacts(Contact *ContactArray); // mental ha
void load_file(Contact *ContactArray); // lap no
void save_file(Contact *ContactArray); // surround ok

#endif /* ADDRESS_BOOK_H_ */
