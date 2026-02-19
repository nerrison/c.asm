#include <stdio.h>

#define SIZE 5

/**
 * struct Item - Represents a single item in a bucket.
 * @data: Stores the actual value.
 */
typedef struct
{
    unsigned char data;
} Item;

/**
 * struct Bucket - Represents a bucket in the hash table.
 * @items: Array of fixed-size items.
 */
typedef struct
{
    Item items[SIZE];
} Bucket;

/**
 * struct Table - Represents the hash table.
 * @bucket: Array of fixed-size buckets.
 */
typedef struct
{
    Bucket bucket[SIZE];
} Table;

/**
 * init_bucket - Initializes a bucket by setting all items to 0.
 * @b: Pointer to the bucket to initialize.
 */
void init_bucket(Bucket *b)
{
    for (int i = 0; i < SIZE; i++)
        b->items[i].data = 0;
}

/**
 * init_table - Initializes the entire hash table.
 * @t: Pointer to the table to initialize.
 */
void init_table(Table *t)
{
    for (int i = 0; i < SIZE; i++)
        init_bucket(&t->bucket[i]);
}

/**
 * insert_entry - Inserts a value into the hash table.
 * @t: Pointer to the table.
 * @data: Value to insert.
 *
 * Return: 0 on success, -1 if the target bucket is full.
 */
int insert_entry(Table *t, unsigned char data)
{
    int hashVal = data % SIZE;

    for (int i = 0; i < SIZE; i++)
    {
        if (t->bucket[hashVal].items[i].data == 0)
        {
            t->bucket[hashVal].items[i].data = data;
            return 0;
        }
    }

    return -1; /* bucket full */
}

/**
 * popItem - Removes a specific value from the hash table.
 * @t: Pointer to the table.
 * @data: Value to remove.
 *
 * Return: 0 on success, -1 if value not found.
 */
int popItem(Table *t, unsigned char data)
{
    int hashVal = data % SIZE;

    for (int i = 0; i < SIZE; i++)
    {
        if (t->bucket[hashVal].items[i].data == data)
        {
            t->bucket[hashVal].items[i].data = 0;
            return 0;
        }
    }

    return -1; /* value not found */
}

/**
 * pop_bucket - Clears all items in a given bucket.
 * @t: Pointer to the table.
 * @bucket_index: Index of the bucket to clear.
 *
 * Return: 0 on success, -1 if invalid bucket index.
 */
int pop_bucket(Table *t, int bucket_index)
{
    if (bucket_index < 0 || bucket_index >= SIZE)
        return -1;

    for (int i = 0; i < SIZE; i++)
        t->bucket[bucket_index].items[i].data = 0;

    return 0;
}

/**
 * lookup - Searches for a value in the hash table.
 * @t: Pointer to the table.
 * @data: Value to search.
 *
 * Return: The value if found, -1 if not found.
 */
int lookup(Table *t, unsigned char data)
{
    int hashVal = data % SIZE;

    for (int i = 0; i < SIZE; i++)
    {
        if (t->bucket[hashVal].items[i].data == data)
            return t->bucket[hashVal].items[i].data;
    }

    return -1;
}

/**
 * printTable - Prints the current state of the hash table.
 * @t: Table to print.
 */
void printTable(Table t)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Bucket %d: ", i);
        for (int j = 0; j < SIZE; j++)
        {
            if (t.bucket[i].items[j].data != 0)
                printf("%d ", t.bucket[i].items[j].data);
            else
                printf("- "); /* empty slot */
        }
        printf("\n");
    }
}

/**
 * main - Entry point for the hash table program.
 *
 * Return: Always 0.
 */
int main(void)
{
    Table t;
    init_table(&t);

    int choice;
    unsigned char data;
    int bucket_index;

    while (1)
    {
        printf("\n==== Menu ====\n");
        printf("1. Insert\n2. Lookup\n3. Pop Item\n4. Print Table\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%hhu", &data);
            if (insert_entry(&t, data) == 0)
                printf("Inserted %d successfully.\n", data);
            else
                printf("Insert failed: bucket full.\n");
            break;

        case 2:
            printf("Enter value to lookup: ");
            scanf("%hhu", &data);
            if (lookup(&t, data) != -1)
                printf("Found %d in the table.\n", data);
            else
                printf("%d not found.\n", data);
            break;

        case 3:
        {
            int subchoice;
            printf("Pop Menu:\n");
            printf("1. Pop single item\n2. Pop entire bucket\n3. Back\n");
            printf("Enter choice: ");
            scanf("%d", &subchoice);

            switch (subchoice)
            {
            case 1:
                printf("Enter value to pop: ");
                scanf("%hhu", &data);
                if (popItem(&t, data) == 0)
                    printf("Popped item %d successfully.\n", data);
                else
                    printf("Item %d not found.\n", data);
                break;

            case 2:
                printf("Enter bucket index to pop (0-%d): ", SIZE - 1);
                scanf("%d", &bucket_index);
                if (pop_bucket(&t, bucket_index) == 0)
                    printf("Bucket %d cleared successfully.\n", bucket_index);
                else
                    printf("Invalid bucket index.\n");
                break;

            case 3:
                break; /* back to main menu */

            default:
                printf("Invalid subchoice.\n");
                break;
            }
            break;
        }

        case 4:
            printTable(t);
            break;

        case 0:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}
