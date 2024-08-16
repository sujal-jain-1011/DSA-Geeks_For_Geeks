/*Java Program to Find the Maximum Difference 
in a Fixed Sized Array(Heap Allocation)*/

import java.util.*;

/*Creating an outer class*/
class Program_2{

    /*Creating an inner class*/
    class Implement_Fixed_Sized_Array{

        /*Data Members of class: int and int []*/
        int capacity, size, position;
        int []arr;

        /*Defining readInput Function*/
        void readInput(Scanner sc)
        {
            System.out.println("Enter the Capacity of Array:");
            capacity=sc.nextInt();
            System.out.println("Enter the Size of Array:");
            size=sc.nextInt();
        }

        /*Member Function of class:
        to Create a Fixed Sized
        Array using Heap Allocation*/
        boolean create_a_fixed_sized_array(Scanner sc)
        {
            readInput(sc);
            /*User is advised to enter a Non-Negative Integer that is
            greater than or equal to 0 and less than (2 raised to power 63)
            as capacity and size otherwise the result will not be as predicted*/

            /*Checking for bounds for capacity*/
            if(capacity>Integer.MAX_VALUE || capacity<0)
            {
                System.out.println(capacity+" is an Invalid Input for Capacity!");
                return false;
            }

            /*Checking for bounds for size*/
            if(size>Integer.MAX_VALUE || size<0)
            {
                System.out.println(size+" is an Invalid Input for Size!");
                return false;
            }

            /*Comparison of size and capacity*/
            if(size>capacity)
            {
                System.out.println("Size can't be greater than Capacity!");
                return false;
            }

            /*Allocating Memory to Array*/
            try{
                arr=new int[capacity];
            }
            catch(OutOfMemoryError e){
                System.out.println("Memory Allocation Failed!");
            }

            /*Taking the Elements of Array as User Input*/
            System.out.println("Enter "+size+" Elements for Array:");
            for(int i=0; i<size; i++)
            {
                System.out.println("Enter Element "+(i+1)+" of Array:");
                arr[i]=sc.nextInt();
            }
            return true;
        }

        /*Member Function of class:
        to Display Elements of Array:
        Display Function*/
        void display()
        {
            /*Displaying the Elements of Array: Traversing an Array*/
            System.out.println("The Elements of Array are:");
            for(int i=0; i<size; i++)
            System.out.println("Element "+(i+1)+" of Array is:"+arr[i]);
        }

        /*Member Function of class:
        to Solve Stock Buy and Sell Problem*/
        int maximum_profit()
        {
            int maximum_profit=0;
            for(int i=1; i<size; i++)
            {
                if(arr[i]>arr[i-1])
                maximum_profit+=(arr[i]-arr[i-1]);
            }
            return maximum_profit;
        }
    }

    /*Driver Function(Code)*/
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        Program_2 program_2=new Program_2();
        Program_2.Implement_Fixed_Sized_Array IFSA=program_2.new Implement_Fixed_Sized_Array();
        if(!IFSA.create_a_fixed_sized_array(sc))
        System.out.println("Array Creation Failed!");
        else
        {
            IFSA.display();
            System.out.println("The Maximum Profit is:"+IFSA.maximum_profit());
        }
        sc.close();
    }
}

