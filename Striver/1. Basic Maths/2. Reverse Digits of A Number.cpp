// Link: https://takeuforward.org/maths/reverse-digits-of-a-number

// video: https://www.youtube.com/watch?v=1xNbjMdbjug&t=930s

                            
#include <iostream>
using namespace std;

int main() {
	// Declare a variable 'n' to
	// store the input integer.
	int n;
	// Prompt the user to enter an
	// integer and store it in 'n'.
	cin >> n;
	// Initialize a variable 'revNum' to
	// store the reverse of the input integer.
	int revNum = 0;
	// Start a while loop to reverse the
	// digits of the input integer.
	while(n > 0){
		// Extract the last digit of
		// 'n' and store it in 'ld'.
		int ld = n % 10;
		// Multiply the current reverse number
		// by 10 and add the last digit.
		revNum = (revNum * 10) + ld;
		// Remove the last digit from 'n'.
		n = n / 10;
	}
	// Print the reversed number.
	cout << revNum;
}
                            
// Time Complexity: O(log10N + 1) where N is the input number. The time complexity is determined by the number of digits in the input integer N. In the worst case when N is a multiple of 10 the number of digits in N is log10 N + 1.

// In the while loop we divide N by 10 until it becomes 0 which takes log10N iterations.
// In each iteration of the while loop we perform constant time operations like modulus and division and pushing elements into the vector.
// Space Complexity: O(1) as only a constant amount of additional memory for the reversed number regardless of size of the input number.