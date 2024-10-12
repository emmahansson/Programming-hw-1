#include <stdio.h>
#include <math.h>

#define COMPLEX "complex"

void calculate_and_display(double A, double B, double H) {
    double x, y;
    printf("x\ty\n"); // header of the table

    for (x = A; x < B; x += H) {
        if (x == 0) {
            printf("%.2f\t%s\n", x, COMPLEX); // division by zero, output 'complex'
        } else {
            y = (pow(x, 3) + 2 * x - 14) / (7 * x);
            printf("%.2f\t%.2f\n", x, y); // output x and y values
        }
    }
}

int main() {
    double A, B, H;

    while (1) {
        printf("Enter initial value A: ");
        scanf("%lf", &A);
        printf("Enter final value B: ");
        scanf("%lf", &B);
        printf("Enter step H: ");
        scanf("%lf", &H);

        if (A >= B || H <= 0 || A == 0) {
            if (A == 0) {
                printf("Invalid input: A cannot be 0.\n");
            } else {
                printf("Invalid input: A must be less than B, and H must be greater than 0.\n");
            }
            printf("Please enter valid values again.\n");
        } else {
            break;
        }
    }

    calculate_and_display(A, B, H);
    return 0;
}