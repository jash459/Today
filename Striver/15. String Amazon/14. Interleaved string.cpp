// Link: 

/*
1. Brute
bool isInterleaved(string A, string B, string C) {
    // Base Case: If all strings are empty
    if (A.empty() && B.empty() && C.empty()) {
        return true;
    }

    // If C is empty and any of the two strings is not empty
    if (C.empty()) {
        return false;
    }

    // If any of the above mentioned two possibilities is true,
    // then return true, otherwise false
    return ((C[0] == A[0]) && isInterleaved(A.substr(1), B, C.substr(1)))
            || ((C[0] == B[0]) && isInterleaved(A, B.substr(1), C.substr(1)));
}


Time Complexity: O(2^n), where n is the length of the given string. 
Space Complexity: O(1). 
*/

// 2. Optimal

bool isInterleave(string A, string B, string C) 
    {
    int n=A.length(),m=B.length();
    vector<vector<int>> dp(n+1,vector <int>(m+1,0));
    dp[0][0]=1;
    // dp[0][0] = 1 because an empty A and an empty B can form an empty C.
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i>0 && A[i-1]==C[i+j-1])dp[i][j]|=dp[i-1][j];
            if(j>0 && B[j-1]==C[i+j-1])dp[i][j]|=dp[i][j-1];
        }
    }
    return dp[n][m];
    }
    
/*
Time Complexity:  O(m*n).

This is the worst case of time complexity, if the given strings contain no common character matching with C then the time complexity will be O(n+m).
Space Complexity: O(m*n).
*/


