#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_LEN 80

struct Book {
	int id;
	char name[20];
	int date;
	char p_name[20];
	char p_number[20];
	char a_name[20];
	char email[20];
};

int main() {
	struct Book a[MAX_SIZE] = { 0 };
	int i, c;
	int pos = 0;

	while (1) {
		printf("\n---------------------------------------------------------------------\n");
		printf("1. Add book information\n");
		printf("2. Update book information\n");
		printf("3. Delete book information\n");
		printf("4. Search book information\n");
		printf("5. Display a list of book(s) published by an author \n");
		printf("6. Display a list of book(s) publisehd by a publisher \n");
		printf("7. Display a list of all book\n");
		printf("Select your operation!   ");
		scanf_s("%d", &c);
		printf("\n---------------------------------------------------------------------\n");

		switch (c) {
			case 1: {
				printf("Enter Book id (id should be unique): ");
				scanf_s("%d", &a[pos].id);
				if (a[pos].id <= 0) {
					printf("Id should not be a negative number or zero. Try it again\n");
					break;
				}
				printf("Enter Book name (don't use space, use _): ");
				scanf_s(" %[^\n]", a[pos].name, MAX_LEN);
				printf("Enter Publication date (YY/MM/DD, only numbers): ");
				scanf_s(" %d", &a[pos].date);
				printf("Enter Publisher name: ");
				scanf_s(" %s", a[pos].p_name, MAX_LEN);
				printf("Enter Publisher phone number : ");
				scanf_s(" %s", a[pos].p_number, MAX_LEN);
				printf("Enter Author name: ");
				scanf_s(" %s", a[pos].a_name, MAX_LEN);
				printf("Enter Author Email Address: ");
				scanf_s(" %s", a[pos].email, MAX_LEN);
				pos++;
				if (pos > MAX_SIZE)
					printf("Bookshelf is full, please retry again");
				printf("Add Finished.\n\n");
				break;
			}
			case 2: { //update
				break;
			}
			case 3: {//delete
				int x;
				printf("Which book to delete? Enter book id: ");
				scanf_s("%d", &x);
				for (i = 0; i < MAX_SIZE; i++) {
					if (a[i].id == x) {
						
					}
				}
				printf("Delete Finished.\n\n");
				break;
			}
			case 4: { //search
				int n;
				int loc = 0;
				printf("Which book to search? Enter book id: ");
				scanf_s("%d", &n);
				for (i = 0; i < MAX_SIZE; i++) {
					if (a[i].id == n) {
						loc = i;
						printf("Book searched! Your Book info will show under. \n");
						printf("------------------------------------------------------------------\n");
						printf("Book id: %d\n", a[i].id);
						printf("Book name: %s\n", a[i].name);
						printf("Publication date: %d\n", a[i].date);
						printf("Publisher name: %s \n", a[i].p_name);
						printf("Publisher phone number: %s\n", a[i].p_number);
						printf("Author name: %s\n", a[i].a_name);
						printf("Author Email address: %s\n", a[i].email);
					}
				}
				if (loc == 0) {
					printf("There is no such Book.\n");
				}
				
				break;
			}
			case 5: {//dispaly a list of book published by an author 
				char n[] = {0};
				int x;
				printf("Which author's book to find? ");
				scanf_s("%s", n, MAX_LEN);
				for (i = 0; i < MAX_SIZE; i++) {
					x = strcmp(a[i].a_name, n);
					if (x == 0) {
						printf("****%s****\n", a[i].name);
					}
				}
				printf("Display Finished!\n\n");
				break;
			}
			case 6: { //display a list of book published by an publisher
				char n[] = { 0 };
				int x;
				printf("Which publisher's book to find? ");
				scanf_s("%s", n, MAX_LEN);
				for (i = 0; i < MAX_SIZE; i++) {
					x = strcmp(a[i].p_name, n);
					if (x == 0) {
						printf("****%s****\n", a[i].name);
					}
				}
				printf("Display Finished!\n\n");
				break;
			}
			case 7: { //display all list 
				for (i = 0; i < MAX_SIZE; i++) {
					if (a[i].id > 0) {
						printf("\n****%d¹øÂ° Book info****\n", i+1);
						printf("id : %d\n", a[i].id);
						printf("Book name: %s\n", a[i].name);
						printf("Publisher's name: %s\n", a[i].p_name);
						printf("Author's name: %s\n", a[i].a_name);
					}
				}
				break;
			}
		}
	}
}