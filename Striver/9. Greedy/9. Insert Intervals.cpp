// Link: https://leetcode.com/problems/insert-interval/

// video: https://youtube.com/watch?v=xxRE-46OCC8&list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea&index=9

class Solution {
  public:
    vector<vector<int>> insertNewEvent(int n, vector<vector<int>> &intervals, vector<int> &newEvent) 
    {
        vector<vector<int>> ans;
        int i = 0;
        while(i < n && intervals[i][1] < newEvent[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        // int start = -1
        while(i < n && intervals[i][0] <= newEvent[1])
        {
            newEvent[0] = min(newEvent[0], intervals[i][0]);
            newEvent[1] = max(newEvent[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newEvent);
        
        while(i < n && intervals[i][0] > newEvent[1])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};

// t.c: o(n)
// s.c: o(n)