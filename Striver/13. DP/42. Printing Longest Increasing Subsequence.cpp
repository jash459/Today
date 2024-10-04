// Link : https://takeuforward.org/data-structure/printing-longest-increasing-subsequence-dp-42/

// video : https://www.youtube.com/watch?v=IFfYfonAFGc

/*
Tabulation algorithm to find the length of the longest increasing subsequence.
#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> dp(n,1);
    
    for(int i=0; i<=n-1; i++){
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if(arr[prev_index]<arr[i]){
                dp[i] = max(dp[i], 1 + dp[prev_index]);
            }
        }
    }
    
    int ans = -1;
    
    for(int i=0; i<=n-1; i++){
        ans = max(ans, dp[i]);
    }
    
    return ans;
}

int main() {
	
	int arr[] = {10,9,2,5,3,7,101,18};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"The length of the longest increasing subsequence is "
        <<longestIncreasingSubsequence(arr,n);
	
	return 0;
}
Output:

The length of the longest increasing subsequence is 4
Time Complexity: O(N*N)
Reason: There are two nested loops.
Space Complexity: O(N)
Reason: We are only using two rows of size ‘N’.
*/

#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> dp(n,1);
    vector<int> hash(n,1);
    
    for(int i=0; i<=n-1; i++){
        
        hash[i] = i; // initializing with current index
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if(arr[prev_index]<arr[i] && 1 + dp[prev_index] > dp[i]){
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }
    
    int ans = -1;
    int lastIndex =-1;
    
    for(int i=0; i<=n-1; i++){
        if(dp[i]> ans){
            ans = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    
    while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);    
    }
    
    // reverse the array 
    reverse(temp.begin(),temp.end());
    
    cout<<"The subsequence elements are ";
    
    for(int i=0; i<temp.size(); i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    
    return ans;
}

int main() {
	
	int arr[] = {10,9,2,5,3,7,101,18};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	longestIncreasingSubsequence(arr,n);
	return 0;
}
// Output:
// The subsequence elements are 2 5 7 101 
// Time Complexity: O(N*N)
// Reason: There are two nested loops.
// Space Complexity: O(N)
// Reason: We are only using two rows of size ‘N’.