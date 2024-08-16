/*C++ Program to Left Rotate a Fixed
Sized Array(Heap Allocation) by d*/

#include<iostream>
#include<new>
#include<limits.h>
using namespace std;

/*Creating a class*/
class Implement_Fixed_Sized_Array{
    public:

    /*Data Members of class:
    long long unsigned int , bool and int* */
    long long unsigned int capacity, size;
    int *arr;
    bool flag=true;

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
    to Left Rotate an Array by d*/
    void left_rotate_by_d(long long unsigned int d)
    {
        /*Normalizing the value of d*/
        d%=size;
    
        /*Creating a Temporary Array for storing d elements*/
        int *temp;
        /*Allocating Memory to Array*/
        temp=new(nothrow) int[d];

        /*Checking for Memory Allocation*/
        if(temp==NULL)
        {
            cout<<"Memory Allocation Failed for Temporary Array!"<<endl;
            flag=false;
        }

        for(long long unsigned int i=0; i<d; i++)
        temp[i]=arr[i];
        for(long long unsigned int i=d; i<size; i++)
        arr[i-d]=arr[i];
        for(long long unsigned int i=0; i<d; i++)
        arr[size-d+i]=temp[i];
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
        long long unsigned int d;
        cout<<"Enter the value of d by which you want to Left Rotate the Array:";
        cin>>d;
        cout<<"Before Left Rotating by "<<d<<" the Array is:"<<endl;
        IFSA.display();
        IFSA.left_rotate_by_d(d);
        if(!IFSA.flag)
        cout<<"Can't Rotate the Array!";
        else
        {
            cout<<"After Left Rotating by "<<d<<" the Array is:"<<endl;
            IFSA.display();
        }
    }
    return 0;
}