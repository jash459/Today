// Link : https://www.geeksforgeeks.org/count-maximum-points-on-same-line/
//      : https://leetcode.com/problems/max-points-on-a-line/solutions/3017649/c-solution-using-hashmap-beat-97-solution-in-speed-easy-explaination/

/*
1. Brute
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if(n<=2) // if the size is 2 then return 2
            return n;
        

        int maxi = 2;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int count=2;
                for(int k=0; k<n; k++)
                {
                    if(k!=i && k!=j)
                    {
                        if((points[j][1]-points[i][1])*(points[i][0]-points[k][0])==(points[i][1]-points[k][1])*(points[j][0]-points[i][0]))
                            count++;
                    }
                }
                maxi = max(maxi,count);
            }
        }
        return maxi;
    }
};

T.C : O(n^3)
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int max_points = 0;

        for(int i=0; i<n; i++){
            unordered_map<double, int> mp;
            int parallel = 1; int coincide = 1;
            for(int j=i+1; j<n; j++){
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
                    coincide++;
                else if(points[i][0]==points[j][0])
                    parallel++;
                else{
                    double slope = (double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                    mp[slope]++;
                }
            }

            int points_count = 0;
            for(auto it : mp)
                points_count = max(points_count, it.second);

            max_points = max(parallel, max(points_count + coincide, max_points));
        }

        return max_points;

    }
};
// Complexity
// Time complexity: O(N^2)
// Space complexity: O(N)