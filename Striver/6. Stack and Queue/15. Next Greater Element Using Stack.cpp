// Link : https://takeuforward.org/data-structure/next-greater-element-using-stack/
//      : https://docs.google.com/document/d/1PhdbvCOaoELjL6KTdPM7_8shnRfvp8tVEoEcWjNtHwc/edit

// vidoe : https://www.youtube.com/watch?v=Du881K7Jtk8

/*

1. Brute :

// Simple C++ program to print
// next greater elements in a
// given array
#include <iostream>
using namespace std;

/* prints element and NGE pair
for all elements of arr[] of size n 
void printNGE(int arr[], int n)
{
	int next, i, j;
	for (i = 0; i < n; i++) {
		next = -1;
		for (j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				next = arr[j];
				break;
			}
		}
		cout << arr[i] << " --> " << next << endl;
	}
}

// Driver Code
int main()
{
	int arr[] = { 11, 13, 21, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printNGE(arr, n);
	return 0;
}

// This code is contributed
// by Akanksha Rai(Abby_akku)

Time Complexity: O(N2) 
Auxiliary Space: O(1)
*/



#include<bits/stdc++.h>

using namespace std;
class Solution {
  public:
    vector < int > nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nge;
    }
};
int main() {
  Solution obj;
  vector < int > v {5,7,1,2,6,0};
  vector < int > res = obj.nextGreaterElements(v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}
// Output:

// The next greater elements are
// 7 -1 2 6 7 5

// Time Complexity: O(N)

// Space Complexity: O(N)