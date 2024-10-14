// Link: https://takeuforward.org/data-structure/number-of-distinct-islands/

// Video: https://www.youtube.com/watch?v=7zmgQSJghpo&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=16

#include<bits/stdc++.h>

using namespace std;

class Solution {
  private:
    void dfs(int row, int col, vector < vector < int >> & vis,
      vector < vector < int >> & grid, vector < pair < int, int >> & vec, int row0, 
      int col0) {
      // mark the cell as visited
      vis[row][col] = 1;

      // coordinates - base coordinates
      vec.push_back({
        row - row0,
        col - col0
      });
      int n = grid.size();
      int m = grid[0].size();

      // delta row and delta column
      int delrow[] = {-1, 0, +1, 0}; 
      int delcol[] = {0, -1, 0, +1}; 

      // traverse all 4 neighbours
      for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        // check for valid unvisited land neighbour coordinates 
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
          !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
          dfs(nrow, ncol, vis, grid, vec, row0, col0);
        }
      }
    }
  public:
    int countDistinctIslands(vector < vector < int >> & grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector < vector < int >> vis(n, vector < int > (m, 0));
      set < vector < pair < int, int >>> st;

      // traverse the grid
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          // if not visited and is a land cell
          if (!vis[i][j] && grid[i][j] == 1) {
            vector < pair < int, int >> vec;
            dfs(i, j, vis, grid, vec, i, j);
            // store in set
            st.insert(vec);
          }
        }
      }
      return st.size();
    }
};

int main() {

  vector<vector<int>> grid{
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}};
            
  Solution obj;
  cout << obj.countDistinctIslands(grid) << endl;

}
// Output:  3

// Time Complexity: O(N x M x log(N x M)) + O(NxMx4) ~ O(N x M), For the worst case, assuming all the pieces as land, the DFS function will be called for (N x M) nodes, and for every node, we are traversing for 4 neighbors, it will take O(N x M x 4) time. Set at max will store the complete grid, so it takes log(N x M) time.

// Space Complexity ~ O(N x M), O(N x M) for the visited array and set takes up N x M locations at max. 