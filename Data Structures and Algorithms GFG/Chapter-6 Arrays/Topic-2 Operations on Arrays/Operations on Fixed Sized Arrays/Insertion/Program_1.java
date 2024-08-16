/*Java Program to Insert an Element at a Given
Index in a Fixed Sized Array(Heap Allocation)*/

import java.util.*;

/*Creating an outer class*/
class Program_1{

    /*Creating an inner class*/
    class Implement_Fixed_Sized_Array{

        /*Data Members of class: int and int []*/
        int capacity, size, position;
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
        to Insert an Element at a Given 
        Position in an Array*/
        boolean insert(int element)
        {
            if(size==capacity)
            {
                System.out.println("Can't Insert "+element+" in Array at Position "+position+" because of Overflow!");
                return false;
            }
            else if(position<=0 || position>(size+1))
            {
                System.out.println(position+" is an Invalid Input for Position!");
                return false;
            }
            else
            {
                int index=position-1;
                int i;
                for(i=size-1; i>=index; i--)
                arr[i+1]=arr[i];    
                arr[i+1]=element;
                size++;
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
            System.out.println("Array before Insertion Operation:");
            IFSA.display();
            System.out.println("And Size of Array before Insertion Operation:"+IFSA.size);
            System.out.println("Enter the Element you want to Insert in Array:");
            IFSA.element=sc.nextInt();
            System.out.println("Enter the Position at which you want to Insert "+IFSA.element+":");
            IFSA.position=sc.nextInt();
            /*User is advised to enter a Non-Negative Integer that is
            greater than or equal to 0 and less than (2 raised to power 63)
            as position otherwise the result will not be as predicted*/

            if(IFSA.insert(IFSA.element)==false)
            System.out.println("Insertion Failed!");
            else
            {
                System.out.println("Array after Insertion Operation:");
                IFSA.display();
                System.out.println("And Size of Array after Insertion Operation:"+IFSA.size);
            }
        }
        sc.close();
    }
}
