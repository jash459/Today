// Link : https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/
//      : https://takeuforward.org/arrays/count-subarray-sum-equals-k/

// video : https://www.youtube.com/watch?v=xvNwoz-ufXA&t=14s

/*

1. Brute

/* A simple program to print subarray
with sum as given sum 
#include <bits/stdc++.h>
using namespace std;

/* Returns true if the there is a subarray
of arr[] with sum equal to 'sum' otherwise
returns false. Also, prints the result 
int subArraySum(int arr[], int n, int sum)
{
	int curr_sum, i, j;

	// Pick a starting point
	for (i = 0; i < n; i++) {
		curr_sum = 0;

		// try all subarrays starting with 'i'
		for (j = i; j < n; j++) {
			curr_sum = curr_sum + arr[j];

			if (curr_sum == sum) {
				cout << "Sum found between indexes " << i
					<< " and " << j;
				return 1;
			}
		}
	}

	cout << "No subarray found";
	return 0;
}

// Driver Code
int main()
{
	int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 23;

	// Function call
	subArraySum(arr, n, sum);
	return 0;
}
Time Complexity: O(N2)
Auxiliary Space: O(1)


*/


2. Optimal : using Hash-Map


// C++ program to print subarray with sum as given sum
#include <bits/stdc++.h>
using namespace std;

// Function to print subarray with sum as given sum
void subArraySum(int arr[], int n, int sum)
{
	// create an empty map
	unordered_map<int, int> map;

	// Maintains sum of elements so far
	int curr_sum = 0;

	for (int i = 0; i < n; i++) {
		// add current element to curr_sum
		curr_sum = curr_sum + arr[i];

		// if curr_sum is equal to target sum
		// we found a subarray starting from index 0
		// and ending at index i
		if (curr_sum == sum) {
			cout << "Sum found between indexes " << 0
				<< " to " << i << endl;
			return;
		}

		// If curr_sum - sum already exists in map
		// we have found a subarray with target sum
		if (map.find(curr_sum - sum) != map.end()) {
			cout << "Sum found between indexes "
				<< map[curr_sum - sum] + 1 << " to " << i
				<< endl;
			return;
		}

		map[curr_sum] = i;
	}

	// If we reach here, then no subarray exists
	cout << "No subarray with given sum exists";
}

// Driver code
int main()
{
	int arr[] = { 10, 2, -2, -20, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = -10;

	// Function call
	subArraySum(arr, n, sum);

	return 0;
}


// Time complexity: O(N). If hashing is performed with the help of an array, then this is the time complexity. In case the elements cannot be hashed in an array a hash map can also be used as shown in the above code.
// Auxiliary space: O(N). As a HashMap is needed, this takes linear space.