// Link: https://takeuforward.org/data-structure/maximum-rectangle-area-with-all-1s-dp-on-rectangles-dp-55/

// video: https://www.youtube.com/watch?v=tOylVCugy9k

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector < int > & heights) {
    int n = heights.size();
    stack < int > st;
    int leftsmall[n], rightsmall[n];
    for (int i = 0; i < n; i++) {
       while (!st.empty() && heights[st.top()] >= heights[i]) {
        st.pop();
       }
       if (st.empty())
         leftsmall[i] = 0;
       else
         leftsmall[i] = st.top() + 1;
       st.push(i);
    }
    // clear the stack to be re-used
    while (!st.empty())
      st.pop();
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && heights[st.top()] >= heights[i])
        st.pop();
        if (st.empty())
         rightsmall[i] = n - 1;
        else
         rightsmall[i] = st.top() - 1;
        st.push(i);
      }
    int maxA = 0;
    for (int i = 0; i < n; i++) {
      maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    }
    return maxA;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m) {
    // Write your code here.
    int maxArea = 0;
    vector<int> height(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        int area = largestRectangleArea(height);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {

    vector<vector<int>> mat = {
        {1, 0, 1, 0, 0}, {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}
    };
    int n = 4, m = 5;
    int maxArea = maximalAreaOfSubMatrixOfAll1(mat, n, m);
    cout << "The maximum are is: " << maxArea << "\n";
    return 0;
}

/*
Output: The maximum area is: 6 (For example 1)
Time Complexity: O(N * (M+M)), where N = total no. of rows and M = total no. of columns.
Reason: O(N) for running a loop to check all rows. Now, inside that loop, O(M) is for visiting all the columns, and another O(M) is for the function we are using. The function takes linear time complexity. Here, the size of the height array is M, so it will take O(M).

Space Complexity: O(M), where M = total no. of columns.
Reason: We are using a height array and a stack of size M
*/