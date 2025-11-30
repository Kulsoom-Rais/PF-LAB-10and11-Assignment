#include <stdio.h>
#define METERS_TO_KM 0.001

double convertToKilometers(double meters) {
    static int callCount = 0;  
    callCount++;

    printf("Function has been called %d time(s)\n", callCount);
    return meters * METERS_TO_KM;
}

int main() {
    double meters;
    char choice;

    do {
        printf("Enter distance in meters: ");
        scanf("%lf", &meters);

        double km = convertToKilometers(meters);
        printf("%.2f meters = %.3f kilometers\n", meters, km);

        printf("Do you want to convert another distance? (y/n): ");
        scanf(" %c", &choice);  
        } while (choice == 'y' || choice == 'Y');

    return 0;
}
