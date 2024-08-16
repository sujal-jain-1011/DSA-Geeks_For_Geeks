/*C++ Program to Calculate the Floor of 
Square Root of a Positive Integer*/

#include<iostream>
#include<limits.h>
using namespace std;

/*Creating a class*/
class Square_Root{
    public:

    /*Data Members of class:
    long long unsigned int*/
    long long unsigned int num, floor_sq_root;

    /*Member Function of class:
    to take user input for num*/
    bool userinput()
    {
        cout<<"Enter a Positive Integer:";
        cin>>num;
        /*User is advised to enter a Non-Negative Integer that is
        greater than or equal to 0 and less than (2 raised to power 64)
        as num otherwise the result will not be as predicted*/

        /*Checking for bounds for num*/
        if(num==0 || num>ULLONG_MAX)
        {
            cout<<"Invalid Input for num!"<<endl;
            return false;
        }
        return true;
    } 

    /*Member Function of class:
    to Calculate Floor of Square Root of num
    Using Iterative Binary Search*/
    void floor_square_root()
    {
        long long unsigned int low=1, high=num;
        /*Here we have squared a long long unsigned int therefore it might happen
        that it exceeds the range of long long unsigned int and wraps around which
        can lead to unexpected results, however in practical scenarios our num
        will not be too large thus the square of mid will also not exceed the max. range*/
        while(low<=high)
        {
            long long unsigned int mid=(low+high)/2;
            if((mid*mid)>num)
            {
                if(mid!=0)
                high=mid-1;
                else 
                break;
            }
            else if((mid*mid)<num)
            {
                low=mid+1;
                floor_sq_root=mid;
            }
            else
            {
                floor_sq_root=mid;
                break;
            }
        }
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