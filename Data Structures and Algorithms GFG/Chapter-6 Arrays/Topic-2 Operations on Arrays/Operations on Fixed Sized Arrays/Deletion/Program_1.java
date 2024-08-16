/*C++ Program to Delete a Given Element 
from a Fixed Sized Array(Heap Allocation)*/

import java.util.*;

/*Creating an outer class*/
class Program_1{

    /*Creating an inner class*/
    class Implement_Fixed_Sized_Array{

        /*Data Members of class: int and int []*/
        int capacity, size;
        int []arr;
        int element;

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
        to Delete a given Element from an Array*/
        boolean deletion(int elmt)
        {
            if(size==0 || capacity==0)
            {
                System.out.println("Can't delete "+elmt+" from Array as there are no Elements in Array!");
                return false;
            }
            else
            {
                int i;
                for(i=0; i<size; i++)
                {
                    if(arr[i]==element)
                    break;
                }
                if(i==size)
                {
                    System.out.println(elmt+" is not there in Array, thus can't perform Deletion Operation!");
                    return false;
                }
                for(int j=i; j<size-1; j++)
                arr[j]=arr[j+1];
                size--;
                return true;
            }
        }
    }

    /*Driver Function(Code)*/
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        Program_1 program_1=new Program_1();
        Program_1.Implement_Fixed_Sized_Array IFSA=program_1.new Implement_Fixed_Sized_Array();
        if(!IFSA.create_a_fixed_sized_array(sc))
        System.out.println("Array Creation Failed!");
        else
        {
            System.out.println("Array before Deletion Operation:");
            IFSA.display();
            System.out.println("And Size of Array before Deletion Operation:"+IFSA.size);
            System.out.println("Enter the Element you want to Delete from Array:");
            IFSA.element=sc.nextInt();
            if(IFSA.deletion(IFSA.element)==false)
            System.out.println("Deletion Failed!");
            else
            {
                System.out.println("Array after Deletion Operation:");
                IFSA.display();
                System.out.println("And Size of Array after Deletion Operation:"+IFSA.size);
            }
        }
        sc.close();
    }
}

