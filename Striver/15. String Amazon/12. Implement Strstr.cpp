// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

/*
Brute

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length()) {
            return -1;
        }
        
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        
        return -1;        
    }
};
Time complexity: O(n∗m)
Space complexity: O(1)
*/

// Optimized

class Solution {
public:
    int strStr(string haystack, string needle) {
        // If both strings are equal, return 0 (needle found at the start)
        if (haystack == needle) {
            return 0;
        }

        int n = needle.length();  // Length of the needle
        int m = haystack.length(); // Length of the haystack

        // Handle the case where the needle is longer than the haystack
        if (n > m) return -1;

        // Get the first n characters of haystack as the initial comparison substring
        string hay = haystack.substr(0, n);

        // Iterate over the haystack starting from the nth character
        for (int i = n; i <= m; i++) {
            if (hay == needle) { // Check if the current substring matches the needle
                return i - n;    // Return the starting index of the match
            }
            // Update the substring by sliding one character to the right
            if (i < m) {
                hay = hay.substr(1) + haystack[i]; // Remove the first char, add next char
            }
        }

        // If no match is found, return -1
        return -1;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)