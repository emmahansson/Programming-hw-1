#include <stdio.h>
#include <math.h>

#define COMPLEX "complex"
#define MAX_VALUES 100 // Maximum number of values

// Global variables to hold values
double A, B, H;
double x_values[MAX_VALUES]; // Array to store x values
double y_values[MAX_VALUES]; // Array to store y values
int count = 0;

// Prototypes 
void sisesta_arv(void);
void calculate_and_display(void);
void tulemus_ekraanile(void);

// Main function
int main(void) {
    while (1) {
        printf("The program will calculate x and y values in function y=(x^3+2x-14)/7x based on entered variables.\n"); // Intro
        sisesta_arv(); // Get input values

        if (A == 0) {
            printf("Invalid input: A cannot be 0.\n");
            continue;
        }

        if (A >= B || H <= 0) {
            printf("Invalid input: A must be less than B, and H must be greater than 0.\n");
        } else {
            break; // Valid inputs, exit loop
        }
    }

    calculate_and_display(); // Perform calculations
    return 0;
}

// Function to input numbers
void sisesta_arv(void) {
    printf("Enter initial value A (cannot be 0):\n");
    scanf("%lf", &A);
    
    printf("Enter final value B (greater than A):\n");
    scanf("%lf", &B);
    
    printf("Enter step H (greater than 0):\n");
    scanf("%lf", &H);
}

// Function to calculate and display results
void calculate_and_display(void) {
    double x, y;
    count = 0;

    // Calculate and store all x values
    for (x = A; x < B; x += H) {
        if (count < MAX_VALUES) {
            x_values[count] = x; // Store x value in array
            count++;
        } else {
            break; // Limit output to MAX_VALUES
        }
    }

    // Calculate and store all y values
    for (int j = 0; j < count; j++) {
        x = x_values[j];
        y = (pow(x, 3) + 2 * x - 14) / (7 * x); // Calculate y
        y_values[j] = y; // Store y value in array
    }

    if (count == MAX_VALUES) {
        printf("Note: Program outputs only the first %d values.\n", MAX_VALUES);
    }

    tulemus_ekraanile(); // Display results
}

// Function to display results on screen
void tulemus_ekraanile(void) {
    printf("x\ty\n"); // Header of the table

    for (int j = 0; j < count; j++) {
        printf("%.2f\t%.2f\n", x_values[j], y_values[j]); // Output x and y values
    }
}
