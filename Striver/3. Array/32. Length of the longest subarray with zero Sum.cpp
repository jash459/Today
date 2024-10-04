// Link : https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/

// video : https://www.youtube.com/watch?v=xmguZ6GbatA

/*
1. Brute



#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a) {
    int maxLen = 0;
    unordered_map<int, int> sumIndexMap;
    int sum = 0;

    for (int i = 0; i < a.size(); i++) {
        sum += a[i];

        if (sum == 0) {
            maxLen = i + 1;
        } else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
            maxLen = max(maxLen, i - sumIndexMap[sum]);
        } else {
            sumIndexMap[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << solve(a) << endl;

    return 0;
}
Time Complexity: O(N^2) as we have two loops for traversal

Space Complexity: O(1) as we aren’t using any extra space.
*/

// 2. Optimal 



int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
}
// Time Complexity: O(N), as we are traversing the array only once
// Space Complexity: O(N), in the worst case we would insert all array elements prefix sum into our hashmap