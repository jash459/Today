// Link : https://www.geeksforgeeks.org/sum-of-minimum-elements-of-all-subarrays/

/*

1. Better :

// CPP implementation of above approach
#include <bits/stdc++.h>
using namespace std;

// Function to return required minimum sum
int sumSubarrayMins(int A[], int n)
{
	// To store answer
	int ans = 0;
	for (int i = 0; i < n; i++) {
		// To store minimum element
		int min_ele = A[i];
		for (int j = i; j < n; j++) {
			// Finding minimum element of subarray
			min_ele = min(min_ele, A[j]);
			// Adding that minimum element of subarray in
			// answer
			ans += min_ele;
		}
	}
	return ans;
}

// Driver program
int main()
{
	int A[] = { 3, 1, 2, 4 };
	int n = sizeof(A) / sizeof(A[0]);
	// function call to get required result
	cout << sumSubarrayMins(A, n);

	return 0;
}


Time Complexity: O(N2),because of two nested for loops 
Space Complexity: O(1).
*/

// 2. Optimal : 

// CPP implementation of above approach
class Solution {
public:
   const int MOD = 1000000007;

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    stack<int> s1, s2;
    vector<long long> left(n), right(n, n);
    for (int i = 0; i < n; ++i) {
        while (!s1.empty() && arr[s1.top()] > arr[i]) {
            s1.pop();
        }
        left[i] = s1.empty() ? i + 1 : i - s1.top();
        s1.push(i);
    }
    for (int i = n - 1; i >= 0; --i) {
        while (!s2.empty() && arr[s2.top()] >= arr[i]) {
            s2.pop();
        }
        right[i] = s2.empty() ? n - i : s2.top() - i;
        s2.push(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + arr[i] * left[i] * right[i]) % MOD;
    }
    return static_cast<int>(ans);
}
};

// Time Complexity: O(N), where N is the length of A. 
// Space Complexity: O(N).
