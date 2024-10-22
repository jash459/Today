// Link: https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/

/*
Brute
#include <algorithm>
#include <iostream>
using namespace std;

// Function to check if two strings are anagrams
bool areAnagrams(string s1, string s2)
{
    // Sort both strings
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    // Compare sorted strings
    return s1 == s2;
}

int main()
{
    string str1 = "listen";
    string str2 = "silent";

    if (areAnagrams(str1, str2)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    str1 = "gram";
    str2 = "arm";

    if (areAnagrams(str1, str2)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}

Time Complexity: O(m*log(m) + n * log(n)), For sorting both strings
Auxiliary Space: O(1) as it is using constant extra space*/

// Optimized:

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s1, string s2)
{

    // If the lengths are not the same, they cannot be
    // anagrams
    if (s1.length() != s2.length()) {
        return false;
    }

    // Initialize s1 frequency array for 26 lowercase
    // characters
    vector<int> freq(26, 0);

    // Count frequency of each character in string s1
    for (char c : s1) {
        freq[c - 'a']++;
    }

    // Subtract frequency of each character in string s2
    for (char c : s2) {
        freq[c - 'a']--;
    }

    // Check if all frequencies are zero
    for (int count : freq) {
        if (count != 0) {
            return false;
        }
    }

    return true;
}

// Driver code
int main()
{
    string s1 = "listen";
    string s2 = "silent";
    cout << boolalpha << isAnagram(s1, s2) << endl;

    s1 = "hello";
    s2 = "bello";
    cout << boolalpha << isAnagram(s1, s2) << endl;

    return 0;
}

// Time Complexity: O(m+n), where m and n is the length of given string
// Auxiliary Space: O(1)