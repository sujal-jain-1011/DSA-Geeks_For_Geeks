/*C++ Program to Count Occurences of an Element
in a Sorted Fixed Sized Array(Heap Allocation)*/

#include<iostream>
#include<new>
#include<limits.h>
using namespace std;

/*Creating a class*/
class Implement_Fixed_Sized_Array{
    public:

    /*Data Members of class:
    long long signed int and int* */
    long long signed int capacity, size;
    int *arr;
    long long signed int ifo=-1, ilo=-1;

    /*Member Function of class:
    to Create a Fixed Sized
    Array using Heap Allocation*/
    bool create_a_fixed_sized_array(void)
    {
        cout<<"Enter the Capacity of Array:";
        cin>>capacity;
        /*User is advised to enter a Non-Negative Integer that is
        greater than or equal to 0 and less than (2 raised to power 63)
        as capacity otherwise the result will not be as predicted*/

        /*Checking for bounds for capacity*/
        if(capacity>LLONG_MAX || capacity<0)
        {
            cout<<capacity<<" is an Invalid Input for Capacity!"<<endl;
            return false;
        }

        cout<<"Enter the Size of Array:";
        cin>>size;
        /*User is advised to enter a Non-Negative Integer that is
        greater than or equal to 0 and less than (2 raised to power 63)
        as size otherwise the result will not be as predicted*/

        /*Checking for bounds for size*/
        if(size>ULLONG_MAX || size<0)
        {
            cout<<size<<" is an Invalid Input for Size!"<<endl;
            return false;
        }

        /*Comparison of size and capacity*/
        if(size>capacity)
        {
            cout<<"Size can't be greater than Capacity!"<<endl;
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
        for(long long signed int i=0; i<size; i++)
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
        for(long long signed int i=0; i<size; i++)
        cout<<"Element "<<i+1<<" of Array is:"<<i[arr]<<endl;
    }

    /*Member Function of class:
    to Find the Index of First Occurence of
    an Element-Using Iterative Binary Search*/
    void index_first_occurence(int element)
    {
        long long signed int low=0, high=size-1;
        while(low<=high)
        {
            long long signed int mid=(low+high)/2;
            if(arr[mid]>element)
            high=mid-1;
            else if(arr[mid]<element)
            low=mid+1;
            else
            {
                if(mid==0 || arr[mid-1]!=element)
                {
                    ifo=mid;
                    return;
                }
                high=mid-1;
            }
        }
        return;
    }

    /*Member Function of class:
    to Find the Index of Last Occurence of
    an Element-Using Iterative Binary Search*/
    void index_last_occurence(int element)
    {
        long long signed int low=0, high=size-1;
        while(low<=high)
        {
            long long signed int mid=(low+high)/2;
            if(arr[mid]>element)
            high=mid-1;
            else if(arr[mid]<element)
            low=mid+1;
            else
            {
                if(mid==size-1 || arr[mid+1]!=element)
                {
                    ilo=mid;
                    return;
                }
                low=mid+1;
            }
        }
        return;
    }

    /*Member Function of class:
    to Count Occurences of an Element*/
    void count_occurence(int element)
    {
        long long signed int count=0;
        if(ifo==-1)
        {
            cout<<"The Count of Occurences of "<<element<<" is:"<<count;
            return;
        }
        count=ilo-ifo+1;
        cout<<"The Count of Occurences of "<<element<<" is:"<<count;
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
        IFSA.index_last_occurence(element);
        IFSA.count_occurence(element);
    }
    return 0;
}