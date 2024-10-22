// Link : https://practice.geeksforgeeks.org/problems/implement-atoi/1

/*
1. Brute 

// A C++ program for
// implementation of atoi
#include <bits/stdc++.h>
using namespace std;

// A simple atoi() function
int myAtoi(char* str)
{
	// Initialize result
	int res = 0;

	// Initialize sign as positive
	int sign = 1;

	// Initialize index of first digit
	int i = 0;

	// If number is negative,
	// then update sign
	if (str[0] == '-') {
		sign = -1;

		// Also update index of first digit
		i++;
	}

	// Iterate through all digits
	// and update the result
	for (; str[i] != '\0'; i++)
		res = res * 10 + str[i] - '0';

	// Return result with sign
	return sign * res;
}

// Driver code
int main()
{
	char str[] = "-123";

	// Function call
	int val = myAtoi(str);
	cout << val;
	return 0;
}

// This is code is contributed by rathbhupendra

Time Complexity: O(n), Only one traversal of the string is needed.
Space Complexity: O(1), As no extra space is required
*/

// A simple C++ program for
// implementation of atoi
#include <bits/stdc++.h>
using namespace std;

int myAtoi(const char* str)
{
	int sign = 1, base = 0, i = 0;

	// if whitespaces then ignore.
	while (str[i] == ' ') {
		i++;
	}

	// sign of number
	if (str[i] == '-' || str[i] == '+') {
		sign = 1 - 2 * (str[i++] == '-');
	}

	// checking for valid input
	while (str[i] >= '0' && str[i] <= '9') {
		// handling overflow test case
		if (base > INT_MAX / 10
			|| (base == INT_MAX / 10 && str[i] - '0' > 7)) {
			if (sign == 1)
				return INT_MAX;
			else
				return INT_MIN;
		}
		base = 10 * base + (str[i++] - '0');
	}
	return base * sign;
}

// Driver Code
int main()
{
	char str[] = " -123";

	// Functional Code
	int val = myAtoi(str);
	cout << " " << val;
	return 0;
}

/*
Time Complexity: O(n), Only one traversal of the string is needed.
Space Complexity: O(1), As no extra space is required.

Four corner cases need to be handled:

Discard all leading whitespaces
Sign of the number
Overflow
Invalid Input
*/
