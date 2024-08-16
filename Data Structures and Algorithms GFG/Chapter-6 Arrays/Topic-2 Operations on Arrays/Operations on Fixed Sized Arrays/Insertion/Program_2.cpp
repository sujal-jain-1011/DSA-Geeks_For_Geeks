/*C++ Program to Insert an Element at a Given
Index in a Fixed Sized Array(Heap Allocation)*/

#include<iostream>
#include<new>
#include<limits.h>
using namespace std;

/*Creating a class*/
class Implement_Fixed_Sized_Array{
    public:

    /*Data Members of class:
    long long signed int and int* */
    long long signed int capacity, size, position;
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
    to Insert an Element at a Given 
    Position in an Array*/
    bool insert(int element)
    {
        if(size==capacity)
        {
            cout<<"Can't Insert "<<element<<" in Array at Position "<<position<<" because of Overflow!";
            return false;
        }
        else if(position<=0 || position>(size+1))
        {
            cout<<position<<" is an Invalid Input for Position!";
            return false;
        }
        else
        {
            long long signed int index=position-1;
            long long signed int i;
            for(i=size-1; i>=index; i--)
            arr[i+1]=arr[i];    
            arr[i+1]=element;
            size++;
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
        cout<<"Array before Insertion Operation:"<<endl;
        IFSA.display();
        cout<<"And Size of Array before Insertion Operation:"<<IFSA.size<<endl;
        cout<<"Enter the Element you want to Insert in Array:";
        cin>>IFSA.element;
        cout<<"Enter the Position at which you want to Insert "<<IFSA.element<<":";
        cin>>IFSA.position;
        /*User is advised to enter a Non-Negative Integer that is
        greater than or equal to 0 and less than (2 raised to power 63)
        as size otherwise the result will not be as predicted*/

        if(!IFSA.insert(IFSA.element))
        cout<<"Insertion Failed!";
        else
        {
            cout<<"Array after Insertion Operation:"<<endl;
            IFSA.display();
            cout<<"And Size of Array after Insertion Operation:"<<IFSA.size<<endl;
        }
    }
    return 0;
}