#include<stdio.h>
struct company{
    char name[100];
    char address[100];
    long long int phone;
    int number_of_employees;
};
int main()
{
    printf("Enter name of company, address, phone and number of employees ");
    struct company s;
    gets(s.name);
    gets(s.address);
    scanf("%lld",&s.phone);
    scanf("%d",&s.number_of_employees);
    printf("Name of company: %s\n" , s.name);
    printf("Address of company: %s\n" , s.address);
    printf("Phone number of company: %lld\n" , s.phone);
    printf("Number of employees of company: %d\n" , s.number_of_employees);
    return 0;
}