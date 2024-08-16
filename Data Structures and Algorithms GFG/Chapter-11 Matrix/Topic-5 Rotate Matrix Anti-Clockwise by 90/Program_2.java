/*Java Program to Rotate a Fixed Sized 
2D Array(Heap Allocation) by 90*/

import java.util.*;

/*Creating an outer class*/
public class Program_2{

    /*Creating an inner class*/
    class Implement_Fixed_Sized_2D_Array{

        /*Data Members of class: int and int [][]*/
        int row_capacity, row_size, column_capacity, column_size;
        int [][]mat;

        /*Defining readInput Function*/
        void readInput(Scanner sc)
        {
            System.out.println("Enter the Row Capacity and Row Size of Matrix:");
            row_capacity=sc.nextInt();
            row_size=sc.nextInt();
            System.out.println("Enter the Column Capacity and Column Size of Matrix:");
            column_capacity=sc.nextInt();
            column_size=sc.nextInt();
        }

        /*Member Function of class:
        to Create a Fixed Sized 2D
        Array using Heap Allocation*/
        boolean create_a_fixed_sized_2D_array()
        {
            Scanner sc=new Scanner(System.in);
            readInput(sc);
            /*User is advised to enter a Non-Negative Integer that is greater than or 
            equal to 0 and less than (2 raised to power 31) as row and column capacity 
            and row and column size otherwise the result will not be as predicted*/

            /*Checking for bounds for row capacity and row size*/
            if(row_capacity>Integer.MAX_VALUE || row_size>Integer.MAX_VALUE || row_capacity<0 || row_size<0)
            {
                if(row_capacity>Integer.MAX_VALUE || row_capacity<0)
                {
                    System.out.println(row_capacity+" is an Invalid Input for Row Capacity!");
                    return false;
                }
                else 
                {
                    System.out.println(row_size+" is an Invalid Input for Row Size!");
                    return false;
                }
            }

            /*Checking for bounds for column capacity and column size*/
            if(column_capacity>Integer.MAX_VALUE || column_size>Integer.MAX_VALUE || column_capacity<0 || column_size<0)
            {
                if(column_capacity>Integer.MAX_VALUE || column_capacity<0)
                {
                    System.out.println(column_capacity+" is an Invalid Input for Column Capacity!");
                    return false;
                }
                else 
                {
                    System.out.println(column_size+" is an Invalid Input for Column Size!");
                    return false;
                }
            }

            /*Comparison of size and capacity*/
            if(row_size>row_capacity || column_size>column_capacity)
            {
                if(row_size>row_capacity)
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
                mat=new int[row_capacity][column_capacity];
            }
            catch(OutOfMemoryError e){
                System.out.println("Memory Allocation Failed!");
            }

            /*Taking the Elements of Matrix as User Input*/
            System.out.println("Enter "+(row_size*column_size)+" Elements for Matrix:");
            for(int i=0; i<row_size; i++)
            {
                for(int j=0; j<column_size; j++)
                {
                    System.out.print("Enter the Element for row "+(i+1)+" and column "+(j+1)+":");
                    int temp=sc.nextInt();
                    mat[i][j]=temp;
                }
            }
            sc.close();
            return true;
        }

        /*Member Function of class:
        to Display Elements of 2D Array:
        Display Function*/
        void display()
        {
            /*Displaying the Elements of Matrix: Traversing a Matrix*/
            System.out.println("The Elements of Matrix are:");
            for(int i=0; i<row_size; i++)
            {
                for(int j=0; j<column_size; j++)
                System.out.print(mat[i][j]+" ");
                System.out.println();
            }
        }

        /*Member Function of class:
        to Print Transpose of 2D Array*/
        void transpose()
        {
            /*Checking For Dimensions of Matrix*/
            if(row_size!=column_size)
            {
                System.out.println("Invalid Dimensions!");
                System.out.println("As entered Matrix is not a Square Matrix!");
                return;
            }
            
            for(int i=0; i<row_size; i++)
            {
                for(int j=i+1; j<column_size; j++)
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
            
            for(int j=0; j<column_size; j++)
            {
                int low=0, high=row_size-1;
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
            System.out.println("After Rotating by 90, the Matrix is:");
            for(int i=0; i<row_size; i++)
            {
                for(int j=0; j<column_size; j++)
                System.out.print(mat[i][j]+" ");
                System.out.println();
            }
        }
    }

    /*Driver Function(Code)*/
    public static void main(String[] args)
    {
        Program_2 program_2=new Program_2();
        Program_2.Implement_Fixed_Sized_2D_Array IFS2A=program_2.new Implement_Fixed_Sized_2D_Array();
        if(!IFS2A.create_a_fixed_sized_2D_array())
        System.out.println("Matrix Creation Failed!");
        else
        {
            IFS2A.display();
            IFS2A.rotate_90();
        }
    }
}

