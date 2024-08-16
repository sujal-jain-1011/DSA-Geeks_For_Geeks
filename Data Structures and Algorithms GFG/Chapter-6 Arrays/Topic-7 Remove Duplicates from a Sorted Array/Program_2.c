/*C Program to Remove Duplicates from a Fixed Sized
Array(Heap Allocation) Sorted in Non-Decreasing Order*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*Decalaring Global Variables*/
long long signed int capacity, size;
int *arr;

/*Function to Create a Fixed Sized
Array using Heap Allocation*/
short unsigned create_a_fixed_sized_array(void)
{
    /*User Input for capacity*/
    printf("Enter the Capacity of Array:");
    scanf("%lld", &capacity);
    /*User is advised to enter a Non-Negative Integer that is
    greater than or equal to 0 and less than (2 raised to power 63)
    as capacity otherwise the result will not be as predicted*/

    /*Checking for bounds for capacity*/
    if(capacity>LLONG_MAX || capacity<0)
    {
        printf("%lld is an Invalid Input for Capacity!\n", capacity);
        return 0;
    }

    /*User Input for size*/
    printf("Enter the Size of Array:");
    scanf("%lld", &size);
    /*User is advised to enter a Non-Negative Integer that is
    greater than or equal to 0 and less than (2 raised to power 63)
    as size otherwise the result will not be as predicted*/

    /*Checking for bounds for size*/
    if(size>LLONG_MAX || size<0)
    {
        printf("%lld is an Invalid Input for size!\n", size);
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
    printf("Enter %lld Elements for Array:\n", size);
    for(long long unsigned int i=0; i<size; i++)
    {
        printf("Enter Element %lld of Array:", i+1);
        scanf("%d", &arr[i]);
    }
    return 1;
}

/*Function to Display Elements of Array: Display Function*/
void display(void)
{
    /*Displaying the Elements of Array: Traversing an Array*/
    printf("The Elements of Array are:\n");
    for(long long signed int i=0; i<size; i++)
    printf("Element %lld of Array is:%d\n", i+1, i[arr]);
}

/*Function to Check if an Array is Sorted 
in Non-Deceasing Order or not*/
short unsigned int check_for_sorted()
{
    for(long long signed int i=1; i<size; i++)
    {
        if(arr[i]<arr[i-1])
        return 0;
    }
    return 1; 
}

/*Function to Remove Duplicates from an 
Array Sorted in Non-Decreasing Order*/
void remove_duplicates()
{
    int *temp=(int *)malloc(size*(sizeof(int)));
    long long signed int result=1;
    temp[0]=arr[0];
    for(long long signed int i=1; i<size; i++)
    {
        if(temp[result-1]!=arr[i])
        {
            temp[result]=arr[i];
            result++;
        }
    }
    for(long long signed int j=1; j<result; j++)
    arr[j]=temp[j];
    size=result;
}

/*Driver Function(Code)*/
int main()
{
    if(!create_a_fixed_sized_array())
    printf("Array Creation Failed!");
    else
    {
        display();
        if(!check_for_sorted())
        printf("The Array is Not Sorted in Non-Decreasing Order!");
        else
        {
            printf("The Array is Sorted in Non-Decreasing Order!\n");
            remove_duplicates();
            printf("After Removing Duplicates, the Array becomes:\n");
            display();
        }
    }
    return 0;
}

