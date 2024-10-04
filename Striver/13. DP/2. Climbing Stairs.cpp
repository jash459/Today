// Link : https://takeuforward.org/data-structure/dynamic-programming-climbing-stairs/

// video : https://www.youtube.com/watch?v=mLfjzJsN8us&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=3

// 1. Tabulation : 

#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=3;
  vector<int> dp(n+1,-1);
  
  dp[0]= 1;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}

// Time Complexity: O(N)
// Reason: We are running a simple iterative loop
// Space Complexity: O(N)
// Reason: We are using an external array of size ‘n+1’.

// 2. Space

#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=3;
  
  int prev2 = 1;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}

// Time Complexity: O(N)
// Reason: We are running a simple iterative loop
// Space Complexity: O(1)
// Reason: We are not using any extra space.