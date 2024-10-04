// Link: https://leetcode.com/problems/max-consecutive-ones-iii/description/

// video: https://www.youtube.com/watch?v=3E4JBHSLpYk

convert question to find the longest subarray with atmost k zeros

/*
1. Brute
Generate all subarray
maxlen =0;
for(int i=0; i<n; i++){
    zeros=0;
    for(int j=i;j<n;j++){
        if(nums[j]==0){
            zeros++;
        }
        if(zeros <=k){
            len=j-i+1;
        maxlen= max(maxlen,len);
        }else break;
    }
}
return maxlen;

T.C: O(N^2)
S.C: O(1)
*/
/*
2. Better
class Solution {
    public int longestOnes(int[] arr, int k) {
        int r=0;
        int l=0;
        int maxlen=0;
        int zeroes=0;
        while(r<arr.length){
            if(arr[r]==0){
                zeroes++;
            }
            while(zeroes>k){
                if(arr[l]==0){
                    zeroes--;
                }
                l++;
            }
            if(zeroes<=k || arr[r]==1){
                maxlen=Math.max(maxlen,r-l+1);
            }
            r++;
            
        }
        return maxlen;
        
    }
}

T.C: O(2N)
S.C: O(1)
*/

// 3. Optimal 
class Solution {
    public int longestOnes(int[] nums, int k) {
        int l=0,r=0,maxLen=0,zero=0,n=nums.length;
        while(r<n){
            if(nums[r]==0) zero++;
            if(zero>k){
            if(nums[l]==0) zero--;
                l++;
            }
            if(zero<=k){
                maxLen=Math.max(maxLen,r-l+1);
            }
            r++;
        }
    return maxLen;
    }
}

T.C: O(N)
S.C: O(1)