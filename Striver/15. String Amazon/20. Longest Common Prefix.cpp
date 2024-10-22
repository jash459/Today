// Link: https://leetcode.com/problems/longest-common-prefix/description/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0], last = strs[n - 1];
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
            {
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};

// The reason for comparing the first and last strings after sorting the array is based on a key observation: after sorting, the common prefix of the entire array must be a common prefix of the first and last strings. This works because sorting orders the strings lexicographically, which naturally aligns similar prefixes together.