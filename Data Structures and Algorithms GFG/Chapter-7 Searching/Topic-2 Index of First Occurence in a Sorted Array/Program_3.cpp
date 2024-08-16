/*C++ Program to Find Index of First Occurence
in a Sorted Fixed Sized Array(Heap Allocation)*/

#include<iostream>
#include<new>
#include<limits.h>
using namespace std;

/*Creating a class*/
class Implement_Fixed_Sized_Array{
    public:

    /*Data Members of class:
    long long unsigned int and int* */
    long long unsigned int capacity, size;
    int *arr;

    /*Member Function of class:
    to Create a Fixed Sized
    Array using Heap Allocation*/
    bool create_a_fixed_sized_array(void)
    {
        cout<<"Enter the Capacity of Array:";
        cin>>capacity;
        /*User is advised to enter a Non-Negative Integer that is
        greater than or equal to 0 and less than (2 raised to power 64)
        as capacity otherwise the result will not be as predicted*/

        /*Checking for bounds for capacity*/
        if(capacity>ULLONG_MAX)
        {
            cout<<capacity<<" is an Invalid Input for Capacity!";
            return false;
        }

        cout<<"Enter the Size of Array:";
        cin>>size;
        /*User is advised to enter a Non-Negative Integer that is
        greater than or equal to 0 and less than (2 raised to power 64)
        as size otherwise the result will not be as predicted*/

        /*Checking for bounds for size*/
        if(size>ULLONG_MAX)
        {
            cout<<size<<" is an Invalid Input for Size!";
            return false;
        }

        /*Comparison of size and capacity*/
        if(size>capacity)
        {
            printf("Size can't be greater than Capacity!\n");
            return false;
        }

        /*Allocating Memory to Array*/
        arr=new(nothrow) int[capacity];

        /*Checking for Memory Allocation*/
        if(arr==NULL)
        {
            cout<<"Memory Allocation Failed!"<<endl;
            return false;
        }

        /*Taking the Elements of Array as User Input*/
        cout<<"Enter "<<size<<" Elements for Array:"<<endl;
        for(long long unsigned int i=0; i<size; i++)
        {
            cout<<"Enter Element "<<i+1<<" of Array:";
            cin>>arr[i];
        }
        return true;
    }

    /*Member Function of class:
    to Display Elements of Array:
    Display Function*/
    void display(void)
    {
        /*Displaying the Elements of Array: Traversing an Array*/
        cout<<"The Elements of Array are:"<<endl;
        for(long long unsigned int i=0; i<size; i++)
        cout<<"Element "<<i+1<<" of Array is:"<<i[arr]<<endl;
    }

    /*Member Function of class:
    to Find the Index of First Occurence of
    an Element-Using Iterative Binary Search*/
    void index_first_occurence(int element)
    {
        long long unsigned int low=0, high=size-1;
        while(low<=high)
        {
            long long unsigned int mid=(low+high)/2;
            if(arr[mid]>element)
            {
                if(mid!=0)
                high=mid-1;
                else 
                break;
            }
            else if(arr[mid]<element)
            low=mid+1;
            else
            {
                if(mid==0 || arr[mid-1]!=element)
                {
                    cout<<"The Index of First Occurence of "<<element<<" is:"<<mid;
                    return;
                }
                if(mid!=0)
                high=mid-1;
                else 
                break;
            }
        }
        cout<<element<<" is not present in the Array";
        return;
    }
};

/*Driver Function(Code)*/
int main()
{
    Implement_Fixed_Sized_Array IFSA;
    if(!IFSA.create_a_fixed_sized_array())
    printf("Array Creation Failed!");
    else
    {
        IFSA.display();
        int element;
        cout<<"Enter an element:";
        cin>>element;
        IFSA.index_first_occurence(element);
    }
    return 0;
}