#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Franklyn Gonzalez, last edited 02/27/2019


int daysInMonth( int month, int year){ //used to validate the leap year date
    if ( month== 4 || month == 6 || month == 9 || month == 11 ){
        return 30;
    } else if ( month == 2 ) {
        if ( year % 4 == 0 && ( year % 100 == 0 || year % 400 == 0) )
            return 29;
        else
            return 28;
    } else {
        return 31;
    }
}

typedef struct person
{
    char name[30]; //name
    int dd, mm, yyyy; //date
    char gender; //gender
    double annualIncome; //annual income
} psn;

main() {
   
    psn person;   

    //initalizing variables
    strcpy(person.name, "John");
    person.dd = 03;
    person.mm = 05;
    person.yyyy = 2003;
    person.gender = '\0';
    person.annualIncome = 0.00;


    printf("Please enter person's name: \n");
    scanf("%[a-z A-Z]s", &person.name);

    printf("Please enter person's date of birth. i.e. 03 05 1995 with ' ' in between. \n");


    while ( scanf( "%i%i%i", &person.dd, &person.mm, &person.yyyy) != 3 || person.dd <= 0 || person.mm <= 0 || person.yyyy < 0 || daysInMonth(person.mm, person.yyyy) < person.dd)
    {        
        printf("Please enter a valid date.\n");
        scanf("%i%i%i", &person.dd, &person.mm, &person.yyyy);
    }
    

    person.gender = '\0'; 
    printf("Please enter person's gender. Choose one of the following: M, F, O.\n");
    while (person.gender == '\0') 
    {
        if (person.gender != 'M' || person.gender != 'F' || person.gender != 'O') 
        {
            printf("Invalid selection for gender. Please try again.\n");
            person.gender = '\0';
            person.gender = getchar();
        }
        if (person.gender == '\n') {
            person.gender = '\0';
        }

    }


    printf("Please enter person's annual income.\n ");
    scanf("%lf", &person.annualIncome);

    while (person.annualIncome > 1000000.00 || person.annualIncome < 0.00) {
        if (person.annualIncome > 1000000.00) {
            printf("Invalid amount. Please try again.\n");
            person.annualIncome = 0.00;
        }
        else if (person.annualIncome < 0.00) {
            printf("Invalid amount. Please try again.\n");
            person.annualIncome = 0.00;
        }
    }


    printf("\n%s\n", person.name);
    printf("%i/%i/%i\n", person.dd, person.mm, person.yyyy );
    printf("%c\n", person.gender);
    printf("%.2lf\n", person.annualIncome); 
}
