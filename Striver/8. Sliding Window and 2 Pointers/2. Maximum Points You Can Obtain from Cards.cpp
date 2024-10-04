// Link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

// video : https://www.youtube.com/watch?v=9kdHxplyl5I

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum=0,rightSum=0,maxSum=0;

        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        }
        maxSum=leftSum;
        int rightIndex=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[rightIndex];
            rightIndex--;
            maxSum=max(maxSum,leftSum+rightSum);
        }
        return maxSum;
    }
}

// Complexity
// Time complexity: O(n)
// Space complexity: O(1)