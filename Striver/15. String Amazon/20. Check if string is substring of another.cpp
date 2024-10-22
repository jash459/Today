// Link : https://www.geeksforgeeks.org/check-string-substring-another/

// video : https://www.youtube.com/watch?v=qonx7QjXawg
/*
1. Brute 

// C++ program to check if a string is
// substring of other.
#include <bits/stdc++.h>
using namespace std;

// Returns true if s1 is substring of s2
int isSubstring(string s1, string s2)
{
	int M = s1.length();
	int N = s2.length();

	A loop to slide pat[] one by one 
	for (int i = 0; i <= N - M; i++) {
		int j;

		 For current index i, check for
pattern match 
		for (j = 0; j < M; j++)
			if (s2[i + j] != s1[j])
				break;

		if (j == M)
			return i;
	}

	return -1;
}

 Driver code 
int main()
{
	string s1 = "for";
	string s2 = "geeksforgeeks";
	int res = isSubstring(s1, s2);
	if (res == -1)
		cout << "Not present";
	else
		cout << "Present at index " << res;
	return 0;
}

Time complexity: O(M * N) where m and n are lengths of s1 and s2 respectively, Nested loops are used, outer from 0 to N – M and inner from 0 to M 
Auxiliary Space: O(1), As no extra space is required.

*/


/*
int strstr(String s, String x)
    {
       // Your code here
       for(int i=0;i<=(s.length()-x.length());i++)
     {
         if(x.equals(s.substring(i,i+x.length())))
         {
             return i;
         }
     }
     return -1;
}  
*/


/*

ONE LINE CODE - C++

int strstr(string s, string x)
{
    
    return s.find(x);
}
*/


// 2. Better (using STL)

// C++ implementation of the approach

#include <bits/stdc++.h>
using namespace std;

// function to get the index of s2 in s1
int isSubstring(string s1, string s2)
{
	// using find method to check if s1 is
	// a substring of s2
	if (s2.find(s1) != string::npos)
		return s2.find(s1);
	return -1;
}

// Driver code
int main()
{
	string s1 = "for";
	string s2 = "geeksforgeeks";

	// Function Call
	int res = isSubstring(s1, s2);
	if (res == -1)
		cout << "Not present";
	else
		cout << "Present at index " << res;
	return 0;
}


// Time Complexity: O(N) ,  where N is the length of the longer string s2 
// Auxiliary space: O(1)

// 3. KMP algo

int strstr(String s, String x)
    {
      int n = s.length();
      int m = x.length();
      //longest Prefix Suffix Tab
      int [] lps = new int[m];
      lps[0] = 0;
      //len of proper substring thats is prefix and also suffix - but not the whole substring <<x>>
      int j = 0;
      int i = 1;
      
      //compute lps
      while(i < m){
          if(x.charAt(i) == x.charAt(j)){
              lps[i] = j + 1;
              j++;
              i++;
          }else{
              if(j == 0) i++;
              else{
                  j = lps[j -1];
              }
          }
      }
      
      i = 0;
      int j = 0;
      //Detect substring
      while(i < n){
          if(s.charAt(i) == x.charAt(j)){
              i++;
              j++;
          }else{
              if(j==0) i++;
              else j = lps[j-1];
          }
          
          if(j == m) return (i - j);
      }
      
      return -1;
    }

// Time Complexity: O(N+M) where N is the length of the text and M is the length of the pattern to be found.
// Auxiliary Space: O(M)

