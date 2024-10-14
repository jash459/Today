// Link: https://www.geeksforgeeks.org/problems/print-anagrams-together/1

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        unordered_map<string,vector<int>>mp;
        for(int i=0; i<string_list.size(); i++){
            string s = string_list[i];
            sort(s.begin(),s.end());
            mp[s].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it: mp){
            vector<string> temp;
            for(int ind : it.second){
                temp.push_back(string_list[ind]);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};

// Expected Time Complexity: O(N*|S|*log|S|), where |S| is the length of the strings.
// Expected Auxiliary Space: O(N*|S|), where |S| is the length of the strings.