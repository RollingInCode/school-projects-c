#include <stdlib.h>
#include <stdio.h>

// Franklyn Gonzalez, last edited on 1/16/2018, program is used to demonstrate an alterative loop, without using "for" "do-while" or "while" loops. This program uses a function to call itself.

int tacoBell(i, x)
{
    if (i <= 11 && x <= 0) {  // base case
        return i,x;  
    } else {       // recursive case
        printf("%i. x equals %i. \n", i, x);
        tacoBell(i + 1, x - 1);
    }
}


int main()
{
    // variables initalized 
    int x = 10, i = 1;
    tacoBell(i, x);


    system("pause");
}