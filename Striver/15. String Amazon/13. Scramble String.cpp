// Link: https://leetcode.com/problems/scramble-string/description/

class Solution
{

private:
    unordered_map<string, bool> dp;

    bool solve(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        if (dp.find(s1 + s2) != dp.end())
            return dp[s1 + s2];

        int n = s1.size();
        bool sub_check = false;

        // The for loop in the solve function starts from 1 because splitting a string at index 0 or at the length of the string would result in one of the substrings being empty, which is not allowed based on the problem constraints.

        // In the swap case, we are considering the possibility that during the scrambling process, the substrings might have been swapped.

        // For a string s1 split into two parts x and y (where s1 = x + y), the scrambled version s2 could have the parts swapped, resulting in s2 = y + x.

        for (int i = 1; i < n; i++)
        {
            bool swap = (solve(s1.substr(0, i), s2.substr(n - i, i)) && solve(s1.substr(i, n - i), s2.substr(0, n - i)));
            bool not_swap = (solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n-i), s2.substr(i, n-i)));

            if (swap || not_swap)
            {
                sub_check = true;
                break;
            }
        }

        return dp[s1 + s2] = sub_check;
    }

public:
    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        if (s1 == "" && s2 == "")
            return true;
        return solve(s1, s2);
    }
};

// Time complexity:
// o(m*n) m and n are sizes of given two strings

// Space complexity:
// o(n+m)