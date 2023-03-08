//------------------------------------------------------------------------------
// Pointer demo
//------------------------------------------------------------------------------

#include <iostream>

#define SIZE		10			// array size

using namespace std;

// a struct can be a programmer-defined type
// here the type name is "user_info"
// this struct might be used to keep track of a gamer's available currency
// the struct contains an integer and a double so struct size is 4 + 8 = 12 
struct user_info
{
	int id;						// the id field is 4 bytes long
	double coins;				// coins field is 8 bytes long
};

// local function prototypes

// func1 and func2 prototypes say the same thing with
// different syntax for the first parameter
// the second parameter is the array size in both prototypes

// func1 uses array syntax - square brackets after the parameter name
void func1(int x[], int size);	// x is the start address of an array

// func2 uses pointer syntax - asterisk before the paramter name
void func2(int *p_x, int size);	// x points to the first element of an array

// func3 uses pointer syntax with programmer-defined type "user_info"
// func3 uses a different way to determine the end of the array
// instead of size, func3 looks for a known value called a "sentinel"
// that flags the end of the array of users
void func3(user_info *x, int size);

//------------------------------------------------------------------------------
// Pointer demo
//------------------------------------------------------------------------------
int main()
{
	// an integer variable holds whatever value you assign it
	// the variable name is a human-readable way of notating 
	// where the variable's value lives in memory
	int i = 99;

	// an integer pointer variable also has an integer value, except
	// it holds the address of the integer value you want to use

	// the & operator gives the address of a variable
	// here integer pointer variable p_i holds the address of variable i
	int* p_i = &i;	

	// these two cout statements say the same thing with different syntax
	cout << "the value at address " << &i << " is " << i << endl;
	cout << "the value at address " << p_i << " is " << *p_i << endl;

	// now let's look at pointers to complex types - arrays and structs

	// first, an array of integers
	int a[SIZE];

	// we traverse this array with a for loop and array indexes, as usual

	// fill the array with random numbers between 1 and 100
	for (int k = 0; k < SIZE; k++)
		a[k] = rand() % 100 + 1;		

	// same thing with a function call
	func1(a, SIZE);

	// now use pointers to do the same thing

	// first, we need a pointer to the array of int
	// because a was declared as an array, we don't need the &
	// the compiler interprets the name "a" as the address of the first element

	int* p_a = a;

	// next, a for loop that uses pointer syntax to access array elements
	
	for (int k = 0; k < SIZE; k++)
	{
		*p_a = k;

		// incrementing the pointer adds the size of the type it points to! 
		p_a++;		// here we add 4
	}

	// same thing again, with a function call
	func2(a, SIZE);

	// now for the struct

	// declare a struct with id and coins fields
	user_info u1;

	// initialize the struct fields using a dot to specify the field
	u1.id = 1;
	u1.coins = 43.5;

	// now for an array of structs
	user_info ua[SIZE];

	// initialize the array with a loop, giving all users 100 coins

	// first, use array index syntax
	for (int k = 0; k < SIZE; k++)
	{
		ua[k].id = k + 1;		// id fields will have values 1 to SIZE
		ua[k].coins = 100;		// each user will stat with 100.0 coins
	}

	// now use pointer syntax

	// declare a pointer to the zeroeth array element 
	user_info* p_ua = ua;

	for (int k = 0; k < SIZE; k++)
	{
		p_ua->id = k;				// id fields will have values 0 to SIZE - 1
		p_ua->coins = 1000;		// each user will stat with 1000.0 coins

		// point to the next element
		// the value of p_ua will increase by 12, the size of type user_info

		p_ua++;
	}

	// same thing again with a function call
	func3(ua, SIZE);

	// same thing again, passing the array pointer instead of array name
	func3(p_ua, SIZE);

	system("pause");

	return 0;

}

//------------------------------------------------------------------------------
// func1 fills an int array with 1's
// func1 takes two parameters:
//		1. the address of an array to work on
//		2. the size of the array (number of elements) 
//------------------------------------------------------------------------------
void func1(int x[], int size)
{
	for (int k = 0; k < size; k++)
		x[k] = 1;
}

//------------------------------------------------------------------------------
// func2 fills an int array with 2's
// func2 takes two parameters:
//		1. a pointer to int - the address of an int array to work on
//		2. the size of the array (number of elements) 
//------------------------------------------------------------------------------
void func2(int* p_x, int size)
{
	for (int k = 0; k < size; k++)
	{
		// set the value of the current element to 2
		*p_x = 2;

		// point to the next int element - value of p_x will grow by 4
		// because an int is 4 bytes long
		p_x++;
}

//------------------------------------------------------------------------------
// func3 initializes an array of user_info structs
// func2 takes two parameters:
//		1. a pointer to user_info - the address of a user_info array to work on
//		2. the size of the array (number of elements) 
//------------------------------------------------------------------------------
void example_func3(user_info *p_x, int size)
{
	for (int k = 0; k < SIZE; k++)
	{
		p_x->id = 1000 + k;		// id fields will start at 1000 
		p_x->coins = 5000;		// each user will stat with 5000.0 coins

		// point to the next element
		// the value of p_ua will increase by 12, the size of type user_info

		p_x++;
	}
}

