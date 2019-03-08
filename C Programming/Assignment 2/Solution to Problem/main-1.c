/*
Menus Functions Arrays
 Adapted by Dr. Macon from a student's submission
 */

#include <stdio.h>
#include <stdlib.h>

//size of data array
#define SIZE 255

// Function Prototypes
void  displayMenu(void);
void clearInputBuf(void);
void makeDeposit(float fDeposits[]);
void displaySum(float fDeposits[]);
void displayAll(float fDeposits[]);
void displayAverage(float fDeposits[]);
void displayLowest(float fDeposits[]);
void sort(float fDeposits[]);
float fCalcSum(float fDeposits[]);
int iGetFirstUnusedIndex(float fDeposits[]);


/*main*/
int main()
{
    float fDeposits[SIZE] = { 0.0 };
    int bExit = 0;
    do
    {
        displayMenu();                          //display menu
        char cSelection = '\0';
        scanf("%c",&cSelection);          //collect input
        clearInputBuf();
        switch (cSelection)                     //perform action
        {
            case 'M':case 'm':
                makeDeposit(fDeposits);           //make a deposit
                break;
            case 'S':case 's':                      //display sum
                displaySum(fDeposits);       //of deposits
                break;
            case 'D':case 'd':                      //display all
                displayAll(fDeposits);       //deopsits
                break;
            case 'A':case 'a':                      //display average
                displayAverage(fDeposits);   //of deposits
                break;
            case 'L':case 'l':                      //display lowest
                displayLowest(fDeposits);    //deposit
                break;
            case 'Q':case 'q':
                bExit = 1;                        //set exit condition to 1
                break;
            default:
                system("cls");
                printf("Invalid selection\n");
                break;
        }//end switch
    } while (!bExit);//end do-while
    return 0;
}//end main

/* display menu option text*/
void displayMenu(void)
{
    printf("*** BANKING MAIN MENU ***"
           "\n\n[M]ake a new deposit"
           "\n\n[S]um of all deposits"
           "\n\n[D]eposits will be displayed from highest to lowest deposit"
           "\n\n[A]verage of all deposits"
           "\n\n[L]owest deposit will be displayed"
           "\n\n[Q]uit the program"
           "\n\n");
    return;
}//end function
/*clear any chars in buffer after an input read
 (code found on StackOverflow)*/
void clearInputBuf(void)
{
    int garbageCollector;
    while ((garbageCollector = getchar()) != '\n' && garbageCollector != EOF)
    {
    }
    return;
}
/*make a deposit, and sort it into the list*/
void makeDeposit(float fDeposits[])
{
    float fDeposit = 0.0;
    printf("Enter amount to deposit: $");   //collect input
    scanf("%f", &fDeposit);
    clearInputBuf();
    if (fDeposit <= 0) //check for nonzero amount
    {
        system("cls");                              //
        printf("Cannot deposit $%.2f", fDeposit);   //display error message
        printf("\n");                               //and return to menu
        return;
    }//end if
    
    int i = iGetFirstUnusedIndex(fDeposits);    //find end of data
    
    if (i == -1)                                //check for full array
    {
        printf("Cannot make deposit: Array full \n");
        return;
    }//end if
    
    fDeposits[i] = fDeposit;    //add to list of deposits
    sort(fDeposits);            //sort list
    
    printf("Deposit successful: $%.2f", fDeposit);
    printf("\n\n");                                   //print success message
 
    return; //return to menu
}//end function

//calculate and display sum of all deposits
void displaySum(float fDeposits[])
{
    int i = iGetFirstUnusedIndex(fDeposits);    //find end of data
    if (i == 0)                                 //check for data to display
    {
        printf("No deposits"    //nothing to display,
               "\n");           //return to menu
        return;
    }//end if
    float fSum = fCalcSum(fDeposits);
    printf("Sum of deposits: $%.2f", fSum); //get and display the sum
    printf("\n\n");
    return; //return to menu
}//end function

/*display all deposits in the array sorted from highest to lowest*/
void displayAll(float fDeposits[])
{
    printf("Deposits: \n");
    int i = iGetFirstUnusedIndex(fDeposits);    //find end of data
    if (i == 0)                                 //check for data to display
    {
 
        printf("No deposits \n");           //return to menu
        return;
    }//end if
    
    for (int j = 0; j < i; j++) //loop through valid data entries
    {
        printf("\n$%.2f", fDeposits[j]);    //display each entry
    }//end for
    
    printf("\n\n");       //end list and
    return; //return to menu
    
}//end function

/*calculate and display the average deposit*/
void displayAverage(float fDeposits[])
{
    float   fAverage = 0.0,             //declare variables
    fSum = fCalcSum(fDeposits); //and get sum
    int   i = iGetFirstUnusedIndex(fDeposits);    //find end of data
    if (i == 0)                                     //check for data to display
    {
        printf("No deposits \n");           //return to menu
        return;
    }//end if
    
    fAverage = fSum / i;    //calculate average
    printf("Average Deposit: $%.2f", fAverage); //display average
    printf("\n\n");
    return; //return to menu
}

/*display the smallest valid deposit in the array sorted highest to
 lowest*/
void displayLowest(float fDeposits[])
{
    float fLowest = 0.0;
    int   i = iGetFirstUnusedIndex(fDeposits);    //find end of data
    if (i == 0)                                 //check for data to display
    {
        printf("No deposits \n");           //return to menu
        return;
    }//end if
    
    fLowest = fDeposits[i - 1]; //array is already sorted, so lowest value = last value
    printf("Smallest deposit: $%.2f", fLowest); //display lowest
    printf("\n\n");                               //value
    return; //return to menu
    
}//end function

/*sort the array from highest to lowest with a bubble sort*/
void sort(float fDeposits[])
{
    int bComplete = 0;  //condition var. 0 = unfinished, 1 = finished
    do  //sorting loop
    {
        bComplete = 1;  //reset test condition
        for (int i = 1; i < SIZE; i++)  //loop through data
        {
            if (fDeposits[i] > fDeposits[i - 1])
                //compare two values
            {
                bComplete = 0;
                //wrong order, not done sorting
                float ftmp = fDeposits[i];
                fDeposits[i] = fDeposits[i - 1];
                //swap the entries
                fDeposits[i - 1] = ftmp;
            }//end if
        }//end for
    } while (!bComplete);//end do-while - exit if no swaps have ocurred this loop
    return;//done sorting
}//end function

/*calculate and return the sum of all deposits*/
float fCalcSum(float fDeposits[])
{
    float fSum = 0.0;
    for (int i = 0; i < SIZE; i++)  //loop through all entries
    {
        fSum += fDeposits[i];   //add each to sum
    }//end for
    return fSum;    //return sum
}//end function

/*find and return the index of the first empty (0.0) entry in the array,
 else return -1 if array is full*/
int iGetFirstUnusedIndex(float fDeposits[])
{
    for (int i = 0; i < SIZE; i++)  //loop through the array
    {
        if (fDeposits[i] == 0.0)    //check if the entry is occupied
        {
            return i;               //return its index
        }//end if
    }//end for
    return -1;  //all entries occupied - return -1
}//end function

