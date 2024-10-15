#include <stdio.h>
#include <math.h>

#define COMPLEX "complex"
int main() {
    double A, B, H;

    while (1) {
        printf("Enter initial value A: ");
        scanf("%lf", &A);
        if (A == 0) {
            printf("Invalid input: A cannot be 0.\n");
            printf("Please enter valid values again.\n");
            continue;
        }
        printf("Enter final value B: ");
        scanf("%lf", &B);
        printf("Enter step H: ");
        scanf("%lf", &H);

        if (A >= B || H <= 0) {
            printf("Invalid input: A must be less than B, and H must be greater than 0.\n");
            printf("Please enter valid values again.\n");
        } else {
            break;
        }
    }
void calculate_and_display(double A, double B, double H) {
    double x, y;
    double x_values[100]; // array to store x values
    double y_values[100]; // array to store y values
    int i = 0;

    for (x = A; x < B; x += H) {
        x_values[i] = x; // store x value in array
        if (x == 0) {
            y_values[i] = 0; // set y value to 0 for division by zero
        } else {
            y = (pow(x, 3) + 2 * x - 14) / (7 * x);
            y_values[i] = y; // store y value in array
        }
        i++;
    }

    printf("x\ty\n"); // header of the table

    for (int j = 0; j < i; j++) {
        if (x_values[j] == 0) {
            printf("%.2f\t%s\n", x_values[j], COMPLEX); // output 'complex' for division by zero
        } else {
            printf("%.2f\t%.2f\n", x_values[j], y_values[j]); // output x and y values
        }
    }
}


    calculate_and_display(A, B, H);
    return 0;
}
