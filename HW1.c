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

char forbidrepeats(char *password);
char let_num_spec(char *password);
char min_max(char *password, int max, int min, int linecount, bool file);
int optional_Tests(char *password, int minTests);

int main()
{
    int maxPass;
    int minPass;
    bool passPhrases = true; 
    bool optTests = true;
    bool strong_pass = true;
    int passPhrase_len;
    int optTest_min;
    int failed_tests = 0;
    int passed_tests = 0;
    char str[MAXLINE];
    char total_file[MAXLINE][MAXLEN];
    char holder[MAXLEN];
    char holder2[MAXLEN];
    char holder3[MAXLEN];
    char holder4[MAXLEN];
    int line_count = 0;

    FILE *passFile; 

    passFile = fopen("Proposed Passwords #2.txt", "r");

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

    if(atoi(total_file[4]) == 1)
    {
        optTest_min = atoi(total_file[5]);
    }
    else
    {
        optTests = false;
    }

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
    printf("Required tests:\n\n");

    //Enforce min and max length
    //Forbid repeats... 
    //Must contain letters, numbers and symbols

   
    if(optTests == 1)
    {
        for(int i = 6; i < line_count; i++)
        { 
            printf("Proposed password: %s\n", total_file[i]);

            //strcpy(holder3, total_file[i]);
            //min_max(holder3, maxPass, minPass, line_count, optTests);
            //printf("\n");
           // strcpy(holder, total_file[i]);
           // forbidrepeats(holder);
           // printf("\n");
           // strcpy(holder2, total_file[i]);
            //let_num_spec(holder2);
           // printf("\n");
            strcpy(holder4, total_file[i]);
            optional_Tests(holder4, optTest_min);
        }
    }
    else
    {
        for(int i = 4; i < line_count; i++)
        { 
            printf("Proposed password: %s\n", total_file[i]);

            strcpy(holder3, total_file[i]);
            min_max(holder3, maxPass, minPass, line_count, optTests);
            printf("\n");
            strcpy(holder, total_file[i]);
            forbidrepeats(holder);
            printf("\n");
            strcpy(holder2, total_file[i]);
            let_num_spec(holder2);
        }
    }
    
    

    //Optional Tests

    // Must contain one lowercase letter
    // Must contain one uppercase letter
    // Must contain at least two digits
    // contain at least 2 special characters


    if(strong_pass == false)
        printf("Strong? --> false.\n");
    else
        printf("Strong? --> passed.\n");
   


    fclose(passFile);
    return 0;

}

char forbidrepeats(char *password)
{
    char checker = password[0];
    int counter = 1;
    for(int i = 1; i < strlen(password); i++)
    {
        if(checker == password[i])
        {
            counter++;
            if(counter == 3)
            {
                printf("Too many repeated characters.\n");
                break;
            }
        }
        else
        {
            checker = password[i];
            counter = 1;
        }
    }
     
}

char let_num_spec(char *password)
{
    bool spec_char = false;
    bool letters = false;
    bool numbers = false;

    for(int i = 0; i < strlen(password)+1; i++)
    {
        if(password[i] >= 'a' && password[i] <= 'z')
        {
            letters = true;
        }
        if(password[i] >= '0' && password[i] <= '9')
        {
            numbers = true;
        }

        if(password[i] >= 33 && password[i] <= 47 || password[i] >= 58 && password[i] <= 64 || password[i] >= 91 && password[i] <= 96 || password[i] >= 123 && password[i] <= 126)
        {
            spec_char = true;
        }
    }
    
    if(spec_char == true && numbers == true && letters == true)
        printf("passed.\n");
    else
        printf("The password lacks either a special character, number or letter.\n");
        
}

char min_max(char *password, int max, int min, int linecount, bool file)
{
    if(strlen(password) >= max)
    {
        printf("The password must be fewer than %d characters.\n", max);
    }   
    if(strlen(password) <= min)
    {
        printf("The password must be at least %d characters long.\n", min);
    }

}

int optional_Tests(char *password, int minTests)
{
    bool passes1 = false;
    bool fails1 = false;
    bool fails2 = false;
    bool fails3 = false;
    bool passes2 = false;
    bool passes3 = false;
    int is_digit = 0; 
    int is_special = 0;
    int pass_counter = 0;
    int fail_counter = 0;

    //printf("%d the min\n", minTests);

    for(int i = 0; i < strlen(password); i++)
    {
        if(password[i] >= 'a' && password[i] <= 'z' || password[i] >= 'A' && password[i] <= 'Z')
        {
            passes1 = true;
        }
        if(password[i] >= '0' && password[i] <= '9')
        {
            is_digit++;
            
        }
        if(password[i]>= 33 && password[i] <= 47 || password[i] >= 58 && password[i] <= 64 || password[i] >= 91 && password[i] <= 96 || password[i] >= 123 && password[i] <= 126)
        {
            is_special++;
             
        }
    }

    if(is_digit >= 2)
    {
        passes2 = true;
    }
    else
    {
        fails2 = true;
    }

    if(is_special >= 2)
    {
        passes3 = true;
    }
    else
    {
        fails3 = true;
    } 

    if(passes1 == true)
    {
        pass_counter++;
    }
    if(passes2 == true)
    {
        pass_counter++;
    }
    if(passes3 == true)
    {
        pass_counter++;
    }

    if(fails1 == true)
    {
        fail_counter++;
    }
    if(fails2 == true)
    {
        fail_counter++;
    }
    if(fails3 == true)
    {
        fail_counter++;
    }
    printf("passlowercase %d | pass digit %d | pass special %d | failcase %d | fail digit %d | fail special %d | isdigit %d | is special %d\n", passes1, passes2, passes3, fails1, fails2, fails3, is_digit, is_special);
    printf("%d pass counter %d fail counter\n", pass_counter, fail_counter);
}