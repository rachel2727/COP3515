// Rachel Singh
// Adv Program Design
// AHPA #6: Multiplication Table

#include <stdio.h>

#define MULT 13

int main()
{

    int guessAnswer = (rand() % 10) + 1;
    int userGuess; 

    printf("Multiplication Table:");

    for(int i = 1; i < MULT; i++){
        printf("\n");
        if(i < 10 || i*2 < 10 || i*3 < 10 || i*4 < 10 && i*5 < 10 && i*6 < 10 && i*7 < 10 && i*8 < 10 && i*9 < 10 && i*10 < 10 && i*11 < 10 && i*12 <10)
            printf("%d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d", i, i*2, i*3, i*4, i*5, i*6, i*7, i*8, i*9, i*10, i*11, i*12);
        if(i >= 10 && i*2 >= 10 && i*3 >= 10 && i*4 >=10 && i*5 >= 10 && i*6 >=10 && i*7 >=10 && i*8 >= 10 && i*9 >= 10 && i*10 >= 10 && i*11 >= 10 && i*12 >= 10)
            printf("%d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d", i, i*2, i*3, i*4, i*5, i*6, i*7, i*8, i*9, i*10, i*11, i*12);
    }

    printf("\n");
    
    do{
        printf("Enter your guess (1 - 10): \n");
        scanf("%d", &userGuess);
        
        if (userGuess > guessAnswer)
            printf("Too high!\n");
        else if(userGuess < guessAnswer)
            printf("Too low!\n");

    } while (guessAnswer != userGuess);
    
    printf("You guessed it!\n");

    guessAnswer = 0;

}