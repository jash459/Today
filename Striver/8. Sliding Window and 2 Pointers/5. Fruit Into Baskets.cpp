// Link: https://www.naukri.com/code360/problems/fruits-and-baskets_985356?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// video: https://www.youtube.com/watch?v=e3bs0uA1NhQ

change the question to maxlen of subarray with at most k types of numbers
/*
1. Brute
genrate all subarray
maxlen=0;
int k =2;
for(int i=0; i<n;i++){
    set<int>st;
    for(int j=i; j<n; j++){
        st.add(arr[j]);
        if(st.size() <= k){  // here k = 2
            maxlen=max(maxlen,j-i+1);
        }
        else break;
    }
}
return maxlen;

T.C: O(N*N)
S.C: O(3)
*/

/*

// 2. Better

int findMaxFruits(vector<int> &str, int n) {
    // Write your code here.
    int l =0, r =0, maxi =0;
    int k =2;
   unordered_map<int, int> mpp;
   while(r < n){
        mpp[str[r]]++;
        if(mpp.size() > k){
        while(mpp.size() > k){
            mpp[str[l]]--;
            if(mpp[str[l]] == 0){
                mpp.erase(str[l]);  
            }
            l++; 
        }
        }
        if(mpp.size() <=k) maxi = max(maxi, r-l+1);
        r++;
    }
    return maxi;
}

T.C: O(N + N)
S.C: O(3)
*/

/*
freq array 
int findMaxFruits(vector<int> &str, int n) {
    int l = 0, r = 0, maxi = 0;
    int k =2;
    vector<int> freq(256, 0); // Initialize frequency vector to store counts of each fruit
    int uniqueFruits = 0; // Count of unique fruits in the current window
    
    while (r < n) {
        // Increment the count of the current fruit
        freq[str[r]]++;
        // If the count of the current fruit becomes 1, increment uniqueFruits
        if (freq[str[r]] == 1) {
            uniqueFruits++;
        }
        // If there are more than 2 unique fruits in the window, move l until there are only 2 unique fruits
        while (uniqueFruits > k) {
            freq[str[l]]--;
            if (freq[str[l]] == 0) {
                uniqueFruits--;
            }
            l++;
        }
        // Update the maximum length of the window if the current window length is greater
        maxi = max(maxi, r - l + 1);   
        r++;
    }    
    return maxi;
}
*/

// 3.Optimal
// here k = 2 , unique fruits 
int findMaxFruits(vector<int> &str, int n) {
    // Write your code here.
    int l =0, r =0, maxi =0;
    int k =2;
   unordered_map<int, int> mpp;
   while(r < n){
        mpp[str[r]]++;
        if(mpp.size() > k){
            mpp[str[l]]--;
            if(mpp[str[l]] == 0){
                mpp.erase(str[l]);  
            }
            l++; 
        }
        if(mpp.size() <=k) maxi = max(maxi, r-l+1);
        r++;
    }
    return maxi;
}

// T.C: O(N)
// S.C: O(1)