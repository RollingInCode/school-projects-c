#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLS system("cls")
// Franklyn Gonzalez, last edited 03/07/2019

void roman(); // Calls Roman Numerals

main() {
    int input = 0;
    printf("Enter a Roman Numeral Value from 1-1000.\n Non-Roman Numeral numbers will return empty.\n\n Enter '-1' to exit.\n"); // prints menu

    while (input != -1)
    {
        scanf("%i", &input);  
        CLS; // clears input
        roman(input); // calls function
    }
}


void roman(input) 
{
    switch (input)
    {
    case 1:
        input = 73;
        input = (char)input;
        printf("%c \n", input);
        input = 0;
        break;
        // I
    case 5:
        input = 86; // ASCII Number of Character
        input = (char)input;
        printf("%c \n", input);
        input = 0;
        break;
        // V
    case 10:
        input = 88; // ASCII Number of Character
        input = (char)input;
        printf("%c \n", input);
        input = 0;
        break;
        // X
    case 50:
        input = 76; // ASCII Number of Character
        input = (char)input;
        printf("%c \n", input);
        input = 0;
        break;
        // L
    case 100:
        input = 67; // ASCII Number of Character
        input = (char)input;
        printf("%c \n", input);
        input = 0;
        // C
        break;
    case 500:
        input = 68; // ASCII Number of Character
        input = (char)input;
        printf("%c \n", input);
        input = 0;
        break;
        // D
    case 1000:
        input = 77; // ASCII Number of Character
        input = (char)input;
        printf("%c \n", input);
        input = 0;
        break;
        // M
    default:
        break;
    }
}

