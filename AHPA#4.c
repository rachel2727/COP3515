// Rachel Singh
// COP 3515 Adv Program Design
// AHPA # 4: The C ATM Machine

#include <stdio.h>

int main(void)
{
    // initialize a and b array, checking and savings for a and b, and variables to keep track of balances

    int abATM[2][2] = {500, 1000, 750, 325};
    int checking;
    int savings;
    int difference;
    int withdraw;

    char acctType;
    char name; 
    
    // specifies the user

    printf("Enter your name:\n");
    scanf("%c", &name);

    // enters money data according to name given

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

    // asks for specific account type for withdrawal

    scanf("%c", &acctType);
    printf("Would you like to withdraw from (c)hecking or (s)avings?\n");
    scanf("%c", &acctType);

    switch (acctType){
        case 'c': difference = checking;
        break;
        case 's': difference = savings;
        break;
    }

    // asks how much to withdraw

    printf("How much would you like to withdraw?\n");
    scanf("%d", &withdraw);

    // if statement if the withdrawal is above $200

    if(withdraw >= 201)
    {
        printf("You can only withdraw up to $200.\n");
        return 0;
    }
    
    printf("Amount in account to be withdrawn from: $%d\n", difference);

    // if statements to print and subtract differences in the acct.

    if(withdraw > 100)
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

    if(withdraw > 50 || withdraw >= 50)
    {
        printf("$50 bill\n");
        difference = difference - 50;
        withdraw = withdraw - 50;
    }

    if(withdraw > 20 || withdraw >= 20)
    {
        printf("$20 bill\n");
        difference = difference - 20;
        withdraw = withdraw - 20;
    }

    if(withdraw > 10 || withdraw >= 10)
    {
        printf("$10 bill\n");
        difference = difference - 10;
        withdraw = withdraw - 10;
    }

    if(withdraw > 5 || withdraw >= 5)
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

    // shows the final amount for the acct.

    printf("Amount in account after withdrawal: $%d\n", difference);

    return 0;
}