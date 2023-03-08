//------------------------------------------------------------------------------
// Lab 12
// Fill a 1-d array with random values
// Find the smallest and largest values
//------------------------------------------------------------------------------

#include <iostream>
#include <ctime>

#define MAX_VALUES	10
#define MAX_RANDOM	99
#define MIN_RANDOM	11

using namespace std;

int find_smallest(int a[], int num_vals);
int find_largest(int a[], int num_vals);

int main()
{
	int nums[MAX_VALUES];
	char user_input;

	//seed random number generator
	srand((unsigned int) time(0));

	do {
		cout << endl << "Array values: ";

		//fill array with random numbers and display array values
		for (int i = 0; i < MAX_VALUES; i++)
		{
			nums[i] = rand() % (MAX_RANDOM - MIN_RANDOM) + MIN_RANDOM;
			cout << nums[i] << " ";
		}

		//display smallest and largest values in array
		cout << endl;
		cout << "Smallest value: " << find_smallest(nums, MAX_VALUES) << endl;
		cout << "Largest value: " << find_largest(nums, MAX_VALUES) << endl;

		//user input
		cout << "Type Q or q to quit, anything else to run again: ";
		cin >> user_input;

	} while (user_input != 'q' && user_input != 'Q');

//	system("pause");

	return 0;
}

//------------------------------------------------------------------------------
// Find the smallest value in passed array
//------------------------------------------------------------------------------
int find_smallest(int a[], int num_vals)
{
	int smallest = MAX_RANDOM;

	for (int i = 0; i < num_vals; i++)
	{
		if (a[i] < smallest)
			smallest = a[i];
	}

	return smallest;
}


//------------------------------------------------------------------------------
// Find the largest value in passed array
//------------------------------------------------------------------------------
int find_largest(int a[], int num_vals)
{
	int largest = 0;

	for (int i = 0; i < num_vals; i++)
	{
		if (a[i] > largest)
			largest = a[i];
	}

	return largest;
}
