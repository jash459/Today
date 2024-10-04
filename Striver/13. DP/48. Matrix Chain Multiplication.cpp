// Link: https://takeuforward.org/dynamic-programming/matrix-chain-multiplication-dp-48/

// video: https://www.youtube.com/watch?v=vRVfmbCFW7Y

/*
Recursive Approach
#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& arr, int i, int j){
    
    // base condition
    if(i == j)
        return 0;
        
    int mini = INT_MAX;
    
    // partioning loop
    for(int k = i; k<= j-1; k++){
        
        int ans = f(arr,i,k) + f(arr, k+1,j) + arr[i-1]*arr[k]*arr[j];
        
        mini = min(mini,ans);
        
    }
    
    return mini;
}


int matrixMultiplication(vector<int>& arr, int N){
    
    int i =1;
    int j = N-1;
    
    
    return f(arr,i,j);
    
    
}

int main() {
	
	vector<int> arr = {10, 20, 30, 40, 50};
	
	int n = arr.size();
	
	cout<<"The minimum number of operations is "<<matrixMultiplication(arr,n);
	
	return 0;
}
Output:

The minimum number of operations is 38000
*/

 #include <bits/stdc++.h>
using namespace std;

int f(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
    
    // base condition
    if(i == j)
        return 0;
        
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int mini = INT_MAX;
    
    // partioning loop
    for(int k = i; k<= j-1; k++){
        
        int ans = f(arr,i,k,dp) + f(arr, k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
        
        mini = min(mini,ans);
        
    }
    
    return mini;
}


int matrixMultiplication(vector<int>& arr, int N){
    
    vector<vector<int>> dp(N,vector<int>(N,-1));
    
    int i =1;
    int j = N-1;
    
    
    return f(arr,i,j,dp);
    
    
}

int main() {
	
	vector<int> arr = {10, 20, 30, 40, 50};
	
	int n = arr.size();
	
	cout<<"The minimum number of operations is "<<matrixMultiplication(arr,n);
	
	return 0;
}
// Output:
// The minimum number of operations is 38000
// Time Complexity: O(N*N*N)
// Reason: There are N*N states and we explicitly run aloop inside the function which will run for N times, therefore at max ‘N*N*N’ new problems will be solved.
// Space Complexity: O(N*N) + O(N)
// Reason: We are using an auxiliary recursion stack space(O(N))and a 2D array ( O(N*N)).