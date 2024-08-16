/*C Program to Left Rotate a Fixed
Sized Array(Heap Allocation) by d*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*Decalaring Global Variables*/
long long signed int capacity, size;
int *arr;
short unsigned int flag=1;

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

/*Function to Left Rotate an Array by d*/
void left_rotate_by_d(long long signed int d)
{
    /*Normalizing the value of d*/
    d%=size;
    
    /*Creating a Temporary Array for storing d elements*/
    int *temp;
    /*Allocating Memory to Array*/
    temp=(int *)malloc(d*sizeof(int));

    /*Checking for Memory Allocation*/
    if(temp==NULL)
    {
        printf("Memory Allocation Failed for Temporary Array!\n");
        flag=0;
    }

    for(long long signed int i=0; i<d; i++)
    temp[i]=arr[i];
    for(long long signed int i=d; i<size; i++)
    arr[i-d]=arr[i];
    for(long long signed int i=0; i<d; i++)
    arr[size-d+i]=temp[i];
}

/*Driver Function(Code)*/
int main()
{
    if(!create_a_fixed_sized_array())
    printf("Array Creation Failed!");
    else
    {
        long long signed int d;
        printf("Enter the value of d by which you want to Left Rotate the Array:");
        scanf("%lld", &d);
        printf("Before Left Rotating by %lld the Array is:\n", d);
        display();
        left_rotate_by_d(d);
        if(!flag)
        printf("Can't Rotate the Array!");
        else
        {
            printf("After Left Rotating by %lld the Array is:\n",d);
            display();
        }
    }
    return 0;
}

