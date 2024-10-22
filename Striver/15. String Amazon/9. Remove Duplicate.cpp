// Link:  https://www.geeksforgeeks.org/problems/remove-duplicates3034/1
// Striver link: https://takeuforward.org/data-structure/remove-all-duplicates-from-a-string/

/*
Brute

#include<bits/stdc++.h>
 
using namespace std;
 
string removeDuplicateLetters(string s) {
  string ans = "";
  for (int i = 0; i < s.length(); i++) {
    int j = 0;
    for (j = 0; j < i; j++) {
      if (s[i] == s[j]) //same character found
      {
        break;
      }
    }
    if (i == j) {
      ans += s[i];
    }
  }
  return ans;
}
int main() {
  string str = "cbacdcbc";
  cout<<"Original String: "<<str<<endl;
  cout <<"After removing duplicates: " <<removeDuplicateLetters(str) << endl;
  return 0;
}
Output:

Original String: cbacdcbc
After removing duplicates: cbad

Time Complexity: O(N^2)

Space Complexity: O(1)
*/

// Optimized 

#include<bits/stdc++.h>
 
using namespace std;
 
string removeDuplicateLetters(string s) {
  string ans = "";
  vector < bool > map(26, false);
  for (int i = 0; i < s.length(); i++) {
    if (map[s[i] - 'a'] == false) {
      ans += s[i];
      map[s[i] - 'a'] = true;
    }
  }
  return ans;
}
int main() {
  string str = "cbacdcbc";
  cout << "Original String: "<<str<<endl<<"After removing duplicates: "
  <<removeDuplicateLetters(str) << endl;
  return 0;
}
// Output:

// Original String: cbacdcbc
// After removing duplicates: cbad

// Time Complexity: O(N)

// Space Complexity: O(1)