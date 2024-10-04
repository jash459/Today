// Link : https://www.geeksforgeeks.org/next-smaller-element/

/*

1. Brute :

// Simple C++ program to print 
// next smaller elements in a given array
#include "bits/stdc++.h"
using namespace std;

/* prints element and NSE pair 
for all elements of arr[] of size n 
void printNSE(int arr[], int n)
{
	int next, i, j;
	for (i = 0; i < n; i++)
	{
		next = -1;
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				next = arr[j];
				break;
			}
		}
		cout << arr[i] << " --> "
			<< next << endl;
	}
}

// Driver Code
int main()
{
	int arr[]= {11, 13, 21, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	printNSE(arr, n);
	return 0;
}

Time Complexity: O(N^2) where N is the size of the input array.
Auxiliary Space: O(1)

*/

// 2. Optimal : using stack 

vector<int> nextSmallerElement(int arr[], int n) {
    vector<int> result(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }
        s.push(arr[i]);
    }
    return result;
}



// Time Complexity: O(N), where N is the size of input array
// Auxiliary Space: O(N)