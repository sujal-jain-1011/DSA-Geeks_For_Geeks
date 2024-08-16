/*C Program to Solve Trapping Rainwater Problem
in an Unsorted Fixed Sized Array(Heap Allocation)*/

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

/*Function to find out max between two integers*/
int max_int(int num_1, int num_2)
{
    return (num_1>=num_2?num_1:num_2);
}

/*Function to find out min between two integers*/
int min_int(int num_1, int num_2)
{
    return (num_1<=num_2?num_1:num_2);
}

/*Function to Solve Trapping Rainwater Problem*/
int trapping_rainwater()
{
    /*Creating lmax and rmax Arrays*/
    /*Allocating memory to lamx and rmax Arrays*/
    int *lmax=(int*)malloc(size*sizeof(int));
    int *rmax=(int*)malloc(size*sizeof(int));

    /*Checking for Memory Allocation*/
    if(lmax==NULL)
    {
        printf("Memory Allocation Failed for lmax Array!\n");
        return -1;
    }
    else if(rmax==NULL)
    {
        printf("Memory Allocation Failed for rmax Array!\n");
        return -1;
    }

    /*Precomputing lmax for all the bars*/
    lmax[0]=arr[0];
    for(long long unsigned int i=1; i<size; i++)
    lmax[i]=max_int(lmax[i-1], arr[i]);
    
    /*Precomputing rmax for all the bars*/
    rmax[size-1]=arr[size-1];
    for(long long unsigned int i=size-2; i>=0; i--)
    {
        rmax[i]=max_int(rmax[i+1], arr[i]);
        if(i==0)
        break;
    }

    int result=0;
    for(long long unsigned int i=1; i<size-1; i++)
    result+=min_int(lmax[i], rmax[i])-arr[i];
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
        int result=trapping_rainwater();
        if(result!=-1)
        printf("The Total Volume of Trapped Rainwater is:%d", trapping_rainwater());
    }
    return 0;
}

