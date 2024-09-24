// Rachel Singh
// Adv Program Design
// AHPA #8

#include <stdio.h>
#include <stdbool.h>

#define NAMELEN 10
int main()
{
    struct uni{
        char stu_name[NAMELEN];
        int age;
        int uNum;
        float gpa;
        bool lcampus;
        bool paid;
    };

    struct uni student1 = {"Rachel", 21, 123456, 4.0, true, true};

    struct uni student2;

    student2 = student1;

    student2.lcampus = false;
    student2.paid = false;

    printf("Student 1's info:\n name: %s, age: %d, uNum: %d, gpa: %.2f, living on campus %d, paid tuition %d\n", 
    student1.stu_name, student1.age, student1.uNum, student1.gpa, student1.lcampus, student1.paid);

    printf("Student 2's info:\n name: %s, age: %d, uNum: %d, gpa: %.2f, living on campus %d, paid tuition %d\n", 
    student2.stu_name, student2.age, student2.uNum, student2.gpa, student2.lcampus, student2.paid);
    return 0;
}