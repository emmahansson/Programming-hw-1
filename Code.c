#include <stdio.h>
#include <math.h>

#define COMPLEX "complex"
#define MAX_VALUES 100 // Maximum number of values

void calculate_and_display(double A, double B, double H);
double sisesta_arv(char w[]);
void tulemus_ekraanile(double x_values[], double y_values[], int count);

int main(void) {
    double A, B, H;

    while (1) {
        A = sisesta_arv("The program will calculate x and y values in function y=(x^3+2x-14)/7x based on entered variables.\n Enter initial value A (cannot be 0):");
        if (A == 0) {
            printf("Invalid input: A cannot be 0.\n");
            continue;
        }

        B = sisesta_arv("Enter final value B (greater than A):");
        H = sisesta_arv("Enter step H (greater than 0) :");

        if (A >= B || H <= 0) {
            printf("Invalid input: A must be less than B, and H must be greater than 0.\n");
        } else {
            break; // Valid inputs, exit loop
        }
    }

    calculate_and_display(A, B, H);
    return 0;
}

double sisesta_arv(char w[]) {
    double lokA;
    printf("%s\n", w);
    scanf("%lf", &lokA);
    return lokA;
}

void calculate_and_display(double A, double B, double H) {
    double x, y;
    double x_values[MAX_VALUES]; // Array to store x values
    double y_values[MAX_VALUES]; // Array to store y values
    int i = 0;

    // Calculate and store all x values
    for (x = A; x < B; x += H) {
        if (i < MAX_VALUES) {
            x_values[i] = x; // Store x value in array
            i++;
        } else {
            break; // Limit output to MAX_VALUES
        }
    }

    // Calculate and store all y values
    for (int j = 0; j < i; j++) {
        x = x_values[j];
        y = (pow(x, 3) + 2 * x - 14) / (7 * x); // Calculate y
        y_values[j] = y; // Store y value in array
    }

    if (i == MAX_VALUES) {
        printf("Note: Program outputs only the first %d values.\n", MAX_VALUES);
    }

    tulemus_ekraanile(x_values, y_values, i);
}

void tulemus_ekraanile(double x_values[], double y_values[], int count) {
    printf("x\ty\n"); // Header of the table

    for (int j = 0; j < count; j++) {
        printf("%.2f\t%.2f\n", x_values[j], y_values[j]); // Output x and y values
    }
}
