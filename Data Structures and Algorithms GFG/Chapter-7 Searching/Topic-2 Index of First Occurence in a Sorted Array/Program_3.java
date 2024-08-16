/*Java Program to Find Index of First Occurence
in a Sorted Fixed Sized Array(Heap Allocation)*/

import java.util.*;

/*Creating an outer class*/
class Program_3{

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
        to Find the Index of First Occurence of
        an Element-Using Recursive Binary Search*/
        void index_first_occurence(int element, int low, int high)
        {
            if(low>high)
            {
                System.out.println(element+" is not present in the Array");
                return;
            }
            int mid=(low+high)/2;
            if(arr[mid]==element)
            {
                if(mid==0 || arr[mid-1]!=element)
                {
                    System.out.println("The Index of First Occurence of "+element+" is:"+mid);
                    return;
                }
                index_first_occurence(element, low, mid-1);
            }
            else if(arr[mid]<element)
            index_first_occurence(element, mid+1, high);
            else
            index_first_occurence(element, low, mid-1);
        }
    }

    /*Driver Function(Code)*/
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        Program_3 program_3=new Program_3();
        Program_3.Implement_Fixed_Sized_Array IFSA=program_3.new Implement_Fixed_Sized_Array();
        if(!IFSA.create_a_fixed_sized_array(sc))
        System.out.println("Array Creation Failed!");
        else
        {
            IFSA.display();
            int element;
            System.out.print("Enter an element:");
            element=sc.nextInt();
            IFSA.index_first_occurence(element, 0, IFSA.size-1);
        }
        sc.close();
    }
}


