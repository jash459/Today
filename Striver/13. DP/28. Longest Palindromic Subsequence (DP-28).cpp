// Link: https://takeuforward.org/data-structure/longest-palindromic-subsequence-dp-28/

// video: https://www.youtube.com/watch?v=6i_T5kkfv4A
/*

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the length of the Longest Common Subsequence
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Create a 2D DP array to store the length of the LCS
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Initialize the first row and first column to 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP array
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    // The value at dp[n][m] contains the length of the LCS
    return dp[n][m];
}

// Function to calculate the length of the Longest Palindromic Subsequence
int longestPalindromeSubsequence(string s) {
    // Create a reversed copy of the string
    string t = s;
    reverse(s.begin(), s.end());

    // Call the LCS function to find the length of the Longest Common Subsequence
    return lcs(s, t);
}

int main() {
    string s = "bbabcbcab";

    // Call the longestPalindromeSubsequence function and print the result
    cout << "The Length of Longest Palindromic Subsequence is " << longestPalindromeSubsequence(s);
    return 0;
}

Time Complexity: O(N*N)
Reason: There are two nested loops
Space Complexity: O(N*N)
Reason: We are using an external array of size ‘(N*N)’. Stack Space is eliminated.
*/

// Space

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the length of the Longest Common Subsequence
int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    // Create two arrays to store the previous and current rows of DP values
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Base Case is covered as we have initialized the prev and cur to 0.

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
        }
        // Update the prev array with the current values
        prev = cur;
    }

    // The value at prev[m] contains the length of the LCS
    return prev[m];
}

// Function to calculate the length of the Longest Palindromic Subsequence
int longestPalindromeSubsequence(string s)
{
    // Create a reversed copy of the string
    string t = s;
    reverse(s.begin(), s.end());

    // Call the LCS function to find the length of the Longest Common Subsequence
    return lcs(s, t);
}

int main()
{
    string s = "bbabcbcab";

    // Call the longestPalindromeSubsequence function and print the result
    cout << "The Length of Longest Palindromic Subsequence is " << longestPalindromeSubsequence(s);
    return 0;
}

// Complexity Analysis
// Time Complexity: O(N*N)
// Reason: There are two nested loops.
// Space Complexity: O(N)
// Reason: We are using an external array of size ‘N+1’ to store only two rows.