#include<stdio.h>
struct address
{
    char street[100];
    char city[100];
    int zip_code;
};
struct person
{
    char name[100];
    struct address a;
};

int main()
{
    struct person p1={"Avirat Joshi",{"Pimpri","Pune",411018}};
    printf("Name: %s\n", p1.name);
    printf("Street: %s\n", p1.a.street);
    printf("City: %s\n", p1.a.city);
    printf("Zip Code: %d\n", p1.a.zip_code);
    return 0;
}