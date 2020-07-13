/**
 * l(eft) value = r(ight) value
 * L value have an address that can be accessed.
 * They are expressions whose evaluation by the compiler 
 * determines the identity of objects or functions.
 */

/**
 * l(eft) value = r(ight) value
 * R valuedo not have an address that is accessible directly.
 * They are temporary expressions used to initialize objects 
 * or compute the value of the operand of an operator.
 * 
 * Using the address operator & we can generate an lvalue from an rvalue
 *  and assign it to another lvalue
 * int *j = &i;
 */
#include <iostream>

void myFunction(int &val)
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    // initialize some variables on the stack
    int i, j, *p;

    // correct usage of lvalues and rvalues
    
    i = 42; // i is an lvalue and 42 is an rvalue
    
    p = new int;
    *p = i; // the dereferenced pointer is an lvalue
    delete p; 
    
    ((i < 42) ? i : j) = 23; // the conditional operator returns an lvalue (eiter i or j)

    // incorrect usage of lvalues and rvalues
    //42 = i; // error : the left operand must be an lvalue
    //j * 42 = 23; // error : the left operand must be an lvalue

    int j = 42;
    myFunction(j);

    // myFunction(42);  // Error myFunction can only take l-value

    int k = 23; 
    // myFunction(j+k); // Error j+k created an r-value

    /** 
     * Since C++11, there is a new type available called rvalue reference
     * Instead of first creating the rvalue i+j , 
     * then copying it and finally deleting it, 
     * we can now hold the temporary object in memory
     */
    int k = i + j; 
    int &&l = i + j; 

    return 0; 
}