// Link : https://leetcode.com/problems/binary-subarrays-with-sum/description/

// video: https://www.youtube.com/watch?v=XnMdNUkX6VM&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=9

/*
1. Brute
//This will give TLE 
//modified brute force--> --> --> --> --> --> -->
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res = 0;
        for (int start = 0; start < nums.size(); ++start) {
            int sum = 0;
            for (int end = start; end < nums.size(); ++end) {
                sum += nums[end];
                if (sum == goal)
                    ++res;
            }
        }
        return res;
    }
};

T.C: O(N*2)
S.C: O(1)
*/

// 2. Optimal

class Solution
{
public:
    int helpMe(vector<int> &nums, int goal)
    {
        int l = 0, r = 0, sum = 0, cnt = 0;
        if (goal < 0)
        {
            return 0;
        }
        while (r < nums.size())
        {
            sum += nums[r];
            while (sum > goal)
            {
                if (nums[l] == 1)
                {
                    sum--;
                }
                l++;
            }
            cnt = cnt + r - l + 1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return helpMe(nums, goal) - helpMe(nums, goal - 1);
    }
};

T.C: 2*O(2N)
S.C: O(1)