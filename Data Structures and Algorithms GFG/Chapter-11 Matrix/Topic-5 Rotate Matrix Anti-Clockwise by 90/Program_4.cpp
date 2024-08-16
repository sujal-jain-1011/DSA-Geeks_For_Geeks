/*C++ Program to Rotate a Fixed Sized 
2D Array(Heap Allocation) by 90*/

#include<iostream>
#include<new>
#include<limits.h>
using namespace std;

/*Creating a class*/
class Implement_Fixed_Sized_2D_Array{
    public:

    /*Data Members of class:
    long long signed int and int** */
    long long signed int row_capacity, row_size, column_capacity, column_size;
    int **mat;

    /*Member Function of class:
    to Create a Fixed Sized
    2D Array using Heap Allocation*/
    bool create_a_fixed_sized_2D_array(void)
    {
        /*User Input for row capacity and row size*/
        cout<<"Enter the Row-Capacity and Row-Size of Matrix:";
        cin>>row_capacity>>row_size;
        /*User is advised to enter a Non-Negative Integer that is greater
        than or equal to 0 and less than (2 raised to power 63) as row capacity
        and row size otherwise the result will not be as predicted*/

        /*Checking for bounds for row capacity and row size*/
        if(row_capacity>LLONG_MAX || row_size>LLONG_MAX || row_capacity<0 || row_size<0)
        {
            if(row_capacity>LLONG_MAX || row_capacity<0)
            {
                cout<<row_capacity<<" is an Invalid Input for Row Capacity!"<<endl;
                return false;
            }
            else 
            {
                cout<<row_size<<" is an Invalid Input for Row Size!"<<endl;
                return false;
            }
        }

        /*User Input for column capacity and column size*/
        cout<<"Enter the Column-Capacity and Column-Size of Matrix:";
        cin>>column_capacity>>column_size;
        /*User is advised to enter a Non-Negative Integer that is greater
        than or equal to 0 and less than (2 raised to power 63) as column capacity
        and column size otherwise the result will not be as predicted*/

        /*Checking for bounds for column capacity and column size*/
        if(column_capacity>LLONG_MAX || column_size>LLONG_MAX || column_capacity<0 || column_size<0)
        {
            if(column_capacity>LLONG_MAX || column_capacity<0)
            {
                cout<<column_capacity<<" is an Invalid Input for Column Capacity!"<<endl;
                return false;
            }
            else 
            {
                cout<<column_size<<" is an Invalid Input for Column Size!"<<endl;
                return false;
            }
        }

        /*Comparison of size and capacity*/
        if(row_size>row_capacity || column_size>column_capacity)
        {
            if(row_size>row_capacity)
            {
                cout<<"Row Size can't be greater than Row Capacity"<<endl;
                return false;
            }
            else
            {
                cout<<"Column Size can't be greater than Column Capacity"<<endl;
                return false;
            }
        }

        /*Allocating Memory to Matrix*/
        mat=new(nothrow) int*[row_capacity];
        for(long long signed int i=0; i<row_capacity; i++)
        mat[i]=new(nothrow) int[column_capacity];

        /*Checking for Memory Allocation*/
        if(mat==NULL)
        {
            cout<<"Memory Allocation Failed!"<<endl;
            return false;
        }
        else 
        {
            for(long long signed int i=0; i<row_capacity; i++)
            {
                if(mat[i]==NULL)
                {
                    cout<<"Memory Allocation Failed!"<<endl;
                    return false;
                }
            }
        }

        /*Taking the Elements of Matrix as User Input*/
        cout<<"Enter "<<row_size*column_size<<" Elements for Matrix:"<<endl;
        for(long long signed int i=0; i<row_size; i++)
        {
            for(long long signed int j=0; j<column_size; j++)
            {
                cout<<"Enter the Element for row "<<(i+1)<<" and column "<<(j+1)<<":";
                cin>>mat[i][j];
            }
        }
        return true;
    }

    /*Member Function of class:
    to Display Elements of 2D Array:
    Display Function*/
    void display(void)
    {
        /*Displaying the Elements of Matrix: Traversing a Matrix*/
        cout<<"The Elements of Matrix are:"<<endl;
        for(long long signed int i=0; i<row_size; i++)
        {
            for(long long signed int j=0; j<column_size; j++)
            cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }

    /*Member Function of class:
    to Find Transpose of 2D Array*/
    void transpose()
    {
        /*Checking For Dimensions of Matrix*/
        if(row_size!=column_size)
        {
            cout<<"Invalid Dimensions!"<<endl;
            cout<<"As entered Matrix is not a Square Matrix!";
            return;
        }
        
        for(long long signed int i=0; i<row_size; i++)
        {
            for(long long signed int j=i+1; j<column_size; j++)
            {
                int temp=mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=temp;
            }
        }
    }

    /*Member Function of class:
    to Rotate a 2D Array by 90*/
    void rotate_90()
    {
        transpose();
        
        for(long long signed int j=0; j<column_size; j++)
        {
            long long signed int low=0, high=row_size-1;
            while(low<high)
            {
                int temp=mat[low][j];
                mat[low][j]=mat[high][j];
                mat[high][j]=temp;
                low++;
                high--;
            }
        }

        /*Displaying the Rotated Matrix*/
        cout<<"After Rotating by 90, the Matrix is:"<<endl;
        for(long long signed int i=0; i<row_size; i++)
        {
            for(long long signed int j=0; j<column_size; j++)
            cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }
};

/*Driver Function(Code)*/
int main()
{
    Implement_Fixed_Sized_2D_Array IFS2A;
    if(!IFS2A.create_a_fixed_sized_2D_array())
    cout<<"Matrix Creation Failed!";
    else
    {
        IFS2A.display();
        IFS2A.rotate_90();
    }
    return 0;
}