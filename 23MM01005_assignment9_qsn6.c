#include <stdio.h>
#include <string.h>
#include <math.h>
struct student
{
    char name[100];
    int roll_no;
    float percentage;
};
struct student s[100];
int number_students;
void sort_roll();
void insert()
{
    int rollno;
    char name[100];
    float perc;
    if (number_students < 100)
    {
        printf("Enter name: ");
        gets(s[number_students].name);
        printf("Enter rollno: ");
        scanf("%d", &s[number_students].roll_no);
        printf("Enter perc: ");
        scanf("%f", &s[number_students].percentage);
        number_students++;
        sort_roll();
    }
    else
        printf("Student list is full \n");
}
void view_student()
{
    if (number_students > 0)
    {
        printf("\nStudentslist\n");
        printf("\n");
        printf("%-20s%-30s%-20s%-20s\n", "Sr no.", "Name", "Roll no.", "Percentage");
        printf("\n");
        for (int i = 0; i < number_students; i++)
        {
            printf("%-18d: %-30s%-20d%-20.2f\n", i + 1, s[i].name, s[i].roll_no, s[i].percentage);
        }
    }
    else
        printf("No students to display\n");
}
void sort_roll()
{
    int size = number_students;
    int check = 0;
    while (size != 0)
    {
        for (int i = 0; i < size - 1; i++)
        {
            check = 1;
            if (s[i].roll_no > s[i + 1].roll_no)
            {
                struct student temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
                check = 0;
            }
        }
        if (check)
            return;
        size--;
    }
}
void sort_name()
{
    int size = number_students;
    int check = 0;
    while (size != 1)
    {
        int val = 0;
        for (int i = 0; i < size - 1; i++)
        {
            check = 1;
            if (strcmp(s[i].name, s[i + 1].name) == 1)
            {
                struct student temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
                check = 0;
            }
        }
        if (check)
        {
            return;
        }
        size--;
    }
}
char *findOne(char *str)
{
    int len=strlen(str);
    for (int i = 0; i < number_students; i++)
    {
        char *str2 = s[i].name;
        int flag = 0;
        for (int j = 0; j < len; j++)
        {
            if (str[i] == str2[i])
            {
                flag = 1;
            }
            else
                flag = 0;
        }
        if (flag == 1)
        {
            return s[i].name;
        }
    }
    return '\0';
}
void specs(float *arr)
{
    arr[0] = number_students;
    float max = s[0].percentage, min = s[0].percentage, mean = 0, std_deviation = 0;
    for (int i = 0; i < number_students; i++)
    {
        mean += s[i].percentage ;
        if (s[i].percentage > max)
        {
            max = s[i].percentage;
        }
        if (s[i].percentage < min)
        {
            min = s[i].percentage;
        }
    }
    mean /= number_students;
    arr[1] = max;
    arr[2] = min;
    arr[3] = mean;
    for (int i = 0; i < number_students; i++)
    {
        std_deviation += (s[i].percentage - mean) * (s[i].percentage - mean);
    }
    std_deviation /= number_students;
    std_deviation = sqrt(std_deviation);
    arr[4] = std_deviation;
}
void delete(int num)
{
    int index = -1;
    for (int i = 0; i < number_students; i++)
    {
        if (s[i].roll_no == num)
        {
            index = i;
        }
    }
    if (index != -1)
    {
        for (int i = index; i < number_students; i++)
        {
            s[i] = s[i + 1];
        }
        number_students--;
    }
    else
        printf("Given roll no. does not exists\n");
}
int main()
{
    int choice;
    do
    {
        printf("\nStudent-list Menu\n");
        printf("0. Exit\n");
        printf("1. Insert Student\n");
        printf("2. View Student\n");
        printf("3. Sort Students by name\n");
        printf("4. Find one\n");
        printf("5. Specs\n");
        printf("6. Delete\n");
        printf("Enter your choice(pls enter the number): ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 0:
            printf("Exiting Application. Goodbye!\n");
            break;
        case 1:
            insert();
            sort_roll();
            break;
        case 2:
            view_student();
            break;

        case 3:
            sort_name();
            break;
        case 4:
        {
            char str[30];
            printf("Enter the part of the name : ");
            gets(str);
            char *str2 = findOne(str);
            printf("The name which starts with the given part is : ");
            puts(str2);
            break;
        }
        case 5:
        {
            float arr[5];
            specs(arr);
            printf("Number of records in the database :%.0f\n", arr[0]);
            printf("Highest percentage :%.2f\n", arr[1]);
            printf("Lowest percentage :%.2f\n", arr[2]);
            printf("Mean :%.2f\n", arr[3]);
            printf("Standard deviation :%.2f\n", arr[4]);
            break;
        }
        case 6:
        {
            int num;
            printf("Enter the roll no. that you want to remove :");
            scanf("%d", &num);
            delete (num);
            break;
        }
        }
    } while (choice != 0);
    return 0;
}