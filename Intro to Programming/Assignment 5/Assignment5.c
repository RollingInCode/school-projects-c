#include <stdio.h>
#include <stdlib.h>

main() 
{
    int grade, sum = 0, pass = 0, fail = 0;
    double total;
    
    printf("Enter a test score (-1 to quit):");
    scanf_s("%i", &grade);
    sum = sum + pass;
    sum = sum + fail;
    if (grade > 100)
    {
        printf("That is not a valid grade!\n");
        grade = 0; 
    }
    else if (grade >= 70) {
        pass = 1;
    }
    else if (grade < 69) {
        pass = 0;
    }
    while (grade != -1) {
        printf("Enter a test score (-1 to quit):");
        scanf_s("%i", &grade);
        // Adds up the number of loops and grades
        sum = sum + 1;

        // Invalid grade is not counted to the sum
        if (grade > 100)
        {
            printf("That is not a valid grade!\n");
            grade = 0;
            sum = sum - 1;
        }
        // Equal or above 70 is passing
        else if (grade >= 70) {
            pass = pass + 1;
        }
        // Below 69 is failing
        else if (grade < 69 && grade != -1) {
            fail = fail + 1;
    }

    }
    // Overcast allows the int to calculate specific values
    // The number of "pass" - passing grades above 70, out of the "sum" - the number of total grades
    total = ((double) pass / sum) * 100;
    // Number of passing grades out of the total
    printf("\n You have entered %i passing grades. \n", pass);
    
    printf("\n'%.2lf' of the valid grades entered are passing grades.\n", total);

}
	

