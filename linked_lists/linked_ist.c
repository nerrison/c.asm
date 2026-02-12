#include <stdio.h>
#include <stdlib.h>

/**
 * struct Node - singly linked list node
 * @data: integer stored in node
 * @next: pointer to the next node
 */
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

/**
 * insert_head - inserts a new node at the head of the list
 * @head: double pointer to the head of the list
 * @value: value to insert
 *
 * Return: 0 on success, -1 on memory allocation failure
 */
int insert_head(Node **head, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
        return -1;

    new_node->data = value;
    new_node->next = *head;
    *head = new_node;

    return 0;
}

/**
 * insert_tail - inserts a new node at the tail of the list
 * @head: double pointer to the head of the list
 * @value: value to insert
 *
 * Return: 0 on success, -1 on memory allocation failure
 */
int insert_tail(Node **head, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
        return -1;

    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return 0;
    }

    Node *current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = new_node;

    return 0;
}

/**
 * delete_value - deletes the first node with the given value
 * @head: double pointer to the head of the list
 * @value: value to delete
 *
 * Return: 0 on success, -1 if value not found
 */
int delete_value(Node **head, int value)
{
    if (*head == NULL)
        return -1;

    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL && current->data != value)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
        return -1;

    if (prev == NULL)
        *head = current->next;
    else
        prev->next = current->next;

    free(current);
    return 0;
}

/**
 * search_value - searches for a value in the list
 * @head: pointer to the head of the list
 * @value: value to search for
 *
 * Return: 1 if found, 0 if not found
 */
int search_value(Node *head, int value)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == value)
            return 1;
        current = current->next;
    }
    return 0;
}

/**
 * print_list - prints all values in the list
 * @head: pointer to the head of the list
 *
 * Return: 0
 */
int print_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    return 0;
}

/**
 * free_list - frees all nodes in the list
 * @head: double pointer to the head of the list
 *
 * Return: 0
 */
int free_list(Node **head)
{
    Node *current = *head;
    Node *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *head = NULL;
    return 0;
}

/**
 * main - demonstrates usage of linked list functions
 *
 * Return: 0 on success
 */
int main(void)
{
    Node *head = NULL;

    insert_head(&head, 10);
    insert_tail(&head, 20);
    insert_head(&head, 15);

    printf("Current List:\n");
    print_list(head);

    printf("Searching for 20: %s\n", search_value(head, 20) ? "Found" : "Not Found");
    printf("Searching for 15: %s\n", search_value(head, 15) ? "Found" : "Not Found");

    delete_value(&head, 10);
    printf("After deleting 10:\n");
    print_list(head);

    free_list(&head);

    return 0;
}
