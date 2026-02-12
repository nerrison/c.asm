#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 /* Maximum size of the circular buffer */

/**
 * struct Ringbuf - Represents a circular buffer
 * @buf: Pointer to dynamically allocated integer buffer
 * @front: Index of the front element
 * @rear: Index of the next insertion point
 * @size: Maximum number of elements buffer can hold
 * @count: Current number of elements in the buffer
 */
typedef struct
{
    int *buf;
    size_t front;
    size_t rear;
    size_t size;
    size_t count;
} Ringbuf;

/* ---------- Core functions ---------- */

/**
 * ring_init - Initializes the circular buffer
 * @rb: Pointer to Ringbuf structure
 *
 * Return: 0 on success, -1 on memory allocation failure
 */
int ring_init(Ringbuf *rb)
{
    rb->buf = malloc(MAX_SIZE * sizeof(int));
    if (!rb->buf)
        return -1;

    rb->front = 0;
    rb->rear  = 0;
    rb->count = 0;
    rb->size  = MAX_SIZE;

    return 0;
}

/**
 * is_empty - Checks if the buffer is empty
 * @rb: Pointer to Ringbuf structure
 *
 * Return: 1 if empty, 0 otherwise
 */
int is_empty(Ringbuf *rb)
{
    return rb->count == 0;
}

/**
 * is_full - Checks if the buffer is full
 * @rb: Pointer to Ringbuf structure
 *
 * Return: 1 if full, 0 otherwise
 */
int is_full(Ringbuf *rb)
{
    return rb->count == rb->size;
}

/**
 * enqueue - Adds an element to the buffer
 * @rb: Pointer to Ringbuf structure
 * @value: Value to enqueue
 *
 * Return: 0 on success, -1 if buffer is full
 */
int enqueue(Ringbuf *rb, int value)
{
    if (is_full(rb))
        return -1;

    rb->buf[rb->rear] = value;
    rb->rear = (rb->rear + 1) % rb->size;
    rb->count++;

    return 0;
}

/**
 * dequeue - Removes an element from the buffer
 * @rb: Pointer to Ringbuf structure
 * @out: Pointer to store dequeued value
 *
 * Return: 0 on success, -1 if buffer is empty
 */
int dequeue(Ringbuf *rb, int *out)
{
    if (is_empty(rb))
        return -1;

    *out = rb->buf[rb->front];
    rb->front = (rb->front + 1) % rb->size;
    rb->count--;

    return 0;
}

/**
 * peek - Gets the front element without removing it
 * @rb: Pointer to Ringbuf structure
 * @out: Pointer to store front value
 *
 * Return: 0 on success, -1 if buffer is empty
 */
int peek(Ringbuf *rb, int *out)
{
    if (is_empty(rb))
        return -1;

    *out = rb->buf[rb->front];
    return 0;
}

/**
 * print_buffer - Displays the contents of the buffer
 * @rb: Pointer to Ringbuf structure
 */
void print_buffer(Ringbuf *rb)
{
    if (is_empty(rb))
    {
        printf("Buffer is empty\n");
        return;
    }

    printf("Buffer: ");
    size_t idx = rb->front;

    for (size_t i = 0; i < rb->count; i++)
    {
        printf("%d ", rb->buf[idx]);
        idx = (idx + 1) % rb->size;
    }

    printf("\n");
}

/* ---------- Main Program ---------- */

/**
 * main - Entry point for the ring buffer program
 *
 * Return: 0 on success, 1 on initialization failure
 */
int main(void)
{
    Ringbuf rb;
    int value;
    int choice;

    /* Initialize buffer */
    if (ring_init(&rb) != 0)
    {
        printf("Failed to initialize buffer\n");
        return 1;
    }

    /* Menu options */
    char *menu[] = {
        "Enqueue",
        "Dequeue",
        "Peek",
        "Print Queue",
        "Exit"
    };

    int menuSize = sizeof(menu) / sizeof(menu[0]);

    while (1)
    {
        /* Display menu */
        printf("\n====== Ring / Circular Buffer ======\n");
        for (int i = 0; i < menuSize; i++)
            printf("%d. %s\n", i + 1, menu[i]);

        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: /* Enqueue */
                printf("Enter value: ");
                scanf("%d", &value);
                if (enqueue(&rb, value) != 0)
                    printf("Buffer is full\n");
                break;

            case 2: /* Dequeue */
                if (dequeue(&rb, &value) != 0)
                    printf("Buffer is empty\n");
                else
                    printf("Dequeued: %d\n", value);
                break;

            case 3: /* Peek */
                if (peek(&rb, &value) != 0)
                    printf("Buffer is empty\n");
                else
                    printf("Front: %d\n", value);
                break;

            case 4: /* Print Queue */
                print_buffer(&rb);
                break;

            case 5: /* Exit */
                free(rb.buf);
                rb.buf = NULL;
                return 0;

            default: /* Invalid input */
                printf("Invalid option\n");
        }
    }
}
