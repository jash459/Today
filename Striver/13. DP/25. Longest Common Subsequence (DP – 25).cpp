// Link : https://takeuforward.org/data-structure/longest-common-subsequence-dp-25/

/*
1. Memo : 
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
int lcsUtil(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp) {
    // Base case: If either string reaches the end, return 0
    if (ind1 < 0 || ind2 < 0)
        return 0;

    // If the result for this pair of indices is already calculated, return it
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    // If the characters at the current indices match, increment the LCS length
    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
    else
        // If the characters don't match, consider two options: moving either left or up in the strings
        return dp[ind1][ind2] = max(lcsUtil(s1, s2, ind1, ind2 - 1, dp), lcsUtil(s1, s2, ind1 - 1, ind2, dp));
}

// Function to calculate the length of the Longest Common Subsequence
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1)); // Create a DP table
    return lcsUtil(s1, s2, n - 1, m - 1, dp);
}

int main() {
    string s1 = "acd";
    string s2 = "ced";

    // Call the function to find and output the length of the Longest Common Subsequence
    cout << "The Length of Longest Common Subsequence is " << lcs(s1, s2) << endl;

    return 0; // Return 0 to indicate successful program execution
}


// Time Complexity: O(N*M)
// Reason: There are N*M states therefore at max ‘N*M’ new problems will be solved.
// Space Complexity: O(N*M) + O(N+M)
// Reason: We are using an auxiliary recursion stack space(O(N+M)) (see the recursive tree, in the worst case, we will go till N+M calls at a time) and a 2D array ( O(N*M)).
*/

/*

2. Tabulation 


#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Create a DP table

    // Initialize the base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP table to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }
    }

    return dp[n][m]; // Return the length of the Longest Common Subsequence
}

int main() {
    string s1 = "acd";
    string s2 = "ced";

    // Call the function to find and output the length of the Longest Common Subsequence
    cout << "The Length of Longest Common Subsequence is " << lcs(s1, s2) << endl;

    return 0; // Return 0 to indicate successful program execution
}
Time Complexity: O(N*M)
Reason: There are two nested loops
Space Complexity: O(N*M)
Reason: We are using an external array of size ‘N*M)’. Stack Space is eliminated.
*/

// 3. Space 


#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Initialize two vectors to store the current and previous rows of the DP table
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Base case is covered as we have initialized the prev and cur vectors to 0.

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1]; // Characters match, increment LCS length
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]); // Characters don't match, consider the maximum from above or left
        }
        prev = cur; // Update the previous row with the current row
    }

    return prev[m]; // Return the length of the Longest Common Subsequence
}

int main() {
    string s1 = "acd";
    string s2 = "ced";

    // Call the function to find and output the length of the Longest Common Subsequence
    cout << "The Length of Longest Common Subsequence is " << lcs(s1, s2) << endl;

    return 0; // Return 0 to indicate successful program execution
}

// Time Complexity: O(N*M)
// Reason: There are two nested loops.
// Space Complexity: O(M)
// Reason: We are using an external array of size ‘M+1’ to store only two rows.