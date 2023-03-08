//------------------------------------------------------------------------------
// ptrdemo1.cpp
// 
// Pointer demo
//------------------------------------------------------------------------------

#include <iostream>
using std::cin;
using std::cout;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int MAX_ELEMENTS = 5;	// to declare array capacity

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    // A variable represents the value at a certain location in memory.
    // When you declare int variable i, 4 bytes of memory are allocated.
    int i;

    // When you assign the value 99 to variable i, 99 is stored in
    // the memory location that the name "i" represents.
    i = 99;
    cout << "the value of i is " << i << '\n';

    // Use &i to get the memory address of variable i.
    &i;

    // An address is just a number. It can be big if you have lots of RAM.
    cout << "&i tells you the address of i: " << &i << '\n';

    // You can use the address of i to get the value of i.
    // The address of i is also called a pointer to i.
    // You can declare a pointer to int variable i like this:
    int* pI = &i;

    // int* is a type. Use int* to declare a variable that points to an int.

    cout << "pI also tells you the address of i: " << pI << '\n';

    // To get the value in address pI, use a star.
    cout << "*pI tells you the contents of &i: " << *pI << '\n';

    // A pointer is an address, which is just a number.
    // The pointer type needs to match the variable type it points to.
    double d = 77.7;
    double* pD = &d;

    // Let's see how to use a pointer to look at int array elements.
    int ai[MAX_ELEMENTS] = { 1, 2, 3, 4, 5 };

    // First, let's use array index syntax to look at each element in ai.
    // You've seen this syntax many times.
    for (int k = 0; k < MAX_ELEMENTS; ++k) {
        cout << "ai[" << k << "] is " << ai[k] << '\n';
    }

    // Now let's use a pointer to do the same thing.

    // First we need a pointer to ai, the array of int.
    // Since ai is an array, we don't need the &.
    // The compiler interprets the name "ai" as
    // the address of the first element in array ai.

    int* pAi = ai;

    // Next, we can use the same for loop. But this time
    // the loop body uses pointer syntax instead of
    // square brackets. 

    for (int k = 0; k < MAX_ELEMENTS; k++) {

        cout << "*pAi is " << *pAi << '\n';

        // We need to move the pointer to the next element. 
        pAi++;
    }

    // We can take some shortcuts in writing this second loop,
    // but we'll hold off for now.
    
    cin.get();
    return 0;
}