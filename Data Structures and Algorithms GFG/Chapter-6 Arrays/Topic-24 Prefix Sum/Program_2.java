/*Java Program to Find Prefix Sum and Prefix Weighted
Sum in a Fixed Sized Array(Heap Allocation)*/

import java.util.*;

/*Creating an outer class*/
class Program_2{

    /*Creating an inner class*/
    class Implement_Fixed_Sized_Array{

        /*Data Members of class: int and int []*/
        int capacity, size;
        int []arr;
        int []psum;
        int []pwsum;

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
        to Precompute Prefix Sum*/
        boolean precompute_prefix_sum()
        {
            /*Allocating Memory to psum Array*/
            try{
                psum=new int[size];
            }
            catch(OutOfMemoryError e){
                System.out.println("Memory Allocation Failed for psum Array!");
                System.out.println("Thus, can't compute Prefix Weighted Sum!");
                System.out.println("Hence, returning the Lowest Possible Integer value!");
            }

            psum[0]=arr[0];
            for(int i=1; i<size; i++)
            psum[i]=psum[i-1]+arr[i];
            return true;
        }

        /*Member Function of class:
        to Find Prefix Sum*/
        int prefix_sum(int start, int end)
        {
            /*We are making a small assumption that the sum of integer elements
            of the array is within the bound of integer, that is an integer*/
            if(!precompute_prefix_sum())
            return Integer.MIN_VALUE;
            if(start==0)
            return psum[end];
            return (psum[end]-psum[start-1]);
        }

        /*Member Function of class:
        to Precompute Prefix Weighted Sum*/
        boolean precompute_prefix_weighted_sum()
        {
            /*Allocating Memory to psum Array*/
            try{
                pwsum=new int[size];
            }
            catch(OutOfMemoryError e){
                System.out.println("Memory Allocation Failed for pwsum Array!");
                System.out.println("Thus, can't compute Prefix Weighted Sum!");
                System.out.println("Hence, returning the Lowest Possible Integer value!");
            }
            
            pwsum[0]=0*arr[0];
            for(int i=1; i<size; i++)
            pwsum[i]=pwsum[i-1]+i*arr[i];
            return true;
        }

        /*Member Function of class:
        to Find Prefix Weighted Sum*/
        int prefix_weighted_sum(int start, int end)
        {
            /*We are making a small assumption that the sum of product of integer elements 
            with their weights of the array is within the bound of integer, that is an integer*/
            if(!precompute_prefix_weighted_sum())
            return Integer.MIN_VALUE;
            if(start==0)
            return pwsum[end]+psum[end];
            return ((pwsum[end]-pwsum[start-1])-(start-1)*(psum[end]-psum[start-1]));
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
            int start, end;
            System.out.println("Enter the Starting and Ending Index for Prefix Sum:");
            start=sc.nextInt();
            end=sc.nextInt();
            /*User is advised to enter Non-Negative Integers that are greater
            than or equal to 0 and less than (2 raised to power 31) as starting
            and ending indices otherwise the result will not be as predicted*/
            if(start>Integer.MAX_VALUE || start<0)
            System.out.println(start+" in an Invalid Input for Starting Index!");
            else if(end>Integer.MAX_VALUE || end<0)
            System.out.println(end+" in an Invalid Input for Ending Index!");
            else if(start>end)
            System.out.println(start+" as Starting Index can't be greater than "+end+" as Ending Index!");
            else
            {
                System.out.println("The Prefix Sum of the Array from Index "+start+" to "+end+" is:"+IFSA.prefix_sum(start, end));
                System.out.println("The Prefix Weighted Sum of the Array from Index "+start+" to "+end+" is:"+IFSA.prefix_weighted_sum(start, end));
            }
        }
        sc.close();
    }
}

