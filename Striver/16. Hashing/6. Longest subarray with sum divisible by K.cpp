// Link : https://www.geeksforgeeks.org/longest-subarray-sum-divisible-k/

/*
1. Brute (Naive Approach)

// C++ implementation to find the longest subarray
// with sum divisible by k

#include <bits/stdc++.h>
using namespace std;

// function to find the longest subarray
// with sum divisible by k

int longestSubarrWthSumDivByK(int arr[], int N, int k)
{
		int maxl=0;
		for(int i=0;i<N;i++)
		{
			int sum1 = 0;
			for(int j=i;j<N;j++)
			{
				sum1+=arr[j];
				if(sum1 % k == 0)
				{
					maxl = max(maxl , j - i + 1);
				}
				
			}
		}

		return maxl;
}

// Driver code
int main()
{
	int arr[] = { 2, 7, 6, 1, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;

	cout << "Length = "
		<< longestSubarrWthSumDivByK(arr, n, k);

	return 0;
}

// This code is contributed by Arpit Jain


Time Complexity: O(n2).
Auxiliary Space: O(1)
*/

// 3. Optimal (Space Optimized approach): The space optimization for the above approach to O(n) Instead of keeping a separate array to store the modulus of all values, we compute it on the go and store remainders in the hash table.

#include <bits/stdc++.h>

using namespace std;

// function to find the longest subarray
// with sum divisible by k
int longestSubarrWthSumDivByK(int arr[], int n, int k)
{
	// unordered map 'um' implemented as
	// hash table
	unordered_map<int, int> um;

	int max_len = 0;
	int curr_sum = 0;

	for (int i = 0; i < n; i++) {
		curr_sum += arr[i];

		int mod = ((curr_sum % k) + k) % k;

		// if true then sum(0..i) is divisible
		// by k
		if (mod == 0)
			// update 'max_len'
			max_len = i + 1;

		// if value 'mod_arr[i]' not present in 'um'
		// then store it in 'um' with index of its
		// first occurrence
		else if (um.find(mod) == um.end())
			um[mod] = i;

		else
			// if true, then update 'max_len'
			if (max_len < (i - um[mod]))
			max_len = i - um[mod];
	}

	// return the required length of longest subarray with
	// sum divisible by 'k'
	return max_len;
}

// Driver code
int main()
{
	int arr[] = { 2, 7, 6, 1, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;

	cout << "Length = "
		<< longestSubarrWthSumDivByK(arr, n, k);

	return 0;
}

// Code Updated by Kshitij Dwivedi


// Time Complexity: O(n), as we traverse the input array only once.
// Auxiliary Space: O(min(n,k))
