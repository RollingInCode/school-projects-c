#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	typedef struct { //assign dates for each record
		int day;
		int month;
		int year;
	} DATE;

	typedef struct { //assign information for labor worker
		char name[100];
		int age;
		float hrlyWage;
		float hrsWorked;
		float regPay;
		float otPay;
		float totalPay;
		DATE payDate;
	} PAYRECORD;

	int totalRecords;
	printf("Number of records you want to add: ");
	fflush(stdout);
	scanf("%d", &totalRecords);
	fflush(stdout);
	if (!(totalRecords > 0 && totalRecords < 100)) {
		printf("enter valid input in b/w 0 - 100");
	}
	fflush(stdout);
	int totalRecords_tmp = totalRecords;

	PAYRECORD record[400];
	DATE tmpDate[1];

	printf("enter valid input in b/w 0 - 100000");
	fflush(stdout);
	int i = 0;
	while (1) {
		printf("1. Add Employee Record...\n");
		printf("2. Search Employee Record...\n");
		printf("3. Display Total Payroll ...\n");
		printf("4. Quit...\n");
		fflush(stdout);
		int choice = 4;
		scanf("%d", &choice);
		fflush(stdout);
		switch (choice) {
		case 1:
			while (totalRecords_tmp > 0 && totalRecords_tmp < 100) {
				printf("Enter Name: ");
				fflush(stdout);
				scanf("%s", record[i].name);
				printf("%s", record[i].name);
				printf("\nEnter Age: ");
				fflush(stdout);
				scanf("%d", &record[i].age);
				fflush(stdout);
				printf("\nEnter Wage: ");
				fflush(stdout);
				scanf("%f", &record[i].hrlyWage);
				printf("\nEnter Worked: ");
				fflush(stdout);
				scanf("%f", &record[i].hrsWorked);
				fflush(stdout);
				printf("\nEnter regPay: ");
				fflush(stdout);
				scanf("%f", &record[i].regPay);
				fflush(stdout);
				printf("\nEnter otPay: ");
				fflush(stdout);
				scanf("%f", &record[i].otPay);
				fflush(stdout);
				/*printf("Enter totalPay");
				 scanf("%d", record[i].totalPay);*/
				record[i].totalPay = (record[i].hrlyWage * record[i].hrsWorked)
					+ record[i].regPay + record[i].otPay;
				printf("Enter date DD MM YYYY");
				fflush(stdout);
				scanf("%d %d %d", &record[i].payDate.day,
					&record[i].payDate.month, &record[i].payDate.year);
				fflush(stdout);
				printf("You Entered details\n"); // Verify the information that is presented here.
				printf("Name: %s \n", record[i].name);
				printf("age: %d \n", record[i].age);
				printf("hrlyWage: %.2f \n", record[i].hrlyWage);
				fflush(stdout);
				printf("hrsWorked: %.2f \n", record[i].hrsWorked);
				printf("regPay: %.2f \n", record[i].regPay);
				printf("otPay: %.2f \n", record[i].otPay);
				printf("date: %d %d %d \n", record[i].payDate.day,
					record[i].payDate.month, record[i].payDate.year);
				printf("totalPay: %f \n", record[i].totalPay);
				printf("===================================\n");
				fflush(stdout);
				totalRecords_tmp--;
				i++;
			}
			break;
		case 2:
			printf("Enter date in DD MM YYYY");
			fflush(stdout);
			scanf("%d %d %d", &tmpDate[0].day, &tmpDate[0].month,
				&tmpDate[0].year);
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
			printf("Total PayRoll records...");
			fflush(stdout);
			for (int i = 0; i < totalRecords; i++) {
				//printf("Name: %s \n", record[i].name);
				//printf("age: %d \n", record[i].age);
				//    printf("hrlyWage: %f \n", record[i].hrlyWage);
				//printf("hrsWorked: %f \n", record[i].hrsWorked);
				//printf("regPay: %f \n", record[i].regPay);
				//printf("otPay: %f \n", record[i].otPay);
				printf("date: %d %d %d \n", record[i].payDate.day,
					record[i].payDate.month, record[i].payDate.year);
				printf("totalPay: %f \n", record[i].totalPay);
				fflush(stdout);
			}
			break;
		case 4:
            printf("Quitting program....");
            exit(-1);
			break;
		default:
			printf("Try again");
			fflush(stdout);
		}
	}
	return 0;
}


