/*C Program to Insert an Element at a Given
Index in a Fixed Sized Array(Heap Allocation)*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*Decalaring Global Variables*/
long long signed int capacity, size, position;
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

/*Function to Insert an Element at a Given Position in an Array*/
short unsigned int insert(int element)
{
    if(size==capacity)
    {
        printf("Can't Insert %d in Array at Position %lld because of Overflow!", element, position);
        return 0;
    }
    else if(position<=0 || position>(size+1))
    {
        printf("%lld is an Invalid Input for Position!", position);
        return 0;
    }
    else
    {
        long long signed int index=position-1;
        long long signed int i;
        for(i=size-1; i>=index; i--)
        arr[i+1]=arr[i];    
        arr[i+1]=element;
        size++;
        return 1;
    }
}

/*Driver Function(Code)*/
int main()
{
    if(!create_a_fixed_sized_array())
    printf("Array Creation Failed!");
    else
    {
        printf("Array before Insertion Operation:\n");
        display();
        printf("And Size of Array before Insertion Operation:%lld\n", size);
        int element;
        printf("Enter the Element you want to Insert in Array:");
        scanf("%d", &element);
        printf("Enter the Position at which you want to Insert %d:", element);
        scanf("%lld", &position);
        /*User is advised to enter a Non-Negative Integer that is
        greater than or equal to 0 and less than (2 raised to power 63)
        as position otherwise the result will not be as predicted*/

        if(!insert(element))
        printf("Insertion Failed!");
        else
        {
            printf("Array after Insertion Operation:\n");
            display();
            printf("And Size of Array after Insertion Operation:%lld\n", size);
        }
    }
    return 0;
}

