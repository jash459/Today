// Link: https://takeuforward.org/data-structure/print-all-divisors-of-a-given-number/

// video: https://www.youtube.com/watch?v=Ae_Ag_saG9s

/*
Better
                                
#include <bits/stdc++.h> 
using namespace std;

int* printDivisors(int n, int &size) {
    // Allocate memory for
    // the array of divisors
    int *divisors = new int[n]; 
     // Initialize the count of divisors
    int count = 0;

    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            // Add the divisor to the array
            divisors[count++] = i; 
        }
    }
    // Update the size parameter
    // with the count of divisors
    size = count; 
    // Return the array of divisors
    return divisors; 
}

int main() {
    int number = 12;
    int size;
    int *divisors = printDivisors(number, size);

    cout << "Divisors of " << number << " are: ";
    for (int i = 0; i < size; i++) {
        cout << divisors[i] << " ";
    }
    cout << std::endl;

    delete[] divisors;

    return 0;
}
                                
                            
Time Complexity: O(N) where N is the input number. The algorithm iterates through each number from 1 to n once to check if it is a divisor.

Space Complexity : O(N) where N is the input number. The algorithm iterates through each number from 1 to n once to check if it is a divisor.
*/

// Optimal

                                
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> findDivisors(int n) {
    // Initialize an empty
    // vector to store the divisors
    vector<int> divisors; 

    // Iterate up to the square
    // root of n to find divisors
    // Calculate the square root of n
    int sqrtN = sqrt(n); 
    
    // Loop from 1 to the
    // square root of n
    for (int i = 1; i <= sqrtN; ++i) { 
        // Check if i divides n
        // without leaving a remainder
        if (n % i == 0) { 
            // Add divisor i to the list
            divisors.push_back(i); 

            // Add the counterpart divisor
            // if it's different from i
            if (i != n / i) {
                // Add the counterpart
                // divisor to the list
                divisors.push_back(n / i); 
            }
        }
    }
    
    // Return the list of divisors
    return divisors; 
}


int main() {
    int number = 12;
    vector<int> divisors = findDivisors(number);

    cout << "Divisors of " << number << " are: ";
    for (int divisor : divisors) {
        cout << divisor << " ";
    }
    cout << endl;

    return 0;
}
                                
// Complexity Analysis
// Time Complexity: O(sqrt(N)) where N is the input number. The algorithm iterates through each number from 1 to the square root of N once to check if it is a divisor.

// Space Complexity : O(2*sqrt(N))where N is the input number. This approach allocates memory for an array to hold all the divisors. The size of this array could go to be 2*(sqrt(N)).            