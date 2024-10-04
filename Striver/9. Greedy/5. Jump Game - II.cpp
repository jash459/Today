// Link: https://leetcode.com/problems/jump-game-ii/

//video: https://www.youtube.com/watch?v=7SBVnw7GSTk&list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea&index=5

/*
1. Brute

int func(int index, vector<int>& arr) {
    if(index >= arr.size()-1)
         return jumps;  //1 is already added while reaching this. 
    int mini = INT_MAX;
     for(int i = 1; i <= arr[ind]; i++) {
            mini = min(func(ind+i, jump + 1), mini);
      }
      return mini;
}
func(0,0);
T.C: O(n^n)
s.c: o(n)
*/

// 2. Optimal

class Solution {
    public int jump(int[] nums) {
        if (nums.length == 1) return 0; 
        
        int n = nums.length;
        int l = 0, r = 0, jumps = 0, farthest = 0;

        while (r <= n - 1) { 
         

            for (int i = l; i <= r; i++) {
                farthest = Math.max(farthest, i + nums[i]);
                if (farthest >= n - 1) { 
                    return jumps + 1;
                }
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
}

// T.C: O(n)
// s.c: o(1)