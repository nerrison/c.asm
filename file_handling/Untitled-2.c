#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct Employee - Represents an employee record
 * @id: Employee ID
 * @hoursWorked: Number of hours worked
 * @hourlyRate: Hourly wage
 * @name: Employee full name
 */
typedef struct
{
    int id;
    int hoursWorked;
    float hourlyRate;
    char name[50];
} Employee;

/**
 * employeeInput - Accepts input for multiple employees
 * @emp: Array of Employee structures
 * @size: Number of employees
 */
void employeeInput(Employee emp[], int size)
{
    int i;

    printf("\n-----Accepts details for %d employees-----\n\n", size);

    for (i = 0; i < size; i++)
    {
        printf("Enter details for Employee %d:\n", i + 1);

        /* Input Employee ID */
        printf("→ Enter Employee ID: ");
        scanf("%d", &emp[i].id);

        getchar(); /* Consume newline character after scanf */

        /* Input Employee Name */
        printf("→ Enter employee name: ");
        fgets(emp[i].name, sizeof(emp[i].name), stdin);

        /* Remove newline character from name if present */
        emp[i].name[strcspn(emp[i].name, "\n")] = '\0';

        /* Input hours worked */
        printf("→ Enter hours worked: ");
        scanf("%d", &emp[i].hoursWorked);

        /* Input hourly rate */
        printf("→ Enter hourly rate: ");
        scanf("%f", &emp[i].hourlyRate);

        printf("\n");
    }
}

/**
 * computeTotalSalary - Calculates total salary for each employee
 * @emp: Array of Employee structures
 * @size: Number of employees
 * @total: Array to store total salary
 */
void computeTotalSalary(Employee emp[], int size, float total[])
{
    int i;

    printf("-----Salary Summary-----\n\n");

    for (i = 0; i < size; i++)
    {
        total[i] = emp[i].hoursWorked * emp[i].hourlyRate;
        printf("→ Total Salary of employee %d (%s) is: %.2f\n\n",
               emp[i].id, emp[i].name, total[i]);
    }
}

/**
 * saveAllEmployeeData - Saves employee details and salary to a file
 * @emp: Array of Employee structures
 * @size: Number of employees
 * @total: Array of total salaries
 */
void saveAllEmployeeData(Employee emp[], int size, float total[])
{
    FILE *file;
    int i;

    file = fopen("employee_data.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (i = 0; i < size; i++)
    {
        fprintf(file, "Employee ID: %d\n", emp[i].id);
        fprintf(file, "Name: %s\n", emp[i].name);
        fprintf(file, "Hours Worked: %d\n", emp[i].hoursWorked);
        fprintf(file, "Hourly Rate: %.2f\n", emp[i].hourlyRate);
        fprintf(file, "Total Salary: %.2f\n\n", total[i]);
    }

    fclose(file);
    printf("Employee data saved to employee_data.txt\n");
}

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
    int size = 3;
    float total[size];
    Employee emp[size];

    employeeInput(emp, size);
    computeTotalSalary(emp, size, total);
    saveAllEmployeeData(emp, size, total);

    return 0;
}
