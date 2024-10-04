// Link: https://takeuforward.org/data-structure/count-square-submatrices-with-all-1s-dp-on-rectangles-dp-56/

// video: https://www.youtube.com/watch?v=auS1fynpnjo

/*
Brute force:
In order to solve this question, we will first try the brute force approach. In the brute force approach, we will just check for every cell(i, j)(if the cell contains 1) that if there exists a k-sized square where k can range from 1 to min(n-i, m-j)(considering 0-based indexing). The implementation will be very much complex. So, we will move on to the optimized approach i.e. the dynamic programming approach.
*/

#include <bits/stdc++.h>
using namespace std;

int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++) dp[0][j] = arr[0][j];
    for (int i = 0; i < n; i++) dp[i][0] = arr[i][0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) dp[i][j] = 0;
            else {
                dp[i][j] = 1 + min(dp[i - 1][j],
                                   min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += dp[i][j];
        }
    }
    return sum;
}

int main() {

    vector<vector<int>> arr = {
        {0, 1, 1, 1}, {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    int n = 3, m = 4;
    int squares = countSquares(n, m, arr);
    cout << "The number of squares: " << squares << "\n";
    return 0;
}

// Output: Total number of squares: 15 (For example 1)
// Time Complexity: O(N*M), where N = total no. of rows and M = total no. of columns
// Reason: We are basically traversing a 2D matrix with N rows and M columns.
// Space Complexity: O(N*M), where N = total no. of rows and M = total no. of columns
// Reason: We are using a 2D dp array with N rows and M columns.