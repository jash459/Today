// Link: https://takeuforward.org/data-structure/count-digits-in-a-number/

// video: https://www.youtube.com/watch?v=1xNbjMdbjug

/*
1. Brute
                                
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Function to count the number
// of digits in an integer 'n'.
int countDigits(int n){
    // Initialize a counter variable
    // 'cnt' to store the count of digits.
    int cnt = 0;
    // While loop iterates until 'n'
    // becomes 0 (no more digits left).
    while(n > 0){
        // Increment the counter
        // for each digit encountered.
        cnt = cnt + 1;
        // Divide 'n' by 10 to
        // remove the last digit.
        n = n / 10;
    }
    // Return the
    // count of digits.
    return cnt;
}



int main() {
    int N = 329823;
    cout << "N: "<< N << endl;
    int digits = countDigits(N);
    cout << "Number of Digits in N: "<< digits << endl;
    return 0;
}

Time Complexity: O(log10N + 1) where N is the input number. The time complexity is determined by the number of digits in the input integer N. In the worst case when N is a multiple of 10 the number of digits in N is log10N + 1.

In the while loop we divide N by 10 until it becomes 0 which takes log10N iterations.
In each iteration of the while loop we perform constant time operations like division and increment the counter.
Space Complexity : O(1) as only a constant amount of additional memory for the counter regardless of size of the input number.

*/

// Optimal:

                                
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;



// Calculate the count of digits in 'n'
// using logarithmic operation log10(n) + 1.
int countDigits(int n){
    // Initialize a variable 'cnt' to
    // store the count of digits.
    int cnt = (int)(log10(n)+1);

    // The expression (int)(log10(n)+1)
    // calculates the number of digits in 'n'
    // and casts it to an integer.
    
    // Adding 1 to the result accounts
    // for the case when 'n' is a power of 10,
    // ensuring that the count is correct.
   
    // Finally, the result is cast
    // to an integer to ensure it is rounded
    // down to the nearest whole number.
    
    // Return the count of digits in 'n'.
    return cnt;
}




int main() {
    int N = 329823;
    cout << "N: "<< N << endl;
    int digits = countDigits(N);
    cout << "Number of Digits in N: "<< digits << endl;
    return 0;
}
                                
                            
// Time Complexity: O(1)as simple arithmetic operations in constant time are computed on integers.

// Space Complexity : O(1)as only a constant amount of additional memory for the count variable regardless of size of the input number.