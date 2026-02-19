#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DAYS 7 /* Number of days for the temperature readings */

/**
 * struct Readings - Stores the temperature for a day
 * @temperature: Temperature reading for a single day
 */
typedef struct
{
    float temperature;
} Readings;

/**
 * ReadingInput - Inputs temperature readings from the user
 * @readings: Array of Readings structures
 */
void ReadingInput(Readings *readings)
{
    int i;

    printf("Enter temperature readings for %d days:\n", NUM_DAYS);
    for (i = 0; i < NUM_DAYS; i++)
    {
        printf("Day %d: ", i + 1);
        scanf("%f", &readings[i].temperature);
    }
}

/**
 * saveReadings - Saves temperature readings to a text file
 * @readings: Array of Readings structures
 */
void saveReadings(Readings *readings)
{
    FILE *file = fopen("temperatures.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file for writing!\n");
        exit(1);
    }

    for (int i = 0; i < NUM_DAYS; i++)
    {
        fprintf(file, "%.2f\n", readings[i].temperature);
    }

    fclose(file);
}

/**
 * computeAvgTemp - Computes the average temperature
 * @readings: Array of Readings structures
 *
 * Return: Average temperature as a float
 */
float computeAvgTemp(Readings *readings)
{
    float sum = 0;

    for (int i = 0; i < NUM_DAYS; i++)
    {
        sum += readings[i].temperature;
    }

    return sum / NUM_DAYS;
}

/**
 * highLowTemp - Finds the highest and lowest temperature readings
 * @readings: Array of Readings structures
 * @highest: Pointer to store the highest temperature
 * @lowest: Pointer to store the lowest temperature
 */
void highLowTemp(Readings *readings, float *highest, float *lowest)
{
    *highest = readings[0].temperature;
    *lowest = readings[0].temperature;

    for (int i = 1; i < NUM_DAYS; i++)
    {
        if (readings[i].temperature > *highest)
            *highest = readings[i].temperature;

        if (readings[i].temperature < *lowest)
            *lowest = readings[i].temperature;
    }
}

/**
 * displayReadings - Displays the temperature summary
 * @avg: Average temperature
 * @highest: Highest temperature
 * @lowest: Lowest temperature
 */
void displayReadings(float avg, float highest, float lowest)
{
    printf("\n--- Temperature Summary ---\n");
    printf("Average Temperature: %.2f°C\n", avg);
    printf("Highest Temperature: %.2f°C\n", highest);
    printf("Lowest Temperature: %.2f°C\n", lowest);
}

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
    Readings readings[NUM_DAYS]; /* Array to store temperature readings */
    float highest, lowest, avg;

    /* Introduction */
    printf("\n-----Daily Temperature Readings-----\n\n");

    /* Step 1: Get temperature input */
    ReadingInput(readings);

    /* Step 2: Save readings to file */
    saveReadings(readings);

    /* Step 3: Compute the average temperature */
    avg = computeAvgTemp(readings);

    /* Step 4: Find the highest and lowest temperatures */
    highLowTemp(readings, &highest, &lowest);

    /* Step 5: Display the results */
    displayReadings(avg, highest, lowest);

    return 0;
}
