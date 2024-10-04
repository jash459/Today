// Link : https://takeuforward.org/data-structure/left-rotate-the-array-by-one/

// video : https://www.youtube.com/watch?v=wvcQg43_V8U&t=61s

/*
1. Better 

#include<bits/stdc++.h>

using namespace std;
void solve(int arr[], int n) {
  int temp[n];
  for (int i = 1; i < n; i++) {
    temp[i - 1] = arr[i];
  }
  temp[n - 1] = arr[0];
  for (int i = 0; i < n; i++) {
    cout << temp[i] << " ";
  }
  cout << endl;
}
int main() {
  int n=5;
  
  int arr[]= {1,2,3,4,5};
  solve(arr, n);
}
Time Complexity: O(n), as we iterate through the array only once.
Space Complexity: O(n) as we are using another array of size, same as the given array.*/

// 2. Optimal 

#include<bits/stdc++.h>

using namespace std;
void solve(int arr[], int n) {
  int temp = arr[0]; // storing the first element of array in a variable
  for (int i = 0; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }
  arr[n - 1] = temp; // assigned the value of variable at the last index
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

}
int main() {
  int n=5;
  
  int arr[]= {1,2,3,4,5};
  solve(arr, n);
}
// Time Complexity: O(n), as we iterate through the array only once.
// Space Complexity: O(1) as no extra space is used