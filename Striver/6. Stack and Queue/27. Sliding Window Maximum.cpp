// Link : https://takeuforward.org/data-structure/sliding-window-maximum/

// video : https://www.youtube.com/watch?v=CZQGRp93K4k
/*

1. Better :

#include<bits/stdc++.h>

using namespace std;

void GetMax(vector < int > nums, int l, int r, vector < int > & arr) {
  int i, maxi = INT_MIN;
  for (i = l; i <= r; i++)
    maxi = max(maxi, nums[i]);
  arr.push_back(maxi);
}
vector < int > maxSlidingWindow(vector < int > & nums, int k) {
  int left = 0, right = 0;
  int i, j;
  vector < int > arr;
  while (right < k - 1) {
    right++;
  }
  while (right < nums.size()) {
    GetMax(nums, left, right, arr);
    left++;
    right++;
  }
  return arr;
}
int main() {
  int i, j, n, k = 3, x;
  vector < int > arr {
4,0,
-1,
3,
5,
3,
6,
8};
  vector < int > ans;
  ans = maxSlidingWindow(arr, k);
  cout << "Maximum element in every " << k << " window " << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << "  ";
  return 0;
}
Output:

Maximum element in every 3 window
4 3 5 5 6 8

Time Complexity: O(N^2)

Reason: One loop for traversing and another to findMax

Space Complexity: O(K) 

Reason: No.of windows
*/

// 2. Optimal

#include<bits/stdc++.h>

using namespace std;

vector < int > maxSlidingWindow(vector < int > & nums, int k) {
  deque < int > dq;
  vector < int > ans;
  for (int i = 0; i < nums.size(); i++) {
    if (!dq.empty() && dq.front() == i - k) dq.pop_front();

    while (!dq.empty() && nums[dq.back()] < nums[i])
      dq.pop_back();

    dq.push_back(i);
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
  }
  return ans;
}
int main() {
  int i, j, n, k = 3, x;
  vector < int > arr {4,0,-1,3,5,3,6,8};
  vector < int > ans;
  ans = maxSlidingWindow(arr, k);
  cout << "Maximum element in every " << k << " window " << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
}
// Output:

// Maximum element in every 3 window
// 4 3 5 5 6 8

// Time Complexity: O(N)
// Space Complexity: O(K)

/*
A deque used to store indices of elements in the current window. It maintains a property that the element at dq.front() is always the maximum within the current window.

if (i >= k - 1): This condition checks if we've processed enough elements to have a full window (at least k elements).

This loop ensures that the deque only stores indices of elements in descending order of their values in the array. It keeps removing elements from the back (dq.pop_back()) as long as the value at the current index (nums[i]) is greater than the value at the back of the deque (nums[dq.back()]). This way, dq.front() always points to the index of the maximum element within the current window
*/