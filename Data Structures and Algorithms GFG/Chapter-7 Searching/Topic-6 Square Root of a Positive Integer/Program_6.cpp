/*C++ Program to Calculate the Floor of 
Square Root of a Positive Integer*/

#include<iostream>
#include<math.h>
#include<limits.h>
using namespace std;

/*Creating a class*/
class Square_Root{
    public:

    /*Data Members of class:
    long long signed int and double*/
    long long signed int num, floor_sq_root;
    double num_d;

    /*Member Function of class:
    to take user input for num*/
    bool userinput()
    {
        cout<<"Enter a Positive Integer:";
        cin>>num;
        /*User is advised to enter a Non-Negative Integer that is
        greater than or equal to 0 and less than (2 raised to power 63)
        as num otherwise the result will not be as predicted*/

        /*Checking for bounds for num*/
        if(num<=0 || num>LLONG_MAX)
        {
            cout<<"Invalid Input for num!"<<endl;
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
        while(1)
        {
            p=r;
            r=r-(((r*r)-num_d)/(2*r));
            if(fabs(r-p)<tolerance)
            break;
        }
        floor_sq_root=(long long signed int)(floor(r));
    }
};

/*Driver Function(Code)*/
int main()
{
    Square_Root SR;
    if(SR.userinput())
    {
        SR.floor_square_root();
        cout<<"The Floor of Square Root of "<<SR.num<<" is:"<<SR.floor_sq_root;
    }
    else
    cout<<"You have probably entered an invalid integer!";
    return 0;
}