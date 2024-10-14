// Link : https://geeksforgeeks.org/find-the-largest-subarray-with-0-sum/

/*
1. Brute

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Returns length of the largest
// subarray with 0 sum
int maxLen(int arr[], int N)
{
	// Initialize result
	int max_len = 0; 

	// Pick a starting point
	for (int i = 0; i < N; i++) {

		// Initialize curr_sum for
		// every starting point
		int curr_sum = 0;

		// Try all subarrays starting with 'i'
		for (int j = i; j < N; j++) {
			curr_sum += arr[j];

			// If curr_sum becomes 0, 
			// then update max_len
			// if required
			if (curr_sum == 0)
				max_len = max(max_len, j - i + 1);
		}
	}
	return max_len;
}

// Driver's Code
int main()
{
	int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
	int N = sizeof(arr) / sizeof(arr[0]);

// Function call
	cout << "Length of the longest 0 sum subarray is "
		<< maxLen(arr, N);
	return 0;
}


Time Complexity: O(N2)
Auxiliary Space: O(1)

*/


2. Optimal (using hashmap)

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Returns Length of the required subarray
int maxLen(int arr[], int N)
{
	// Map to store the previous sums
	unordered_map<int, int> presum;

	int sum = 0; // Initialize the sum of elements
	int max_len = 0; // Initialize result

	// Traverse through the given array
	for (int i = 0; i < N; i++) {

		// Add current element to sum
		sum += arr[i];
		if (sum == 0)
			max_len = i + 1;

		// Look for this sum in Hash table
		if (presum.find(sum) != presum.end()) {

			// If this sum is seen before, then update
			// max_len
			max_len = max(max_len, i - presum[sum]);
		}
		else {
			// Else insert this sum with index
			// in hash table
			presum[sum] = i;
		}
	}

	return max_len;
}

// Driver's Code
int main()
{
	int arr[] = { 15, -2, 2, -8, 1, 7, 10, 23 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "Length of the longest 0 sum subarray is "
		<< maxLen(arr, N);

	return 0;
}


// Time Complexity: O(N)
// Auxiliary Space: O(N)

