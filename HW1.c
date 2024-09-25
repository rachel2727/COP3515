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

int forbidrepeats(char *password, int test_stats);
int let_num_spec(char *password, int test_stats);
int min_max(char *password, int max, int min, int test_stats,  bool passphrases);
int optional_Tests(char *password, int minTests, int total_stats);
bool pass_phrases(char *password, bool passphrase, int max);
bool pass_fail(int opt_passes, int req_passes);

int main()
{
    int maxPass;
    int minPass;
    bool passPhrases = true; 
    bool optTests = true;
    bool strong_pass = false;
    int passPhrase_len;
    int optTest_min;
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
    

    //Enforce min and max length
    //Forbid repeats... 
    //Must contain letters, numbers and symbols
    int test = 0;
    int sum = 0;
    int failed_tests = 0;
    int opt_fails = 0;
    int req_fails = 0;
    int total_failed = 0;
   
    if(optTests == 1)
    {
        for(int i = 6; i < line_count; i++)
        { 
            printf("Proposed password: %s\n", total_file[i]);

            printf("Required tests:\n");

            test = 0;
            req_fails = 0;
            strcpy(holder, total_file[i]);
            test = forbidrepeats(holder, passed_tests);

            if(test == 1)
            {
                req_fails = 1;
            }
            total_failed += req_fails;

            test = 0;
            req_fails = 0;
            strcpy(holder2, total_file[i]);
            test = let_num_spec(holder2, passed_tests);

            if(test == 1)
            {
                req_fails = 1;
            }
            total_failed += req_fails;

            test = 0;
            req_fails = 0;
            strcpy(holder3, total_file[i]);
            test = min_max(holder3, maxPass, minPass, passed_tests, passPhrases);

            if(test == 1)
            {
                req_fails = 1;
            }
            total_failed += req_fails;

            printf("\nOptional Tests: \n");

            test = 0;
            req_fails = 0;
            strcpy(holder4, total_file[i]);
            test = optional_Tests(holder4, optTest_min, passed_tests);

            opt_fails = test;
            total_failed += opt_fails;

            printf("total failed: %d\n", total_failed);
            passed_tests = 7 - total_failed;
            printf("total passed: %d\n", passed_tests);

            if(passed_tests > total_failed)
                strong_pass = true;
            else{
                strong_pass = false;
            }

            if(strong_pass == false)
                printf("Strong? --> false.\n");
            else
                printf("Strong? --> passed.\n");

            total_failed = 0;
            passed_tests = 0;

            printf("\n");
        }
    }
    else
    {
        for(int i = 4; i < line_count; i++)
        { 
            printf("Proposed password: %s\n", total_file[i]);

            printf("Required tests:\n");
            
            strcpy(holder3, total_file[i]);
            test = min_max(holder3, maxPass, minPass, passed_tests, passPhrases);

            if(test == 1)
            {
                failed_tests = 1;
            }
            total_failed += failed_tests;

            printf("\n");

            test = 0;
            failed_tests = 0;
            strcpy(holder, total_file[i]);
            test = forbidrepeats(holder, passed_tests);

            if(test >= 1)
            {
                failed_tests = 1;
            }
            total_failed += failed_tests;

            printf("\n");

            test = 0;
            failed_tests = 0;
            strcpy(holder2, total_file[i]);
            test = let_num_spec(holder2, passed_tests);

            if(test >= 1)
            {
                failed_tests = 1;
            }
            total_failed += failed_tests;

            printf("total failed: %d\n", total_failed);
            passed_tests = 3 - total_failed;
            printf("total passed: %d\n", passed_tests);

            if(passed_tests > total_failed)
                strong_pass = true;
            else{
                strong_pass = false;
            }
            
            if(strong_pass == false)
                printf("Strong? --> false.\n");
            else
                printf("Strong? --> passed.\n");
   

            total_failed = 0;
            passed_tests = 0;

            printf("\n");
        }
    }
    

    fclose(passFile);
    return 0;

}

int forbidrepeats(char *password, int test_stats)
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
                test_stats++;
                break;
            }
        }
        else
        {
            checker = password[i];
            counter = 1;
        }
    }
    return test_stats;
     
}

int let_num_spec(char *password, int test_stats)
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
    else{
        printf("The password lacks either a special character, number or letter.\n");
        test_stats++;
    }
    
    return test_stats;

}

int min_max(char *password, int max, int min, int test_stats, bool passphrases)
{
    int pPhrase_allowed;

    if(strlen(password) >= max)
    {
        if(strlen(password) >= 20)
            pPhrase_allowed = pass_phrases(password, passphrases, max);
            if(pPhrase_allowed > 0)
                test_stats--;
        else    
            printf("The password must be fewer than %d characters.\n", max);
    }
    else
    {
        test_stats++;
    }   
    if(strlen(password) <= min)
    {
        printf("The password must be at least %d characters long.\n", min);
    }
    else
    {
        test_stats++;
    }

    return test_stats;

}

int optional_Tests(char *password, int minTests, int total_stats)
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
    int is_letter = 0;
    int min = 0;

    for(int i = 0; i < strlen(password); i++)
    {
        if(password[i] >= 'a' && password[i] <= 'z' || password[i] >= 'A' && password[i] <= 'Z')
        {
            if(min < minTests)
            {
                min++;
            }
            passes1 = true;
            is_letter++;
        }
        if(password[i] >= '0' && password[i] <= '9')
        {
            if(min <= minTests)
            {
                min++;
            }
            is_digit++;
            
        }
        if(password[i]>= 33 && password[i] <= 47 || password[i] >= 58 && password[i] <= 64 || password[i] >= 91 && password[i] <= 96 || password[i] >= 123 && password[i] <= 126)
        {
            if(min <= minTests)
            {
                min++;
            }
            is_special++;
             
        }
    }

    if(is_letter == 0)
    {
        fails1 = true;
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
    if(min >= minTests && pass_counter >= minTests)
    {
        printf("Strong password for opt tests.\n");
    }

    printf("Total optional tests passed: %d\n", fail_counter);

    return fail_counter;
}

bool pass_phrases(char *password, bool passphrase, int max)
{
    if(passphrase == true)
    {
        printf("Pass phrases allowed.\n");
    }
    else{
        printf("The password must be fewer than %d characters.\n", max);
    }

    return passphrase;
}