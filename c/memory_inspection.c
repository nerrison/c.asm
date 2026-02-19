#include <stdio.h>
#include <stdlib.h>

/**
 * memory_inspection.c
 *
 * Purpose:
 *   Demonstrates stack and heap memory allocation in C,
 *   pointer behavior, and function scope.
 *
 *   This code is formatted in **Betty style** for readability
 *   and professional C coding conventions.
 *
 * Learning Objectives:
 *   - Stack memory allocation (variables and arrays)
 *   - Heap memory allocation using malloc/free
 *   - Pointer behavior (pointing to stack and heap variables)
 *   - Function-local (scope) stack variables
 *
 * Compilation:
 *   gcc -Wall -Wextra -std=c11 memory_inspection.c -o memory_inspection
 *
 * Running:
 *   ./memory_inspection
 *
 * Notes:
 *   - Heap memory must be freed after use to prevent leaks
 *   - Pointer reassignment demonstrates stack vs heap referencing
 *   - Leading zeros in addresses are formatting in 64-bit systems
 *   - Stack grows downward, heap grows upward (usually)
 */

/**
 * funcScopeTest - Demonstrates stack memory allocation in a function
 * @x: function parameter (unused, just for demo)
 */
void funcScopeTest(int x)
{
	int localVar;

	printf("\n[funcScopeTest] Address of localVar: %p\n", (void *)&localVar);
}

/**
 * main - Demonstrates stack vs heap memory, pointers, and function scope
 *
 * Return: 0 on success
 */
int main(void)
{
	/* ===== STACK MEMORY ===== */
	int a = 1;
	char b = 'H';
	int arr[5] = {1, 2, 3, 4, 5};

	printf("=== STACK MEMORY ===\n");
	printf("Value of a: %d\n", a);
	printf("Value of b: %c\n", b);

	printf("\nValues in arr:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("\nAddresses:\n");
	printf("Address of a: %p\n", (void *)&a);
	printf("Address of b: %p\n", (void *)&b);
	printf("Addresses of arr elements:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("arr[%d]: %p\n", i, (void *)&arr[i]);
	}

	printf("\nSizes:\n");
	printf("Size of int a: %zu bytes\n", sizeof(a));
	printf("Size of char b: %zu bytes\n", sizeof(b));
	printf("Size of arr: %zu bytes\n", sizeof(arr));

	/* ===== HEAP MEMORY ===== */
	int *x = malloc(sizeof(int));
	if (!x)
		return (1);

	*x = 42;
	a = *x;

	printf("\n=== HEAP MEMORY ===\n");
	printf("Value of a after heap allocation: %d\n", a);
	printf("Heap allocated x address: %p\n", (void *)x);
	printf("Value at heap allocated x: %d\n", *x);

	free(x);
	x = NULL; /* prevent dangling pointer */

	int *heapArr = malloc(5 * sizeof(int));
	if (!heapArr)
		return (1);

	for (int i = 0; i < 5; i++)
		heapArr[i] = i * 10;

	printf("\nHeap array values:\n");
	for (int i = 0; i < 5; i++)
		printf("%d ", heapArr[i]);
	printf("\nHeap array addresses:\n");
	for (int i = 0; i < 5; i++)
		printf("heapArr[%d]: %p\n", i, (void *)&heapArr[i]);
	printf("Total heap memory allocated: %zu bytes\n", 5 * sizeof(int));

	free(heapArr);
	heapArr = NULL; /* prevent dangling pointer */

	/* ===== POINTER BEHAVIOR ===== */
	int *p;

	/* Pointer to stack variable */
	p = &a;
	printf("\nPointer p points to stack address: %p with value: %d\n",
	       (void *)p, *p);

	/* Pointer to heap variable */
	x = malloc(sizeof(int));
	if (!x)
		return (1);

	*x = 100;
	p = x;
	printf("Pointer p now points to heap address: %p with value: %d\n",
	       (void *)p, *p);

	free(x);
	x = NULL; /* prevent dangling pointer */

	/* ===== FUNCTION SCOPE VARIABLE ===== */
	funcScopeTest(10);

	return (0);
}
