// Link: https://www.geeksforgeeks.org/problems/distinct-palindromic-substrings5141/1


#include <iostream>
#include <set>
using namespace std;

// Function to find all distinct palindrome 
// substrings in a given string
int GFG(string str, set<string> &result) {
	int n = str.length();
	bool dp[n][n];
	for (int gap = 0; gap < n; gap++) {
		for (int i = 0, j = gap; j < n; i++, j++) {
			if (gap == 0)
				dp[i][j] = true; 
		// Single characters are palindromes
			else if (gap == 1)
				dp[i][j] = (str[i] == str[j]); 
		// Two characters are palindromes if they are the same
			else
				dp[i][j] = (str[i] == str[j] && dp[i + 1][j - 1]); 
		// Check if the substring is a palindrome
			if (dp[i][j])
				result.insert(str.substr(i, j - i + 1));
		}
	}
	return result.size(); 
// Return the count of distinct palindromic substrings
}
int main() {
	string str = "abaaa";
	set<string> result;
	// Call the function to find palindromic substrings
	GFG(str, result);
	cout << "Number of distinct palindromic substrings are: " << result.size() << endl;
	// Print the distinct palindromic substrings
	for (const string &s : result)
		cout << s << endl;
	return 0;
}
Time Complexity: O(N^2 * log(N)) since we are iterating through the matrix and while doing so we put elements in set which takes log(N) time
Space Complexity: O(N^2) since we using 2-D array


// 2. Optimal

unordered_set<string> helper;
    void addpalindrome(string s,int left,int right,int n){
        while(left>=0 && right<n){
            if(s[left]!=s[right])break;
            helper.insert(s.substr(left,right-left+1));
            left--,right++;
        }
        return;
    }
    int palindromeSubStrs(string s) {
        int  n=s.size();
        for(int i=0;i<n;i++){
            addpalindrome(s,i,i,n);   // Check for odd length palindromes
            addpalindrome(s,i,i+1,n);  // Check for even length palindromes
        }
        return helper.size();
    }

// Time complexity: O(N^3)
// Space complexity: O(N)