// Link: https://leetcode.com/problems/longest-repeating-character-replacement/description/

// video: https://www.youtube.com/watch?v=_eNhaDCr6P0&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=8

/*
1. Brute: generate all substring
class Solution {
public:
    int characterReplacement(string s, int k) {
    int maxlen=0;
    int n = s.size();
    for(int i =0;i<n;i++){
    int maxf=0; vector<int>mpp(26,0);
    for(int j=i;j<n;j++){ 
       mpp[s[j]-'A']++;
       maxf= max(maxf, mpp[s[i]-'A']);
       int changes = (j-i+1) - maxf;
       if(changes <=k ){
        maxlen= max(maxlen, (j-i+1));
       }
       else break;
    }
    }
    return maxlen;
    }
};
print(maxlen);
T.C: O(N*2)
S.C: O(26)
*/

// 2.Optimal

class Solution {
public:
     int characterReplacement(string s, int k) {
        unordered_map<char, int> hash;
        int ans = 0;
        int left = 0;
        int right = 0;
        int maxf = 0;
        for (right = 0; right < s.size(); right++) {
            hash[s[right]] = 1 + hash[s[right]];
            maxf = max(maxf, hash[s[right]]);
            if ((right - left + 1) - maxf > k) {
                hash[s[left]] -= 1;
                left++;
            } else {
                ans = max(ans, (right - left + 1));
            }
        }
        return ans;
    }
};

// Time complexity: O(2n) * 26
// space complexity: O(26)