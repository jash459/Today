// Link : https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/

/*

1. Brute :

// C++ implementation of simple algorithm to find
// smaller element on left side
#include <iostream>
using namespace std;

// Prints smaller elements on left side of every element
void printPrevSmaller(int arr[], int n)
{
	// Always print empty or '_' for first element
	cout << "_, ";

	// Start from second element
	for (int i = 1; i < n; i++) {
		// look for smaller element on left of 'i'
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				cout << arr[j] << ", ";
				break;
			}
		}

		// If there is no smaller element on left of 'i'
		if (j == -1)
			cout << "_, ";
	}
}

int main()
{
	int arr[] = { 1, 3, 0, 2, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printPrevSmaller(arr, n);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)

The time complexity of the above solution is O(n2).

Space Complexity: O(1)


*/

// 2. Optimal : using stack 

// C++ implementation of efficient algorithm to find
// smaller element on left side
#include <iostream>
#include <stack>
using namespace std;

// Prints smaller elements on left side of every element
void printPrevSmaller(int arr[], int n)
{
	// Create an empty stack
	stack<int> S;

	// Traverse all array elements
	for (int i=0; i<n; i++)
	{
		// Keep removing top element from S while the top
		// element is greater than or equal to arr[i]
		while (!S.empty() && S.top() >= arr[i])
			S.pop();

		// If all elements in S were greater than arr[i]
		if (S.empty())
			cout << "_, ";
		else //Else print the nearest smaller element
			cout << S.top() << ", ";

		// Push this element
		S.push(arr[i]);
	}
}

int main()
{
	int arr[] = {1, 3, 0, 2, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	printPrevSmaller(arr, n);
	return 0;
}


// Time complexity of the above program is O(n) as every element is pushed and popped at most once to the stack. So overall constant number of operations are performed per element.

// Auxiliary Space: O(n)