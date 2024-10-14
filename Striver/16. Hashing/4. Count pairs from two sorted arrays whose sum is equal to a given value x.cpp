// Link : https://www.geeksforgeeks.org/count-pairs-two-sorted-arrays-whose-sum-equal-given-value-x/


// video : https://www.youtube.com/watch?v=UXDSeD9mN-k
/*

1. Brute 

// C++ implementation to count 
// pairs from both sorted arrays 
// whose sum is equal to a given 
// value
#include <bits/stdc++.h>
using namespace std;

// function to count all pairs
// from both the sorted arrays 
// whose sum is equal to a given
// value
int countPairs(int arr1[], int arr2[], 
			int m, int n, int x)
{
	int count = 0;
	
	// generating pairs from 
	// both the arrays
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)

			// if sum of pair is equal 
			// to 'x' increment count 
			if ((arr1[i] + arr2[j]) == x) 
				count++;
	
	// required count of pairs	 
	return count;
}

// Driver Code
int main()
{
	int arr1[] = {1, 3, 5, 7};
	int arr2[] = {2, 3, 5, 8};
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);
	int x = 10;
	cout << "Count = "
		<< countPairs(arr1, arr2, m, n, x);
	return 0;	 
} 


Time Complexity : O(mn) 
Auxiliary space : O(1)
*/


/*
2. Better (Binary Search)

// C++ implementation to count 
// pairs from both sorted arrays 
// whose sum is equal to a given
// value
#include <bits/stdc++.h>
using namespace std;

// function to search 'value' 
// in the given array 'arr[]' 
// it uses binary search technique 
// as 'arr[]' is sorted 
bool isPresent(int arr[], int low,
			int high, int value)
{
	while (low <= high)
	{
		int mid = (low + high) / 2;
		
		// value found
		if (arr[mid] == value)
			return true;	 
			
		else if (arr[mid] > value) 
			high = mid - 1;
		else
			low = mid + 1; 
	}
	
	// value not found
	return false;
}

// function to count all pairs 
// from both the sorted arrays 
// whose sum is equal to a given
// value
int countPairs(int arr1[], int arr2[],
			int m, int n, int x)
{
	int count = 0;	 
	for (int i = 0; i < m; i++)
	{
		// for each arr1[i]
		int value = x - arr1[i];
		
		// check if the 'value'
		// is present in 'arr2[]'
		if (isPresent(arr2, 0, n - 1, value))
			count++;
	}
	
	// required count of pairs	 
	return count;
}

// Driver Code
int main()
{
	int arr1[] = {1, 3, 5, 7};
	int arr2[] = {2, 3, 5, 8};
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);
	int x = 10;
	cout << "Count = "
		<< countPairs(arr1, arr2, m, n, x);
	return 0;	 
}


Time Complexity : O(mlogn), searching should be applied on the array which is of greater size so as to reduce the time complexity. 
Auxiliary space : O(1)


*/

//. Hashing

/*

// C++ implementation to count 
// pairs from both sorted arrays 
// whose sum is equal to a given 
// value
#include <bits/stdc++.h>
using namespace std;

// function to count all pairs 
// from both the sorted arrays 
// whose sum is equal to a given
// value
int countPairs(int arr1[], int arr2[], 
			int m, int n, int x)
{
	int count = 0;
	
	unordered_set<int> us;
	
	// insert all the elements 
	// of 1st array in the hash
	// table(unordered_set 'us')
	for (int i = 0; i < m; i++)
		us.insert(arr1[i]);
	
	// for each element of 'arr2[] 
	for (int j = 0; j < n; j++) 

		// find (x - arr2[j]) in 'us'
		if (us.find(x - arr2[j]) != us.end())
			count++;
	
	// required count of pairs	 
	return count;
}

// Driver Code
int main()
{
	int arr1[] = {1, 3, 5, 7};
	int arr2[] = {2, 3, 5, 8};
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);
	int x = 10;
	cout << "Count = "
		<< countPairs(arr1, arr2, m, n, x);
	return 0;	 
}


Time Complexity : O(m+n) 
Auxiliary space : O(m), hash table should be created of the array having smaller size so as to reduce the space complexity.

*/

// 3. Optimal

// C++ implementation to count 
// pairs from both sorted arrays 
// whose sum is equal to a given 
// value
#include <bits/stdc++.h>
using namespace std;

// function to count all pairs 
// from both the sorted arrays 
// whose sum is equal to a given 
// value
int countPairs(int arr1[], int arr2[], 
			int m, int n, int x)
{
	int count = 0; 
	int l = 0, r = n - 1;
	
	// traverse 'arr1[]' from 
	// left to right
	// traverse 'arr2[]' from 
	// right to left
	while (l < m && r >= 0)
	{
		// if this sum is equal 
		// to 'x', then increment 'l', 
		// decrement 'r' and
		// increment 'count'
		if ((arr1[l] + arr2[r]) == x)
		{
			l++; r--;
			count++;		 
		}
		
		// if this sum is less 
		// than x, then increment l
		else if ((arr1[l] + arr2[r]) < x)
			l++;
			
		// else decrement 'r' 
		else
			r--; 
	}
	
	// required count of pairs	 
	return count;
}

// Driver Code
int main()
{
	int arr1[] = {1, 3, 5, 7};
	int arr2[] = {2, 3, 5, 8};
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);
	int x = 10;
	cout << "Count = "
		<< countPairs(arr1, arr2, m, n, x);
	return 0;	 
}


// Time Complexity : O(m + n) 
// Auxiliary space : O(1)