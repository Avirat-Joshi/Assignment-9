#include <stdio.h>
struct CourseRecord
{
    char first_name[50];
    char last_name[50];
    char roll_number[10];
    char department[50];
    char course_code[10];
    int marks[3];
};
float average_test_marks(struct CourseRecord cr)
{
    float avg = (float)(cr.marks[0] + cr.marks[1] + cr.marks[2]) / 3;
    return avg;
}
int pass(struct CourseRecord cr)
{
    if(cr.marks[0]>=35 && cr.marks[1]>=35 && cr.marks[2]>=35)
        return 1;
    else
        return 0;        
}
int main()
{
    struct CourseRecord c = {"Avirat", "Joshi", "23MM01005", "Metallurgy", "CS1L001", {98, 95, 99}};
    printf("Average marks : %.2f", average_test_marks(c));
    if (pass(c))
        printf("\nPass");
    else
        printf("\nFail");
    return 0;
}