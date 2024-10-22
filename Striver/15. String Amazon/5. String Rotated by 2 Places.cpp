// Link: https://www.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1
//     : https://www.geeksforgeeks.org/check-string-can-obtained-rotating-another-string-2-places/


/*

1. Brute

#include <bits/stdc++.h>
using namespace std;

// Function to check if a string can be obtained by rotating
// another string by exactly 2 places.
bool isRotated(string str1, string str2)
{
    // Check if the lengths of the two strings are not
    // equal, return false if they are not.
    if (str1.length() != str2.length())
        return false;

    // If the length of the strings is less than or equal to
    // 2, simply check if they are equal.
    if (str1.length() <= 2 || str2.length() <= 2)
        return (str1 == str2);

    // Initialize strings to store the clockwise and
    // anti-clockwise rotations of str2.
    string clock_rot = "";
    string anticlock_rot = "";
    int len = str2.length();

    // Store the anti-clockwise rotation of str2 by
    // concatenating the last 2 characters to the beginning.
    anticlock_rot = anticlock_rot + str2.substr(len - 2, 2)
                    + str2.substr(0, len - 2);

    // Store the clockwise rotation of str2 by concatenating
    // the first 2 characters to the end.
    clock_rot
        = clock_rot + str2.substr(2) + str2.substr(0, 2);

    // Check if either the clockwise or anti-clockwise
    // rotation of str2 is equal to str1, and return the
    // result.
    return (str1.compare(clock_rot) == 0
            || str1.compare(anticlock_rot) == 0);
}

// Driver code
int main()
{
    string str1 = "amazon";
    string str2 = "azonam";

    if (isRotated(str1, str2)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    
    str1 = "amazon";
    str2 = "onamaz";
    if (isRotated(str1, str2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    
    return 0;
}

Time Complexity: O(n), Time is taken to rotate the string and then compare the string.
Auxiliary Space: O(n), Space for storing clockwise and anticlockwise strings.
*/


// Optimized

// C++ program to check if a string can be obtained by
// rotating another string by exactly 2 places.

#include <bits/stdc++.h>
using namespace std;

// Function to check if a string can be obtained by rotating
// another string by exactly 2 places.
bool isRotated(string str1, string str2)
{
    // Your code here
    int n = str1.length();
    bool clockwise = true, anticlockwise = true;

    // Check if str2 can be obtained by rotating str1
    // clockwise by 2 places
    for (int i = 0; i < n; i++) {
        if (str1[i] != str2[(i + 2) % n]) {
            clockwise = false; // not rotated clockwise
            break;
        }
    }

    // Check if str2 can be obtained by rotating str1
    // anticlockwise by 2 places
    for (int i = 0; i < n; i++) {
        if (str1[(i + 2) % n] != str2[i]) {
            anticlockwise
                = false; // not rotated anticlockwise
            break;
        }
    }

    // if any of both is true, return true
    return clockwise or anticlockwise;
}

// Driver code
int main()
{
    string str1 = "amazon";
    string str2 = "azonam";
    if (isRotated(str1, str2)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    str1 = "amazon";
    str2 = "onamaz";
    if (isRotated(str1, str2)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}


// Time Complexity: O(n), Iterating over the string 2 times for comparing both the strings.
// Auxiliary Space: O(1)