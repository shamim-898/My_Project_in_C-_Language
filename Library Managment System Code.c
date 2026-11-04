#include <stdio.h>
struct Book
{
int id;
char name[100];
int available;
};
struct Book books[100];
int totalBooks = 0;
void showMenu();
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void clearInputBuffer();
void readLine(char str[], int size);
int findBookByID(int id);
int findBookByName(char name[]);
void showBookDetails(int index);
int readInteger(char message[], int *value);
int main()
{
int choice;
while (1)
{
    showMenu();

    if (!readInteger("Enter your choice: ", &choice))
    {
        printf("\nInvalid input! Enter a number.\n");
        continue;
    }
    if (choice == 1)
    {
        addBook();
    }
    else if (choice == 2)
    {
        displayBooks();
    }
    else if (choice == 3)
    {
        searchBook();
    }
    else if (choice == 4)
    {
        issueBook();
    }
    else if (choice == 5)
    {
        returnBook();
    }
    else if (choice == 6)
    {
        printf("\nThank you for using our library!\n");
        break;
    }
    else
    {
        printf("\nInvalid choice! Select 1 to 6.\n");
    }
}
return 0;
}

/* Display Menu */
void showMenu()
{
printf("\n");
printf("====================================\n");
printf("      LIBRARY MANAGEMENT SYSTEM\n");
printf("====================================\n");
printf("       1. Add New Book\n");
printf("       2. Display All Books\n");
printf("       3. Search Book\n");
printf("       4. Issue Book\n");
printf("       5. Return Book\n");
printf("       6. Exit\n");
printf("====================================\n");
}
/* Clear Input Buffer */
void clearInputBuffer()
{
int ch;
while ((ch = getchar()) != '\n' && ch != EOF)
{
}
}
/* Read Full Book Name with Spaces */
void readLine(char str[], int size)
{
int i = 0;
int ch;
while ((ch = getchar()) != '\n' && ch != EOF)
{
    if (i < size - 1)
    {
        str[i] = ch;
        i++;
    }
}
str[i] = '\0';
}
/* Read Integer */
int readInteger(char message[], int *value)
{
printf("%s", message);
if (scanf("%d", value) != 1)
{
    clearInputBuffer();
    return 0;
}
clearInputBuffer();
return 1;
}
/* Find Book by ID */
int findBookByID(int id)
{
int i;
for (i = 0; i < totalBooks; i++)
{
    if (books[i].id == id)
    {
        return i;
    }
}
return -1;
}
/* Find Book by Name */
int findBookByName(char name[])
{
int i, j;
int same;
for (i = 0; i < totalBooks; i++)
{
    j = 0;
    same = 1;

    while (books[i].name[j] != '\0' ||
           name[j] != '\0')
    {
        if (books[i].name[j] != name[j])
        {
            same = 0;
            break;
        }
        j++;
    }
    if (same == 1)
    {
        return i;
    }
}
return -1;
}
/* Display Book Details */
void showBookDetails(int index)
{
printf("------------------------------------\n");
printf("Book ID   : %d\n", books[index].id);
printf("Book Name : %s\n", books[index].name);
if (books[index].available == 1)
{
    printf("Status    : Available\n");
}

else
{
    printf("Status    : Issued\n");
}
printf("------------------------------------\n");
}
/* Add New Book */
void addBook()
{
int id;
printf("\n========== ADD NEW BOOK ==========\n");
if (totalBooks >= 100)
{
    printf("Library is full!\n");
    return;
}
if (!readInteger("Enter Book ID: ", &id))
{
    printf("Invalid Book ID!\n");
    return;
}
if (findBookByID(id) != -1)
{
    printf("This Book ID already exists!\n");
    return;
}
books[totalBooks].id = id;

printf("Enter Book Name: ");
readLine(books[totalBooks].name, 100);
if (books[totalBooks].name[0] == '\0')
{
    printf("Book name cannot be empty!\n");
    return;
}
books[totalBooks].available = 1;
totalBooks++;
printf("\nBook added successfully!\n");
}
/* Display All Books */
void displayBooks()
{
int i;
printf("\n========== ALL BOOKS ==========\n");
if (totalBooks == 0)
{
    printf("No books available!\n");
    return;
}
for (i = 0; i < totalBooks; i++)
{
    showBookDetails(i);
}
printf("Total Books: %d\n", totalBooks);
}
/* Search by ID or Name */
void searchBook()
{
int choice;
int id;
int index;
char name[100];
printf("\n========== SEARCH BOOK ==========\n");
printf("1. Search by Book ID\n");
printf("2. Search by Book Name\n");
if (!readInteger("Choose option: ", &choice))
{
    printf("Invalid input!\n");
    return;
}
if (choice == 1)
{
    if (!readInteger("Enter Book ID: ", &id))
    {
        printf("Invalid Book ID!\n");
        return;
    }
    index = findBookByID(id);
}
else if (choice == 2)
{
    printf("Enter Complete Book Name: ");
    readLine(name, 100);

    index = findBookByName(name);
}
else
{
    printf("Invalid option!\n");
    return;
}
if (index != -1)
{
    printf("\nBook Found Successfully!\n");
    showBookDetails(index);
}
else
{
    printf("\nBook Not Found!\n");
}
}
/* Issue Book */
void issueBook()
{
int choice;
int id;
int index;
char name[100];
printf("\n========== ISSUE BOOK ==========\n");
printf("1. Search by Book ID\n");
printf("2. Search by Book Name\n");
if (!readInteger("Choose option: ", &choice))
{
    printf("Invalid input!\n");
    return;
}
if (choice == 1)
{
    if (!readInteger("Enter Book ID: ", &id))
    {
        printf("Invalid Book ID!\n");
        return;
    }
    index = findBookByID(id);
}
else if (choice == 2)
{
    printf("Enter Complete Book Name: ");
    readLine(name, 100);

    index = findBookByName(name);
}
else
{
    printf("Invalid option!\n");
    return;
}
if (index == -1)
{
    printf("Book Not Found!\n");
    return;
}
if (books[index].available == 1)
{
    books[index].available = 0;
    printf("Book Issued Successfully!\n");
    printf("Book Name: %s\n", books[index].name);
}
else
{
    printf("This Book Is Already Issued!\n");
}
}
/* Return Book */
void returnBook()
{
int choice;
int id;
int index;
char name[100];
printf("\n========== RETURN BOOK ==========\n");
printf("1. Search by Book ID\n");
printf("2. Search by Book Name\n");
if (!readInteger("Choose option: ", &choice))
{
    printf("Invalid input!\n");
    return;
}
if (choice == 1)
{
    if (!readInteger("Enter Book ID: ", &id))
    {
        printf("Invalid Book ID!\n");
        return;
    }
    index = findBookByID(id);
}
else if (choice == 2)
{
    printf("Enter Complete Book Name: ");
    readLine(name, 100);
    index = findBookByName(name);
}
else
{
    printf("Invalid option!\n");
    return;
}
if (index == -1)
{
    printf("Book Not Found!\n");
    return;
}
if (books[index].available == 0)
{
    books[index].available = 1;
    printf("Book Returned Successfully!\n");
    printf("Book Name: %s\n", books[index].name);
}
else
{
    printf("This Book Was Not Issued!\n");
}
}
