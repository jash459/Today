// Link: https://www.geeksforgeeks.org/longest-palindromic-substring/

/*
Brute

#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring s[low..high] is a palindrome
bool checkPal(const string &s, int low, int high) {
    while (low < high) {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}

// This function prints the longest palindrome substring
// It also returns the length of the longest palindrome
string longestPalSubstr(string& s) {
  
    // Get length of input string
    int n = s.size();

    // All substrings of length 1 are palindromes
    int maxLen = 1, start = 0;

    // Nested loop to mark start and end index
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
          
            // Check if the current substring is 
            // a palindrome
            if (checkPal(s, i, j) && (j - i + 1) > maxLen) {
                start = i;
                maxLen = j - i + 1;
            }
        }
    }

    return s.substr(start, maxLen);
}

// Driver Code
int main() {
    string s = "forgeeksskeegfor";
    cout << longestPalSubstr(s) << endl;
    return 0;
}

Complexity Analysis: 

Time complexity: O(N3). Three nested loops are needed to find the longest palindromic substring in this approach.
Auxiliary complexity: O(1). As no extra space is needed.

*/

// Optimized

#include <bits/stdc++.h>
using namespace std;

string longestPalSubstr(string &s) {
    int n = s.length();
    if (n == 0) return "";

    int start = 0, maxLen = 1;

    // Traverse the input string
    for (int i = 0; i < n; i++) {

        // THIS RUNS TWO TIMES 
        // for both odd and even length
        // palindromes. j = 0 means odd
        // and j = 1 means odd length
        for (int j = 0; j <= 1; j++) {
            int low = i;
            int hi = i + j; 

            // Expand substring while it is a palindrome
            // and in bounds
            while (low >= 0 && hi < n && s[low] == s[hi]) {
                int currLen = hi - low + 1;
                if (currLen > maxLen) {
                    start = low;
                    maxLen = currLen;
                }
                low--;
                hi++;
            }
        }
    }

    return s.substr(start, maxLen);
}

// Driver code
int main() {
    string s = "forgeeksskeegfor";
    cout << longestPalSubstr(s) << endl;
    return 0;
}


// Time complexity: O(N2), where N is the length of the input string
// Auxiliary Space: O(1), No extra space used.