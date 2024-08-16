/*C Program to Find Prefix Sum in a
Fixed Sized Array(Heap Allocation)*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*Decalaring Global Variables*/
long long unsigned int capacity, size;
int *arr;

/*Function to Create a Fixed Sized
Array using Heap Allocation*/
short unsigned int create_a_fixed_sized_array(void)
{
    /*User Input for capacity*/
    printf("Enter the Capacity of Array:");
    scanf("%llu", &capacity);
    /*User is advised to enter a Non-Negative Integer that is
    greater than or equal to 0 and less than (2 raised to power 64)
    as capacity otherwise the result will not be as predicted*/

    /*Checking for bounds for capacity*/
    if(capacity>ULLONG_MAX)
    {
        printf("%llu is an Invalid Input for Capacity!\n", capacity);
        return 0;
    }

    /*User Input for size*/
    printf("Enter the Size of Array:");
    scanf("%llu", &size);
    /*User is advised to enter a Non-Negative Integer that is
    greater than or equal to 0 and less than (2 raised to power 64)
    as size otherwise the result will not be as predicted*/

    /*Checking for bounds for size*/
    if(size>ULLONG_MAX)
    {
        printf("%llu is an Invalid Input for size!\n", size);
        return 0;
    }

    /*Comparison of size and capacity*/
    if(size>capacity)
    {
        printf("Size can't be greater than Capacity!\n");
        return 0;
    }

    /*Allocating Memory to Array*/
    arr=(int *)malloc(capacity*sizeof(int));

    /*Checking for Memory Allocation*/
    if(arr==NULL)
    {
        printf("Memory Allocation Failed!\n");
        return 0;
    }

    /*Taking the Elements of Array as User Input*/
    printf("Enter %llu Elements for Array:\n", size);
    for(long long unsigned int i=0; i<size; i++)
    {
        printf("Enter Element %llu of Array:", i+1);
        scanf("%d", &arr[i]);
    }
    return 1;
}

/*Function to Display Elements of Array: Display Function*/
void display(void)
{
    /*Displaying the Elements of Array: Traversing an Array*/
    printf("The Elements of Array are:\n");
    for(long long unsigned int i=0; i<size; i++)
    printf("Element %llu of Array is:%d\n", i+1, i[arr]);
}

/*Function to Find Prefix Sum*/
int prefix_sum(long long unsigned int start, long long unsigned int end)
{
    int result=0;
    /*We are making a small assumption that the sum of integer elements
    of the array is within the bound of integer, that is an integer*/
    for(long long unsigned int i=start; i<=end; i++)
    result+=arr[i];
    return result;
}

/*Driver Function(Code)*/
int main()
{
    if(!create_a_fixed_sized_array())
    printf("Array Creation Failed!");
    else
    {
        display();
        long long unsigned int start, end;
        printf("Enter the Starting and Ending Index for Prefix Sum:");
        scanf("%llu%llu", &start, &end);
        /*User is advised to enter Non-Negative Integers that are greater
        than or equal to 0 and less than (2 raised to power 64) as starting
        and ending indices otherwise the result will not be as predicted*/
        if(start>ULLONG_MAX)
        printf("%llu in an Invalid Input for Starting Index!", start);
        else if(end>ULLONG_MAX)
        printf("%llu in an Invalid Input for Ending Index!", end);
        else if(start>end)
        printf("%llu as Starting Index can't be greater than %llu as Ending Index!", start, end);
        else
        printf("The Prefix Sum of the Array from Index %llu to %llu is:%d", start, end, prefix_sum(start, end));
    }
    return 0;
}

