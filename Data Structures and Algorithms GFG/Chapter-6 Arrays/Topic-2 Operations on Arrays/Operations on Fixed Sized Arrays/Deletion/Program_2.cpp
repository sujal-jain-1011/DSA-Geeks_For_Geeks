/*C++ Program to Delete a Given Element 
from a Fixed Sized Array(Heap Allocation)*/

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
    int element;

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
    to Delete a given Element from an Array*/
    bool deletion(int elmt)
    {
        if(size==0 || capacity==0)
        {
            cout<<"Can't delete "<<elmt<<" from Array as there are no Elements in Array!"<<endl;
            return false;
        }
        else
        {
            long long signed int i;
            for(i=0; i<size; i++)
            {
                if(arr[i]==element)
                break;
            }
            if(i==size)
            {
                cout<<elmt<<" is not there in Array, thus can't perform Deletion Operation!"<<endl;
                return false;
            }
            for(long long signed int j=i; j<size-1; j++)
            arr[j]=arr[j+1];
            size--;
            return true;
        }
    }
};

/*Driver Function(Code)*/
int main()
{
    Implement_Fixed_Sized_Array IFSA;
    if(!IFSA.create_a_fixed_sized_array())
    cout<<"Array Creation Failed!";
    else
    {
        cout<<"Array before Deletion Operation:"<<endl;
        IFSA.display();
        cout<<"And Size of Array before Deletion Operation:"<<IFSA.size<<endl;
        cout<<"Enter the Element you want to Delete from Array:";
        cin>>IFSA.element;
        if(!IFSA.deletion(IFSA.element))
        cout<<"Deletion Failed!";
        else
        {
            cout<<"Array after Deletion Operation:"<<endl;
            IFSA.display();
            cout<<"And Size of Array after Deletion Operation:"<<IFSA.size<<endl;
        }
    }
    return 0;
}