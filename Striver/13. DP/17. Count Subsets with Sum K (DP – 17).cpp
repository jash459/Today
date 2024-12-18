// Link : https://takeuforward.org/data-structure/count-subsets-with-sum-k-dp-17/

// video : https://www.youtube.com/watch?v=ZHyb-A2Mte4

/*

1. Memo : 


#include <bits/stdc++.h>

using namespace std;

int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){

    if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2; // Both including and excluding arr[0] yield the target sum
        if(target==0 || target == arr[0])
            return 1; // Either including or excluding arr[0] yields the target sum
            return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}

int findWays(vector<int> &num, int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}

int main() {

  vector<int> arr = {0,0,1};
  int k=1;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}


Time Complexity: O(N*K)

Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved.

Space Complexity: O(N*K) + O(N)

Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).


*/


/*

2. Better  ---> see the memo code for extra edge case . 


#include <bits/stdc++.h>
using namespace std;

// Function to count the number of subsets with a given sum
int findWays(vector<int>& num, int k) {
    int n = num.size();

    // Create a 2D DP table with dimensions n x k+1, initialized with zeros
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // Base case: If the target sum is 0, there is one valid subset (the empty subset)
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    // Initialize the first row based on the first element of the array
    if (num[0] <= k) {
        dp[0][num[0]] = 1;
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // Exclude the current element
            int notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target) {
                taken = dp[ind - 1][target - num[ind]];
            }

            // Update the DP table
            dp[ind][target] = notTaken + taken;
        }
    }

    // The final result is in the last cell of the DP table
    return dp[n - 1][k];
}

int main() {
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);

    return 0;
}


Time Complexity: O(N*K)

Reason: There are two nested loops

Space Complexity: O(N*K)

Reason: We are using an external array of size ‘N*K’. Stack Space is eliminated.
*/

// 3. Optimal :


#include <bits/stdc++.h>
using namespace std;

// Function to count the number of subsets with a given sum
int findWays(vector<int>& num, int k) {
    int n = num.size();

    // Initialize a vector 'prev' to represent the previous row of the DP table
    vector<int> prev(k + 1, 0);

    // Base case: If the target sum is 0, there is one valid subset (the empty subset)
    prev[0] = 1;

    // Initialize the first row based on the first element of the array
    if (num[0] <= k) {
        prev[num[0]] = 1;
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        // Create a vector 'cur' to represent the current row of the DP table
        vector<int> cur(k + 1, 0);

        cur[0] = 1;

        for (int target = 1; target <= k; target++) {
            // Exclude the current element
            int notTaken = prev[target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target) {
                taken = prev[target - num[ind]];
            }

            // Update the current row of the DP table
            cur[target] = notTaken + taken;
        }

        // Set 'cur' as 'prev' for the next iteration
        prev = cur;
    }

    // The final result is in the last cell of the 'prev' vector
    return prev[k];
}

int main() {
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);

    return 0;
}


// Time Complexity: O(N*K)
// Reason: There are two nested loops
// Space Complexity: O(K)
// Reason: We are using an external array of size ‘K+1’ to store only one row.