// Link: https://leetcode.com/problems/subarrays-with-k-different-integers/description/

// video: https://www.youtube.com/watch?v=7wYGbV_LsX4&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=11

/*
1. Brute  -> TLE
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
    int n = nums.size(), cnt=0;
    for(int i=0; i<n;i++){
    unordered_map<int, int> mpp;
    for(int j=i;j<n;j++){
        mpp[nums[j]]++;
        if(mpp.size() == k) cnt++;
        else if(mpp.size() >k) break;
    }
}
return cnt;
    }
};

T.C: O(N*2)
S.C: O(N)
*/

// 2. Optimal 

class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int left = 0, right = 0;
        map<int,int> map;
        int cnt = 0;
        while(right < nums.size()) {
            map[nums[right]]++;
            while(map.size() > k) {
                map[nums[left]]--;
                if(map[nums[left]] == 0)
                    map.erase(nums[left]);
                left++;
            }   
            cnt += right - left + 1;
            right++;
        }
        return cnt;
    }  
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};

T.C: 2*O(2N)
S.C: O(1)
/*
why for (==k) , we have to do ( <=k - <=k-1 ) ?

when sliding window shrinking is happening then at that time we will use k-1 probably this case arises when there is problems ask us  to count. Even in the above problem also when we took up to k then we missed few subarrays so at that time we take k-1 . so by subtracting k and (k-1) we get the exact answer

for example, k=3
if we take <=k, cases will be x=1, x=2, x=3   ---> (i)
and for <=k-1,  cases will be x=1, x=2              --->(ii)
so to find for k==3, if we subtract (i) - (ii) => x=3=k
hope this helps.
*/