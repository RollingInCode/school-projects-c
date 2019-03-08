#include <stdio.h>
#include <stdlib.h>

main() {
    // 5 numbers for entry, Lvalue for lowest value, Hvalue for highest value, count for average and entries entered
    int choice = 0, count = 0, input = 0, number1 = 0, number2 = 0, number3 = 0, number4 = 0, number5 = 0, Lvalue = 0, Hvalue = 0, result = 0;
    // specifies the value for the variable - average
    double average = 0;

    do
    {
        // Select 5 numbers
        printf("Select the values:\n");
        scanf_s("%i", &number1);
        // Count adds per entry
        count++;
        scanf_s("%i", &number2);
        count++;
        scanf_s("%i", &number3);
        count++;
        scanf_s("%i", &number4);
        count++;
        scanf_s("%i", &number5);
        count++;
        // Menu
        printf("Select the option below:\n");
        printf("1. Display the smallest number entered.\n");
        printf("2. Display the largest number entered.\n");
        printf("3. Display the sum of the five numbers entered.\n");
        printf("4. Display the average of the five numbers entered.\n");
        printf("5. Exit.\n");
        scanf_s("%i", &choice);
        switch (choice)
        {
            // Lowest
        case 1:
            // Give Lvalue a value that is lower than all the numbers
            Lvalue = number1;
            if (Lvalue > number2) {
                Lvalue = number2;
            }
            if (Lvalue > number3) {
                Lvalue = number3;
            }
            if (Lvalue > number4) {
                Lvalue = number4;
            }
            if (Lvalue > number5) {
                Lvalue = number5;
            }
            printf("The smallest number entered is: %i \n", Lvalue);
            // Reset values
            Lvalue = 0;
            result = 0;
            count = 0;
            break;
            // Highest
        case 2:
            // Allow all values to compete for highest value
            if (number1 > Hvalue) {
                Hvalue = number1;
            }
            if (number2 > Hvalue) {
                Hvalue = number2;
            }
            if (number3 > Hvalue) {
                Hvalue = number3;
            }
            if (number4 > Hvalue) {
                Hvalue = number4;
            }
            if (number5 > Hvalue) {
                Hvalue = number5;
            }
            printf("The largest number entered is: %i \n", Hvalue);
            // Reset values
            Hvalue = 0;
            result = 0;
            count = 0;
            break;
            // Sum
        case 3:
            result = (number1 + number2 + number3 + number4 + number5);
            printf("The sum of the five numbers entered is: %i \n", result);
            // Reset values
            count = 0;
            result = 0;
            break;
            // Average
        case 4:
            result = (number1 + number2 + number3 + number4 + number5);
            average = (double)result / count;
            printf("The average of the five numbers entered is: %.2lf \n", average);
            // Reset values
            average = 0;
            count = 0;
            result = 0;
            break;
        case 5:
            break;
        default:
            printf("That is an invalid option.\n\n");
            break;
        }
        // Exit
    } while (choice != 5);
    
}