#include <stdio.h>

int main()
{
    int m[5][9]; //five rows nine columns, or five rows of nine values.

    const char chars[] = {'0', '1'};

    char grade = 'A';

    switch (grade) {
        case 'A': printf("Excellent\n");
                break;
        case 'B': printf("Good\n");
                break;
        case 'C': printf("Average\n");
                break;
        case 'D': printf("Poor\n");
                break;
        case 'F': printf("Failing\n");
                break;
        default: printf("Illegal grade\n");
                break;

        printf("\nAll done");
    }
}