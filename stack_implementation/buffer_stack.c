#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 8 /* Maximum number of elements in the stack */

/**
 * struct Stack - Represents a simple fixed-size stack
 * @data: Array storing stack elements
 * @top: Index of the next free slot (number of elements in stack)
 */
typedef struct
{
    int data[STACK_MAX];
    int top;
} Stack;

/* ---------- Core stack functions ---------- */

/**
 * stack_init - Initializes the stack
 * @s: Pointer to Stack structure
 *
 * Return: 0 on success
 */
int stack_init(Stack *s)
{
    s->top = 0; /* Stack is empty initially */
    return 0;
}

/**
 * stack_is_empty - Checks if the stack is empty
 * @s: Pointer to Stack structure
 *
 * Return: 1 if empty, 0 otherwise
 */
int stack_is_empty(Stack *s)
{
    return s->top == 0;
}

/**
 * stack_is_full - Checks if the stack is full
 * @s: Pointer to Stack structure
 *
 * Return: 1 if full, 0 otherwise
 */
int stack_is_full(Stack *s)
{
    return s->top == STACK_MAX;
}

/**
 * stack_push - Pushes a value onto the stack
 * @s: Pointer to Stack structure
 * @value: Value to push
 *
 * Return: 0 on success, -1 if stack is full
 */
int stack_push(Stack *s, int value)
{
    if (stack_is_full(s))
        return -1; /* Cannot push, stack full */

    s->data[s->top] = value; /* Store value at top */
    s->top++; /* Increment top index */

    return 0;
}

/**
 * stack_pop - Pops a value from the stack
 * @s: Pointer to Stack structure
 * @out: Pointer to store popped value
 *
 * Return: 0 on success, -1 if stack is empty
 */
int stack_pop(Stack *s, int *out)
{
    if (stack_is_empty(s))
        return -1; /* Cannot pop, stack empty */

    s->top--; /* Decrement top index */
    *out = s->data[s->top]; /* Retrieve value */

    return 0;
}

/**
 * stack_peek - Gets the top value without removing it
 * @s: Pointer to Stack structure
 * @out: Pointer to store top value
 *
 * Return: 0 on success, -1 if stack is empty
 */
int stack_peek(Stack *s, int *out)
{
    if (stack_is_empty(s))
        return -1; /* Cannot peek, stack empty */

    *out = s->data[s->top - 1]; /* Get top value */
    return 0;
}

/**
 * stack_print - Displays all elements in the stack
 * @s: Pointer to Stack structure
 */
void stack_print(Stack *s)
{
    if (stack_is_empty(s))
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (top -> bottom): ");
    for (int i = s->top - 1; i >= 0; i--)
        printf("%d ", s->data[i]);
    printf("\n");
}

/* ---------- Main Program ---------- */

/**
 * main - Interactive program to demonstrate stack operations
 *
 * Return: 0 on success
 */
int main(void)
{
    Stack s;       /* Stack instance */
    int choice;    /* User menu choice */
    int value;     /* Value to push/pop/peek */

    /* Initialize the stack */
    stack_init(&s);

    while (1)
    {
        /* Display menu */
        printf("\n====== Stack Menu ======\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: /* Push */
                printf("Enter value to push: ");
                scanf("%d", &value);
                if (stack_push(&s, value) != 0)
                    printf("Stack is full. Cannot push.\n");
                else
                    printf("Value %d pushed successfully.\n", value);
                break;

            case 2: /* Pop */
                if (stack_pop(&s, &value) != 0)
                    printf("Stack is empty. Cannot pop.\n");
                else
                    printf("Popped value: %d\n", value);
                break;

            case 3: /* Peek */
                if (stack_peek(&s, &value) != 0)
                    printf("Stack is empty. Nothing to peek.\n");
                else
                    printf("Top value: %d\n", value);
                break;

            case 4: /* Print Stack */
                stack_print(&s);
                break;

            case 5: /* Exit */
                printf("Exiting program. Goodbye!\n");
                return 0;

            default: /* Invalid input */
                printf("Invalid choice. Please enter 1-5.\n");
        }
    }

    return 0;
}
