// link: https://leetcode.com/problems/subsets/description/
//     : https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/

// video: https://www.youtube.com/watch?v=LqKaUv1G3_I&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=4

/*
1. Brute
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
Output:

All possible subsequences are:
abc ab ac a bc b c

Time Complexity: O(2^n)
Space Complexity: O(n), recursion stack.*/

// 2. Optimal : using bit manipulation

int n = v.size();
num = pow(2,n);
vector<vector<int>>ans(num);
for(int i = 0; i<num; i++){
    vector<int> temp;
    for(int j = 0;j<n;j++){
        if(num & (1<<j)) temp[i].push_back(arr[j]);
    }
    ans.push_back(temp);
}
return ans;

t.c: o(n*(2^n))
s.c: o(n*(2^n))