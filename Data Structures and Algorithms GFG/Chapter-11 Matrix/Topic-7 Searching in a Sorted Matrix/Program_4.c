/*C Program to Search for an Element in 
Fixed Sized 2D Array(Heap Allocation)*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*Decalaring Global Variables*/
long long signed int row_capacity, row_size, column_capacity, column_size;
int **mat;

/*Function to Create a Fixed Sized
2D Array using Heap Allocation*/
short unsigned int create_a_fixed_sized_2D_array(void)
{
    /*User Input for row capacity and row size*/
    printf("Enter the Row-Capacity and Row-Size of Matrix:");
    scanf("%lld%lld", &row_capacity, &row_size);
    /*User is advised to enter a Non-Negative Integer that is greater
    than or equal to 0 and less than (2 raised to power 63) as row capacity
    and row size otherwise the result will not be as predicted*/

    /*Checking for bounds for row capacity and row size*/
    if(row_capacity>LLONG_MAX || row_size>LLONG_MAX || row_capacity<0 || row_size<0)
    {
        if(row_capacity>LLONG_MAX || row_capacity<0)
        {
            printf("%lld is an Invalid Input for Row Capacity!\n", row_capacity);
            return 0;
        }
        else 
        {
            printf("%lld is an Invalid Input for Row Size!\n", row_size);
            return 0;
        }
    }

    /*User Input for column capacity and column size*/
    printf("Enter the Column-Capacity and Column-Size of Matrix:");
    scanf("%lld%lld", &column_capacity, &column_size);
    /*User is advised to enter a Non-Negative Integer that is greater
    than or equal to 0 and less than (2 raised to power 63) as column capacity
    and column size otherwise the result will not be as predicted*/

    /*Checking for bounds for column capacity and column size*/
    if(column_capacity>LLONG_MAX || column_size>LLONG_MAX || column_capacity<0 || column_size<0)
    {
        if(column_capacity>LLONG_MAX || column_capacity<0)
        {
            printf("%lld is an Invalid Input for Column Capacity!\n", column_capacity);
            return 0;
        }
        else 
        {
            printf("%lld is an Invalid Input for Column Size!\n", column_size);
            return 0;
        }
    }

    /*Comparison of size and capacity*/
    if(row_size>row_capacity || column_size>column_capacity)
    {
        if(row_size>row_capacity)
        {
            printf("Row Size can't be greater than Row Capacity\n");
            return 0;
        }
        else
        {
            printf("Column Size can't be greater than Column Capacity\n");
            return 0;
        }
    }

    /*Allocating Memory to Matrix*/
    mat=(int **)malloc(row_capacity*(sizeof(int *)));
    for(long long signed int i=0; i<row_capacity; i++)
    mat[i]=(int *)malloc(column_capacity*sizeof(int));

    /*Checking for Memory Allocation*/
    if(mat==NULL)
    {
        printf("Memory Allocation Failed!\n");
        return 0;
    }
    else 
    {
        for(long long unsigned int i=0; i<row_capacity; i++)
        {
            if(mat[i]==NULL)
            {
                printf("Memory Allocation Failed!\n");
                return 0;
            }
        }
    }

    /*Taking the Elements of Matrix as User Input*/
    printf("Enter %lld Elements for Matrix:\n", row_size*column_size);
    for(long long signed int i=0; i<row_size; i++)
    {
        for(long long signed int j=0; j<column_size; j++)
        {
            printf("Enter the Element for row %lld and column %lld:", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
    return 1;
}

/*Function to Display Elements of 2D Array: Display Function*/
void display(void)
{
    /*Displaying the Elements of Matrix: Traversing a Matrix*/
    printf("The Elements of Matrix are:\n");
    for(long long signed int i=0; i<row_size; i++)
    {
        for(long long signed int j=0; j<column_size; j++)
        printf("%d ", mat[i][j]);
        printf("\n");
    }
}

/*Function to Sort 2D Array row and column-wise*/
void sort_matrix()
{
    /*Sorting Elements of Matrix Row-wise*/
    for(long long signed int i=0; i<row_size; i++)
    {
        for(long long signed int j=0; j<column_size-1; j++)
        {
            for(long long signed int k=0; k<column_size-j-1; k++)
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
    for(long long signed int j=0; j<column_size; j++)
    {
        for(long long signed int i=0; i<row_size-1; i++)
        {
            for(long long signed int k=0; k<row_size-i-1; k++)
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
    printf("After Sorting the Matrix in Ascending order we have:\n");
    for(long long signed int i=0; i<row_size; i++)
    {
        for(long long signed int j=0; j<column_size; j++)
        printf("%d ", mat[i][j]);
        printf("\n");
    }
}

/*Function to Search for an Element in 2D Array*/
void search_element(int element)
{
    long long signed int i=0, j=column_size-1;
    while(i<row_size && j>=0)
    {
        if(element==mat[i][j])
        {
            printf("%d is there in Matrix at indices:(%lld,%lld)", element, i, j);
            return;
        }
        else if(element<mat[i][j])
        j--;
        else
        i++;
    }
    printf("%d is not there in Matrix!", element);
}

/*Driver Function(Code)*/
int main()
{
    if(!create_a_fixed_sized_2D_array())
    printf("Matrix Creation Failed!");
    else
    {
        display();
        sort_matrix();
        int element;
        printf("Enter the Element you want to search for in the Sorted Matrix:");
        scanf("%d", &element);
        search_element(element);
    }
    return 0;
}

