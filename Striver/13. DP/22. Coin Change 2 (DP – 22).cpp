// Link : https://takeuforward.org/data-structure/coin-change-2-dp-22/

/*

1. Memo :


#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to make change for a given target sum
long countWaysToMakeChangeUtil(vector<int>& arr, int ind, int T, vector<vector<long>>& dp) {
    // Base case: if we're at the first element
    if (ind == 0) {
        // Check if the target sum is divisible by the first element
        return (T % arr[0] == 0);
    }
    
    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][T] != -1)
        return dp[ind][T];
        
    // Calculate the number of ways without taking the current element
    long notTaken = countWaysToMakeChangeUtil(arr, ind - 1, T, dp);
    
    // Calculate the number of ways by taking the current element
    long taken = 0;
    if (arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr, ind, T - arr[ind], dp);
        
    // Store the sum of ways in the DP table and return it
    return dp[ind][T] = notTaken + taken;
}

// Function to count the number of ways to make change for the target sum
long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T + 1, -1)); // Create a DP table
    
    // Call the utility function to calculate the answer
    return countWaysToMakeChangeUtil(arr, n - 1, T, dp);
}

int main() {
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();
    
    cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target) << endl;

    return 0; // Return 0 to indicate successful program execution
}


Time Complexity: O(N*T)
Reason: There are N*W states therefore at max ‘N*T’ new problems will be solved.
Space Complexity: O(N*T) + O(N)
Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*T)).
*/

/*

2. Tabulation :


#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to make change for a given target sum
long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T + 1, 0)); // Create a DP table

    // Initializing base condition
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = 1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            long notTaken = dp[ind - 1][target];

            long taken = 0;
            if (arr[ind] <= target)
                taken = dp[ind][target - arr[ind]];

            dp[ind][target] = notTaken + taken;
        }
    }

    return dp[n - 1][T];
}

int main() {
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();

    cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target) << endl;

    return 0; // Return 0 to indicate successful program execution
}


Time Complexity: O(N*T)
Reason: There are two nested loops
Space Complexity: O(N*T)
Reason: We are using an external array of size ‘N*T’. Stack Space is eliminated.*/

// 3. Space


#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to make change for a given target sum
long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<long> prev(T + 1, 0);  // Create a vector to store the previous DP state

    // Initialize base condition
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            prev[i] = 1;  // There is one way to make change for multiples of the first coin
        // Else condition is automatically fulfilled,
        // as the prev vector is initialized to zero
    }

    for (int ind = 1; ind < n; ind++) {
        vector<long> cur(T + 1, 0);  // Create a vector to store the current DP state
        for (int target = 0; target <= T; target++) {
            long notTaken = prev[target];  // Number of ways without taking the current coin

            long taken = 0;
            if (arr[ind] <= target)
                taken = cur[target - arr[ind]];  // Number of ways by taking the current coin
                
            cur[target] = notTaken + taken;  // Total number of ways for the current target
        }
        prev = cur;  // Update the previous DP state with the current state for the next coin
    }

    return prev[T];  // Return the total number of ways to make change for the target
}

int main() {
    vector<int> arr = {1, 2, 3};  // Coin denominations
    int target = 4;  // Target sum
    int n = arr.size();  // Number of coin denominations

    // Call the function to calculate and output the total number of ways to make change
    cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target) << endl;

    return 0;  // Return 0 to indicate successful program execution
}


// Time Complexity: O(N*T)
// Reason: There are two nested loops.
// Space Complexity: O(T)
// Reason: We are using an external array of size ‘T+1’ to store two rows only.