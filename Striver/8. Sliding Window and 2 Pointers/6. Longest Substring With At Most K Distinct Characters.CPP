// link: https://www.naukri.com/code360/problems/longest-substring-with-at-most-k-distinct-characters_2221410?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

//video: https://www.youtube.com/watch?v=teM9ZsVRQyc

/*
1. Brute
Generate all substring

func(string s, int k){
maxlen=0, map<char, int>mpp
for(int i=0; i<n;i++){
  mpp.clear();
  for(int j=i; j<n;j++){
    mpp[s[j]]++;
    if(mpp[s[j]]<= k){
        maxlen= max(maxlen, j-i+1);
    }
    else break;
}
}
return maxlen;

T.C: O(N*2 * log(256))
S.C: O(log(256))

}*/


/* 
2. Better

int kDistinctChars(int k, string &str)
{
    int n = str.size();
    int l = 0;
    int r = 0;
    int maxi = 0;
    unordered_map<char, int> mpp;
    while(r < n){
        mpp[str[r]]++;
        while(mpp.size() > k){
            mpp[str[l]]--;
            if (mpp[str[l]] == 0) mpp.erase(str[l]);
            l++;
        }
        if(mpp.size() <= k) maxi = max(maxi, r-l+1);
        r++;
    }
    return maxi;
}

T.C: O(N + N + log(256))
S.C: O(log(256))
*/

// 3. Optimal

int kDistinctChars(int k, string &str)
{
    int n = str.size();
    int l = 0;
    int r = 0;
    int maxi = 0;
    unordered_map<char, int> mpp;
    while(r < n){
        mpp[str[r]]++;
        if(mpp.size() > k){
            mpp[str[l]]--;
            if (mpp[str[l]] == 0) mpp.erase(str[l]);
            l++;
        }
        if(mpp.size() <= k) maxi = max(maxi, r-l+1);
        r++;
    }
    return maxi;
}

// T.C: O(N + log(256))
// S.C: O(log(256))