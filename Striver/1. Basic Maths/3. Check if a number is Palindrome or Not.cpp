// Link: https://takeuforward.org/data-structure/check-if-a-number-is-palindrome-or-not/

// video: https://www.youtube.com/watch?v=1xNbjMdbjug
                            
#include <iostream>
using namespace std;

// Function to check if a
// given integer is a palindrome
bool palindrome(int n)
{
    // Initialize a variable to
    // store the reverse of the number
    int revNum = 0;
    // Create a duplicate variable to
    // store the original number
    int dup = n;
    // Iterate through each digit of
    // the number until it becomes 0
    while (n > 0) {
        // Extract the last
        // digit of the number
        int ld = n % 10;
        // Build the reverse number
        // by appending the last digit
        revNum = (revNum * 10) + ld;
        // Remove the last digit
        // from the original number
        n = n / 10;
    }
    // Check if the original number
    // is equal to its reverse
    if (dup == revNum) {
        // If equal, return true
        // indicating it's a palindrome
        return true;
    } else {
        // If not equal, return false
        // indicating it's not a palindrome
        return false;
    }
}


int main() {
    int number = 4554;

    if (palindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}
                            
// Time Complexity: O(log10N + 1) where N is the input number. The time complexity is determined by the number of digits in the input integer N. In the worst case when N is a multiple of 10 the number of digits in N is log10 N + 1.

// In the while loop we divide N by 10 until it becomes 0 which takes log10N iterations.
// In each iteration of the while loop we perform constant time operations like modulus and division and pushing elements into the vector.
// Space Complexity: O(1) as only a constant amount of additional memory for the reversed number regardless of size of the input number.