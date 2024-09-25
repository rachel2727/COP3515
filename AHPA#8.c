// Rachel Singh
// Adv Program Design
// AHPA # 8: What's The Temperature?

#include <stdio.h>

float f_to_c(int temp)
{
    int filler = temp; 
    temp = (temp-32)/1.8;
    printf("Given a Fahrenheit temperature of %d.00, the equalvilant Celcius temperature is %.2f\n", filler, temp);
}

float c_to_f(int temp)
{
    int filler = temp; 
    temp = temp * 1.8 +32;
    printf("Given a Celcius temperature of %d.00, the equalvilant Fahrenheit temperature is %.2f\n", filler, temp);
}

int main()
{
    char user_temp;
    int degree;

    printf("What type of temperature will you be entering (c/f)\n");
    scanf("%c", &user_temp);

    printf("What temperature value should be converted?\n");
    scanf("%d", &degree);

    if(user_temp == 'c')
        c_to_f(degree);
    else
        f_to_c(degree);

    return 0;
}

    



