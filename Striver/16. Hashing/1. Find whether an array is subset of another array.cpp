// Link : https://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/

/*
1. Brute 

// C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>

 Return 1 if arr2[] is a subset of
arr1[] 
bool isSubset(int arr1[], int arr2[], int m, int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (arr2[i] == arr1[j])
				break;
		}

		 If the above inner loop was
		not broken at all then arr2[i]
		is not present in arr1[] 
		if (j == m)
			return 0;
	}

	 If we reach here then all
	elements of arr2[] are present
	in arr1[] 
	return 1;
}

// Driver code
int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, arr2, m, n))
		printf("arr2[] is subset of arr1[] ");
	else
		printf("arr2[] is not a subset of arr1[]");

	getchar();
	return 0;
}

Time Complexity: O(m*n)
Auxiliary Space: O(1)
*/

/*
2. Better (using Sorting and Binary Search)

// C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>
using namespace std;

/* Function prototypes 
void quickSort(int* arr, int si, int ei);
int binarySearch(int arr[], int low, int high, int x);

/* Return 1 if arr2[] is a subset of arr1[] 
bool isSubset(int arr1[], int arr2[], int m, int n)
{
	int i = 0;

	quickSort(arr1, 0, m - 1);
	for (i = 0; i < n; i++) {
		if (binarySearch(arr1, 0, m - 1, arr2[i]) == -1)
			return 0;
	}

	/* If we reach here then all elements
	of arr2[] are present in arr1[] 
	return 1;
}

/* FOLLOWING FUNCTIONS ARE ONLY FOR
	SEARCHING AND SORTING PURPOSE 
/* Standard Binary Search function
int binarySearch(int arr[], int low, int high, int x)
{
	if (high >= low) {
		/*low + (high - low)/2;
		int mid = (low + high) / 2;

		/* Check if arr[mid] is the first
		occurrence of x. arr[mid] is first
		occurrence if x is one of the following
		is true:
		(i) mid == 0 and arr[mid] == x
		(ii) arr[mid-1] < x and arr[mid] == x 
		if ((mid == 0 || x > arr[mid - 1])
			&& (arr[mid] == x))
			return mid;
		else if (x > arr[mid])
			return binarySearch(arr, (mid + 1), high, x);
		else
			return binarySearch(arr, low, (mid - 1), x);
	}
	return -1;
}

void exchange(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int A[], int si, int ei)
{
	int x = A[ei];
	int i = (si - 1);
	int j;

	for (j = si; j <= ei - 1; j++) {
		if (A[j] <= x) {
			i++;
			exchange(&A[i], &A[j]);
		}
	}
	exchange(&A[i + 1], &A[ei]);
	return (i + 1);
}

/* Implementation of Quick Sort
A[] --> Array to be sorted
si --> Starting index
ei --> Ending index

void quickSort(int A[], int si, int ei)
{
	int pi; /* Partitioning index 
	if (si < ei) {
		pi = partition(A, si, ei);
		quickSort(A, si, pi - 1);
		quickSort(A, pi + 1, ei);
	}
}

/*Driver code 
int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, arr2, m, n))
		cout << "arr2[] is subset of arr1[] ";
	else
		cout << "arr2[] is not a subset of arr1[] ";

	return 0;
}

// This code is contributed by Shivi_Aggarwal

Time Complexity: O(mLog(m) + nlog(m)). O(mLog(m)) for sorting and O(nlog(m)) for binary searching each element of one array in another. In the above code, Quick Sort is used and the worst-case time complexity of Quick Sort is O(m2).
Auxiliary Space: O(n)
*/

// 3. Optimal (using Sorting and Merging)

// C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>
using namespace std;

/* Return 1 if arr2[] is a subset of arr1[] */
bool isSubset(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;

	if (m < n)
		return 0;

	// Sort both the arrays
	sort(arr1, arr1 + m);
	sort(arr2, arr2 + n);

	// Iterate till they do not exceed their sizes
	while (i < n && j < m) {
		// If the element is smaller then
		// Move ahead in the first array
		if (arr1[j] < arr2[i])
			j++;
		// If both are equal, then move
		// both of them forward
		else if (arr1[j] == arr2[i]) {
			j++;
			i++;
		}

		// If we do not have an element smaller
		// or equal to the second array then break
		else if (arr1[j] > arr2[i])
			return 0;
	}

	return (i < n) ? false : true;
}

// Driver Code
int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, arr2, m, n))
		printf("arr2[] is subset of arr1[] ");
	else
		printf("arr2[] is not a subset of arr1[] ");

	return 0;
}


// Time Complexity: O(mLog(m) + nLog(n)) which is better than approach 2.
// Auxiliary Space: O(1)

// using Hashing

// C++ code to find whether an array is subset of
// another array
#include <bits/stdc++.h>
using namespace std;

/* Return true if arr2[] is a subset of arr1[] */
bool isSubset(int arr1[], int m, int arr2[], int n)
{

	// Using STL set for hashing
	set<int> hashset;

	// hashset stores all the values of arr1
	for (int i = 0; i < m; i++) {
		hashset.insert(arr1[i]);
	}

	// loop to check if all elements of arr2 also
	// lies in arr1
	for (int i = 0; i < n; i++) {
		if (hashset.find(arr2[i]) == hashset.end())
			return false;
	}
	return true;
}

// Driver Code
int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, m, arr2, n))
		cout << "arr2[] is subset of arr1[] "
			<< "\n";
	else
		cout << "arr2[] is not a subset of arr1[] "
			<< "\n";
	return 0;
}
// This code is contributed by Satvik Shrivas

// Time Complexity: O(m+n*logm)
// Auxiliary Space: O(m)

// using Set

#include <bits/stdc++.h>
using namespace std;

int main()
{
	// code
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);
	unordered_set<int> s;
	for (int i = 0; i < m; i++) {
		s.insert(arr1[i]);
	}
	int p = s.size();
	for (int i = 0; i < n; i++) {
		s.insert(arr2[i]);
	}
	if (s.size() == p) {
		cout << "arr2[] is subset of arr1[] "
			<< "\n";
	}
	else {
		cout << "arr2[] is not subset of arr1[] "
			<< "\n";
	}
	return 0;
}


// Time Complexity: O(m+n) because we are using unordered_set and inserting in it, If we would be using an ordered set inserting would have taken log n increasing the TC to O(mlogm+nlogn), but order does not matter in this approach.
// Auxiliary Space: O(n+m)

// using the Frequency Table

// C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>
using namespace std;
/* Return true if arr2[] is a subset of arr1[] */

bool isSubset(int arr1[], int m, int arr2[], int n)
{
	// Create a Frequency Table using STL
	map<int, int> frequency;

	// Increase the frequency of each element
	// in the frequency table.
	for (int i = 0; i < m; i++) {
		frequency[arr1[i]]++;
	}
	// Decrease the frequency if the
	// element was found in the frequency
	// table with the frequency more than 0.
	// else return 0 and if loop is
	// completed return 1.
	for (int i = 0; i < n; i++) {
		if (frequency[arr2[i]] > 0)
			frequency[arr2[i]]--;
		else {
			return false;
		}
	}
	return true;
}

// Driver Code
int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, m, arr2, n))
		cout << "arr2[] is subset of arr1[] "
			<< "\n";
	else
		cout << "arr2[] is not a subset of arr1[] "
			<< "\n";
	return 0;
}
// This code is contributed by Dhawal Sarin.

// Time Complexity: O(m log (m+n)) which is better than methods 1,2,3
// Auxiliary Space: O(m)

// Note that method 1, method 2, method 4, and method 5 don’t handle the cases when we have duplicates in arr2[]. For example, {1, 4, 4, 2} is not a subset of {1, 4, 2}, but these methods will print it as a subset.  

