#include <stdio.h>

/**
 * struct Employee - Represents an employee record
 * @id: Employee ID
 * @salary: Employee salary
 */
typedef struct
{
    int id;
    float salary;
} Employee;

/**
 * main - Entry point of the program
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    int size = 5; /* Number of employees */
    Employee emp[size];

    /* Initialize employee data */
    emp[0].id = 101; emp[0].salary = 50000.50;
    emp[1].id = 102; emp[1].salary = 60000.75;
    emp[2].id = 103; emp[2].salary = 55000.00;
    emp[3].id = 104; emp[3].salary = 70000.25;
    emp[4].id = 105; emp[4].salary = 65000.80;

    /* Open binary file for writing */
    FILE *file = fopen("employees.bin", "wb"); /* Binary write mode */
    if (!file)
    {
        perror("fopen");
        return 1;
    }

    /* Write the entire employee array to the file */
    fwrite(emp, sizeof(Employee), size, file);

    /* Close the file after writing */
    fclose(file);

    /* Open binary file for reading and writing */
    file = fopen("employees.bin", "r+b"); /* Read and write in binary mode */
    if (!file)
    {
        perror("fopen");
        return 1;
    }

    /* Employee record to update */
    Employee updated_emp = {106, 72000.90};
    int index_to_update = 2; /* Update the 3rd employee (index 2) */
    long offset = index_to_update * sizeof(Employee);

    /* Move file pointer to the 3rd record */
    fseek(file, offset, SEEK_SET);

    /* Overwrite the record with updated data */
    fwrite(&updated_emp, sizeof(Employee), 1, file);

    /* Move file pointer back to the beginning for reading */
    rewind(file); /* Equivalent to fseek(file, 0, SEEK_SET); */

    /* Read and display all employee records */
    Employee check_emp;
    while (fread(&check_emp, sizeof(Employee), 1, file))
    {
        printf("Employee - ID: %d, Salary: %.2f\n", check_emp.id, check_emp.salary);
    }

    /* Close the file after operations */
    fclose(file);

    printf("Employee record updated successfully.\n");

    return 0;
}
