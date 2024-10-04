// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/

// video: https://www.youtube.com/watch?v=j_QOv9OT9Og&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=10

// same as previous
// consider odd as 1 and even as 0
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
            sum += nums[r] % 2;
            while (sum > goal)
            {
                if (nums[l] % 2 == 1)
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
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return helpMe(nums, k) - helpMe(nums, k - 1);
    }
};

T.C: 2*O(2N)
S.C: O(1)