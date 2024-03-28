#include <stdio.h>
struct students
{
    char roll[10];
    char name[100];
    char address[100];
    int age;
    float average_marks;
};
void print(struct students s[])
{
    for (int i = 0; i < 6; i++)
    {
        printf("Roll number: %s", s[i].roll);
        printf("Name: %s", s[i].name);
        printf("Address: %s", s[i].address);
        printf("Age: %d", s[i].age);
        printf("average_marks: %d", s[i].average_marks);
    }
}
int main()
{
    struct students a[5];
    for (int i = 0; i < 6; i++)
    {
        printf("For the student number %d \n",i);
        printf("Roll number: ");
        gets(a[i].roll);
        printf("Name: ");
        gets(a[i].name);
        printf("Address ");
        gets(a[i].address);
        printf("Age: ");
        scanf("%d", &a[i].age);
        printf("Average Marks: ");
        scanf("%f", &a[i].average_marks);
    }
    print(a);
    return 0;
}

















