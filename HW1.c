/*
COP 3515 - Fall Semester 2024

Homework #1: Password Strength Meter

Rachel Singh
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 10000
#define MINLEN 12
#define MAXLINE 100

int main()
{
    int maxPass;
    int minPass;
    bool passPhrases = true; 
    bool optTests = true;
    int passPhrase_len;
    int optTest_min;
    int failed_tests = 0;
    int passed_tests = 0;
    char str[MAXLINE];
    char total_file[MAXLINE][MAXLEN];
    int line_count = 0;

    FILE *passFile; 

    passFile = fopen("Proposed passwords #1.txt", "r");

    if(passFile == NULL)
    {
        printf("There was an error.\n");
        return 1;
    }    

    printf("Processing file #1...\n\n");

    while(fgets(str, MAXLEN, passFile) != NULL)
    {   
        if(*str == '\n')
        {
            continue;
        }
        strcpy(total_file[line_count], str);
        line_count++;
    }

    //for(int i = 0; i < line_count; i++)
    //    printf("%s", total_file[i]);
        
    maxPass = atoi(total_file[0]);
    minPass = atoi(total_file[1]);

    if(atoi(total_file[2]) == 1)
    {
        passPhrase_len = atoi(total_file[3]);
    }
    else
    {
        passPhrases = false;
    }

    //printf("\ntotal file 4: %s\n", total_file[4]);
    if(atoi(total_file[4]) == 1)
    {
        optTest_min = atoi(total_file[5]);
    }
    else
    {
        optTests = false;
    }
   // printf("%d opt tests new \n", optTests);


    printf("Maximum password length: %d\n", maxPass);
    printf("Minimum password length: %d\n", minPass);

     if(passPhrases == false)
        printf("Pass phrases are NOT allowed.\n");
    else
        printf("Pass phrases are permitted.\n");
    
    if(optTests == false)
        printf("Optional Tests are NOT allowed.\n");
    else   
        printf("Optional Tests are permitted.\n");


    printf("\n");

    // Required tests

    //Enforce min and max length
   
    if(optTests == 1)
    {
        for(int i = 6; i < line_count; i++)
        { 
            printf("Proposed password: %s\n", total_file[i]);
            if(strnlen(total_file[i], MAXLEN) > maxPass)
            {
                printf("The password must be fewer than %d characters.\n", maxPass);
                failed_tests++;
            }
            if(strnlen(total_file[i], MAXLEN) < minPass)
            {
                printf("The password must be at least %d characters long.\n", minPass);
                failed_tests++;
            }
        }
    }
    else
    {
        for(int i = 4; i < line_count; i++)
        { 
            printf("Proposed password: %s", total_file[i]);
            if(strnlen(total_file[i], MAXLEN) > maxPass)
            {
                printf("The password must be fewer than %d characters.\n", maxPass);
                failed_tests++;
            }
            if(strnlen(total_file[i], MAXLEN) < minPass)
            {
                printf("The password must be at least %d characters long.\n", minPass);
                failed_tests++;
            }
        }
    }
    
    //Forbid repeats

    for(int i = 4; i < line_count; i++)
    {
        for(int j = 0; j < MAXLEN; j++)
        {
            
        }
    }
    //Must contain letters, numbers and symbols


    //Optional Tests

    // Must contain one lowercase letter
    // Must contain one uppercase letter
    // Must contain at least two digits
    // contain at least 2 special characters
    
    



   // printf("%d max\n", maxPass);
   // printf("%d min\n", minPass);
    //printf("%d passphrase\n", passPhrases);
    //printf("%d opt tests\n", optTests);

   


    fclose(passFile);
    return 0;

}