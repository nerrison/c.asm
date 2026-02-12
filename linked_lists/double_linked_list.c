#include <stdio.h>
#include <stdlib.h>

/**
 * struct Node - Doubly linked list node
 * @data: integer data
 * @prev: pointer to previous node
 * @next: pointer to next node
 */
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

/**
 * clear_screen - Clears the terminal screen (cross-platform)
 */
void clear_screen(void)
{
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[H");
#endif
}

/**
 * insert_head - Inserts a new node at the head of the list
 * @head: double pointer to the head node
 * @value: integer value to insert
 *
 * Return: 0 on success, -1 on failure
 */
int insert_head(Node **head, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
        return (-1);

    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;

    return (0);
}

/**
 * insert_tail - Inserts a new node at the tail of the list
 * @head: double pointer to the head node
 * @value: integer value to insert
 *
 * Return: 0 on success, -1 on failure
 */
int insert_tail(Node **head, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    Node *tail;

    if (!new_node)
        return (-1);

    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) /* empty list */
    {
        new_node->prev = NULL;
        *head = new_node;
        return (0);
    }

    tail = *head;
    while (tail->next != NULL)
        tail = tail->next;

    tail->next = new_node;
    new_node->prev = tail;

    return (0);
}

/**
 * search_node - Searches for a node with a given value
 * @head: pointer to the head node
 * @value: integer value to search
 *
 * Return: 1 if found, 0 if not found
 */
int search_node(Node *head, int value)
{
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == value)
            return (1);
        curr = curr->next;
    }

    return (0);
}

/**
 * delete_node - Deletes the first node with a matching value
 * @head: double pointer to the head node
 * @value: integer value to delete
 *
 * Return: 0 on success, -1 if value not found
 */
int delete_node(Node **head, int value)
{
    Node *curr;

    if (*head == NULL)
        return (-1);

    curr = *head;
    while (curr != NULL && curr->data != value)
        curr = curr->next;

    if (!curr)
        return (-1);

    if (curr->prev)
        curr->prev->next = curr->next;
    else
        *head = curr->next;

    if (curr->next)
        curr->next->prev = curr->prev;

    free(curr);

    return (0);
}

/**
 * print_list - Prints all nodes in the list
 * @head: pointer to the head node
 */
void print_list(Node *head)
{
    Node *curr = head;

    printf("List: ");
    while (curr != NULL)
    {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

/**
 * free_list - Frees all nodes in the list
 * @head: double pointer to the head node
 */
void free_list(Node **head)
{
    Node *curr = *head;
    Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }

    *head = NULL;
}

/**
 * main - Interactive menu for doubly linked list operations
 *
 * Return: 0 on success
 */
int main(void)
{
    Node *head = NULL;
    int choice, value;

    while (1)
    {
        clear_screen();
        printf("=== Doubly Linked List Menu ===\n");
        printf("1. Insert Head\n");
        printf("2. Insert Tail\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Print List\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            if (insert_head(&head, value) == 0)
                printf("%d inserted at head.\n", value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            if (insert_tail(&head, value) == 0)
                printf("%d inserted at tail.\n", value);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search_node(head, value))
                printf("%d found in list.\n", value);
            else
                printf("%d not found.\n", value);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            if (delete_node(&head, value) == 0)
                printf("%d deleted.\n", value);
            else
                printf("%d not found.\n", value);
            break;
        case 5:
            print_list(head);
            break;
        case 6:
            free_list(&head);
            printf("Exiting...\n");
            return (0);
        default:
            printf("Invalid option.\n");
        }
        printf("Press Enter to continue...");
        getchar();
        getchar(); /* pause */
    }

    return (0);
}
