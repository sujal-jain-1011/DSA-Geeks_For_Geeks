/*Java Program to Calculate the Floor of 
Square Root of a Positive Integer*/

import java.util.*;

/*Creating an outer class*/
class Program_1{

    /*Creating an inner class*/
    class Square_Root{

        /*Data Members of class: long*/
        long num, floor_sq_root;

        /*Member Function of class:
        to take user input for num*/
        boolean userinput(Scanner sc)
        {
            System.out.println("Enter a Positive Integer:");
            num=sc.nextLong();
            /*User is advised to enter a Non-Negative Integer that is
            greater than or equal to 0 and less than (2 raised to power 63)
            as num otherwise the result will not be as predicted*/

            /*Checking for bounds for num*/
            if(num<=0 || num>Long.MAX_VALUE)
            {
                System.out.println("Invalid Input for num!");
                return false;
            }
            return true;
        }

        /*Member Function of class:
        to Calculate Floor of Square Root of num*/
        void floor_square_root()
        {
            long i=1;
            /*Here we have squared a long therefore it might happen that it
            exceeds the range of long and wraps around which can lead to 
            unexpected results, however in practical scenarios our num will not
            be too large thus the square of i will also not exceed the max. range*/
            while(i*i<=num)
            i++;
            floor_sq_root=(i-1);
        }
    }

    /*Driver Function(Code)*/
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        Program_1 program_1=new Program_1();
        Program_1.Square_Root SR=program_1.new Square_Root();
        if(SR.userinput(sc))
        {
            SR.floor_square_root();
            System.out.println("The Floor of Square Root of "+SR.num+" is:"+SR.floor_sq_root);
        }
        else
        System.out.println("You have probably entered an invalid integer!");
    }
}
