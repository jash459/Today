// Link : https://takeuforward.org/data-structure/buy-and-sell-stock-iv-dp-38/

// video: https://www.youtube.com/watch?v=IV1dHbk5CDc

/*

1. Memo :


#include <bits/stdc++.h>
using namespace std;

int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp) {
    // Base case
    if (ind == n || cap == 0) return 0;

    // Check if the result is already computed
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

    // Store the result in the DP array and return
    return dp[ind][buy][cap] = profit;
}

int maximumProfit(vector<int>& prices, int n, int k) {
    // Creating a 3D DP array of size [n][2][k+1]
    vector<vector<vector<int>>> dp(n,
                                    vector<vector<int>>(2, vector<int>(k + 1, -1)));

    return getAns(prices, n, 0, 0, k, dp);
}

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;

    cout << "The maximum profit that can be generated is " << maximumProfit(prices, n, k) << endl;
    return 0;
}
Time Complexity: O(N*2*3) 
Reason: There are N*2*K states therefore at max ‘N*2*K’ new problems will be solved.
Space Complexity: O(N*2*K) + O(N)
Reason: We are using a recursion stack space(O(N)) and a 3D array ( O(N*2*K)).
*/

/*

2. Tabulation :


#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int>& Arr, int n, int k) {
    // Creating a 3D DP array of size [n+1][2][k+1] initialized to 0
    vector<vector<vector<int>>> dp(n + 1,
                                    vector<vector<int>>(2, vector<int>(k + 1, 0)));

    // Loop through the stock prices from the end to the beginning
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
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

    return dp[0][0][k];
}

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;

    cout << "The maximum profit that can be generated is " << maximumProfit(prices, n, k) << endl;
    return 0;
}

Time Complexity: O(N*2*k) 
Reason: There are three nested loops that account for O(N*2*K) complexity.
Space Complexity: O(N*2*k)
Reason: We are using an external array of size ‘N*2*K’. Stack Space is eliminated.
*/

// 3. Space


#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& Arr, int n, int k) {
    // Create two arrays, 'ahead' and 'cur', to track the maximum profit at each step
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
    vector<vector<int>> cur(2, vector<int>(k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
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
        // Update the 'ahead' array with the current values
        ahead = cur;
    }

    return ahead[0][k];
}

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;

    cout << "The maximum profit that can be generated is " << maxProfit(prices, n, k) << endl;
    return 0;
}


// Time Complexity: O(N*2*K)
// Reason: There are three nested loops that account for O(N*2*K) complexity
// Space Complexity: O(K)
// Reason: We are using two external arrays of size ‘2*K’.