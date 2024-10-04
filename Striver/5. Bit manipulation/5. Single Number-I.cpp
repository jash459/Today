// link: https://leetcode.com/problems/single-number/solutions/1771720/c-easy-solutions-sorting-xor-maps-or-frequency-array/
//     : https://takeuforward.org/arrays/find-the-number-that-appears-once-and-the-other-numbers-twice/
//video: https://www.youtube.com/watch?v=sFBCAl8yBfE&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=5

/*
1. Brute
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       unordered_map<int,int> a;
	   for(auto x: nums)
		   a[x]++;
	   for(auto z:a)
		   if(z.second==1)
			   return z.first;
	   return -1;
    }
};
TC: O(N)
SC: O(N)*/

/*
2. Better
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};
TC: O(NlogN)
SC: O(1)
*/

// 3.Optimal

class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   for(auto x:nums)
	   ans^=x;
	   return ans;
    }
};
// TC: O(N)
// SC: O(1)

// optimal-2 : SUM OF ELEMENTS