// Rachel Singh
// COP 3515 Adv Program Design
// AHPA # 4: The C ATM Machine

#include <stdio.h>

int main(void)
{
    // initialize a and b array, checking and savings for a and b

    int abATM[2][2] = {500, 1000, 750, 325};
    int checking;
    int savings;
    int difference;
    int withdraw;

    char acctType;
    char name; 

    //testing
    /*
    for (int i = 0; i <2; i++){
        for(int j = 0; j <2; j++){
            printf("%d \n", abATM[i][j]);
        }
    }

    */
    
    printf("Enter your name:\n");
    scanf("%c", &name);

    if(name == 'a')
    {
        checking = abATM[0][0];
        savings = abATM[0][1]; 
    }
    else
    {
        checking = abATM[1][0];
        savings = abATM[1][1];
    }

    scanf("%c", &acctType);
    printf("Would you like to withdraw from (c)hecking or (s)avings?\n");
    scanf("%c", &acctType);

    switch (acctType){
        case 'c': difference = checking;
        break;
        case 's': difference = savings;
        break;
    }

    printf("How much would you like to withdraw?\n");
    scanf("%d", &withdraw);

    if(withdraw > 200)
    {
        printf("You can only withdraw up to $200.\n");
    }
    
    printf("Amount in account to be withdrawn from: $%d\n", difference);

    if(withdraw > 100 )
    {
        printf("$100 bill\n");
        difference = difference - 100;
        withdraw = withdraw - 100;
    }
    
    if(withdraw >= 100)
    {
        printf("$100 bill\n");
        difference = difference - 100;
        withdraw = withdraw - 100;
    }

    if(withdraw > 50)
    {
        printf("$50 bill\n");
        difference = difference - 50;
        withdraw = withdraw - 50;
    }

    if(withdraw > 20)
    {
        printf("$20 bill\n");
        difference = difference - 20;
        withdraw = withdraw - 20;
    }

    if(withdraw > 10)
    {
        printf("$10 bill\n");
        difference = difference - 10;
        withdraw = withdraw - 10;
    }

    if(withdraw > 5)
    {
        printf("$5 bill\n");
        difference = difference - 5;
        withdraw = withdraw - 5; 
    }

    if(withdraw < 5 && withdraw != 0)
    {
        for(int i = withdraw; i > 0; i--)
        {
            printf("$1 bill\n");
            difference = difference - 1;
            withdraw = withdraw - 1;        
        }
    }

    printf("Withdrawl is here: %d\n", withdraw);

    printf("Amount in account after withdrawal: $%d\n", difference);

    return 0;
}