#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct Product - Represents a product in the store
 * @id: Product ID
 * @name: Product name
 * @price: Product price
 */
typedef struct
{
    int id;
    char name[50];
    float price;
} Product;

/**
 * compareIgnoreCase - Compares two strings ignoring case
 * @s1: First string
 * @s2: Second string
 *
 * Return: 1 if strings are equal (case-insensitive), 0 otherwise
 */
int compareIgnoreCase(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        if (tolower((unsigned char)*s1) != tolower((unsigned char)*s2))
            return 0; /* Not equal */
        s1++;
        s2++;
    }

    return *s1 == *s2; /* Only equal if both strings end */
}

/**
 * productStore - Populates an array of products with sample data
 * @products: Array of Product structures
 * @size: Size of the array
 */
void productStore(Product products[], int size)
{
    /* Sample product names */
    const char *names[] = {
        "iPhone 17 Pro",
        "Heat Sink",
        "Wireless Charger",
        "HP Business Monitor",
        "Intel Graphics Card"
    };

    /* Sample product prices */
    float prices[] = {
        999.98,
        50.34,
        99.99,
        199.34,
        500.34
    };

    int totalProducts = sizeof(names) / sizeof(names[0]);

    /* Display sample product list */
    printf("\n------Product Names------\n\n");
    for (int i = 0; i < totalProducts; i++)
    {
        printf("%s\n", names[i]);
    }

    /* Ensure provided array is large enough */
    if (size < totalProducts)
    {
        printf("Provided array too small. Expected at least %d.\n", totalProducts);
        return;
    }

    /* Populate product array with IDs, names, and prices */
    for (int i = 0; i < totalProducts; i++)
    {
        products[i].id = 101 + i;
        strcpy(products[i].name, names[i]);
        products[i].price = prices[i];
    }
}

/**
 * searchProductbyName - Searches for a product by name (case-insensitive)
 * @products: Array of Product structures
 * @size: Number of products in the array
 * @searchName: Name to search for
 */
void searchProductbyName(Product products[], int size, const char *searchName)
{
    int found = 0;

    for (int i = 0; i < size; i++)
    {
        if (compareIgnoreCase(products[i].name, searchName))
        {
            printf("\nProduct Found:\n");
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Price: %.2f\n", products[i].price);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nProduct not found: %s\n", searchName);
}

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
    int size = 5;
    Product products[size];

    /* Populate product list */
    productStore(products, size);

    /* Get product name to search */
    printf("\nEnter product name to search: ");
    char searchName[50];
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; /* Remove newline */

    /* Search for the product */
    searchProductbyName(products, size, searchName);

    return 0;
}
