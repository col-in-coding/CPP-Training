#include <stdio.h> 
#include <stdlib.h> 

// New and delete shouldn't be used in application code
// They are the implementation of abstraction

// Error of memory usage:
// 1. Memory leak
// 2. Buffer overruns (char A[2], A="abcd")
// 3. Uinitialized Memory
// 4. incorrectly pairing (malloc with delete or new with free)
// 5. invalid memory access (use the address memory after deleted)


struct MyStruct {
    int i; 
    double d; 
    char a[5];
};


int main() 
{ 
    // malloc: Memory Allocation
    int *p =(int*) malloc(2 * sizeof(int));
    printf("address=%p, value=%d\n", p, *p);
    p[0] = 0; p[1] = 1;

    // realloc: Re-allocation (p0, p2 are preserved)
    p =(int*) realloc(p, 4 * sizeof(int));
    p[2] = 2; p[3] = 3;

    // free can only used with malloc or calloc 
    free(p);

    // calloc: Cleared Memory Allocation
    MyStruct *p2 = (MyStruct*)calloc(4,sizeof(MyStruct));
    p2[0].i = 1; p2[0].d = 3.14159; p2[0].a[0] = 'a';

    // avoid memory leak
    free(p2);


    int *pInt = new int[10];
    delete[] pInt;

    return 0; 
}

/**
 *  Debug memory problems using valgrind
 *  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=/xx/workspace/valgrind-out.txt /xx/a.out


==952== 40 bytes in 1 blocks are definitely lost in loss record 18 of 45

...

==952==    by 0x10019A377: operator new(unsigned long) (in /usr/lib/libc++abi.dylib)

...

==952==    by 0x100000F8A: main (memory_leaks_debugging.cpp:12)

...

==952== LEAK SUMMARY:
==952==    definitely lost: 40 bytes in 1 blocks
==952==    indirectly lost: 0 bytes in 0 blocks
==952==      possibly lost: 72 bytes in 3 blocks
==952==    still reachable: 200 bytes in 6 blocks
==952==         suppressed: 18,876 bytes in 160 blocks

 */