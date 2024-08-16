/*C++ Program to Find Equilibrium Point in 
a Fixed Sized Array(Heap Allocation)*/

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
    int *psum;
    int *ssum;

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
    to Precompute psum Array*/
    bool precompute_prefix_sum()
    {
        /*Allocating Memory to psum Array*/
        psum=new(nothrow) int[size];

        /*Checking for Memory Allocation*/
        if(psum==NULL)
        {
            cout<<"\nMemory Allocation Failed for psum Array!"<<endl;
            cout<<"Therefore, can't find Equilibrium Point!"<<endl;
            return false;
        }
        psum[0]=arr[0];
        for(long long signed int i=1; i<size; i++)
        psum[i]=psum[i-1]+arr[i];
        return true;
    }

    /*Member Function of class:
    to Precompute ssum Array*/
    bool precompute_suffix_sum()
    {
        /*Allocating Memory to ssum Array*/
        ssum=new(nothrow) int[size];

        /*Checking for Memory Allocation*/
        if(ssum==NULL)
        {
            cout<<"\nMemory Allocation Failed for ssum Array!"<<endl;
            cout<<"Therefore, can't find Equilibrium Point!"<<endl;
            return false;
        }
        ssum[size-1]=arr[size-1];
        for(long long signed int i=1; i<size; i++)
        ssum[size-i-1]=ssum[size-i]+arr[size-i-1];
        return true;
    }

    /*Member Function of class:
    to Find Equilibrium Point*/
    bool equilibrium_point()
    {
        if(!precompute_prefix_sum() || !precompute_suffix_sum())
        return false;
        /*We are making a small assumption that the sum of integer elements
        of the array is within the bound of integer, that is an integer*/
        if((psum[size-2]==0) || (ssum[1]==0))
        return true;
        for(long long signed int i=1; i<size-1; i++)
        {
            if(psum[i-1]==ssum[i+1])
            return true;
        }
        return false;
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
        if(!IFSA.equilibrium_point())
        cout<<"There does not exist any Equilibrium Point in the Array!";
        else
        cout<<"There exists an Equilibrium Point in the Array!";
    }
    return 0;
}