#include<stdio.h>
struct time{
    int day;
    int month;
    int years;
};
int compare(struct time a,struct time b)
{
    if(a.years>b.years)
        return 1;
    else if(a.years<b.years)
        return -1;
    else if(a.month>b.month)
        return 1;
    else if(a.month<b.month)
        return -1;
    else if(a.day<b.day)
        return -1;
    else if(a.day>b.day)
        return 1;           
    else
        return 0;     
}
int main()
{
    struct time a;
    printf("Year of first structure ");
    scanf("%d",&a.years);
    printf("Months of first structure ");
    scanf("%d",&a.month);
    printf("Days of first structure ");
    scanf("%d",&a.day);
    struct time b;
    printf("Year of second structure ");
    scanf("%d",&b.years);
    printf("Months of second structure ");
    scanf("%d",&b.month);
    printf("Days of second structure ");
    scanf("%d",&b.day);
    printf("%d",compare(a,b));
    return 0;
}