// Link: https://takeuforward.org/data-structure/implement-powxn-x-raised-to-the-power-n/

// video: https://www.youtube.com/watch?v=l0YC3876qxg

/*
#include<bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
      double ans = 1.0;
      for (int i = 0; i < n; i++) {
        ans = ans * x;
      }
      return ans;
}
int main()
{
    cout<<myPow(2,10)<<endl;
}
Output: 1024

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution {
public:
    double myPow(double x, int n) {
        double num = 1;
        long long temp = n;
        if(temp < 0) temp = -temp;
        while(temp>0){
            if(temp%2==1){
                num = num * x;
                temp--;
            }
            else{
                x = x*x;
                temp/=2;
            }
        }
        if(n < 0){
            num = 1.0/num;
        }
        return num;
    }
};

// Time Complexity : O(logN).
// Space Complexity : O(1), Constant space.