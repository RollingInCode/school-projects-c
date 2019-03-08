#include <stdio.h>
#include <stdlib.h>

/*
int leapYear(int payDate.year, int payDate.month, int payDate.day) {
    if ( payDate.month== 4 || payDate.month == 6 || payDate.month == 9 || payDate.month == 11 ){
        return payDate.year,payDate.month,30;
    } else if ( payDate.month == 2 ) {
        if ( payDate.year % 4 == 0 && ( payDate.year % 100 == 0 || payDate.year % 400 == 0) )
            return payDate.year,payDate.month, 29;
        else
            return payDate.year,payDate.month, 28;
    } else {
        return payDate.year,payDate.month, 31;
    }
}
*/
/*
int dateA( int month, int year){ //used to validate the leap year date    
    int top= 0, bottom = 0, middle = 0, search = 0, location = 0;
    char stop = 'N';
    int month[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int count = 12; 

    search = month;

    top = 0;
    bottom = count - 1;
    middle = (top + bottom) / 2;

    while ( top <= bottom && stop == 'N')
    {
        if ( month[middle] < search ) {
            top = middle + 1;   
        }
        else if ( month[middle] == search ) 
        {
            location = middle+1;
            stop = 'Y';
        }
        else {
            bottom = middle - 1;
            middle = (top + bottom) / 2;
        }
    if (top > bottom) {
        printf("Not found! %i is not present in the list.\n", search);
        return 0;
    }

    else
        printf("Value %i at %i element.\n", search, location-1);
    pause;
} 

*/






int totalRecords(int count) {
    int totalRecords = 0;
    if (count == 0) {
        printf("How many records would you like to add?\t");
        fflush(stdout);
        scanf("%d", &totalRecords);
        fflush(stdout);
        if (!(totalRecords > 0 && totalRecords < 100)) {
            printf("Enter a valid input from 0 - 100.\n");
        }
        fflush(stdout);
        return totalRecords;
    }
    else if (count == 1) // PLEASE COMPLETE!
    {

    }
}
//void record();
//void menu();


void menu() { //menu start
    printf("Welcome to the system of Payrolls here in TrainMech LLC. Please select one of the options below.");
    printf("1. Add Employee Record...\n"); //add additional information for the employee
    printf("2. Search Employee Record...\n"); //
    printf("3. Display Total Payroll ...\n");
    printf("4. Quit...\n");
}


int main() {

    typedef struct {
        int day;
        int month;
        int year;
    } DATE;

    typedef struct payroll {
        char name[100];
        int age;
        float hrlyWage;
        float hrsWorked;
        float regPay;
        float otPay;
        float totalPay;
        DATE payDate;
    } pay;

    //initalizing variables
    //strcpy(person.name, "John");
    //person.dd = 03;
    //person.mm = 05;
    //person.yyyy = 2003;
    //person.gender = '\0';
    //person.annualIncome = 0.00;

    int totalRecords_tmp = totalRecords; //what is totalRecords_tmp even used for?
    pay record[100];
    DATE tmpDate[1];

    int option1 = 0;
    int count = 0;
    int valid = 0;
    int j = 0; //used to keep track of the number of records that are added into the database
    int toggle = 0;
    int payroll[100] = { 0 };
    menu(); //Call menu
    scanf("%i", toggle);
    fflush(stdout);



		switch (toggle) {
		case 1:
            
            totalRecords(option1);
            if (j < 100) {
                for (int i = option1; i >= 1; i--)
                {
                    //FILE *fp[count] = fopen("C:\\MyFiles\\Payroll.txt", "w+"); //open resume file
                    
                    printf("Enter Name: ");
                    fflush(stdout);
                    scanf("%s", &pay.name);
                    printf("%s", pay.name);
                    printf("\nEnter Age: ");
                    fflush(stdout);
                    scanf("%d", &pay.age);
                    fflush(stdout);
                    printf("\nEnter Wage: ");
                    fflush(stdout);
                    scanf("%.2f", &payroll.hrlyWage);
                    printf("Enter Hours Worked: ");
                    fflush(stdout);
                    scanf("%.2f", &payroll.hrsWorked);
                    fflush(stdout);
                    printf("Enter Regular Pay: ");
                    fflush(stdout);
                    scanf("%.2f", &payroll.regPay);
                    fflush(stdout);
                    printf("Enter OverTime Pay: ");
                    fflush(stdout);
                    scanf("%.2f", &payroll.otPay);
                    fflush(stdout);
                    /*printf("Enter totalPay");
                    scanf("%d", record[i].totalPay);*/
                    record[j].totalPay = (payroll.hrlyWage * payroll.hrsWorked)
                        + record[j].regPay + record[j].otPay;
                    printf("Enter date DD MM YYYY\n");
                    fflush(stdout);
                    scanf("%i %i %i", &payDate.day, &payDate.month, &payDate.year);
                    valid = 1; //enter date validate loop
                    // validating date by month
                    while (valid != 0) 
                    {     
                        if (payDate.day <= 1 && payDate.month <= 1 && payDate.year > 1900)
                        {
                            leapYear(payDate.year,payDate.month,payDate.day);
                            valid = 0;
                        }
                        else if (payDate.day < 1 && payDate.month < 1 && payDate.year < 1900)
                        {
                            printf("Please enter a valid date.\n");
                            scanf("%i %i %i", &payDate.day, &payDate.month, &payDate.year);
                        }
                        else if (payDate.day > 31 || payDate.month > 13 || payDate.year > 2019)
                        {
                            printf("Please enter a valid date.\n");
                            scanf("%i %i %i", &payDate.day, &payDate.month, &payDate.year);
                        }
                    }

                    scanf("%d %d %d", &record[j].payDate.day,
                        &record[j].payDate.month, &record[j].payDate.year);
                    fflush(stdout);
                    printf("-Information-\n");
                    printf("Name: %s \n", record[j].name);
                    printf("age: %d \n", record[j].age);
                    printf("hrlyWage: %f \n", record[j].hrlyWage);
                    fflush(stdout);
                    printf("hrsWorked: %f \n", record[j].hrsWorked);
                    printf("regPay: %f \n", record[j].regPay);
                    printf("otPay: %f \n", record[j].otPay);
                    printf("date: %d %d %d \n", record[j].payDate.day,
                        record[j].payDate.month, record[j].payDate.year);
                    printf("totalPay: %f \n", record[j].totalPay);
                    printf("===================================\n");
                    fflush(stdout);
                    //totalRecords_tmp--;
                    j++;
                }
                //totalRecords = option1;
            }
            else if (j > 100)
            {
                printf("WARNING. You can only add up to 100 records. Please try again later.");               
            }
            /*
            }
			while (totalRecords_tmp > 0 && totalRecords_tmp < 100) {
				printf("Enter Name");
				fflush(stdout);
				scanf("%s", record[i].name);
				printf("%s", record[i].name);
				printf("Enter Age");
				fflush(stdout);
				scanf("%d", &record[i].age);
				fflush(stdout);
				printf("Enter Wage");
				fflush(stdout);
				scanf("%f", &record[i].hrlyWage);
				printf("Enter Worked");
				fflush(stdout);
				scanf("%f", &record[i].hrsWorked);
				fflush(stdout);
				printf("Enter regPay");
				fflush(stdout);
				scanf("%f", &record[i].regPay);
				fflush(stdout);
				printf("Enter otPay");
				fflush(stdout);
				scanf("%f", &record[i].otPay);
				fflush(stdout);

				printf("Enter totalPay");
				 scanf("%d", record[i].totalPay);
				record[i].totalPay = (record[i].hrlyWage * record[i].hrsWorked)
					+ record[i].regPay + record[i].otPay;
				printf("Enter date DD MM YYYY");
				fflush(stdout);
				scanf("%d %d %d", &record[i].payDate.day,
					&record[i].payDate.month, &record[i].payDate.year);
				fflush(stdout);
				printf("You Entered details\n");
				printf("Name: %s \n", record[i].name);
				printf("age: %d \n", record[i].age);
				printf("hrlyWage: %f \n", record[i].hrlyWage);
				fflush(stdout);
				printf("hrsWorked: %f \n", record[i].hrsWorked);
				printf("regPay: %f \n", record[i].regPay);
				printf("otPay: %f \n", record[i].otPay);
				printf("date: %d %d %d \n", record[i].payDate.day,
					record[i].payDate.month, record[i].payDate.year);
				printf("totalPay: %f \n", record[i].totalPay);
				printf("===================================\n");
				fflush(stdout);
				totalRecords_tmp--;
				i++;
			}
            */

			break;
		case 2:
			printf("Enter date in DD MM YYYY");
			fflush(stdout);
			scanf("%d %d %d", &tmpDate[1].day, &tmpDate[1].month,
				&tmpDate[1].year);
            for (int i = 0; i < totalRecords; i++) {
                if ((record[i].payDate.day == tmpDate[0].day)
                    && (record[i].payDate.month == tmpDate[0].month)
                    && (record[i].payDate.year == tmpDate[0].year)) {
                    printf("Name: %s \n", record[i].name);
                    printf("age: %d \n", record[i].age);
                    printf("hrlyWage: %f \n", record[i].hrlyWage);
                    printf("hrsWorked: %f \n", record[i].hrsWorked);
                    fflush(stdout);
                    printf("regPay: %f \n", record[i].regPay);
                    printf("otPay: %f \n", record[i].otPay);
                    fflush(stdout);
                    printf("date: %d %d %d \n", record[i].payDate.day,
                        record[i].payDate.month, record[i].payDate.year);
                    printf("totalPay: %f \n", record[i].totalPay);
                    fflush(stdout);
                }
            }
			break;
		case 3:
			printf("Total PayRoll records..."); //must fix, is not complete!
			fflush(stdout);
			for (int i = 0; i < j; i++) {
				//printf("Name: %s \n", record[i].name);
				//printf("age: %d \n", record[i].age);
				//    printf("hrlyWage: %f \n", record[i].hrlyWage);
				//printf("hrsWorked: %f \n", record[i].hrsWorked);
				//printf("regPay: %f \n", record[i].regPay);
				//printf("otPay: %f \n", record[i].otPay);
				printf("date: %d %d %d \n", record[j].payDate.day,
					record[j].payDate.month, record[j].payDate.year);
				printf("totalPay: %f \n", record[j].totalPay);
				fflush(stdout);
			}
			break;
		case 4:
            printf("Exiting program....");
            return 0;
			break;
		default:
			printf("\nPlease try again. Enter a valid input. \n");
            //menu();
			fflush(stdout);
		}
	}
	return 0;
}


