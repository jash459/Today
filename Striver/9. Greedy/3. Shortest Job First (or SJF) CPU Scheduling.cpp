// Link: https://www.geeksforgeeks.org/problems/shortest-job-first/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-job-first

// video: https://www.youtube.com/watch?v=3-QbX1iDbXs&list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea&index=3

class Solution {
public:
    long long solve(std::vector<int>& bt) {
      
        std::sort(bt.begin(), bt.end());
        
        long long total_waiting_time = 0;
        long long current_time = 0;
        
        
        for (int i = 0; i < bt.size(); ++i) {
            total_waiting_time += current_time;
            current_time += bt[i];
        }
        
       
        return total_waiting_time / bt.size();
    }
};

T.C: O(NlogN + N)
S.C: O(1)