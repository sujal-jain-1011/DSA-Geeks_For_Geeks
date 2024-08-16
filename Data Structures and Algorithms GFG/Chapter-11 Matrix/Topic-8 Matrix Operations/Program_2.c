/*C Program to Perform Operations: Addition, Subtraction
and Multiplication of Fixed Sized 2D Arrays(Heap Allocation)*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*Decalaring Global Variables*/
/*We will be Performing Operations on only two Matrices
However we can take into account more number of Matrices as well*/
long long signed int row_capacity[2], row_size[2], column_capacity[2], column_size[2];
int **mat[2];
int **result;

/*Function to Create a Fixed Sized
2D Array using Heap Allocation*/
short unsigned int create_a_fixed_sized_2D_array(short signed int mat_num)
{
    if(mat_num<1 || mat_num>2)
    {
        printf("You have entered an Incorrect Matrix Number!");
        return 0;
    }

    /*User Input for row capacity and row size*/
    printf("Enter the Row-Capacity and Row-Size of Matrix %hd:", mat_num);
    scanf("%lld%lld", &row_capacity[mat_num-1], &row_size[mat_num-1]);
    /*User is advised to enter a Non-Negative Integer that is greater
    than or equal to 0 and less than (2 raised to power 63) as row capacity
    and row size otherwise the result will not be as predicted*/

    /*Checking for bounds for row capacity and row size*/
    if(row_capacity[mat_num-1]>LLONG_MAX || row_size[mat_num-1]>LLONG_MAX || row_capacity[mat_num-1]<0 || row_size[mat_num-1]<0)
    {
        if(row_capacity[mat_num-1]>LLONG_MAX || row_capacity[mat_num-1]<0)
        {
            printf("%lld is an Invalid Input for Row Capacity!\n", row_capacity[mat_num-1]);
            return 0;
        }
        else 
        {
            printf("%lld is an Invalid Input for Row Size!\n", row_size[mat_num-1]);
            return 0;
        }
    }

    /*User Input for column capacity and column size*/
    printf("Enter the Column-Capacity and Column-Size of Matrix %hd:", mat_num);
    scanf("%lld%lld", &column_capacity[mat_num-1], &column_size[mat_num-1]);
    /*User is advised to enter a Non-Negative Integer that is greater
    than or equal to 0 and less than (2 raised to power 63) as column capacity
    and column size otherwise the result will not be as predicted*/

    /*Checking for bounds for column capacity and column size*/
    if(column_capacity[mat_num-1]>LLONG_MAX || column_size[mat_num-1]>LLONG_MAX || column_capacity[mat_num-1]<0 || column_size[mat_num-1]<0)
    {
        if(column_capacity[mat_num-1]>LLONG_MAX || column_capacity[mat_num-1]<0)
        {
            printf("%lld is an Invalid Input for Column Capacity!\n", column_capacity[mat_num-1]);
            return 0;
        }
        else 
        {
            printf("%lld is an Invalid Input for Column Size!\n", column_size[mat_num-1]);
            return 0;
        }
    }

    /*Comparison of size and capacity*/
    if(row_size[mat_num-1]>row_capacity[mat_num-1] || column_size[mat_num-1]>column_capacity[mat_num-1])
    {
        if(row_size[mat_num-1]>row_capacity[mat_num-1])
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
    mat[mat_num-1]=(int **)malloc(row_capacity[mat_num-1]*(sizeof(int *)));
    for(long long signed int i=0; i<row_capacity[mat_num-1]; i++)
    mat[mat_num-1][i]=(int *)malloc(column_capacity[mat_num-1]*sizeof(int));

    /*Checking for Memory Allocation*/
    if(mat[mat_num-1]==NULL)
    {
        printf("Memory Allocation Failed!\n");
        return 0;
    }
    else 
    {
        for(long long signed int i=0; i<row_capacity[mat_num-1]; i++)
        {
            if(mat[mat_num-1][i]==NULL)
            {
                printf("Memory Allocation Failed!\n");
                return 0;
            }
        }
    }

    /*Taking the Elements of Matrix as User Input
    Here we are making a small assumption that the
    number of elements lie within the positive range
    of long long signed int*/
    printf("Enter %lld Elements for Matrix %hd:\n", row_size[mat_num-1]*column_size[mat_num-1], mat_num);
    for(long long signed int i=0; i<row_size[mat_num-1]; i++)
    {
        for(long long signed int j=0; j<column_size[mat_num-1]; j++)
        {
            printf("Enter the Element for row %llu and column %llu:", i+1, j+1);
            scanf("%d", &mat[mat_num-1][i][j]);
        }
    }
    return 1;
}

/*Function to Display Elements of 2D Array: Display Function*/
void display(short signed int mat_num)
{
    if(mat_num<1 || mat_num>2)
    {
        printf("You have entered an Incorrect Matrix Number!");
        return;
    }

    /*Displaying the Elements of Matrix: Traversing a Matrix*/
    printf("The Elements of Matrix %hd are:\n", mat_num);
    for(long long signed int i=0; i<row_size[mat_num-1]; i++)
    {
        for(long long signed int j=0; j<column_size[mat_num-1]; j++)
        printf("%d ", mat[mat_num-1][i][j]);
        printf("\n");
    }
}

/*Function to Add two Matrices*/
short unsigned int add_matrices(short signed int mat_num_1, short signed int mat_num_2)
{
    if((mat_num_1<1 || mat_num_1>2) || (mat_num_2<1 || mat_num_2>2))
    {
        printf("You have entered an Incorrect Matrix Numbers!\n");
        printf("Thus, Addition can't be Performed!\n");
        return 0;
    }
    if((row_size[mat_num_1-1]!=row_size[mat_num_2-1]) || (column_size[mat_num_1-1]!=column_size[mat_num_2-1]))
    {
        printf("Incompatible Dimensions for Matrix Addition!\n");
        return 0;
    }

    /*Allocating Memory to Result Matrix*/
    result=(int **)malloc(row_capacity[mat_num_1-1]*sizeof(int *));
    for(long long signed int i=0; i<row_capacity[mat_num_1-1]; i++)
    result[i]=(int *)malloc(column_capacity[mat_num_1-1]*sizeof(int));

    /*Checking for Memory Allocation*/
    if(result==NULL)
    {
        printf("Memory Allocation Failed!\n");
        return 0;
    }
    else 
    {
        for(long long signed int i=0; i<row_capacity[mat_num_1-1]; i++)
        {
            if(result[i]==NULL)
            {
                printf("Memory Allocation Failed!\n");
                return 0;
            }
        }
    }

    for(long long signed int i=0; i<row_size[mat_num_1-1]; i++)
    {
        for(long long signed int j=0; j<column_size[mat_num_1-1]; j++)
        result[i][j]=mat[mat_num_1-1][i][j]+mat[mat_num_2-1][i][j];
    }

    /*Displaying the Resultant Matrix*/
    printf("The Addition of two entered Matrices is:\n");
    for(long long signed int i=0; i<row_size[mat_num_1-1]; i++)
    {
        for(long long signed int j=0; j<column_size[mat_num_1-1]; j++)
        printf("%d ", result[i][j]);
        printf("\n");
    }

    /*Deallocating Memory to Result Matrix*/
    for(long long signed int i=0; i<row_capacity[mat_num_1-1]; i++)
    free(result[i]);
    free(result);
    return 1;
}

/*Function to Subtract two Matrices*/
short unsigned int subtract_matrices(short signed int mat_num_1, short signed int mat_num_2)
{
    if((mat_num_1<1 || mat_num_1>2) || (mat_num_2<1 || mat_num_2>2))
    {
        printf("You have entered an Incorrect Matrix Numbers!\n");
        printf("Thus, Subtraction can't be Performed!\n");
        return 0;
    }
    if((row_size[mat_num_1-1]!=row_size[mat_num_2-1]) || (column_size[mat_num_1-1]!=column_size[mat_num_2-1]))
    {
        printf("Incompatible Dimensions for Matrix Subtraction!\n");
        return 0;
    }

    /*Allocating Memory to Result Matrix*/
    result=(int **)malloc(row_capacity[mat_num_1-1]*sizeof(int *));
    for(long long signed int i=0; i<row_capacity[mat_num_1-1]; i++)
    result[i]=(int *)malloc(column_capacity[mat_num_1-1]*sizeof(int));

    /*Checking for Memory Allocation*/
    if(result==NULL)
    {
        printf("Memory Allocation Failed!\n");
        return 0;
    }
    else 
    {
        for(long long signed int i=0; i<row_capacity[mat_num_1-1]; i++)
        {
            if(result[i]==NULL)
            {
                printf("Memory Allocation Failed!\n");
                return 0;
            }
        }
    }

    for(long long signed int i=0; i<row_size[mat_num_1-1]; i++)
    {
        for(long long signed int j=0; j<column_size[mat_num_1-1]; j++)
        result[i][j]=mat[mat_num_1-1][i][j]-mat[mat_num_2-1][i][j];
    }

    /*Displaying the Resultant Matrix*/
    printf("The Subtraction of two entered Matrices is:\n");
    for(long long signed int i=0; i<row_size[mat_num_1-1]; i++)
    {
        for(long long signed int j=0; j<column_size[mat_num_1-1]; j++)
        printf("%d ", result[i][j]);
        printf("\n");
    }

    /*Deallocating Memory to Result Matrix*/
    for(long long signed int i=0; i<row_capacity[mat_num_1-1]; i++)
    free(result[i]);
    free(result);
    return 1;
}

/*Function to Multiply two Matrices*/
short unsigned int multiply_matrices(short signed int mat_num_1, short signed int mat_num_2)
{
    if((mat_num_1<1 || mat_num_1>2) || (mat_num_2<1 || mat_num_2>2))
    {
        printf("You have entered an Incorrect Matrix Numbers!\n");
        printf("Thus, Multiplication can't be Performed!\n");
        return 0;
    }
    if(column_size[mat_num_1-1]!=row_size[mat_num_2-1])
    {
        printf("Incompatible Dimensions for Matrix Multiplication!\n");
        return 0;
    }

    /*Allocating Memory to Result Matrix*/
    result=(int **)malloc(row_capacity[mat_num_1-1]*sizeof(int *));
    for(long long signed int i=0; i<row_capacity[mat_num_1-1]; i++)
    result[i]=(int *)malloc(column_capacity[mat_num_2-1]*sizeof(int));

    /*Checking for Memory Allocation*/
    if(result==NULL)
    {
        printf("Memory Allocation Failed!\n");
        return 0;
    }
    else 
    {
        for(long long signed int i=0; i<row_capacity[mat_num_1-1]; i++)
        {
            if(result[i]==NULL)
            {
                printf("Memory Allocation Failed!\n");
                return 0;
            }
        }
    }

    for(long long signed int i=0; i<row_size[mat_num_1-1]; i++)
    {
        for(long long signed int j=0; j<column_size[mat_num_2-1]; j++)
        {
            result[i][j]=0;
            for(long long signed int k=0; k<row_size[mat_num_2-1]; k++)
            result[i][j]+=mat[mat_num_1-1][i][k]*mat[mat_num_2-1][k][j];
        }
    }

    /*Displaying the Resultant Matrix*/
    printf("The Multiplication of two entered Matrices is:\n");
    for(long long signed int i=0; i<row_size[mat_num_1-1]; i++)
    {
        for(long long signed int j=0; j<column_size[mat_num_2-1]; j++)
        printf("%d ", result[i][j]);
        printf("\n");
    }

    /*Deallocating Memory to Result Matrix*/
    for(long long signed int i=0; i<row_capacity[mat_num_1-1]; i++)
    free(result[i]);
    free(result);
    return 1;
}

/*Driver Function(Code)*/
int main()
{
    if(!create_a_fixed_sized_2D_array(1))
    printf("Matrix %hd creation failed!", 1);
    else 
    display(1);
    if(!create_a_fixed_sized_2D_array(2))
    printf("Matrix %hd creation failed!", 2);
    else 
    display(2);

    /*Operations on Matrices*/
    if(!add_matrices(1,2))
    printf("Error while Adding two matrices!\n");
    if(!subtract_matrices(1,2))
    printf("Error while Subtracting two matrices!\n");
    if(!multiply_matrices(1,2))
    printf("Error while Multiplying two matrices!\n");

    return 0;
}