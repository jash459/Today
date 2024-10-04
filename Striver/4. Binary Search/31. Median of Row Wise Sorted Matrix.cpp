// Link : https://takeuforward.org/data-structure/median-of-row-wise-sorted-matrix/

// video : https://www.youtube.com/watch?v=Q9wXgdxJq48&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=29

/*
1.Brute

#include <bits/stdc++.h>
using namespace std;
// Function to find median  of row wise sorted matrix
int Findmedian(int arr[3][3], int row, int col)
{
  int median[row * col];
  int index = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      median[index] = arr[i][j];
      index++;
    }
  }
 
  return median[(row * col) / 2];
}
int main()
{
  int row = 3, col = 3;
  int arr[3][3] = {{1, 3, 8},
                   {2, 3, 4},
                   {1, 2, 5}};
  cout <<"The median of the row-wise sorted matrix is: "<<Findmedian
  (arr, row, col) << endl;
  return 0;
}
Output: The median of the row-wise sorted matrix is: 3

Time Complexity: O(row*col log(row*col)) for sorting the array where r*c denotes the number of elements in the linear array.

Space Complexity: O(row*col)  for storing elements in the linear array
*/

// 2. Optimal 

#include <bits/stdc++.h>
using namespace std;
int countSmallerThanMid(vector<int> &row, int mid)
{
  int l = 0, h = row.size() - 1;
  while (l <= h)
  {
    int md = (l + h) >> 1;
    if (row[md] <= mid)
    {
      l = md + 1;
    }
    else
    {
      h = md - 1;
    }
  }
  return l;
}
int findMedian(vector<vector<int>> &A)
{
  int low = 1;
  int high = 1e9;
  int n = A.size();
  int m = A[0].size();
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      cnt += countSmallerThanMid(A[i], mid);
    }
    if (cnt <= (n * m) / 2)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}
int main()
{
  int row = 3, col = 3;
  vector<vector<int>> arr = {{1, 3, 8},
                             {2, 3, 4},
                             {1, 2, 5}};
  cout <<"The median of the row-wise sorted matrix is: "<<findMedian(arr)<<endl;
  return 0;
}
// Output: The median of the row-wise sorted matrix is: 3
// Time Complexity: O(row*log col) since the upper bound function takes log c time.
// Space Complexity: O(1) since no extra space is required.