/*C Program to Calculate the Floor of 
Square Root of a Positive Integer*/

#include<stdio.h>
#include<math.h>
#include<limits.h>

/*Declaring Global Variables*/
long long signed int num;
double num_d;
long long signed int floor_sq_root;

/*Function to take user input*/
short unsigned int userinput()
{
    /*User Input for a Positive Integer*/
    printf("Enter a Positive Integer:");
    scanf("%lld", &num);
    /*User is advised to enter a Non-Negative Integer that is
    greater than or equal to 0 and less than (2 raised to power 63)
    as num otherwise the result will not be as predicted*/

    /*Checking for bounds for num*/
    if(num<=0 || num>LLONG_MAX)
    {
        printf("Invalid Input for num!\n");
        return 0;
    }
    num_d=num;
    return 1;
}

/*Function to Calculate Floor of Square Root of num-Using Newton Raphson Method*/
void floor_square_root()
{
    double r=num_d, p, tolerance=1e-7;
    while(1)
    {
        p=r;
        r=r-(((r*r)-num_d)/(2*r));
        if(fabs(r-p)<tolerance)
        break;
    }
    floor_sq_root=(long long signed int)(floor(r));
}

/*Driver Function(Code)*/
int main()
{
    if(userinput())
    {
        floor_square_root();
        printf("The Floor of Square Root of %lld is:%lld", num, floor_sq_root);
    }
    else
    printf("You have probably entered an invalid integer!");
    return 0;
}