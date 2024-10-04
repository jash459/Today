// Link: https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/

// video: https://www.youtube.com/watch?v=b7AYbpM5YrE

/*
1. Using Bit Manipulation
#include<bits/stdc++.h>
using namespace std;
vector<string> AllPossibleStrings(string s) {
	int n = s.length();
	vector<string>ans;
	for (int num = 0; num < (1 << n); num++) {
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}
int main()
{


	string s="abc";
	vector<string>ans = AllPossibleStrings(s);
	//printint all the subsequence.
	cout<<"All possible subsequences are "<<endl;
	for (auto it : ans) {
		cout << it << " ";
	}

}
Output:

All possible subsequences are
a ab abc ac b bc c

Time Complexity: O(2^n * n)
Reason: O(2^n) for the outer for loop and O(n) for the inner for loop.
Space Complexity: O(1)*/

// Using recurrsion(backtracking)
#include<bits/stdc++.h>
using namespace std;
void solve(int i, string s, string &f) {
	if (i == s.length()) {
		cout << f << " ";
		return;
	}
	//picking 
	f = f + s[i];
	solve(i + 1, s,  f);
	//poping out while backtracking
	f.pop_back();
	solve(i + 1, s,  f);
}
int main() {
	string s = "abc";
	string f = "";
	cout<<"All possible subsequences are: "<<endl;
	solve(0, s, f);
}
// Output:

// All possible subsequences are:
// abc ab ac a bc b c

// Time Complexity: O(2^n)
// Space Complexity: O(n), recursion stack.