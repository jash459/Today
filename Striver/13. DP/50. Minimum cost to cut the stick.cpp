// Link: https://takeuforward.org/data-structure/minimum-cost-to-cut-the-stick-dp-50/

// video: https://www.youtube.com/watch?v=xwomavsC86c

/*
1. Recursive Approach:

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum cost incurred
int findMinimumCost(int i, int j, vector<int> &cuts) {
    // Base case: If i is greater than j, there are no cuts to consider.
    if (i > j) {
        return 0;
    }

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++) {
        // Calculate the cost for making a cut at position 'ind'.
        int ans = cuts[j + 1] - cuts[i - 1] +
                  findMinimumCost(i, ind - 1, cuts) +
                  findMinimumCost(ind + 1, j, cuts);

        mini = min(mini, ans);
    }

    return mini;
}

// Function to compute the minimum cost
int minimumCost(int n, int c, vector<int> &cuts) {
    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Call the recursive function to find the minimum cost.
    return findMinimumCost(1, c, cuts);
}

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;

    cout << "The minimum cost incurred is: " << minimumCost(n, c, cuts) << endl;

    return 0;
}

Time Complexity: Exponential
*/

/*
2. Memo


#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum cost incurred
int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
    // Base case: If i is greater than j, there are no cuts to consider.
    if (i > j) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++) {
        // Calculate the cost for making a cut at position 'ind'.
        int ans = cuts[j + 1] - cuts[i - 1] +
                  findMinimumCost(i, ind - 1, cuts, dp) +
                  findMinimumCost(ind + 1, j, cuts, dp);

        mini = min(mini, ans);
    }

    return dp[i][j] = mini;
}

// Function to compute the minimum cost
int minimumCost(int n, int c, vector<int> &cuts) {
    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Create a DP table to store calculated values.
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

    // Call the recursive function to find the minimum cost.
    return findMinimumCost(1, c, cuts, dp);
}

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;

    cout << "The minimum cost incurred is: " << minimumCost(n, c, cuts) << endl;

    return 0;
}

Time Complexity: O(N*N*N)

Reason: There are 2 variables i and j, therefore, N*N states and we explicitly run a loop inside the function which will run for N times, therefore at max ‘N*N*N’ new problems will be solved.
Space Complexity: O(N*N) + O(N)
Reason: We are using an auxiliary recursion stack space(O(N))and a 2D array ( O(N*N)).
*/

// 3. Tabulation:


#include <bits/stdc++.h>
using namespace std;

// Function to compute the minimum cost incurred
int minimumCost(int n, int c, vector<int> &cuts) {
    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Create a DP table to store calculated values.
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--) {
        for (int j = 1; j <= c; j++) {
            if (i > j) continue;

            int mini = INT_MAX;

            for (int ind = i; ind <= j; ind++) {
                // Calculate the cost for making a cut at position 'ind'.
                int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];

                mini = min(mini, ans);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][c];
}

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;

    cout << "The minimum cost incurred is: " << minimumCost(n, c, cuts) << endl;

    return 0;
}

// Time Complexity: O(N*N*N)
// Reason: There are 2 variables i and j, therefore, N*N states and we explicitly run a loop inside the function which will run for N times, therefore at max ‘N*N*N’ new problems will be solved.
// Space Complexity: O(N*N) 
// Reason: We are using a 2D array ( O(N*N)).