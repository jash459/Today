// Link: https://leetcode.com/problems/assign-cookies/description/

// video: https://www.youtube.com/watch?v=DIX2p7vb9co&list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea&index=1

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        
        int l = 0, r = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (r < m && l<n) {
            if (g[r] <= s[l]) {
                r++;  
            }
            l++;  
        }
        return r;  
    }
};

T.C: O(NlogN + MlogM + M)
S.C: O(1)