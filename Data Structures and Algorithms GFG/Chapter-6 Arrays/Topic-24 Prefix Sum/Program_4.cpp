/*C++ Program to Find Prefix Sum and Prefix Weighted
Sum in a Fixed Sized Array(Heap Allocation)*/

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
    int *pwsum;

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
    to Precompute Prefix Sum*/
    bool precompute_prefix_sum()
    {
        /*Allocating Memory to psum array*/
        psum=new(nothrow) int[size];
        
        /*Checking for Memory Allocation*/
        if(psum==NULL)
        {
            cout<<"\nMemory Allocation Failed for psum Array!"<<endl;
            cout<<"Thus, can't compute Prefix Sum!"<<endl;
            cout<<"Hence, returning the Lowest Possible Integer value!"<<endl;
            return false;
        }
        psum[0]=arr[0];
        for(long long signed int i=1; i<size; i++)
        psum[i]=psum[i-1]+arr[i];
        return true;
    }

    /*Member Function of class:
    to Find Prefix Sum*/
    int prefix_sum(long long signed int start, long long signed int end)
    {
        /*We are making a small assumption that the sum of integer elements
        of the array is within the bound of integer, that is an integer*/
        if(!precompute_prefix_sum())
        return INT_MIN;
        if(start==0)
        return psum[end];
        return (psum[end]-psum[start-1]);
    }

    /*Member Function of class:
    to Precompute Prefix Weighted Sum*/
    bool precompute_prefix_weighted_sum()
    {
        /*Allocating Memory to pwsum array*/
        pwsum=new(nothrow) int[size];
        
        /*Checking for Memory Allocation*/
        if(pwsum==NULL)
        {
            cout<<"\nMemory Allocation Failed for pwsum Array!"<<endl;
            cout<<"Thus, can't compute Prefix Weighted Sum!"<<endl;
            cout<<"Hence, returning the Lowest Possible Integer value!"<<endl;
            return false;
        }
        pwsum[0]=0*arr[0];
        for(long long signed int i=1; i<size; i++)
        pwsum[i]=pwsum[i-1]+i*arr[i];
        return true;
    }

    /*Member Function of class:
    to Find Prefix Weighted Sum*/
    int prefix_weighted_sum(long long signed int start, long long signed int end)
    {
        /*We are making a small assumption that the sum of product of integer elements 
        with their weights of the array is within the bound of integer, that is an integer*/
        if(!precompute_prefix_weighted_sum())
        return INT_MIN;
        if(start==0)
        return pwsum[end]+psum[end];
        return ((pwsum[end]-pwsum[start-1])-(start-1)*(psum[end]-psum[start-1]));
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
        long long signed int start, end;
        cout<<"Enter the Starting and Ending Index for Prefix Sum:";
        cin>>start>>end;
        /*User is advised to enter Non-Negative Integers that are greater
        than or equal to 0 and less than (2 raised to power 63) as starting
        and ending indices otherwise the result will not be as predicted*/
        if(start>LLONG_MAX || start<0)
        cout<<start<<" in an Invalid Input for Starting Index!";
        else if(end>LLONG_MAX || end<0)
        cout<<end<<" in an Invalid Input for Ending Index!";
        else if(start>end)
        cout<<start<<" as Starting Index can't be greater than "<<end<<" as Ending Index!";
        else
        {
            cout<<"The Prefix Sum of the Array from Index "<<start<<" to "<<end<<" is:"<<IFSA.prefix_sum(start, end)<<endl;
            cout<<"The Prefix Weighted Sum of the Array from Index "<<start<<" to "<<end<<" is:"<<IFSA.prefix_weighted_sum(start, end);
        }
    }
    return 0;
}