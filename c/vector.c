#include <stdio.h>
#include <stdlib.h>

/**
 * vector.c
 *
 * Demonstrates:
 *  - Dynamic array (vector) implementation in C
 *  - Automatic resizing (doubling capacity)
 *  - Optional shrinking (halving capacity)
 *  - Safe memory management
 *  - Accessing, retrieving, and removing elements
 */

/**
 * struct Vector - Dynamic integer vector
 * @size: Number of elements in the vector
 * @capacity: Allocated memory slots
 * @data: Pointer to integer array
 */
typedef struct
{
    size_t size;
    size_t capacity;
    int *data;
} Vector;

/**
 * vector_init - Initialize a vector with given capacity
 * @v: Pointer to the vector
 * @initial_capacity: Initial capacity to allocate
 *
 * Return: 0 on success, -1 on memory allocation failure
 */
int vector_init(Vector *v, size_t initial_capacity)
{
    v->size = 0;
    v->capacity = initial_capacity;
    v->data = (int *)malloc(initial_capacity * sizeof(int));
    if (!v->data)
        return -1;

    return 0;
}

/**
 * vector_resize - Resize vector to a new capacity
 * @v: Pointer to the vector
 * @new_capacity: New capacity to allocate
 *
 * Return: 0 on success, -1 if allocation fails
 */
int vector_resize(Vector *v, size_t new_capacity)
{
    int *new_data = (int *)malloc(new_capacity * sizeof(int));
    if (!new_data)
        return -1;

    for (size_t i = 0; i < v->size; i++)
        new_data[i] = v->data[i];

    free(v->data);
    v->data = new_data;
    v->capacity = new_capacity;

    return 0;
}

/**
 * vector_push - Add a value to the end of the vector
 * @v: Pointer to the vector
 * @value: Value to push
 *
 * Return: 0 on success, -1 if memory allocation fails
 */
int vector_push(Vector *v, int value)
{
    if (v->size == v->capacity)
    {
        if (vector_resize(v, v->capacity * 2) != 0)
            return -1;
    }

    v->data[v->size] = value;
    v->size++;
    return 0;
}

/**
 * vector_pop - Remove and return the last element
 * @v: Pointer to the vector
 * @out_value: Pointer to store popped value
 *
 * Return: 0 on success, -1 if vector is empty
 */
int vector_pop(Vector *v, int *out_value)
{
    if (v->size == 0)
        return -1;

    v->size--;
    *out_value = v->data[v->size];

    /* shrinking: reduce capacity if too empty */
    if (v->size > 0 && v->size <= v->capacity / 4)
        vector_resize(v, v->capacity / 2);

    return 0;
}

/**
 * vector_get - Retrieve value at a specific index
 * @v: Pointer to the vector
 * @index: Index of element to retrieve
 * @out_value: Pointer to store retrieved value
 *
 * Return: 0 on success, -1 if index is out of bounds
 */
int vector_get(Vector *v, size_t index, int *out_value)
{
    if (index >= v->size)
        return -1;

    *out_value = v->data[index];
    return 0;
}

/**
 * vector_free - Free memory used by the vector
 * @v: Pointer to the vector
 */
void vector_free(Vector *v)
{
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

/**
 * main - Demonstrates vector usage
 *
 * Return: 0 on success
 */
int main(void)
{
    Vector v;

    if (vector_init(&v, 4) != 0)
    {
        fprintf(stderr, "Failed to initialize vector\n");
        return 1;
    }

    /* Push 10 values into the vector */
    for (int i = 0; i < 10; i++)
    {
        if (vector_push(&v, i) != 0)
        {
            fprintf(stderr, "Failed to push value %d\n", i);
            vector_free(&v);
            return 1;
        }
    }

    /* Pop 3 values from the vector */
    for (int i = 0; i < 3; i++)
    {
        int val;
        if (vector_pop(&v, &val) == 0)
            printf("Popped value: %d\n", val);
    }

    /* Retrieve and print remaining values */
    printf("Remaining vector elements:\n");
    for (size_t i = 0; i < v.size; i++)
    {
        int value;
        if (vector_get(&v, i, &value) == 0)
            printf("v[%zu] = %d\n", i, value);
    }

    vector_free(&v);
    return 0;
}
