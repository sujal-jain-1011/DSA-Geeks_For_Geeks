/*C Program to Find Equilibrium Point in 
a Fixed Sized Array(Heap Allocation)*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*Decalaring Global Variables*/
long long signed int capacity, size;
int *arr;
int *psum;
int *ssum;

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

/*Function to Precompute psum Array*/
short unsigned int precompute_prefix_sum()
{
    /*Allocating Memory to psum Array*/
    psum=(int *)malloc(size*sizeof(int));

    /*Checking for Memory Allocation*/
    if(psum==NULL)
    {
        printf("\nMemory Allocation Failed for psum Array!\n");
        printf("Therefore, can't find Equilibrium Point!\n");
        return 0;
    }
    psum[0]=arr[0];
    for(long long signed int i=1; i<size; i++)
    psum[i]=psum[i-1]+arr[i];
    return 1;
}

/*Function to Precompute ssum Array*/
short unsigned int precompute_suffix_sum()
{
    /*Allocating Memory to ssum Array*/
    ssum=(int *)malloc(size*sizeof(int));

    /*Checking for Memory Allocation*/
    if(ssum==NULL)
    {
        printf("\nMemory Allocation Failed for ssum Array!\n");
        printf("Therefore, can't find Equilibrium Point!\n");
        return 0;
    }
    ssum[size-1]=arr[size-1];
    for(long long signed int i=1; i<size; i++)
    ssum[size-i-1]=ssum[size-i]+arr[size-i-1];
    return 1;
}

/*Function to Find Equilibrium Point*/
short unsigned int equilibrium_point()
{
    if(!precompute_prefix_sum() || !precompute_suffix_sum())
    return 0;
    /*We are making a small assumption that the sum of integer elements
    of the array is within the bound of integer, that is an integer*/
    if((psum[size-2]==0) || (ssum[1]==0))
    return 1;
    for(long long signed int i=1; i<size-1; i++)
    {
        if(psum[i-1]==ssum[i+1])
        return 1;
    }
    return 0;
}

/*Driver Function(Code)*/
int main()
{
    if(!create_a_fixed_sized_array())
    printf("Array Creation Failed!");
    else
    {
        display();
        if(!equilibrium_point())
        printf("There does not exist any Equilibrium Point in the Array!");
        else
        printf("There exists an Equilibrium Point in the Array!");
    }
    return 0;
}

