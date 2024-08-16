/*C Program to Left Rotate a Fixed
Sized Array(Heap Allocation) by d*/

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

/*Function to Reverse a Given Array*/
void reverse(long long unsigned int start, long long unsigned int end)
{
    long long unsigned int low=start, high=end;
    int temp;
    while(low<high)
    {
        temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        low++;
        high--;
    }
}

/*Function to Left Rotate an Array by d*/
void left_rotate_by_d(long long unsigned int d)
{
    /*Normalizing the value of d*/
    d%=size;
    
    /*Reversing first d elements*/
    reverse(0, d-1);
    /*Reversing remaining size-d elements*/
    reverse(d, size-1);
    /*Reversing the whole array*/
    reverse(0, size-1);
}

/*Driver Function(Code)*/
int main()
{
    if(!create_a_fixed_sized_array())
    printf("Array Creation Failed!");
    else
    {
        long long unsigned int d;
        printf("Enter the value of d by which you want to Left Rotate the Array:");
        scanf("%llu", &d);
        printf("Before Left Rotating by %llu the Array is:\n", d);
        display();
        left_rotate_by_d(d);
        printf("After Left Rotating by %llu the Array is:\n",d);
        display();
    }
    return 0;
}


