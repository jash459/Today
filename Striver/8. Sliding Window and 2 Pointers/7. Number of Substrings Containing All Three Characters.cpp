// Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

// video: https://www.youtube.com/watch?v=xtqN4qlgr8s&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=7

/*
1. Brute  -> it will give TLE
class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int n=s.size();
    for(int i =0;i<n;i++){
    int hash[3]={0};
    for(int j =i; j<n;j++){
        hash[s[j] - 'a']  = 1;
        if(hash[0] + hash[1] + hash[2] == 3) {
        cnt = cnt +(n-j);
        break;
        }
    }
}
return cnt;
    }
};
T.C: O(N*2)
S.C: O(1)
*/

// 2. Optimal
// with every chaaracter there is sbtring that ends

int numberOfSubstrings(string s)
{
    vector<int> lastSeen(3, -1);
    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        lastSeen[s[i] - 'a'] = i;

        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
        {
            cnt = cnt + (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
        }
    }

    return cnt;
}

T.C : O(N)
          S.C : O(1)