// Link : https://takeuforward.org/data-structure/buy-and-sell-stock-iii-dp-37/

// video : https://www.youtube.com/watch?v=-uQGzhYj8BQ

/*

1. Memo :


#include <bits/stdc++.h>
using namespace std;

int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp) {
    // Base case: If we reach the end of the array or run out of allowed transactions, return 0.
    if (ind == n || cap == 0)
        return 0;

    // If the result is already calculated, return it.
    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    int profit;

    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(Arr, n, ind + 1, 0, cap, dp),
                     -Arr[ind] + getAns(Arr, n, ind + 1, 1, cap, dp));
    }

    if (buy == 1) { // We can sell the stock
        profit = max(0 + getAns(Arr, n, ind + 1, 1, cap, dp),
                     Arr[ind] + getAns(Arr, n, ind + 1, 0, cap - 1, dp));
    }

    // Store and return the calculated profit.
    return dp[ind][buy][cap] = profit;
}

int maxProfit(vector<int>& prices, int n) {
    // Creating a 3D DP array of size [n][2][3]
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    // Call the recursive function to calculate maximum profit
    return getAns(prices, n, 0, 0, 2, dp);
}

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    // Call the maxProfit function and print the result
    cout << "The maximum profit that can be generated is " << maxProfit(prices, n);

    return 0;
}


Time Complexity: O(N*2*3) 
Reason: There are N*2*3 states therefore at max ‘N*2*3’ new problems will be solved.
Space Complexity: O(N*2*3) + O(N)
Reason: We are using a recursion stack space(O(N)) and a 3D array ( O(N*2*3)).
*/

/*
2. Tabulation :



#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& Arr, int n) {
    // Creating a 3D DP array of size [n+1][2][3] initialized to 0
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // Base case: dp array is already initialized to 0, covering the base case.

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 0) { // We can buy the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                           -Arr[ind] + dp[ind + 1][1][cap]);
                }

                if (buy == 1) { // We can sell the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                           Arr[ind] + dp[ind + 1][0][cap - 1]);
                }
            }
        }
    }

    // The result is stored in dp[0][0][2] which represents maximum profit after the final transaction.
    return dp[0][0][2];
}

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    // Call the maxProfit function and print the result
    cout << "The maximum profit that can be generated is " << maxProfit(prices, n);

    return 0;
}


Time Complexity: O(N*2*3) 
Reason: There are three nested loops that account for O(N*2*3) complexity.
Space Complexity: O(N*2*3)
Reason: We are using an external array of size ‘N*2*3’. Stack Space is eliminated.
*/

// 3. Space :


#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& Arr, int n) {
    // Create two 2D arrays to store the profit information, one for the current state and one for the ahead state.
    vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 0) { // We can buy the stock
                    cur[buy][cap] = max(0 + ahead[0][cap], 
                                        -Arr[ind] + ahead[1][cap]);
                }

                if (buy == 1) { // We can sell the stock
                    cur[buy][cap] = max(0 + ahead[1][cap],
                                        Arr[ind] + ahead[0][cap - 1]);
                }
            }
        }
        // Update the ahead state with the current state for the next iteration.
        ahead = cur;
    }

    return ahead[0][2];
}

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    // Call the maxProfit function and print the result
    cout << "The maximum profit that can be generated is " << maxProfit(prices, n);

    return 0;
}


// Time Complexity: O(N*2*3)
// Reason: There are three nested loops that account for O(N*2*3) complexity
// Space Complexity: O(1)
// Reason: We are using two external arrays of size ‘2*3’