#include <stdio.h>
#include <stdlib.h>
#define COUNTER 50 

main() {
    double values[COUNTER] = { 0.0 };
    int i = 0;  

    while (values[i] != -999 && i < COUNTER) {           
        printf("%i ", i + 1);
        i++;
        printf("Enter a number (-999 to quit) : ");
        scanf_s("%lf", &values[i]); // values entered
        
        
    }
    printf("Program Complete.");
}