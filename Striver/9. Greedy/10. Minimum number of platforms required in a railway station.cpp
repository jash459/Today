// Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// video: https://www.youtube.com/watch?v=AsGzwR_FWok&list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea&index=10

/*

1. Brute
#include<bits/stdc++.h>
 using namespace std;
  
it pass only 3 cases 
int findPlatform(int arr[], int dep[], int n) {
    int ans = 1; // Final value

    for (int i = 0; i < n; i++) {
        int count = 1; // Count of overlapping interval of only this iteration

        for (int j = i + 1; j < n; j++) {
            // Check if train i overlaps with train j
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || 
                (arr[j] >= arr[i] && arr[j] <= dep[i]) || 
                (arr[j] >= arr[i] && dep[j] <= dep[i]) || 
                (arr[i] >= arr[j] && dep[i] <= dep[j])) {
                count++;
            }
        }
        ans = max(ans, count); // Updating the value
    }

    return ans;
}

 
 int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
 }
Output: Minimum number of Platforms required 3

Time Complexity: O(n^2)  (due to two nested loops).

Space Complexity: O(1)  (no extra space used).
*/

// 2. Optimal

#include<bits/stdc++.h>
 using namespace std;
 
 int countPlatforms(int n,int arr[],int dep[])
 {
    sort(arr,arr+n);
    sort(dep,dep+n);
 
    int ans=1;
    int count=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) //one more platform needed
        {
            count++;
            i++;
        }
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;
 }
 
 int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
 }
// Output:

// Minimum number of Platforms required 3

// Time Complexity: O(nlogn) Sorting takes O(nlogn) and traversal of arrays takes O(n) so overall time complexity is O(nlogn).

// Space complexity: O(1)  (No extra space used).