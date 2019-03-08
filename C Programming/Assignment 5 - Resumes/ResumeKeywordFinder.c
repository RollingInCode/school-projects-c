#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

//Franklyn Gonzalez, last edited 02/23/2019
//Resume Keyword Finder v1.0 - This program will provide you with the basic needs in qualifying your next candidate. Please note, when creating a keyword.txt document, provide a comma after the keyword. String case sensitive keywords are counted. This program excludes ':', '(' , ')' , '\n' , ' ' , '.'

void keywordGenerator(FILE *fp1, FILE *fp2, char keyword[])
{
    char resume[200] = { '\0' };
   


    int words = 0; // number words matched from the keyword.txt to the resume.txt
    int count = 0; 

    for (int i = 0; i < 14; i++) // 14 is the value set for the amount of keywords in the file. Modify 'i' length as needed for keyword.txt
    {
        
        for (int j = 0; j < 15; j++)
        {            
            keyword[j] = getc(fp2);
            if (keyword[j] == ',') { //commas used to stop 'for' loop
                keyword[j] = '\0'; // replaced with a null character
                j = 15; // loop-end
                
            }                            
        }
        while (count != 200) // count is used to stop the loop after a certain amount of characters in the resume have been reached
        {                
            count++;
            for (int i = 0; i < 25; i++)
            {
                resume[i] = getc(fp1);
               

                if (resume[i] == ' ' || resume[i] == '\n' || resume[i] == '(' || resume[i] == ')' || resume[i] == ':' || resume[i] == '\0' || resume[i] == '.') //special characters excluded, other special characters next to keywords may not be detected
                {
                    resume[i] = '\0'; // replaced with a null character
                    if (strcmp(keyword, resume) == 0) // compares the two character arrays 
                    {
                        words++; 
                    }   
                    i = 25; // end loop
                }
                
            }
        }
        count = 0;
        fclose(fp1); // close resume file
        FILE *fp1 = fopen("C:\\MyFiles\\Resume.txt", "r"); // re-open resume file
    }

    printf("Total Keywords found in both files: %d\t", words); // keywords found in resume
}



 
int main()
{	
	FILE *fp1 = fopen("C:\\MyFiles\\Resume.txt", "r"); //open resume file
	FILE *fp2 = fopen("C:\\MyFiles\\Keywords.txt", "r"); //open keyword file


    
    char keyword[15][20] = { '\0' }; // array used to store keyword characters
	if (fp1 == NULL || fp2 == NULL) // if an error occurrs, a notification will appear
	{
		printf("ERROR: The files could not be opened!");
		exit(-1);
	}

	keywordGenerator(fp1, fp2, keyword); //call compareFiles


	fclose(fp1); // close resume file
	fclose(fp2); // close keyword file
	return 0;
}
