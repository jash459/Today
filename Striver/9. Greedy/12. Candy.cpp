// Link: https://leetcode.com/problems/candy/

// video: https://youtube.com/watch?v=IIqVFvKE6RY&list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea&index=12


/*
1. Brute
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left(n, 1), right(n, 1);

        for(int i=1; i<n; ++i){
            if(ratings[i-1]<ratings[i]){
                left[i]=left[i-1]+1;
            }
        }

        for(int i=n-2; i>=0; --i){
            if(ratings[i]>ratings[i+1]){
                right[i]= right[i+1]+1;
            }
        }

        int sum=0;
        for(int i=0;i<n;i++){
        sum += max(left[i] + right[i])
        }
        return sum;
    }
};

t.c: o(3n)
s.c: o(2n)
*/


/*
 2. Better
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> allocation(n, 1);

        for(int i=1; i<n; ++i){
            if(ratings[i-1]<ratings[i]){
                allocation[i]=allocation[i-1]+1;
            }
        }

        curr =1 , right =1 ;
        sum = max(1, left[n-1])
        for(int i=n-2; i>=0; --i){
            if(ratings[i]>ratings[i+1]){
                curr = right + 1;
                right = curr;
            }
            else curr =1;
            sum = sum + max(left[i], curr)
        }
        return sum;
    }
};
t.c: o(2n)
s.c: o(n)

*/

// 3. Optimal 

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int ans = 1;
        int up = 0, down = 0, peak = 0;
        int i=1;
         while(i < n) {
            if (ratings[i-1] == ratings[i])  {
                i++;
                ans++;
                continue;
            } 
            peak=1;

             //ascending
             while( i < n && ratings[i-1] < ratings[i]) {
                peak ++;
                i++;
                ans+= peak;
            } 
             down= 1;

            //descending
             while( i < n && ratings[i-1] > ratings[i]){
                i++;
                ans+= down;
                down ++;
            } 

            if( down > peak) ans += down - peak;
        }
        return ans;
    }
};

// t.c: o(n)
// s.c: o(1)