#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* for malloc */

/**
 * struct Student - Represents a student record
 * @id: Student ID
 * @age: Student age
 * @gpa: Student GPA
 * @name: Student full name
 */
typedef struct
{
    int id;
    int age;
    float gpa;
    char name[50];
} Student;

/**
 * studentInput - Gets input from user for all students
 * @arr: Array of Student structures
 * @size: Number of students
 */
void studentInput(Student *arr, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("Enter Student %d ID:\n", i + 1);
        scanf("%d", &arr[i].id);

        /* Age validation */
        do {
            printf("Enter Student %d Age (1-120):\n", i + 1);
            scanf("%d", &arr[i].age);
            if (arr[i].age < 1 || arr[i].age > 120)
                printf("Invalid age! Try again.\n");
        } while (arr[i].age < 1 || arr[i].age > 120);

        printf("Enter Student %d GPA:\n", i + 1);
        scanf("%f", &arr[i].gpa);

        getchar(); /* consume leftover newline */

        printf("Enter Student %d full name:\n", i + 1);
        fgets(arr[i].name, sizeof(arr[i].name), stdin);

        /* Remove newline from fgets */
        arr[i].name[strcspn(arr[i].name, "\n")] = '\0';
    }
}

/**
 * displayStudents - Prints all student information
 * @arr: Array of Student structures
 * @size: Number of students
 */
void displayStudents(Student *arr, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("Student %d: ID=%d, Age=%d, GPA=%.3f, Name=%s\n",
               i + 1, arr[i].id, arr[i].age, arr[i].gpa, arr[i].name);
    }
}

/**
 * accessStudent - Prints information of a single student by index
 * @arr: Array of Student structures
 * @index: Index of the student to access
 * @size: Total number of students
 */
void accessStudent(Student *arr, int index, int size)
{
    Student *ptr;

    if (index < 0 || index >= size)
    {
        printf("Invalid student index!\n");
        return;
    }

    ptr = &arr[index]; /* pointer to the selected student */

    printf("Accessing Student %d:\n", index + 1);
    printf("ID: %d\n", ptr->id);
    printf("Age: %d\n", ptr->age);
    printf("GPA: %.2f\n", ptr->gpa);
    printf("Name: %s\n", ptr->name);
}

/**
 * sortStudentsByAge - Sorts students in ascending order by age
 * @student: Array of Student structures
 * @size: Number of students
 */
void sortStudentsByAge(Student *student, int size)
{
    int i, j;
    Student temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (student[j].age > student[j + 1].age)
            {
                /* Swap the students */
                temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by age successfully!\n");
}

/**
 * saveToFile - Saves all student data to a file
 * @student: Array of Student structures
 * @size: Number of students
 */
void saveToFile(Student *student, int size)
{
    FILE *file;
    int i;

    file = fopen("students.txt", "w");
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    for (i = 0; i < size; i++)
    {
        fprintf(file, "%d %d %.3f %s\n",
                student[i].id,
                student[i].age,
                student[i].gpa,
                student[i].name);
    }

    fclose(file);
    printf("\n All students saved successfully to students.txt!\n");
}

/**
 * main - Entry point of the program
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    int size, idx, choice;
    Student *student;

    printf("Enter number of students:\n");
    scanf("%d", &size);

    student = malloc(size * sizeof(Student));
    if (student == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    studentInput(student, size);

    printf("\nDo you want to sort students by age?\n1 = Yes, 0 = No: ");
    scanf("%d", &choice);

    if (choice == 1)
        sortStudentsByAge(student, size);

    displayStudents(student, size);

    printf("\nEnter which student to view (1 - %d): ", size);
    scanf("%d", &idx);

    accessStudent(student, idx - 1, size);

    saveToFile(student, size);

    free(student);

    return 0;
}
