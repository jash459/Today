// Link: https://leetcode.com/problems/jump-game/

// video: https://www.youtube.com/watch?v=tZAa_jJ3SwQ&list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea&index=4

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex=0;
        for(int i=0; i<n; i++){
            if(i > maxIndex){
                return false;
            }
            maxIndex= max(maxIndex + nums[i])
        }
       return true;
    }
};

T.C.: O(N)
S.C.: o(1)