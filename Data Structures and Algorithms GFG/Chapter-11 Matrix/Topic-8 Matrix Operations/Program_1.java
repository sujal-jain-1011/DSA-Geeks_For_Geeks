/*Java Program to Perform Operations: Addition, Subtraction
and Multiplication of Fixed Sized 2D Arrays(Heap Allocation)*/

import java.util.*;

/*We will be Performing Operations on only two Matrices
However we can take into account more number of Matrices as well*/
/*Creating an outer class*/
public class Program_1{

    /*Creating an inner class*/
    class Implement_Fixed_Sized_2D_Array{

        /*Data Members of class:
        int [], int[][][] and int[][]*/
        int []row_capacity=new int[2], 
        row_size=new int[2], 
        column_capacity=new int[2], 
        column_size=new int[2];
        int [][][]mat=new int[2][][];
        int [][]result;

        /*Defining readInputrow Function*/
        void readInputRow(Scanner sc, int mat_num)
        {
            System.out.println("Enter the Row-Capacity and Row-Size of Matrix "+mat_num+":");
            row_capacity[mat_num-1]=sc.nextInt();
            row_size[mat_num-1]=sc.nextInt();
        }

        /*Defining readInputcolumn Function*/
        void readInputColumn(Scanner sc, int mat_num)
        {
            System.out.println("Enter the Column-Capacity and Column-Size of Matrix "+mat_num+":");
            column_capacity[mat_num-1]=sc.nextInt();
            column_size[mat_num-1]=sc.nextInt();
        }

        boolean create_a_fixed_sized_2D_array(Scanner sc, int mat_num)
        {
            if(mat_num<1 || mat_num>2)
            {
                System.out.println("You have entered an Incorrect Matrix Number!");
                return false;
            }

            /*User Input for row capacity and row size*/
            readInputRow(sc, mat_num);
            /*User is advised to enter a Non-Negative Integer that is greater
            than or equal to 0 and less than (2 raised to power 31) as row capacity
            and row size otherwise the result will not be as predicted*/

            /*Checking for bounds for row capacity and row size*/
            if(row_capacity[mat_num-1]>Integer.MAX_VALUE || row_size[mat_num-1]>Integer.MAX_VALUE || row_capacity[mat_num-1]<0 || row_size[mat_num-1]<0)
            {
                if(row_capacity[mat_num-1]>Integer.MAX_VALUE || row_capacity[mat_num-1]<0)
                {
                    System.out.println(row_capacity[mat_num-1]+" is an Invalid Input for Row Capacity!");
                    return false;
                }
                else 
                {
                    System.out.println(row_size[mat_num-1]+" is an Invalid Input for Row Size!");
                    return false;
                }
            }

            /*User Input for column capacity and column size*/
            readInputColumn(sc, mat_num);
            /*User is advised to enter a Non-Negative Integer that is greater
            than or equal to 0 and less than (2 raised to power 31) as column capacity
            and column size otherwise the result will not be as predicted*/

            /*Checking for bounds for column capacity and column size*/
            if(column_capacity[mat_num-1]>Integer.MAX_VALUE || column_size[mat_num-1]>Integer.MAX_VALUE || column_capacity[mat_num-1]<0 || column_size[mat_num-1]<0)
            {
                if(column_capacity[mat_num-1]>Integer.MAX_VALUE || column_capacity[mat_num-1]<0)
                {
                    System.out.println(column_capacity[mat_num-1]+" is an Invalid Input for Column Capacity!");
                    return false;
                }
                else 
                {
                    System.out.println(column_size[mat_num-1]+" is an Invalid Input for Column Size!");
                    return false;
                }
            }

            /*Comparison of size and capacity*/
            if(row_size[mat_num-1]>row_capacity[mat_num-1] || column_size[mat_num-1]>column_capacity[mat_num-1])
            {
                if(row_size[mat_num-1]>row_capacity[mat_num-1])
                {
                    System.out.println("Row Size can't be greater than Row Capacity");
                    return false;
                }
                else
                {
                    System.out.println("Column Size can't be greater than Column Capacity");
                    return false;
                }
            }

            /*Allocating Memory to Matrix*/
            try{
                mat[mat_num-1]=new int[row_capacity[mat_num-1]][column_capacity[mat_num-1]];
            }
            catch(OutOfMemoryError e){
                System.out.println("Memory Allocation Failed!");
            }
            
            /*Taking the Elements of Matrix as User Input*/
            System.out.println("Enter "+row_size[mat_num-1]*column_size[mat_num-1]+" Elements for Matrix "+mat_num+":");
            for(int i=0; i<row_size[mat_num-1]; i++)
            {
                for(int j=0; j<column_size[mat_num-1]; j++)
                {
                    System.out.println("Enter the Element for row "+(i+1)+" and column "+(j+1)+":");
                    int temp=sc.nextInt();
                    mat[mat_num-1][i][j]=temp;
                }
            }
            return true;
        }

        /*Member Function of class:
        to Display Elements of 2D Array: Display Function*/
        void display(int mat_num)
        {
            if(mat_num<1 || mat_num>2)
            {
                System.out.println("You have entered an Incorrect Matrix Number!");
                return;
            }

            /*Displaying the Elements of Matrix: Traversing a Matrix*/
            System.out.println("The Elements of Matrix "+mat_num+" are:");
            for(int i=0; i<row_size[mat_num-1]; i++)
            {
                for(int j=0; j<column_size[mat_num-1]; j++)
                System.out.print(mat[mat_num-1][i][j]+" ");
                System.out.println();
            }
        }

        /*Member Function of class:
        to Add two Matrices*/
        boolean add_matrices(int mat_num_1, int mat_num_2)
        {
            if((mat_num_1<1 || mat_num_1>2) || (mat_num_2<1 || mat_num_2>2))
            {
                System.out.println("You have entered an Incorrect Matrix Numbers!");
                System.out.println("Thus, Addition can't be Performed!");
                return false;
            }
            if((row_size[mat_num_1-1]!=row_size[mat_num_2-1]) || (column_size[mat_num_1-1]!=column_size[mat_num_2-1]))
            {
                System.out.println("Incompatible Dimensions for Matrix Addition!");
                return false;
            }

            /*Allocating Memory to Result Matrix*/
            try{
                result=new int[row_capacity[mat_num_1-1]][column_capacity[mat_num_1-1]];
            }
            catch(OutOfMemoryError e){
                System.out.println("Memory Allocation Failed!");
            }

            for(int i=0; i<row_size[mat_num_1-1]; i++)
            {
                for(int j=0; j<column_size[mat_num_1-1]; j++)
                result[i][j]=mat[mat_num_1-1][i][j]+mat[mat_num_2-1][i][j];
            }

            /*Displaying the Resultant Matrix*/
            System.out.println("The Addition of two entered Matrices is:");
            for(int i=0; i<row_size[mat_num_1-1]; i++)
            {
                for(int j=0; j<column_size[mat_num_1-1]; j++)
                System.out.print(result[i][j]+" ");
                System.out.println();
            }
            return true;
        }

        /*Member Function of class:
        to Subtract two Matrices*/
        boolean subtract_matrices(int mat_num_1, int mat_num_2)
        {
            if((mat_num_1<1 || mat_num_1>2) || (mat_num_2<1 || mat_num_2>2))
            {
                System.out.println("You have entered an Incorrect Matrix Numbers!");
                System.out.println("Thus, Subtraction can't be Performed!");
                return false;
            }
            if((row_size[mat_num_1-1]!=row_size[mat_num_2-1]) || (column_size[mat_num_1-1]!=column_size[mat_num_2-1]))
            {
                System.out.println("Incompatible Dimensions for Matrix Subtraction!");
                return false;
            }

            for(int i=0; i<row_size[mat_num_1-1]; i++)
            {
                for(int j=0; j<column_size[mat_num_1-1]; j++)
                result[i][j]=mat[mat_num_1-1][i][j]-mat[mat_num_2-1][i][j];
            }

            /*Displaying the Resultant Matrix*/
            System.out.println("The Subtraction of two entered Matrices is:");
            for(int i=0; i<row_size[mat_num_1-1]; i++)
            {
                for(int j=0; j<column_size[mat_num_1-1]; j++)
                System.out.print(result[i][j]+" ");
                System.out.println();
            }
            return true;
        }

        /*Member Function of class:
        to Multiply two Matrices*/
        boolean multiply_matrices(int mat_num_1, int mat_num_2)
        {
            if((mat_num_1<1 || mat_num_1>2) || (mat_num_2<1 || mat_num_2>2))
            {
                System.out.println("You have entered an Incorrect Matrix Numbers!");
                System.out.println("Thus, Multiplication can't be Performed!");
                return false;
            }
            if(column_size[mat_num_1-1]!=row_size[mat_num_2-1])
            {
                System.out.println("Incompatible Dimensions for Matrix Multiplication!");
                return false;
            }

            for(int i=0; i<row_size[mat_num_1-1]; i++)
            {
                for(int j=0; j<column_size[mat_num_2-1]; j++)
                {
                    result[i][j]=0;
                    for(int k=0; k<row_size[mat_num_2-1]; k++)
                    result[i][j]+=mat[mat_num_1-1][i][k]*mat[mat_num_2-1][k][j];
                }
            }

            /*Displaying the Resultant Matrix*/
            System.out.println("The Multiplication of two entered Matrices is:");
            for(int i=0; i<row_size[mat_num_1-1]; i++)
            {
                for(int j=0; j<column_size[mat_num_1-1]; j++)
                System.out.print(result[i][j]+" ");
                System.out.println();
            }
            return true;
        }
    }

    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        Program_1 program_1=new Program_1();
        Program_1.Implement_Fixed_Sized_2D_Array IFS2A=program_1.new Implement_Fixed_Sized_2D_Array();
        if(!IFS2A.create_a_fixed_sized_2D_array(sc, 1))
        System.out.println("Matrix "+1+" creation failed!");
        else 
        IFS2A.display(1);
        if(!IFS2A.create_a_fixed_sized_2D_array(sc, 2))
        System.out.println("Matrix "+2+" creation failed!");
        else 
        IFS2A.display(2);

        /*Operations on Matrices*/
        if(!IFS2A.add_matrices(1,2))
        System.out.println("Error while Adding two matrices!");
        if(!IFS2A.subtract_matrices(1,2))
        System.out.println("Error while Subtracting two matrices!");
        if(!IFS2A.multiply_matrices(1,2))
        System.out.println("Error while Multiplying two matrices!");

        sc.close();
    }
}