// Link: https://takeuforward.org/data-structure/burst-balloons-partition-dp-dp-51/

// video: https://www.youtube.com/watch?v=Yz4LlDSlkns

/*
1. Recursive Approach

#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the maximum coins obtained
int maxCoinsHelper(int i, int j, vector<int> &nums) {
    if (i > j) return 0;
    int maxCoins = INT_MIN;
    
    // Iterate through each possible balloon to burst last
    for (int k = i; k <= j; k++) {
        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i - 1] * nums[k] * nums[j + 1];
        
        // Recursively calculate the maximum coins for the remaining balloons
        int remainingCoins = maxCoinsHelper(i, k - 1, nums) + maxCoinsHelper(k + 1, j, nums);
        
        // Update the maximum coins
        maxCoins = max(maxCoins, coins + remainingCoins);
    }
    
    return maxCoins;
}

// Function to calculate the maximum coins obtained
int maxCoins(vector<int> &nums) {
    int n = nums.size();
    
    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    // Call the helper function to compute the maximum coins
    return maxCoinsHelper(1, n, nums);
}

int main() {
    vector<int> nums = {3, 1, 5, 8};
    int maxCoinsResult = maxCoins(nums);
    cout << "Maximum coins obtained: " << maxCoinsResult << "\n";
    
    return 0;
}

Time Complexity: Exponential
*/

/*
2. Memo


#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the maximum coins obtained
int maxCoinsHelper(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int maxCoins = INT_MIN;
    
    // Iterate through each possible balloon to burst last
    for (int k = i; k <= j; k++) {
        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i - 1] * nums[k] * nums[j + 1];
        
        // Recursively calculate the maximum coins for the remaining balloons
        int remainingCoins = maxCoinsHelper(i, k - 1, nums, dp) + maxCoinsHelper(k + 1, j, nums, dp);
        
        // Update the maximum coins
        maxCoins = max(maxCoins, coins + remainingCoins);
    }
    
    return dp[i][j] = maxCoins;
}

// Function to calculate the maximum coins obtained
int maxCoins(vector<int> &nums) {
    int n = nums.size();
    
    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    // Create a DP array for memoization
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    
    // Call the helper function to compute the maximum coins
    return maxCoinsHelper(1, n, nums, dp);
}

int main() {
    vector<int> nums = {3, 1, 5, 8};
    int maxCoinsResult = maxCoins(nums);
    cout << "Maximum coins obtained: " << maxCoinsResult << "\n";
    
    return 0;
}

Time Complexity: O(N3), There are total N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.

Space Complexity: O(N2) + Auxiliary stack space of O(N), N2 for the dp array we are using. 
*/

// 3. 

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum coins obtained
int maxCoins(vector<int> &nums) {
    int n = nums.size();
    
    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    // Create a DP array for memoization
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (i > j) continue;
            int maxi = INT_MIN;
            
            // Iterate through each possible balloon to burst last
            for (int ind = i; ind <= j; ind++) {
                // Calculate the coins obtained by bursting the ind-th balloon last
                int coins = nums[i - 1] * nums[ind] * nums[j + 1];
                
                // Calculate the maximum coins for the remaining balloons
                int remainingCoins = dp[i][ind - 1] + dp[ind + 1][j];
                
                // Update the maximum coins
                maxi = max(maxi, coins + remainingCoins);
            }
            
            dp[i][j] = maxi;
        }
    }
    
    return dp[1][n];
}

int main() {
    vector<int> nums = {3, 1, 5, 8};
    int maxCoinsResult = maxCoins(nums);
    cout << "Maximum coins obtained: " << maxCoinsResult << "\n";
    
    return 0;
}

// Time Complexity: O(N3), There are total N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.
// Space Complexity: O(N2), N2 for the dp array we are using.