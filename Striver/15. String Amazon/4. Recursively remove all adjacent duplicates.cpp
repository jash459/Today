// Link: https://www.geeksforgeeks.org/recursively-remove-adjacent-duplicates-given-string/

/*

1. Brute

#include <bits/stdc++.h>
using namespace std;

// Function to recursively remove adjacent duplicates
string rremove(string s) {
    // Create an empty string to build the result
    string sb = ""; 

    // Get the size of the input string
    int n = s.size(); 

    // Iterate over the length of current string
    for (int i = 0; i < n; i++) {
        bool repeated = false;

        // Check if the current characteris the same
        // as the next one
        while (i + 1 < n && s[i] == s[i + 1]) {
            repeated = true;  // Mark as repeated
          
            // Skip the next character
            // since it's a duplicate
            i++;  
        }

        // If the character was not repeated,
        // add it to the result string
        if (!repeated) sb += s[i];
    }

    // If no changes made, return the result string
    if (n == sb.length())
        return sb;
    
    // Otherwise, recursively call the function 
    // to check for more duplicates
    return rremove(sb);
}

int main() {
    string s = "geeksforgeek";  
    string result = rremove(s);  
    cout << result << endl;
    
    return 0;
}

Time Complexity: O(N2), In the worst case, the function may need to iterate almost through the entire string for each recursion, which makes the time complexity as O(N2).
Auxiliary Space:O(N), As we are making a new string at every iteration.

*/

// Optimized

#include <bits/stdc++.h>
using namespace std;

// Helper function to remove adjacent duplicates
void remove_util(string &str, int n) {

     // Get the length of the string
    int len = str.length(); 

     // Index to store the result string
    int k = 0; 

    // Iterate over the string to remove adjacent
    // duplicates
    for (int i = 0; i < n; i++) {

        // Check if the current character is the same
        //  as the next one
        if (i < n - 1 && str[i] == str[i + 1]) {
            // Skip all the adjacent duplicates
            while (i < n - 1 && str[i] == str[i + 1]) {
                i++;
            }
        } else {
            // If not a duplicate, store the character
            str[k++] = str[i];
        }
    }

    // Remove the remaining characters from the
    // original string
    str.erase(k);

    // If any adjacent duplicates were removed,
    //  recursively check for more
    if (k != n)
        remove_util(str, k);
}

// Function to initiate the removal of adjacent
// duplicates
string rremove(string s) {

    // Call the helper function
    remove_util(s, s.length());

    // Return the modified string
    return s;  
}

int main() {
    string s = "geeksforgeek";
    cout << rremove(s) << endl; 
    return 0;
}

// Time Complexity: O(N2), In the worst case, the function may need to iterate almost through the entire string for each recursion, which makes the time complexity as O(N2).
// Auxiliary Space: O(N), As the size of the recursive call stack can be N/2 in the worst case if we have the input like this abccba.