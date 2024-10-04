// Link: https://leetcode.com/problems/sum-of-subarray-ranges/description/

/*
Solution 0, Brute Force
Time O(n^3)
Space O(1)*/

/*Solution 1, Two Loops Solution

    long long subArrayRanges(vector<int>& A) {
        long long res = 0;
        for (int i = 0; i < A.size(); i++) {
            int ma = A[i], mi = A[i];
            for (int j = i; j < A.size(); j++) {
                ma = max(ma, A[j]);
                mi = min(mi, A[j]);
                res += ma - mi;
            }
        }
        return res;
    }

Time O(n^2)
Space O(1)
*/

// https://leetcode.com/problems/sum-of-subarray-ranges/solutions/1624222/java-c-python-o-n-solution-detailed-explanation/

class Solution
{
private:
    long long min_sum(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        long long mini = 0;
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || arr[st.top()] > arr[i]))
            {
                int top1 = st.top();
                st.pop();

                int top2 = -1;
                if (!st.empty())
                    top2 = st.top();

                mini -= 1LL * arr[top1] * (i - top1) * (top1 - top2);
            }
            st.push(i);
        }
        return mini;
    }
    long long max_sum(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        long long maxi = 0;
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || arr[st.top()] < arr[i]))
            {
                int top1 = st.top();
                st.pop();

                int top2 = -1;
                if (!st.empty())
                    top2 = st.top();

                maxi += 1LL * arr[top1] * (i - top1) * (top1 - top2);
            }
            st.push(i);
        }
        return maxi;
    }

public:
    long long subArrayRanges(vector<int> &nums)
    {
        return max_sum(nums) - min_sum(nums);
    }
};

// All elements will be pushed twice and popped at most twice
// Time O(n)
// Space O(n)