// Link : https://www.geeksforgeeks.org/recamans-sequence/

/*

1. Brute 

// C++ program to print n-th number in Recaman's 
// sequence
#include <bits/stdc++.h>
using namespace std;

// Prints first n terms of Recaman sequence
int recaman(int n)
{
	// Create an array to store terms
	int arr[n];

	// First term of the sequence is always 0
	arr[0] = 0;
	printf("%d, ", arr[0]);

	// Fill remaining terms using recursive
	// formula.
	for (int i=1; i< n; i++)
	{
		int curr = arr[i-1] - i;
		int j;
		for (j = 0; j < i; j++)
		{
			// If arr[i-1] - i is negative or
			// already exists.
			if ((arr[j] == curr) || curr < 0)
			{
				curr = arr[i-1] + i;
				break;
			}
		}

		arr[i] = curr;
		printf("%d, ", arr[i]);
	}
}

// Driver code
int main()
{
	int n = 17;
	recaman(n);
	return 0;
}


Time Complexity : O(n2) 
Auxiliary Space : O(n), since n extra space has been added
*/

// 3. Optimal (use hashing)

// C++ program to print n-th number in Recaman's 
// sequence
#include <bits/stdc++.h>
using namespace std;

// Prints first n terms of Recaman sequence
void recaman(int n)
{
	if (n <= 0)
	return;

	// Print first term and store it in a hash 
	printf("%d, ", 0);
	unordered_set<int> s;
	s.insert(0);

	// Print remaining terms using recursive
	// formula.
	int prev = 0;
	for (int i=1; i< n; i++)
	{
		int curr = prev - i;

		// If arr[i-1] - i is negative or
		// already exists.
		if (curr < 0 || s.find(curr) != s.end())
		curr = prev + i;

		s.insert(curr);

		printf("%d, ", curr);
		prev = curr;
	}
}

// Driver code
int main()
{
	int n = 17;
	recaman(n);
	return 0;
}


// Time Complexity : O(n) 
// Auxiliary Space : O(n), since n extra space has been taken.