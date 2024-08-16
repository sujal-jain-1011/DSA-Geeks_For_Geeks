/*C++ Program to Remove Duplicates from a Fixed Sized
Array(Heap Allocation) Sorted in Non-Decreasing Order*/

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
    int *temp;

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
    to Check if an Array is Sorted 
    in Non-Deceasing Order or not*/
    bool check_for_sorted()
    {
        for(long long signed int i=1; i<size; i++)
        {
            if(arr[i]<arr[i-1])
            return false;
        }
        return true;
    }

    /*Member Function of class:
    to Remove Duplicates from an Array
    Sorted in Non-Decreasing Order*/
    void remove_duplicates()
    {
        temp=new(nothrow) int[size];
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
        if(!IFSA.check_for_sorted())
        cout<<"The Array is Not Sorted in Non-Decreasing Order!";
        else
        {
            cout<<"The Array is Sorted in Non-Decreasing Order!\n";
            IFSA.remove_duplicates();
            cout<<"After Removing Duplicates, the Array becomes:\n";
            IFSA.display();
        }
    }
    return 0;
}