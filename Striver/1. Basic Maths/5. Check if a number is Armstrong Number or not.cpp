// Link: https://takeuforward.org/maths/check-if-a-number-is-armstrong-number-or-not/

// video: https://www.youtube.com/watch?v=1xNbjMdbjug

                            
#include <bits/stdc++.h> 
using namespace std;

// Function to check if a
// number is an Armstrong number
bool isArmstrong(int num) {
    // Calculate the number of
    // digits in the given number
    int k = to_string(num).length();
    // Initialize the sum of digits
    // raised to the power of k to 0
    int sum = 0;
    // Copy the value of the input
    // number to a temporary variable n
    int n = num;
    // Iterate through each
    // digit of the number
    while(n > 0){
        // Extract the last
        // digit of the number
        int ld = n % 10;
        // Add the digit raised to
        // the power of k to the sum
        sum += pow(ld, k); 
        // Remove the last digit
        // from the number
        n = n / 10;
    }
    // Check if the sum of digits raised to
    // the power of k equals the original number
    return sum == num ? true : false;
}

int main() {
    int number = 153;
    if (isArmstrong(number)) {
        cout << number << " is an Armstrong number." << endl;
    } else {
        cout << number << " is not an Armstrong number." << endl;
    }
    return 0;
}
                            
// Time Complexity: O(log10N + 1) where N is the input number. The time complexity is determined by the number of digits in the input integer N. In the worst case when N is a multiple of 10 the number of digits in N is log10 N + 1.

// In the while loop we divide N by 10 until it becomes 0 which takes log10N iterations.
// In each iteration of the while loop we perform constant time operations like modulus and division and pushing elements into the vector.
// Space Complexity: O(1) as only a constant amount of additional memory for the reversed number regardless of size of the input number.