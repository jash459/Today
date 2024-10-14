// Link : https://www.geeksforgeeks.org/pair-with-given-product-set-1-find-if-any-pair-exists/

/*
1. Brute Force : 

// A simple C++ program to find if there is a pair
// with given product.
#include<bits/stdc++.h>
using namespace std;

// Returns true if there is a pair in arr[0..n-1]
// with product equal to x.
bool isProduct(int arr[], int n, int x)
{
	// Consider all possible pairs and check for
	// every pair.
	for (int i=0; i<n-1; i++)
	for (int j=i+1; j<n; j++)
		if (arr[i] * arr[j] == x)
			return true;

	return false;
}

// Driver code
int main()
{
	int arr[] = {10, 20, 9, 40};
	int x = 400;
	int n = sizeof(arr)/sizeof(arr[0]);
	isProduct(arr, n, x)? cout << "Yes\n"
						: cout << "No\n";
	x = 190;
	isProduct(arr, n, x)? cout << "Yes\n"
						: cout << "No\n";
	return 0;
}


Time Complexity: O(n2)
Auxiliary Space: O(1)

*/

/*
2. Better 

// A simple C++ program to find if there is a pair
// with given product.
#include<bits/stdc++.h>
using namespace std;

//Function to check if x is present in the array or not
// such that arr[i] + x == given sum
bool binarysearch(int arr[], int n, int i,int x)
{ 
	int l = 0, r = n - 1;

	while (l <= r) {
		int mid = (l + r) / 2;

		// Checking if the middle element is equal to x
		if (arr[mid]*arr[i] == x)
		{ 
		if(i!=mid)//if position is no same
		{	 return true; }
		else{ //if position is same
			if(mid>0 && arr[mid-1]==arr[mid])
			{ return true; }//if exist adjacent element
			else if(mid<n-1 && arr[mid+1]==arr[mid])
			{ return true; }//if exist adjacent element
			else { return false; }
		}
		}
		else if (arr[mid]*arr[i] < x)
		{
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	// return true , if element x is present in the array
	// else false
	return false;
}
// Returns true if there is a pair in arr[0..n-1]
// with product equal to x.
bool isProduct(int arr[], int n, int x)
{ sort( arr , arr+n);//sorting array for Binary search

	// Consider all possible pairs and check for
	// every pair.
	for (int i=0; i<n; i++)
	{ //Using binary search to check if there exist a 
	//index in arr such that arr[i]*arr[index]==given sum
	if(binarysearch( arr, n, i , x))
		{ return true; }// Return true if pair found 
	}
	return false;
}

// Driver code
int main()
{
	int arr[] = {10, 20, 9, 40};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int x = 400;
	// Function call test case 1
	if(isProduct(arr, n, x))
	{ cout<<"Yes"<<endl; }
	else { cout << "No"<<endl; }
						
	x = 190;
	// Function call test case 2
	if(isProduct(arr, n, x))
	{ cout<<"Yes"<<endl; }
	else { cout << "No"<<endl; }

	return 0;
}


Time Complexity: O(n log n)
Auxiliary Space: O(1)
*/

/*
Using Two Pointer

// C++ code for the approach

#include <bits/stdc++.h>
using namespace std;

// Returns true if there is a pair in arr[0..n-1]
// with product equal to x.
bool isProduct(int arr[], int n, int x) {
	// sort the array arr
	sort(arr, arr + n);

	int l = 0, r = n - 1;

	// traverse the array inorder
	// using two pointer l and r
	while (l < r) {
		int prod = arr[l] * arr[r];

		// if product of element
		// at the two pinters is k
		// return this as res
		if (prod == x) {
			return true;
		}
		// if prod is less then
		// increase l as we have to
		// increase element value
		else if (prod < x)
			l++;
		// if prod is greater then
		// decrease r as we have to
		// decrease element value
		else
			r--;
	}

	return false;
}

// Driver code
int main() {
	int arr[] = { 10, 20, 9, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int x = 400;
	// Function call test case 1
	if (isProduct(arr, n, x)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	x = 190;
	// Function call test case 2
	if (isProduct(arr, n, x)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}

// This code is contributed by Chandramani Kumar
Time Complexity: O(N * logN) where N is size of input array. This is because sort has been called which takes N*logN time.

Space Complexity: O(1) as no extra space has been taken.

*/

// 3. Optimal (using Hashing)

// C++ program to find if there is a pair
// with given product.
#include<bits/stdc++.h>
using namespace std;

// Returns true if there is a pair in arr[0..n-1]
// with product equal to x.
bool isProduct(int arr[], int n, int x)
{
	if (n < 2)
		return false;

	// Create an empty set and insert first
	// element into it
	unordered_set<int> s;

	// Traverse remaining elements
	for (int i=0; i<n; i++)
	{
		// 0 case must be handles explicitly as
		// x % 0 is undefined behaviour in C++
		if (arr[i] == 0)
		{
		if (x == 0)
			return true;
		else
			continue;
		}

		// x/arr[i] exists in hash, then we
		// found a pair
		if (x%arr[i] == 0)
		{
			if (s.find(x/arr[i]) != s.end())
			return true;

			// Insert arr[i]
			s.insert(arr[i]);
		}
	}
	return false;
}

// Driver code
int main()
{
	int arr[] = {10, 20, 9, 40};
	int x = 400;

	int n = sizeof(arr)/sizeof(arr[0]);
	isProduct(arr, n, x)? cout << "Yes\n"
					: cout << "No";

	x = 190;
	isProduct(arr, n, x)? cout << "Yes\n"
						: cout << "No";

	return 0;
}


// Time Complexity : O(n2)
// Auxiliary Space: O(n)

