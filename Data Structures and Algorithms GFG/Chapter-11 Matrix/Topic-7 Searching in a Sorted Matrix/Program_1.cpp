/*C++ Program to Search for an Element in 
Fixed Sized 2D Array(Heap Allocation)*/

#include<iostream>
#include<new>
#include<limits.h>
using namespace std;

/*Creating a class*/
class Implement_Fixed_Sized_2D_Array{
    public:

    /*Data Members of class:
    long long unsigned int and int** */
    long long unsigned int row_capacity, row_size, column_capacity, column_size;
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
        than or equal to 0 and less than (2 raised to power 64) as row capacity
        and row size otherwise the result will not be as predicted*/

        /*Checking for bounds for row capacity and row size*/
        if(row_capacity>ULLONG_MAX || row_size>ULLONG_MAX)
        {
            if(row_capacity>ULLONG_MAX)
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
        than or equal to 0 and less than (2 raised to power 64) as column capacity
        and column size otherwise the result will not be as predicted*/

        /*Checking for bounds for column capacity and column size*/
        if(column_capacity>ULLONG_MAX || column_size>ULLONG_MAX)
        {
            if(column_capacity>ULLONG_MAX)
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
        for(long long unsigned int i=0; i<row_capacity; i++)
        mat[i]=new(nothrow) int[column_capacity];

        /*Checking for Memory Allocation*/
        if(mat==NULL)
        {
            cout<<"Memory Allocation Failed!"<<endl;
            return false;
        }
        else 
        {
            for(long long unsigned int i=0; i<row_capacity; i++)
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
        for(long long unsigned int i=0; i<row_size; i++)
        {
            for(long long unsigned int j=0; j<column_size; j++)
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
        for(long long unsigned int i=0; i<row_size; i++)
        {
            for(long long unsigned int j=0; j<column_size; j++)
            cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }

    /*Member Function of class:
    to Sort 2D Array row and column-wise*/
    void sort_matrix()
    {
        /*Sorting Elements of Matrix Row-wise*/
        for(long long unsigned int i=0; i<row_size; i++)
        {
            for(long long unsigned int j=0; j<column_size-1; j++)
            {
                for(long long unsigned int k=0; k<column_size-j-1; k++)
                {
                    if(mat[i][k]>mat[i][k+1])
                    {
                        int temp=mat[i][k];
                        mat[i][k]=mat[i][k+1];
                        mat[i][k+1]=temp;
                    }
                }
            }
        }

        /*Sorting Elements of Matrix Column-wise*/
        for(long long unsigned int j=0; j<column_size; j++)
        {
            for(long long unsigned int i=0; i<row_size-1; i++)
            {
                for(long long unsigned int k=0; k<row_size-i-1; k++)
                {
                    if(mat[k][j]>mat[k+1][j])
                    {
                        int temp=mat[k][j];
                        mat[k][j]=mat[k+1][j];
                        mat[k+1][j]=temp;
                    }
                }
            }
        }

        /*Displaying the Sorted Matrix*/
        cout<<"After Sorting the Matrix in Ascending order we have:"<<endl;
        for(long long unsigned int i=0; i<row_size; i++)
        {
            for(long long unsigned int j=0; j<column_size; j++)
            cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }

    /*Member Function of class:
    to Search for an Element in 2D Array*/
    void search_element(int element)
    {
        for(long long unsigned int i=0; i<row_size; i++)
        {
            for(long long unsigned int j=0; j<column_size; j++)
            {
                if(mat[i][j]==element)
                {
                    cout<<element<<" is there in the Matrix at indices:("<<i<<","<<j<<")";
                    return;
                }
            }
        }
        cout<<element<<" is not there in Matrix!";
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
        IFS2A.sort_matrix();
        int element;
        cout<<"Enter the Element you want to search for in the Sorted Matrix:";
        cin>>element;
        IFS2A.search_element(element);
    }
    return 0;
}