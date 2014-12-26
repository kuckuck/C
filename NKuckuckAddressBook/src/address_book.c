/*
 * address_book.c
 *
 *  Created on: May 9, 2014
 *      Author: nick
 */

#include "address_book.h" //header

void add_new_contact(Contact *ContactArray, int size) {
	char buffer[BUFSIZ + 1]; // Reusable keyboard input buffer
	const char s[2] = ",";
	int i;
	char *l;
	char *f;
	char *e;
	char *p;
	int index;

	index = atoi(gets(buffer)); // get number
// move elements in array + 1
	for (i = 1000 - 1; i >= index; i--)
		strcpy(ContactArray[i + 1].last_name, ContactArray[i].last_name);
	for (i = 1000 - 1; i >= index; i--)
		strcpy(ContactArray[i + 1].first_name, ContactArray[i].first_name);
	for (i = 1000 - 1; i >= index; i--)
		strcpy(ContactArray[i + 1].email, ContactArray[i].email);
	for (i = 1000 - 1; i >= index; i--)
		strcpy(ContactArray[i + 1].phone_number, ContactArray[i].phone_number);

	fgets(buffer, BUFSIZ, stdin); // get comma delimited last name, first name, email, phone_number , then strtok on comma

	l = strtok(buffer, s);

	f = strtok(NULL, s);
	e = strtok(NULL, s);
	p = strtok(NULL, s);
//insert into array
	strcpy(ContactArray[index].last_name, l);
	strcpy(ContactArray[index].first_name, f);
	strcpy(ContactArray[index].email, e);
	strcpy(ContactArray[index].phone_number, p);

	//printf("%s  %s  %s  %s", ContactArray[index].last_name, ContactArray[index].first_name, ContactArray[index].email, ContactArray[index].phone_number);

}

void delete_contact(Contact *ContactArray) {
	char buffer[BUFSIZ + 1];
	int i;
	int index;

	index = atoi(gets(buffer));

	for (i = index + 1; i <= 999; i++)
		strcpy(ContactArray[i - 1].last_name, ContactArray[i].last_name);
	for (i = index + 1; i <= 999; i++)
		strcpy(ContactArray[i - 1].first_name, ContactArray[i].first_name);
	for (i = index + 1; i <= 999; i++)
		strcpy(ContactArray[i - 1].email, ContactArray[i].email);
	for (i = index + 1; i <= 999; i++)
		strcpy(ContactArray[i - 1].phone_number, ContactArray[i].phone_number);

}

void get_contact(Contact *ContactArray) {
	char buffer[BUFSIZ + 1];
	int index;
	index = atoi(gets(buffer));

	printf("%s,%s,%s,%s", ContactArray[index].last_name,
			ContactArray[index].first_name, ContactArray[index].email,
			ContactArray[index].phone_number);

}

void get_field(Contact *ContactArray) {
}

void number_of_contacts(Contact *ContactArray) {  //done in main

//	int size = *ContactArraySize;

	//printf("%i\n", size);
}

void load_file(Contact *ContactArray) {
}

void save_file(Contact *ContactArray) {
}

