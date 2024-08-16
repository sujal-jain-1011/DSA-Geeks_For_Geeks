/*C Program to Find Prefix Sum and Prefix Weighted
Sum in a Fixed Sized Array(Heap Allocation)*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*Decalaring Global Variables*/
long long signed int capacity, size;
int *arr;
int *psum;
int *pwsum;

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

/*Function to Precompute Prefix Sum*/
short unsigned int precompute_prefix_sum()
{
    /*Allocating Memory to psum array*/
    psum=(int *)malloc(size*sizeof(int));
    
    /*Checking for Memory Allocation*/
    if(psum==NULL)
    {
        printf("\nMemory Allocation Failed for psum Array!\n");
        printf("Thus, can't compute Prefix Sum!\n");
        printf("Hence, returning the Lowest Possible Integer value!\n");
        return 0;
    }
    psum[0]=arr[0];
    for(long long signed int i=1; i<size; i++)
    psum[i]=psum[i-1]+arr[i];
    return 1;
}

/*Function to Find Prefix Sum*/
int prefix_sum(long long signed int start, long long signed int end)
{
    /*We are making a small assumption that the sum of integer elements
    of the array is within the bound of integer, that is an integer*/
    if(!precompute_prefix_sum())
    return INT_MIN;
    if(start==0)
    return psum[end];
    return (psum[end]-psum[start-1]);
}

/*Function to Precompute Prefix Weighted Sum*/
short unsigned int precompute_prefix_weighted_sum()
{
    /*Allocating Memory to pwsum array*/
    pwsum=(int *)malloc(size*sizeof(int));
    
    /*Checking for Memory Allocation*/
    if(pwsum==NULL)
    {
        printf("\nMemory Allocation Failed for pwsum Array!\n");
        printf("Thus, can't compute Prefix Weighted Sum!\n");
        printf("Hence, returning the Lowest Possible Integer value!\n");
        return 0;
    }
    pwsum[0]=0*arr[0];
    for(long long signed int i=1; i<size; i++)
    pwsum[i]=pwsum[i-1]+i*arr[i];
    return 1;
}

/*Function to Find Prefix Weighted Sum*/
int prefix_weighted_sum(long long signed int start, long long signed int end)
{
    /*We are making a small assumption that the sum of product of integer elements 
    with their weights of the array is within the bound of integer, that is an integer*/
    if(!precompute_prefix_weighted_sum())
    return INT_MIN;
    if(start==0)
    return pwsum[end]+psum[end];
    return ((pwsum[end]-pwsum[start-1])-(start-1)*(psum[end]-psum[start-1]));
}

/*Driver Function(Code)*/
int main()
{
    if(!create_a_fixed_sized_array())
    printf("Array Creation Failed!");
    else
    {
        display();
        long long signed int start, end;
        printf("Enter the Starting and Ending Index for Prefix Sum:");
        scanf("%lld%lld", &start, &end);
        /*User is advised to enter Non-Negative Integers that are greater
        than or equal to 0 and less than (2 raised to power 63) as starting
        and ending indices otherwise the result will not be as predicted*/
        if(start>LLONG_MAX || start<0)
        printf("%lld in an Invalid Input for Starting Index!", start);
        else if(end>LLONG_MAX || end<0)
        printf("%lld in an Invalid Input for Ending Index!", end);
        else if(start>end)
        printf("%lld as Starting Index can't be greater than %lld as Ending Index!", start, end);
        else
        {
            printf("The Prefix Sum of the Array from Index %lld to %lld is:%d\n", start, end, prefix_sum(start, end));
            printf("The Prefix Weighted Sum of the Array from Index %lld to %lld is:%d", start, end, prefix_weighted_sum(start, end));
        }
    }
    return 0;
}

