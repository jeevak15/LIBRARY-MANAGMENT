
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    char author[50];
};

struct Book b;

void addBook() {
    FILE *fp;
    fp = fopen("books.txt", "ab");

    printf("Enter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", b.name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b.author);

    fwrite(&b, sizeof(b), 1, fp);

    fclose(fp);

    printf("Book Added Successfully!\n");
}

void displayBooks() {
    FILE *fp;
    fp = fopen("books.txt", "rb");

    while(fread(&b, sizeof(b), 1, fp)) {
        printf("\nID: %d", b.id);
        printf("\nBook: %s", b.name);
        printf("\nAuthor: %s\n", b.author);
    }

    fclose(fp);
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Library Management System ---");
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid Choice!");
        }
    }

    return 0;
}
