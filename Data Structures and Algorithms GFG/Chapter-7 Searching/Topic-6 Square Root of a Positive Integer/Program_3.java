/*Java Program to Calculate the Floor of 
Square Root of a Positive Integer*/

import java.util.*;

/*Creating an outer class*/
class Program_3{

    /*Creating an inner class*/
    class Square_Root{

        /*Data Members of class: long and double*/
        long num, floor_sq_root;
        double num_d;

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
            num_d=num;
            return true;
        }

        /*Member Function of class:
        Function to Calculate Floor of Square Root 
        of num-Using Newton Raphson Method*/
        void floor_square_root()
        {
            double r=num_d, p, tolerance=1e-7;
            while(true)
            {
                p=r;
                r=r-(((r*r)-num_d)/(2*r));
                if(Math.abs(r-p)<tolerance)
                break;
            }
            floor_sq_root=(long)Math.floor(r);
        }
    }

    /*Driver Function(Code)*/
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        Program_3 program_3=new Program_3();
        Program_3.Square_Root SR=program_3.new Square_Root();
        if(SR.userinput(sc))
        {
            SR.floor_square_root();
            System.out.println("The Floor of Square Root of "+SR.num+" is:"+SR.floor_sq_root);
        }
        else
        System.out.println("You have probably entered an invalid integer!");
    }
}
