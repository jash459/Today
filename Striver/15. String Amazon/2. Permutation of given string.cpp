// Link: https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
// Striver link: 


// For string:
class Solution
{   private:
        void solve(string S,set<string> &set, int index ){
            int n=S.length();
            if(index==n){
                set.insert(S);
                return ;
            }
            
            for(int j=index; j<n; j++){
                swap(S[index],S[j]);
                solve(S,set,index+1);// recursive Call
                swap(S[index],S[j]);//Back-Tracking
            }
        }
    public:
        vector<string>find_permutation(string S)
        {
           set<string> set;// set is used to store all the unique permutations
           solve(S,set,0);
           
           vector<string> ans;//all possible permutations will be pushed into ans string
           for(auto i:set){
               ans.push_back(i);
           }
           return ans ;
        }
};

// Time Complexity: O(N! X N)

// Space Complexity: O(1)

// for integer
#include<bits/stdc++.h>

using namespace std;
class Solution {
  private:
    void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
      if (index == nums.size()) {
        ans.push_back(nums);
        return;
      }
      for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
      }
    }
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      recurPermute(0, nums, ans);
      return ans;
    }
};

int main() {
  Solution obj;
  vector < int > v {1,2,3};
  vector < vector < int >> sum = obj.permute(v);
  cout << "All Permutations are" << endl;
  for (int i = 0; i < sum.size(); i++) {
    for (int j = 0; j < sum[i].size(); j++)
      cout << sum[i][j] << " ";
    cout << endl;
  }
}
// Output:

// All Permutations are
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

// Time Complexity: O(N! X N)

// Space Complexity: O(1)