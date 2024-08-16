/*Java Program to Find Equilibrium Point in 
a Fixed Sized Array(Heap Allocation)*/

import java.util.*;

/*Creating an outer class*/
class Program_2{

    /*Creating an inner class*/
    class Implement_Fixed_Sized_Array{

        /*Data Members of class: int and int []*/
        int capacity, size;
        int []arr;
        int []psum;
        int []ssum;

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
        to Precompute psum Array*/
        boolean precompute_prefix_sum()
        {
            /*Allocating Memory to psum Array*/
            try{
                psum=new int[size];
            }
            catch(OutOfMemoryError e){
                System.out.println("Memory Allocation Failed for psum Array!");
                System.out.println("Therefore, can't find Equilibrium Point!");
            }

            psum[0]=arr[0];
            for(int i=1; i<size; i++)
            psum[i]=psum[i-1]+arr[i];
            return true;
        }

        /*Member Function of class:
        to Precompute ssum Array*/
        boolean precompute_suffix_sum()
        {
            /*Allocating Memory to ssum Array*/
            try{
                ssum=new int[size];
            }
            catch(OutOfMemoryError e){
                System.out.println("Memory Allocation Failed for ssum Array!");
                System.out.println("Therefore, can't find Equilibrium Point!");
            }

            ssum[size-1]=arr[size-1];
            for(int i=1; i<size; i++)
            ssum[size-i-1]=ssum[size-i]+arr[size-i-1];
            return true;
        }

        /*Member Function of class:
        to Find Equilibrium Point*/
        boolean equilibrium_point()
        {
            if(!precompute_prefix_sum() || !precompute_suffix_sum())
            return false;
            /*We are making a small assumption that the sum of integer elements
            of the array is within the bound of integer, that is an integer*/
            if((psum[size-2]==0) || (ssum[1]==0))
            return true;
            for(int i=1; i<size-1; i++)
            {
                if(psum[i-1]==ssum[i+1])
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
            if(!IFSA.equilibrium_point())
            System.out.println("There does not exist any Equilibrium Point in the Array!");
            else
            System.out.println("There exists an Equilibrium Point in the Array!");
        }
        sc.close();
    }
}

