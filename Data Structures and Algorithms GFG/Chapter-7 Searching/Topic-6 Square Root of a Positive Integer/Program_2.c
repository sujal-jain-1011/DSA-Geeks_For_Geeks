/*C Program to Calculate the Floor of 
Square Root of a Positive Integer*/

#include<stdio.h>
#include<limits.h>

/*Declaring Global Variables*/
long long signed int num;
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
    return 1;
}

/*Function to Calculate Floor of Square Root of num*/
void floor_square_root()
{
    long long signed int i=1;
    /*Here we have squared a long long signed int therefore it might happen
    that it exceeds the range of long long signed int and wraps around which
    can lead to unexpected results, however in practical scenarios our num
    will not be too large thus the square of i will also not exceed the max. range*/
    while(i*i<=num)
    i++;
    floor_sq_root=(i-1);
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