// Link : https://takeuforward.org/data-structure/rod-cutting-problem-dp-24/

// video: https://www.youtube.com/watch?v=mO8XpGoJwuo

/*

1. Memo :

int f(int ind, int N, vector<int> &price, vector<vector<int>> &dp){
    if(ind == 0){
        return N * price[0];
    }

        // If the result for this index and weight limit is already calculated, return it
    if (dp[ind][N] != -1)
        return dp[ind][N];
        
    // Calculate the maximum value without taking the current item
    int notTaken = 0 + f(ind-1, N, price, dp);
    
    // Calculate the maximum value by taking the current item
    int taken = INT_MIN;
    int rodLength= ind+1;
    if (rodLength <= N)
        taken = price[ind] + f( ind, N - rodLength, price, dp);
        
    // Store the maximum value in the DP table and return it
    return dp[ind][N] = max(notTaken, taken);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>>dp(n, vector<int>(n+1, -1));
    return f(n-1, n, price, dp);
}

Time Complexity: O(N*N)
Reason: There are N*N states therefore at max ‘N*W’ new problems will be solved.
Space Complexity: O(N*N) + O(N)
Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*N)).


/*

2. Tabulation "


#include <bits/stdc++.h>
using namespace std;

// Function to solve the unbounded knapsack problem
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0)); // Create a DP table

    // Base Condition
    for (int i = wt[0]; i <= W; i++) {
        dp[0][i] = (i / wt[0]) * val[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = 0 + dp[ind - 1][cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]]; // Maximum value by taking the current item

            dp[ind][cap] = max(notTaken, taken); // Store the maximum value in the DP table
        }
    }

    return dp[n - 1][W]; // Return the maximum value considering all items and the knapsack capacity
}

int main() {
    vector<int> wt = {2, 4, 6}; // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10; // Weight capacity of the knapsack
    int n = wt.size(); // Number of items

    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}


Time Complexity: O(N*W)
Reason: There are two nested loops
Space Complexity: O(N*W)
Reason: We are using an external array of size ‘N*W’. Stack Space is eliminated."*/


// 3. Space 


#include <bits/stdc++.h>
using namespace std;

// Function to solve the unbounded knapsack problem
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<int> cur(W + 1, 0); // Create a vector to store the current DP state

    // Base Condition
    for (int i = wt[0]; i <= W; i++) {
        cur[i] = (i / wt[0]) * val[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = cur[cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]]; // Maximum value by taking the current item

            cur[cap] = max(notTaken, taken); // Store the maximum value in the current DP state
        }
    }

    return cur[W]; // Return the maximum value considering all items and the knapsack capacity
}

int main() {
    vector<int> wt = {2, 4, 6}; // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10; // Weight capacity of the knapsack
    int n = wt.size(); // Number of items

    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}


// Time Complexity: O(N*W)
// Reason: There are two nested loops.
// Space Complexity: O(W)
// Reason: We are using an external array of size ‘W+1’ to store only one row.