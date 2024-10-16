// Link : https://takeuforward.org/data-structure/longest-divisible-subset-dp-44/

// video : https://www.youtube.com/watch?v=gDuZwBW9VvM

#include<bits/stdc++.h>
using namespace std;

// Function to find the longest divisible subset
vector<int> divisibleSet(vector<int>& arr) {
    int n = arr.size();

    // Sort the array in ascending order
    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1);   // dp[i] stores the length of the divisible subset ending at arr[i]
    vector<int> hash(n, i); // hash[i] stores the previous index in the divisible subset ending at arr[i]

    for (int i = 0; i < n; i++) {
        hash[i] = i; // Initialize with the current index
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[i] % arr[prev_index] == 0 && 1 + dp[prev_index] > dp[i]) {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }

    int ans = -1;
    int lastIndex = -1;

    for (int i = 0; i < n; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    // Reconstruct the divisible subset using the hash table
    while (hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    // Reverse the array to get the correct order
    reverse(temp.begin(), temp.end());

    return temp;
}

int main() {
    vector<int> arr = {1, 16, 7, 8, 4};

    vector<int> ans = divisibleSet(arr);

    cout << "The longest divisible subset elements are: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
// Output:
// The longest divisible subset elements are: 1 4 8 16
// Time Complexity: O(N*N)
// Reason: There are two nested loops.
// Space Complexity: O(N)
// Reason: We are only using two rows of size n.
