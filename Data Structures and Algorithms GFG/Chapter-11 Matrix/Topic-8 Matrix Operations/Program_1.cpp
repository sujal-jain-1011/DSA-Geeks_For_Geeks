/*C++ Program to Perform Operations: Addition, Subtraction
and Multiplication of Fixed Sized 2D Arrays(Heap Allocation)*/

#include<iostream>
#include<new>
#include<limits.h>
using namespace std;

/*We will be Performing Operations on only two Matrices
However we can take into account more number of Matrices as well*/
class Implement_Fixed_Sized_2D_Array{
    public:

    /*Data Members of class:
    long long unsigned int[], int **[] and int** */
    long long unsigned int row_capacity[2], row_size[2], column_capacity[2], column_size[2];
    int **mat[2];
    int **result;

    /*Member Function of class:
    to Create a Fixed Sized
    2D Array using Heap Allocation*/
    bool create_a_fixed_sized_2D_array(short signed int mat_num)
    {
        if(mat_num<1 || mat_num>2)
        {
            cout<<"You have entered an Incorrect Matrix Number!";
            return false;
        }

        /*User Input for row capacity and row size*/
        cout<<"Enter the Row-Capacity and Row-Size of Matrix "<<mat_num<<":";
        cin>>row_capacity[mat_num-1]>>row_size[mat_num-1];
        /*User is advised to enter a Non-Negative Integer that is greater
        than or equal to 0 and less than (2 raised to power 64) as row capacity
        and row size otherwise the result will not be as predicted*/

        /*Checking for bounds for row capacity and row size*/
        if(row_capacity[mat_num-1]>ULLONG_MAX || row_size[mat_num-1]>ULLONG_MAX)
        {
            if(row_capacity[mat_num-1]>ULLONG_MAX)
            {
                cout<<row_capacity[mat_num-1]<<" is an Invalid Input for Row Capacity!"<<endl;
                return false;
            }
            else 
            {
                cout<<row_size[mat_num-1]<<" is an Invalid Input for Row Size!"<<endl;
                return false;
            }
        }

        /*User Input for column capacity and column size*/
        cout<<"Enter the Column-Capacity and Column-Size of Matrix "<<mat_num<<":";
        cin>>column_capacity[mat_num-1]>>column_size[mat_num-1];
        /*User is advised to enter a Non-Negative Integer that is greater
        than or equal to 0 and less than (2 raised to power 64) as column capacity
        and column size otherwise the result will not be as predicted*/

        /*Checking for bounds for column capacity and column size*/
        if(column_capacity[mat_num-1]>ULLONG_MAX || column_size[mat_num-1]>ULLONG_MAX)
        {
            if(column_capacity[mat_num-1]>ULLONG_MAX)
            {
                cout<<column_capacity[mat_num-1]<<" is an Invalid Input for Column Capacity!"<<endl;
                return false;
            }
            else 
            {
                cout<<column_size[mat_num-1]<<" is an Invalid Input for Column Size!"<<endl;
                return false;
            }
        }

        /*Comparison of size and capacity*/
        if(row_size[mat_num-1]>row_capacity[mat_num-1] || column_size[mat_num-1]>column_capacity[mat_num-1])
        {
            if(row_size[mat_num-1]>row_capacity[mat_num-1])
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
        mat[mat_num-1]=new(nothrow) int*[row_capacity[mat_num-1]];
        for(long long unsigned int i=0; i<row_capacity[mat_num-1]; i++)
        mat[mat_num-1][i]=new(nothrow) int[column_capacity[mat_num-1]];

        /*Checking for Memory Allocation*/
        if(mat[mat_num-1]==NULL)
        {
            cout<<"Memory Allocation Failed!"<<endl;
            return false;
        }
        else 
        {
            for(long long unsigned int i=0; i<row_capacity[mat_num-1]; i++)
            {
                if(mat[mat_num-1][i]==NULL)
                {
                    cout<<"Memory Allocation Failed!"<<endl;
                    return false;
                }
            }
        }

        /*Taking the Elements of Matrix as User Input*/
        cout<<"Enter "<<row_size[mat_num-1]*column_size[mat_num-1]<<" Elements for Matrix "<<mat_num<<":"<<endl;
        for(long long unsigned int i=0; i<row_size[mat_num-1]; i++)
        {
            for(long long unsigned int j=0; j<column_size[mat_num-1]; j++)
            {
                cout<<"Enter the Element for row "<<i+1<<" and column "<<j+1<<":";
                cin>>mat[mat_num-1][i][j];
            }
        }
        return true;
    }

    /*Member Function of class:
    to Display Elements of 2D Array: Display Function*/
    void display(short signed int mat_num)
    {
        if(mat_num<1 || mat_num>2)
        {
            cout<<"You have entered an Incorrect Matrix Number!";
            return;
        }

        /*Displaying the Elements of Matrix: Traversing a Matrix*/
        cout<<"The Elements of Matrix "<<mat_num<<" are:"<<endl;
        for(long long unsigned int i=0; i<row_size[mat_num-1]; i++)
        {
            for(long long unsigned int j=0; j<column_size[mat_num-1]; j++)
            cout<<mat[mat_num-1][i][j]<<" ";
            cout<<endl;
        }
    }

    /*Member Function of class:
    to Add two Matrices*/
    bool add_matrices(short signed int mat_num_1, short signed int mat_num_2)
    {
        if((mat_num_1<1 || mat_num_1>2) || (mat_num_2<1 || mat_num_2>2))
        {
            cout<<"You have entered an Incorrect Matrix Numbers!"<<endl;
            cout<<"Thus, Addition can't be Performed!"<<endl;
            return false;
        }
        if((row_size[mat_num_1-1]!=row_size[mat_num_2-1]) || (column_size[mat_num_1-1]!=column_size[mat_num_2-1]))
        {
            cout<<"Incompatible Dimensions for Matrix Addition!"<<endl;
            return false;
        }

        /*Allocating Memory to Result Matrix*/
        result=new(nothrow) int*[row_capacity[mat_num_1-1]];
        for(long long unsigned int i=0; i<row_capacity[mat_num_1-1]; i++)
        result[i]=new(nothrow) int[column_capacity[mat_num_1-1]];

        /*Checking for Memory Allocation*/
        if(result==NULL)
        {
            cout<<"Memory Allocation Failed!"<<endl;
            return false;
        }
        else 
        {
            for(long long unsigned int i=0; i<row_capacity[mat_num_1-1]; i++)
            {
                if(result[i]==NULL)
                {
                    cout<<"Memory Allocation Failed!"<<endl;
                    return false;
                }
            }
        }

        for(long long unsigned int i=0; i<row_size[mat_num_1-1]; i++)
        {
            for(long long unsigned int j=0; j<column_size[mat_num_1-1]; j++)
            result[i][j]=mat[mat_num_1-1][i][j]+mat[mat_num_2-1][i][j];
        }

        /*Displaying the Resultant Matrix*/
        cout<<"The Addition of two entered Matrices is:"<<endl;
        for(long long unsigned int i=0; i<row_size[mat_num_1-1]; i++)
        {
            for(long long unsigned int j=0; j<column_size[mat_num_1-1]; j++)
            cout<<result[i][j]<<" ";
            cout<<endl;
        }

        /*Deallocating Memory to Result Matrix*/
        for(long long unsigned int i=0; i<row_capacity[mat_num_1-1]; i++)
        delete result[i];
        delete result;
        return true;
    }

    /*Member Function of class:
    to Subtract two Matrices*/
    bool subtract_matrices(short signed int mat_num_1, short signed int mat_num_2)
    {
        if((mat_num_1<1 || mat_num_1>2) || (mat_num_2<1 || mat_num_2>2))
        {
            cout<<"You have entered an Incorrect Matrix Numbers!"<<endl;
            cout<<"Thus, Subtraction can't be Performed!"<<endl;
            return false;
        }
        if((row_size[mat_num_1-1]!=row_size[mat_num_2-1]) || (column_size[mat_num_1-1]!=column_size[mat_num_2-1]))
        {
            cout<<"Incompatible Dimensions for Matrix Subtraction!"<<endl;
            return false;
        }

        /*Allocating Memory to Result Matrix*/
        result=new(nothrow) int*[row_capacity[mat_num_1-1]];
        for(long long unsigned int i=0; i<row_capacity[mat_num_1-1]; i++)
        result[i]=new(nothrow) int[column_capacity[mat_num_1-1]];

        /*Checking for Memory Allocation*/
        if(result==NULL)
        {
            cout<<"Memory Allocation Failed!"<<endl;
            return false;
        }
        else 
        {
            for(long long unsigned int i=0; i<row_capacity[mat_num_1-1]; i++)
            {
                if(result[i]==NULL)
                {
                    cout<<"Memory Allocation Failed!"<<endl;
                    return false;
                }
            }
        }

        for(long long unsigned int i=0; i<row_size[mat_num_1-1]; i++)
        {
            for(long long unsigned int j=0; j<column_size[mat_num_1-1]; j++)
            result[i][j]=mat[mat_num_1-1][i][j]-mat[mat_num_2-1][i][j];
        }

        /*Displaying the Resultant Matrix*/
        cout<<"The Subtraction of two entered Matrices is:"<<endl;
        for(long long unsigned int i=0; i<row_size[mat_num_1-1]; i++)
        {
            for(long long unsigned int j=0; j<column_size[mat_num_1-1]; j++)
            cout<<result[i][j]<<" ";
            cout<<endl;
        }

        /*Deallocating Memory to Result Matrix*/
        for(long long unsigned int i=0; i<row_capacity[mat_num_1-1]; i++)
        delete result[i];
        delete result;
        return true;
    }

    /*Member Function of class:
    to Mulitply two Matrices*/
    bool multiply_matrices(short signed int mat_num_1, short signed int mat_num_2)
    {
        if((mat_num_1<1 || mat_num_1>2) || (mat_num_2<1 || mat_num_2>2))
        {
            printf("You have entered an Incorrect Matrix Numbers!\n");
            printf("Thus, Multiplication can't be Performed!\n");
            return false;
        }
        if(column_size[mat_num_1-1]!=row_size[mat_num_2-1])
        {
            printf("Incompatible Dimensions for Matrix Multiplication!\n");
            return false;
        }

        /*Allocating Memory to Result Matrix*/
        result=(int **)malloc(row_capacity[mat_num_1-1]*sizeof(int *));
        for(long long unsigned int i=0; i<row_capacity[mat_num_1-1]; i++)
        result[i]=(int *)malloc(column_capacity[mat_num_2-1]*sizeof(int));

        /*Checking for Memory Allocation*/
        if(result==NULL)
        {
            printf("Memory Allocation Failed!\n");
            return false;
        }
        else 
        {
            for(long long unsigned int i=0; i<row_capacity[mat_num_1-1]; i++)
            {
                if(result[i]==NULL)
                {
                    printf("Memory Allocation Failed!\n");
                    return false;
                }
            }
        }

        for(long long unsigned int i=0; i<row_size[mat_num_1-1]; i++)
        {
            for(long long unsigned int j=0; j<column_size[mat_num_2-1]; j++)
            {
                result[i][j]=0;
                for(long long unsigned int k=0; k<row_size[mat_num_2-1]; k++)
                result[i][j]+=mat[mat_num_1-1][i][k]*mat[mat_num_2-1][k][j];
            }
        }

        /*Displaying the Resultant Matrix*/
        cout<<"The Multiplication of two entered Matrices is:"<<endl;
        for(long long unsigned int i=0; i<row_size[mat_num_1-1]; i++)
        {
            for(long long unsigned int j=0; j<column_size[mat_num_2-1]; j++)
            cout<<result[i][j]<<" ";
            cout<<endl;
        }

        /*Deallocating Memory to Result Matrix*/
        for(long long unsigned int i=0; i<row_capacity[mat_num_1-1]; i++)
        delete result[i];
        delete result;
        return true;
    }
};

/*Driver Function(Code)*/
int main()
{
    Implement_Fixed_Sized_2D_Array IFS2A;
    if(!IFS2A.create_a_fixed_sized_2D_array(1))
    cout<<"Matrix "<<1<<" creation failed!";
    else 
    IFS2A.display(1);
    if(!IFS2A.create_a_fixed_sized_2D_array(2))
    cout<<"Matrix "<<2<<" creation failed!";
    else 
    IFS2A.display(2);

    /*Operations on Matrices*/
    if(!IFS2A.add_matrices(1,2))
    cout<<"Error while Adding two matrices!"<<endl;
    if(!IFS2A.subtract_matrices(1,2))
    cout<<"Error while Subtracting two matrices!"<<endl;
    if(!IFS2A.multiply_matrices(1,2))
    cout<<"Error while Multiplying two matrices!"<<endl;

    return 0;
}