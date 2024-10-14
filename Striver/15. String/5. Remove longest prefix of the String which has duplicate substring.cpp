// Link: https://www.geeksforgeeks.org/remove-longest-prefix-of-the-string-which-has-duplicate-substring/

// C++ code for the above approach:

#include <bits/stdc++.h>
using namespace std;

// Function to delete the longest prefix
string delPrefix(string S)
{
	if (S.size() == 1)
		return S;
	int i = 0, maxi = 0;

	// Loop to find the
	// longest duplicate of prefix
	for (int j = 1; j < S.size(); j++) {
		int k = j;
		while (k < S.size() and S[k] == S[i]) {
			k++;
			i++;
		}
		maxi = max(maxi, i);
		i = 0;
	}
	return S.substr(maxi);
}

// Driver code
int main()
{
	string S = "aaaaa";
	string ans = delPrefix(S);

	// Function call
	cout << ans;
	return 0;
}

// Time Complexity: O(N2)
// Auxiliary Space: O(1)