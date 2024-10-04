// link: 

//video: https://www.youtube.com/watch?v=5Bb2nqA40JY&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=6

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int bitIndex = 0; bitIndex <= 31 ; bitIndex++) {
            int cnt = 0;
            for(int i = 0;i<nums.size();i++) {
                if( ( nums[i] & (1 << bitIndex)) ){                    
                    cnt++;                                                           
                }                       
            }
            if(cnt % 3 == 1) {                  
                ans = (ans | (1 << bitIndex));                 
            }
        }
        return ans;
    }
};

// t.c: O(n*32)
// s.c: O(1)

// optimal

#include<bits/stdc++.h>
using namespace std;
 int singleNumII(vector<int> a,int n)
{
  int ones=0,twos=0;
  int i;
  for(i=0;i<n;i++)
  {
    ones=(ones^a[i])&~twos;
    twos=(twos^a[i])&~ones;
  }
  return ones;
}
int main()
{
    vector<int> arr={5,6,7,5,4,4,5};
    int n=arr.size();
    int ans=singleNumII(arr,n);
    cout<<"number occuring ones "<<ans<<endl;
}

// t.c: o(n)
// s.c: o(1)
