#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

/**
 * sensor_logger.c
 *
 * Demonstrates:
 *  - Heap memory allocation and dynamic resizing
 *  - Pointer-based array access
 *  - Structs for sensor data
 *  - Input validation and sentinel "END"
 *  - Computing sum, average, max, and min
 */

typedef struct SensorLog
{
    float sensor_value;
    char sensorname[50];
} SensorL;

/**
 * log_sensor_data - prints all sensor entries and statistics
 * @arr: pointer to array of SensorL
 * @size: number of entries in the array
 */
void log_sensor_data(SensorL *arr, int size)
{
    float sum = 0;
    float max = arr[0].sensor_value;
    float min = arr[0].sensor_value;
    float average;

    FILE *fp = fopen("sensor_log.txt", "w");
    if (!fp)
    {
        printf("error opeining file\n");
        return;
    };

    fprintf(fp,"\n=== Sensor Log ===\n");
    printf("\n=== Sensor Log ===\n");

    for (int i = 0; i < size; i++)
    {
        sum += arr[i].sensor_value;

        if (arr[i].sensor_value > max)
            max = arr[i].sensor_value;
        if (arr[i].sensor_value < min)
            min = arr[i].sensor_value;

        fprintf(fp,"Sensor Name: %s, Sensor Value: %.2f\n",
               arr[i].sensorname, arr[i].sensor_value);
        printf("Sensor Name: %s, Sensor Value: %.2f\n",
               arr[i].sensorname, arr[i].sensor_value);
    }

    average = sum / size;

    fprintf(fp,"\nSum of Sensor Values: %.2f\n", sum);
    printf("\nSum of Sensor Values: %.2f\n", sum);
    fprintf(fp,"Average Sensor Value: %.2f\n", average);
    printf("Average Sensor Value: %.2f\n", average);
    fprintf(fp,"Max Sensor Value: %.2f\n", max);
    printf("Max Sensor Value: %.2f\n", max);
    fprintf(fp,"Min Sensor Value: %.2f\n", min);
    printf("Min Sensor Value: %.2f\n", min);
    fclose(fp);
}

/**
 * main - dynamically logs sensor data entered by the user
 *
 * Return: 0 on success, 1 on memory allocation failure
 */
int main(void)
{
    SensorL log_entry;
    SensorL *arr = malloc(MAX_SIZE * sizeof(SensorL));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    int capacity = MAX_SIZE;
    int size = 0;

    while (1)
    {
        printf("Enter Sensor Name (or type 'END' to finish): ");
        scanf("%s", log_entry.sensorname);

        if (strcmp(log_entry.sensorname, "END") == 0)
            break;

        printf("Enter Sensor Value: ");
        if (scanf("%f", &log_entry.sensor_value) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); /* Clear input buffer */
            continue;
        }

        arr[size] = log_entry;
        size++;

        /* Dynamic resizing if capacity exceeded */
        if (size >= capacity)
        {
            capacity *= 2;
            SensorL *tmp = realloc(arr, capacity * sizeof(SensorL));
            if (tmp == NULL)
            {
                printf("Memory reallocation failed\n");
                free(arr);
                return 1;
            }
            arr = tmp;
        }
    }

    /* Print all sensor data and statistics */
    log_sensor_data(arr, size);

    /* Free allocated memory */
    free(arr);
    arr = NULL;

    return 0;
}
