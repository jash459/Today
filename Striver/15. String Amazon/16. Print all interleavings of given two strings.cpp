// Link: https://www.geeksforgeeks.org/print-all-interleavings-of-given-two-strings/

/*
1. Brute 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printIlsRecur(string str1, string str2, string interleaving, vector<string>& results) {
  // Base case: If both strings are empty, add the interleaving to results
  if (str1.empty() && str2.empty()) {
    results.push_back(interleaving);
    return;
  }

  // If str1 is not empty, append its first character to interleaving and recur
  if (!str1.empty()) {
    printIlsRecur(str1.substr(1), str2, interleaving + str1[0], results);
  }

  // If str2 is not empty, append its first character to interleaving and recur
  if (!str2.empty()) {
    printIlsRecur(str1, str2.substr(1), interleaving + str2[0], results);
  }
}

void printIls(string str1, string str2) {
  vector<string> results;
  printIlsRecur(str1, str2, "", results);

  cout << "Interleavings of " << str1 << " and " << str2 << ":" << endl;
  for (const string& interleaving : results) {
    cout << interleaving << endl;
  }
}

int main() {
  string str1 = "AB";
  string str2 = "CD";
  printIls(str1, str2);
  return 0;
}


// This is code is contributed by rathbhupendra
Time Complexity: O(2 ^ (m+n))
Auxiliary Space: O(1)
*/

// 2. Optimal

#include <bits/stdc++.h>
using namespace std;

// Function to print interleavings of two strings
void printInterleavings(string str1, string str2)
{
	int m = str1.length();
	int n = str2.length();

	// Create a 2D vector to store interleavings
	vector<vector<vector<string> > > dp(
		m + 1, vector<vector<string> >(n + 1));

	// Base cases: If one of the strings is empty,
	// return the other string
	for (int i = 0; i <= m; i++) {
		dp[i][0] = { str1.substr(0, i) };
	}
	for (int j = 0; j <= n; j++) {
		dp[0][j] = { str2.substr(0, j) };
	}

	// Fill in the dynamic programming table
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			// Append the current character of str1 to
			// each interleaved string from previous cells
			dp[i][j] = dp[i - 1][j];
			for (string& s : dp[i][j]) {
				s += str1[i - 1];
			}

			// Append the current character of str2 to each
			// interleaved string from previous cells
			for (string& s : dp[i][j - 1]) {
				dp[i][j].push_back(s + str2[j - 1]);
			}
		}
	}

	// Print all interleavings
	for (const string& interleaved : dp[m][n]) {
		cout << interleaved << endl;
	}
}

// Example usage
int main()
{
	string str1 = "AB";
	string str2 = "CD";
	printInterleavings(str1, str2);
	return 0;
}
// THIS CODE IS CONTRIBUTED BY YASH
// AGARWAL(YASHAGARWAL2852002)

/*
Time complexity: O(m * n * L), where m and n are the lengths of str1 and str2 respectively, and L is the average length of the interleaved strings.
Auxiliary Space: O(m * n * L), where m and n are the lengths of str1 and str2 respectively, and L is the average length of the interleaved strings.
*/