// Link: https://takeuforward.org/data-structure/check-if-a-number-is-prime-or-not/

// video: https://www.youtube.com/watch?v=MJcckSfoYdI

/*
Brute
                                
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

// Function to check if a
// given number is prime.
bool checkPrime(int n){ 
     // Initialize a counter variable to
    // count the number of factors.
    int cnt = 0;
    // Loop through numbers from 1 to n.
    for(int i = 1; i<=n; i++){ 
        // If n is divisible by i
        // without any remainder.
        if(n%i ==0){ 
             // Increment the counter.
            cnt = cnt+1;
        }
    }

     // If the number of
     // factors is exactly 2
    if(cnt==2){
         // Return true, indicating
         // that the number is prime.
        return true;
    }
    // If the number of
    // factors is not 2.
    else{ 
        // Return false, indicating
        // that the number is not prime.
        return false; 
    }
}

int main() {
    int n = 1483;
    bool isPrime = checkPrime(n);
    if(isPrime){
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
                                
                            
Time Complexity: O(N) where N is the input number as we iterate from 1 to N performing constant-time operation for each iteration.

Space Complexity : O(1) as the space used by the algorithm does not increase with the size of the input.\
*/

                                
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

// Function to check if a
// given number is prime.
bool checkPrime(int n){ 

    // Initialize a counter variable to
    // count the number of factors.
    int cnt = 0;

    // Loop through numbers from 1
    // to the square root of n.
    for(int i = 1; i <= sqrt(n); i++){ 

        // If n is divisible by i
        // without any remainder.
        if(n % i == 0){ 

            // Increment the counter.
            cnt = cnt + 1;

            // If n is not a perfect square,
            // count its reciprocal factor.
            if(n / i != i){
                cnt = cnt + 1;
            }
        }
    }

    // If the number of
    // factors is exactly 2.
    if(cnt == 2){
         // Return true, indicating
         // that the number is prime.
        return true;
    }
    // If the number of
    // factors is not 2.
    else{ 
        // Return false, indicating
        // that the number is not prime.
        return false; 
    }
}


int main() {
    int n = 1483;
    bool isPrime = checkPrime(n);
    if(isPrime){
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
                                
// Time Complexity: O(sqrt(N))where N is the input number. The loop iterates up to the square root of n performing constant time operations at each step.

// Space Complexity : O(1) as the space complexity remains constant and independent of the input size. Only a fixed amount of memory is required to store the integer variables.                                