/*Java Program to Find a Subarray with Given Sum
in a Fixed Sized Array(Heap Allocation)*/

import java.util.*;

/*Creating an outer class*/
class Program_2{

    /*Creating an inner class*/
    class Implement_Fixed_Sized_Array{

        /*Data Members of class: int and int []*/
        int capacity, size;
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
        to Transform a Negative Array
        to a Positive Array*/
        void transform()
        {
            /*Here we are assuming that array doesn't contain
            the element -(2 raised to power 31)*/
            for(int i=0; i<size; i++)
            {
                if(arr[i]<0)
                arr[i]=Math.abs(arr[i]);
            }
        }

        /*Member Function of class:
        to Find Maximum Sum of a 
        Given Size Subarray*/
        boolean sub_sum(int sum)
        {
            /*We are making a small assumption that the sum of the
            array(subarray) won't be out of the bound of int*/
            int current_sum=0;
            int s=0;
            for(int e=0; e<size; e++)
            {
                current_sum+=arr[e];
                while(sum<current_sum)
                {
                    current_sum-=arr[s];
                    s++;
                }
                if(current_sum==sum)
                return true;
            }
            return false;
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
            IFSA.transform();
            int sum;
            System.out.println("Enter the Sum(it should be positive):");
            sum=sc.nextInt();
            if(sum<0)
            System.out.println(sum+" is Invalid Entry for Sum!");
            else
            {
                if(!IFSA.sub_sum(sum))
                System.out.println("There is no Subarray that can produce the sum:"+sum);
                else
                System.out.println("There is a Subarray that can produce the sum:"+sum);
            }
        }
        sc.close();
    }
}

