// Link : https://www.geeksforgeeks.org/palindrome-substring-queries/

/*

1. Brute 

/* A C++ program to answer queries to check whether
the substrings are palindrome or not 
#include <bits/stdc++.h>
using namespace std;

// A function to check if a string str is palindrome
// in the range L to R
bool isPalindrome(string& str, int L, int R)
{
	// Keep comparing characters while they are same
	while (R > L)
		if (str[L++] != str[R--])
			return (false);
	return (true);
}

/* Driver program to test above function 
int main()
{
	string str = "abaaabaaaba";
	int n = str.size();

	vector<vector<int> > queries
		= { { 0, 10 }, { 5, 8 }, { 2, 5 }, { 5, 9 } };

	for (auto q : queries) {
		bool result = isPalindrome(str, q[0], q[1]);
		if (result)
			cout << "The substring [" << q[0] << "," << q[1]
				<< "] is a palindrome" << endl;
		else
			cout << "The substring [" << q[0] << "," << q[1]
				<< "] is not palindrome" << endl;
	}
	return (0);
}

// This code is contributed by hkdass001


Time Complexity: O(N*Q)
Auxiliary Space: O(1)
*/


/*

2.Better (Cumulative Hash)

#include <bits stdc++.h="">

using namespace std;

int main()
{
string x = "abcdefaabaal";
int p = 1331;
int hash1[x.size()];
int hash2[x.size()];

int i;
hash2[x.size()-1] = x[x.size()-1];
hash1[0] = x[0];
int pi[x.size()];
pi[0] = 1;

//using string hashing , 1 + p + p^2 + p^3 + ... + p^n

for(i = 1; i < x.size(); i++) {
pi[i] = pi[i-1]*p;
}

for(i = 1; i < x.size(); i++) {

hash1[i] = hash1[i-1]*p + x[i];
}

for(i = x.size()-2;i >= 0; i--) {

hash2[i] = hash2[i+1]*p + x[i];
}

int l; // Left range
int r; // Right range

cin>>l>>r;

if(hash1[r] - hash1[l-1]*pi[r-l+1] == hash2[l] - hash2[r+1]*pi[r-l+1] ) {

cout<<"YES"<<endl; }else{="" cout<<"no"<<endl;="" }="" return="" 0;="" }="">



int dp[1001][1001];

int countPalinInRange (int n, string A, int q1, int q2)
{
   int i,j;
   if(q1>q2) swap(q1,q2);
   
   for(int gap=0;gap<n;gap++){
       for(i=0,j=gap;j<n;i++,j++){
           if(gap==0) dp[i][j]=1;
           else if(gap==1 or gap==2){
               dp[i][j]= A[i]==A[j]?1:0;
           }
           else{
               dp[i][j]= (A[i]==A[j] && dp[i+1][j-1]==1 ) ? 1:0;
           }
       }
   }
   //
   int count=0;
   for(int i=q1;i<=q2 ;i++){
       for(int j=q1;j<=q2;j++){
           if(dp[i][j]==1){
               count++;
           }
       }
   }
   
   return count;
}

*/

// 3.Optimal :

int countPalinInRange (int n, string A, int q1, int q2)
{
   // your code here
   if(q1>q2){
       swap(q1,q2);
   }
   string s=A.substr(q1,q2-q1+1);
   int n1=s.size();
   vector<vector<bool>>dp(n1,vector<bool>(n1));
   int count=0;
   for(int g=0;g<n1;g++){
       for(int i=0,j=g;j<n1;i++,j++){
           if(g==0){
               dp[i][j]=true;
           }
           else if(g==1){
               if(s[i]==s[j]){
                   dp[i][j]=true;
               }
               else{
                   dp[i][j]=false;
               }
           }
           else{
               if(s[i]==s[j] and dp[i+1][j-1]==true){
                 dp[i][j]=true;
               }
               else{
                   dp[i][j]=false;
               }
           }
           if(dp[i][j]){
               count++;
           }
       }
   }
    return count;
}
/*
Outer Loop (g): g represents the gap between the starting and ending indices of the substring.
Inner Loop (i, j): i is the starting index and j is the ending index of the substring.
Gap 0 (g == 0): Single character substrings are always palindromes.
Gap 1 (g == 1): Substrings of length 2 are palindromes if both characters are the same.
Gap > 1 (g > 1): For longer substrings, s[i:j] is a palindrome if s[i] == s[j] and the substring s[i+1:j-1] is also a palindrome.
Count Palindromes: If a substring s[i:j] is a palindrome, increment the count
Total Time Complexity
Combining all the steps:

Handling the range: O(1)
Extracting the substring: O(n1)
Dynamic programming: O(n1^2)
Thus, the overall time complexity is dominated by the dynamic programming step, which is O(n1^2).
Total Space Complexity
The dominant term in space complexity is the 2D dp table.
Thus, the overall space complexity is O(n1^2).
*/