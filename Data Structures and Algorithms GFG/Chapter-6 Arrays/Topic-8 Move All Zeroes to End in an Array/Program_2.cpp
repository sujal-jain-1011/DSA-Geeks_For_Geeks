/*C++ Program to Move all Zeroes to End 
in a Fixed Sized Array(Heap Allocation)*/

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
    to Swap Two Integers*/
    void swap(int *ptr_1, int *ptr_2)
    {
        int temp;
        temp=*ptr_1;
        *ptr_1=*ptr_2;
        *ptr_2=temp;
    }

    /*Member Function of class:
    to Move all Zeroes to End 
    in a Fixed Sized Array */
    void move_all_zeroes_to_end()
    {
        for(long long signed int i=0; i<size; i++)
        {
            if(arr[i]==0)
            {
                for(long long signed int j=i+1; j<size; j++)
                {
                    if(arr[j]!=0)
                    {
                        swap((arr+i), (arr+j));
                        break;
                    }
                }
            }
        }
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
        cout<<"Array before Moving all Zeroes to End:"<<endl;
        IFSA.display();
        IFSA.move_all_zeroes_to_end();
        cout<<"Array after Moving all Zeroes to End:"<<endl;
        IFSA.display();
    }
    return 0;
}