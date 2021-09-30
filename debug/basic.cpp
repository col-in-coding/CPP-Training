/*
 Basic Command Line Instructions
 gcc -g basic.cpp -o basic
 gdb basic
 
 gdb commands:
 b or break basic.cpp:26 // create a break point
 i or info b // show break points
 r or run
 p or print x
 l or list // list code lines near around
 where or bt or backtrace
*/


#include <iostream>
using namespace std;  

int divint(int, int);

int main() 
{ 
   int x = 5, y = 2; 
   cout << divint(x, y); 
   
   x =3; y = 0; 
   cout << divint(x, y); 
   
   return 0; 
}  

int divint(int a, int b) 
{ 
   return a / b; // divint error
}  