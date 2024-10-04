// Link : https://takeuforward.org/data-structure/target-sum-dp-21/

// video : https://www.youtube.com/watch?v=b3GD8263-PQ

/*

1. Memo : 


#include <bits/stdc++.h>
using namespace std;

// Function to count partitions of the array into subsets with a given target sum
int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // Base cases
    if (ind == 0) {
        if (target == 0 && arr[0] == 0)
            return 2; // Two ways to partition: include or exclude the element
        if (target == 0 || target == arr[0])
            return 1; // One way to partition: include or exclude the element
        return 0; // No way to partition
    }
    
    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];
        
    // Calculate the number of ways without taking the current element
    int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);
    
    // Calculate the number of ways by taking the current element
    int taken = 0;
    if (arr[ind] <= target)
        taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);
        
    // Store the sum of ways in the DP array and return it
    return dp[ind][target] = (notTaken + taken);
}

// Function to count the number of ways to achieve the target sum
int targetSum(int n, int target, vector<int>& arr) {
    int totSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        totSum += arr[i];
    }
    
    // Checking for edge cases
    if (totSum - target < 0)
        return 0; // Not possible to achieve the target sum
    if ((totSum - target) % 2 == 1)
        return 0; // The difference between the total sum and target sum must be even
    
    int s2 = (totSum - target) / 2; // Calculate the required sum for each subset
    
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1)); // Initialize DP table
    return countPartitionsUtil(n - 1, s2, arr, dp); // Call the helper function
}

int main() {
    vector<int> arr = {1, 2, 3, 1};
    int target = 3;
                     
    int n = arr.size();
    cout << "The number of ways found is " << targetSum(n, target, arr) << endl;
    
    return 0; // Return 0 to indicate successful program execution
}


Time Complexity: O(N*K)

Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved.

Space Complexity: O(N*K) + O(N)

Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).

*/

/*

2. Tabulation :


#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;

// Function to count the number of ways to achieve the target sum
int findWays(vector<int> &num, int tar) {
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if (num[0] == 0)
        dp[0][0] = 2;  // 2 cases - pick and not pick
    else
        dp[0][0] = 1;  // 1 case - not pick

    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1;  // 1 case - pick

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= tar; target++) {

            int notTaken = dp[ind - 1][target];

            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];

            dp[ind][target] = (notTaken + taken) % mod;
        }
    }
    return dp[n - 1][tar];
}

// Function to calculate the number of ways to achieve the target sum
int targetSum(int n, int target, vector<int>& arr) {
    int totSum = 0;
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;  // Not possible to achieve the target sum

    return findWays(arr, (totSum - target) / 2);
}

int main() {
    vector<int> arr = {1, 2, 3, 1};
    int target = 3;

    int n = arr.size();
    cout << "The number of ways found is " << targetSum(n, target, arr) << endl;

    return 0;  // Return 0 to indicate successful program execution
}

Time Complexity: O(N*K)

Reason: There are two nested loops

Space Complexity: O(N*K)

Reason: We are using an external array of size ‘N*K’. Stack Space is eliminated.*/

// 3. Space


#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;

// Function to count the number of ways to achieve the target sum
int findWays(vector<int> &num, int tar) {
    int n = num.size();

    vector<int> prev(tar + 1, 0);

    if (num[0] == 0)
        prev[0] = 2;  // 2 cases - pick and not pick
    else
        prev[0] = 1;  // 1 case - not pick

    if (num[0] != 0 && num[0] <= tar)
        prev[num[0]] = 1;  // 1 case - pick

    for (int ind = 1; ind < n; ind++) {
        vector<int> cur(tar + 1, 0);
        for (int target = 0; target <= tar; target++) {
            int notTaken = prev[target];

            int taken = 0;
            if (num[ind] <= target)
                taken = prev[target - num[ind]];

            cur[target] = (notTaken + taken) % mod;
        }
        prev = cur;
    }
    return prev[tar];
}

// Function to calculate the number of ways to achieve the target sum
int targetSum(int n, int target, vector<int>& arr) {
    int totSum = 0;
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;  // Not possible to achieve the target sum

    return findWays(arr, (totSum - target) / 2);
}

int main() {
    vector<int> arr = {1, 2, 3, 1};
    int n = arr.size();
    int target = 3;

    cout << "The number of subsets found is " << targetSum(n, target, arr) << endl;

    return 0;  // Return 0 to indicate successful program execution
}


// Time Complexity: O(N*K)

// Reason: There are three nested loops

// Space Complexity: O(K)

// Reason: We are using an external array of size ‘K+1’ to store only one row.