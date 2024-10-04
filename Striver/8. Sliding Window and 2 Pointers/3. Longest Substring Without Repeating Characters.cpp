// Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// video : https://www.youtube.com/watch?v=-zSxTJkcdAo

/*
1. Brute 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
           vector<int> hash(256, 0);  Initialize frequency array to 0
            // unordered_map<char, int> hash;
            for (int j = i; j < n; j++) {
                if (hash[s[j]] == 1) break;
                int len = j - i + 1; // Calculate the length of the current substring
                maxlen = max(maxlen, len);
                hash[s[j]] = 1;
            }
        }
        return maxlen;
    }
};


T.C: O(N^2)
S.C: O(256) 
*/

// 2. Optimal : sliding window and 2 pointer

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        vector<int> hash(128, -1);
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (hash[s[right]] >= left) {
                left = hash[s[right]] + 1;
            }
            hash[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

T.C: O(N)
S.C: O(256)