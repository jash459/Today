// Link: https://leetcode.com/problems/asteroid-collision/description/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        vector<int> v;
        // collision tabhi hoga jab stack ka top element 0 se greater hoga and resultant direction stack ke top element aur ith element ke sum se decide hoga 
        // agar sum > 0 , direction right otherwise left direction me proceed hoga
        for(int a : asteroids)
        {
            // A collision happens only if the current asteroid a is moving left (a < 0) and the top of the stack is moving right (s.top() > 0).
            while(!s.empty() && a < 0 && s.top() > 0)
            {
                int diff = a + s.top();
                if(diff < 0) // agar sum >0 , resultant direction will be right(forward) otherwise left 
                {
                    s.pop();
                }
                else if(diff > 0)
                {
                    a = 0;
                }
                else
                {  // in case of sum == 0 
                    s.pop();
                    a = 0;
                }
            }
            if(a != 0)
            {
                s.push(a);
            }
        }
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

// Time complexity:
// O(n)

// Space complexity:
// No any extra space used --- O(n)