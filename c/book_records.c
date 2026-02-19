#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct Book - Represents a book record
 * @title: Title of the book
 * @author: Author of the book
 * @price: Price of the book
 * @year: Year of publication
 */
typedef struct
{
    char title[100];
    char author[50];
    float price;
    int year;
} Book;

/**
 * bookEntries - Accepts details for multiple books from the user
 * @arr: Array of Book structures
 * @size: Number of books
 */
void bookEntries(Book arr[], int size)
{
    int i;

    getchar(); /* Clear newline character from input buffer */

    for (i = 0; i < size; i++)
    {
        printf("Enter details for book %d\n", i + 1);

        /* Input book title */
        printf("Title: ");
        fgets(arr[i].title, sizeof(arr[i].title), stdin);
        arr[i].title[strcspn(arr[i].title, "\n")] = '\0'; /* Remove newline */

        /* Input author name */
        printf("Author: ");
        fgets(arr[i].author, sizeof(arr[i].author), stdin);
        arr[i].author[strcspn(arr[i].author, "\n")] = '\0'; /* Remove newline */

        /* Input book price */
        printf("Price: ");
        scanf("%f", &arr[i].price);

        /* Input year of publication */
        printf("Year of Publication: ");
        scanf("%d", &arr[i].year);
        getchar(); /* Clear newline character from input buffer */

        printf("\n");
    }
}

/**
 * saveBookToFile - Saves each book into a separate text file
 * @arr: Array of Book structures
 * @size: Number of books
 *
 * Return: 0 on success
 */
int saveBookToFile(Book arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        char filename[150];
        int n;

        /* Create filename using title and year */
        n = snprintf(filename, sizeof(filename), "%s_%d.txt", arr[i].title, arr[i].year);
        if (n < 0)
        {
            printf("Error formatting filename for book %d\n", i + 1);
            continue;
        }
        else if (n >= sizeof(filename))
        {
            printf("Filename too long for book %d, truncating\n", i + 1);
        }

        /* Open file for writing */
        FILE *file = fopen(filename, "w");
        if (!file)
        {
            perror(filename);
            continue;
        }

        /* Write book details to file */
        fprintf(file, "Title: %s\nAuthor: %s\nPrice: %.2f\nYear of Publication: %d\n",
                arr[i].title, arr[i].author, arr[i].price, arr[i].year);
        fclose(file);

        printf("Book details saved to %s\n", filename);
    }

    return 0;
}

/**
 * main - Entry point of the program
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    int size;
    Book *books;
    char ch;

    /* Input number of books */
    printf("Enter the number of books: ");
    scanf("%d", &size);

    /* Allocate memory for books */
    books = malloc(size * sizeof(Book));
    if (!books)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    /* Accept book details from user */
    bookEntries(books, size);

    /* Ask user if they want to save books */
    printf("Do you want to save books? (Y/N): ");
    scanf(" %c", &ch);
    if (ch == 'Y' || ch == 'y')
    {
        saveBookToFile(books, size);
    }

    free(books); /* Free allocated memory */

    printf("Program ended successfully!\n");

    return 0;
}
