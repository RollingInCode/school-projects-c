#include <stdio.h>
#include <stdlib.h>

main() {
    // The first value of Lvalue will set the lowest number
    int input = 0, count = 0, sum = 0, Nvalues = 0, Lvalue = 10000000, Hvalue = -1;
    double average = 0;
    printf("Enter an integer.\n");
    scanf_s("%i", &input);
    while (input != 0) {
        if (input != 0)
        {
            // sum adds the total of numbers accumulated
            sum = sum + input;
            // count++ is same as count = count + 1
            count++;
            // if input is higher than Hvalue, Hvalue gets input
            if (input > Hvalue) {
                Hvalue = input;
            }
            // if input is lower than Lvalue, Lvalue gets input
            if (input < Lvalue) {
                Lvalue = input;
            }
        }
        printf("Your total sum of count is: %i\n", sum);
        // overcast the output in this division problem
        average = (double)sum / count;
        printf("Your highest number is: %i\n", Hvalue);
        printf("Your lowest number is: %i\n", Lvalue);
        printf("Your average of count is: %.2lf\n", average);
        // continue loop until "0" is entered
        scanf_s("%i", &input);
    }

}