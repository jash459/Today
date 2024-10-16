// Link : https://www.geeksforgeeks.org/previous-greater-element/

/*

1. Brute :
// C++ program previous greater element
// A naive solution to print previous greater
// element for every element in an array.
#include <bits/stdc++.h>
using namespace std;

void prevGreater(int arr[], int n)
{ 
	// Previous greater for first element never
	// exists, so we print -1.
	cout << "-1, ";

	// Let us process remaining elements.
	for (int i = 1; i < n; i++) {

		// Find first element on left side
		// that is greater than arr[i].
		int j;
		for (j = i-1; j >= 0; j--) {
			if (arr[i] < arr[j]) {
			cout << arr[j] << ", ";
			break;
			}			 
		}

		// If all elements on left are smaller.
		if (j == -1)
		cout << "-1, ";
	}
}
// Driver code
int main()
{
	int arr[] = { 10, 4, 2, 20, 40, 12, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	prevGreater(arr, n);
	return 0;
}

*/

// 2. Optimal : using stack 

// C++ program previous greater element
// An efficient solution to print previous greater
// element for every element in an array.
#include <bits/stdc++.h>
using namespace std;

void prevGreater(int arr[], int n)
{
	// Create a stack and push index of first element 
	// to it
	stack<int> s;
	s.push(arr[0]);
	
	// Previous greater for first element is always -1.
	cout << "-1, ";

	// Traverse remaining elements
	for (int i = 1; i < n; i++) {

		// Pop elements from stack while stack is not empty 
		// and top of stack is smaller than arr[i]. We 
		// always have elements in decreasing order in a 
		// stack.
		while (s.empty() == false && s.top() < arr[i])
			s.pop();

		// If stack becomes empty, then no element is greater
		// on left side. Else top of stack is previous
		// greater.
		s.empty() ? cout << "-1, " : cout << s.top() << ", ";

		s.push(arr[i]);
	}
}
// Driver code
int main()
{
	int arr[] = { 10, 4, 2, 20, 40, 12, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	prevGreater(arr, n);
	return 0;
}

// Time Complexity: O(n). It seems more than O(n) at first look. If we take a closer look, we can observe that every element of array is added and removed from stack at most once. So there are total 2n operations at most. Assuming that a stack operation takes O(1) time, we can say that the time complexity is O(n).
// Auxiliary Space: O(n) in worst case when all elements are sorted in decreasing order.