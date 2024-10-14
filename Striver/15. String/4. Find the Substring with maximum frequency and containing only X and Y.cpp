// Link: https://www.geeksforgeeks.org/find-the-substring-with-maximum-frequency-and-containing-only-x-and-y/

/*
Naive Approach:- The basic approach to solve the problem is to check for different substrings of different lengths consisting of only given even and odd numbers.

Time Complexity: O(N2)
Auxiliary Space: O(N2)
*/

// 2. Optimal

// C++ code for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find substring
// which occur maximum number of times
char find(int N, string S, char even, char odd)
{
	// Count1 for even and count2 for odd
	// traversing the whole string
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < N; i++) {

		// Checking if the character is
		// equal to even
		if (S[i] == even)
			count1++;

		// Checking if the character
		// is equal to odd
		else if (S[i] == odd)
			count2++;
	}

	// If even occur maximum times
	if (count1 > count2)
		return even;

	// If odd occur maximum times
	else if (count2 > count1)
		return odd;

	// If both occur same times
	// checking which one is
	// lexicographically minimum
	else {
		if (even - '0' < odd - '0')
			return even;
		else
			return odd;
	}
}

// Driver Code
int main()
{
	// Length of string
	int N = 8;

	// Even and odd number
	char even = '2', odd = '7';
	string S = "22772777";

	// Output string
	string ans;

	// Calling function to find string
	ans = find(N, S, even, odd);

	// Printing output
	cout << ans << endl;
	return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)