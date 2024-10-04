// Link: https://leetcode.com/problems/minimum-window-substring/description/

//video: https://www.youtube.com/watch?v=WJaij9ffOIY&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=12

/*
1. Brute  // not all test case pass

class Solution {
public:
    string minWindow(string s, string t) {
    int n=s.length(),m=t.length(), minLen=INT_MAX, start=-1;
    for(int l=0;l<n;l++){
    int cnt=0;    
    vector<int> hash(256,0);
    for(int i=0;i<m;i++){
        hash[t[i]]++;
    }
    for(int r=0; r<n; ++r){
    if(hash[s[r]] > 0) cnt++;
    hash[s[r]]--;
    if(cnt==m){
        if(r-l+1<minLen){
             start=l;
             break;
            }
        }   
      }
    }
    return minLen==INT_MAX?"":s.substr(start, minLen);
   }
};
T.C.: O(N*2)
S.C: O(256)
*/

// 2. Optimal

class Solution {
public:
    string minWindow(string s, string t) {
        int l=0, r=0, n=s.length(), m=t.length(), minLen=INT_MAX, start=-1;
        vector<int> freq(256,0);
        for(int i=0; i<m; ++i){
            freq[t[i]]++;
        }
        int cnt=0; // Initialize cnt to 0

        for(r=0; r<n; ++r){
            if(freq[s[r]]>0) cnt++;  // Update cnt based on frequency of s[r]
            --freq[s[r]];              // Decrement frequency of s[r]

            while(cnt==m){ 
                if(r-l+1<minLen){
                    start=l;
                    minLen = r-l+1;
                }
                ++freq[s[l]];           // Restore frequency of s[l]
                if(freq[s[l]]>0) --cnt;  // Update cnt if frequency becomes positive
                ++l;                      // Move left pointer forward
            }
        }
        return minLen==INT_MAX?"":s.substr(start, minLen);
    }
};
T.C: O(2N)+ O(M)
S.C: O(256)
/*
class Solution {
public:
    string minWindow(string s, string t) {
        int l=0, r=0, n=s.length(), minLen=INT_MAX, start=-1;

        unordered_map<char, int> freq;
        for(auto ch:t) ++freq[ch];

        int cnt=freq.size();
        
        for(r=0; r<n; ++r){
            char ch=s[r];
            --freq[ch];
            if(freq[ch]==0) --cnt;

            while(cnt==0){ // while the window is valid, we calculate the min
                //minLen=min(minLen, r-l+1);
                if(r-l+1<minLen){
                    start=l;
                    minLen = r-l+1;
                }
                ++freq[s[l]];
                if(freq[s[l]]==1) ++cnt;
                ++l;
            }
        }

        return minLen==INT_MAX?"":s.substr(start, minLen);
    }
};
T.C: O(2N)+ O(M)
S.C: O(256)

same using map*/