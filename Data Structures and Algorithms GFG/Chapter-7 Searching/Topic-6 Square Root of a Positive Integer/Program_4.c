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

/*Function to Calculate Floor of Square Root of num-Using Iterative Binary Search*/
void floor_square_root()
{
    long long signed int low=1, high=num;
    /*Here we have squared a long long signed int therefore it might happen
    that it exceeds the range of long long signed int and wraps around which
    can lead to unexpected results, however in practical scenarios our num
    will not be too large thus the square of mid will also not exceed the max. range*/
    while(low<=high)
    {
        long long signed int mid=(low+high)/2;
        if((mid*mid)>num)
        high=mid-1;
        else if((mid*mid)<num)
        {
            low=mid+1;
            floor_sq_root=mid;
        }
        else
        {
            floor_sq_root=mid;
            break;
        }
    }
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