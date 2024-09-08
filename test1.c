#include <stdio.h>

int main()
{
    printf("Oh");

    enum flavors{vanilla, chocolate, mint};
    enum flavors i = vanilla;

    float price_of_flavors[3];

    printf("This is the first flavors price:\n");
    float sales;
    scanf("%f", &sales);
    price_of_flavors[i] = sales;

    

}