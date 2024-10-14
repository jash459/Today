// Link: https://www.geeksforgeeks.org/smallest-window-containing-0-1-and-2/

/*
1.Brute

// C++ program for above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the smallest substring
int smallestSubstring(string S)
{
	int res = INT_MAX;
	// To check 0, 1 and 2
	bool zero = false, one = false, two = false;
	// To store indexes of 0, 1 and 2
	int zeroindex, oneindex, twoindex;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '0') {
			zero = true;
			zeroindex = i;
		}
		else if (S[i] == '1') {
			one = true;
			oneindex = i;
		}
		else if (S[i] == '2') {
			two = true;
			twoindex = i;
		}

		// Calculating length
		if (zero and one and two)
			res = min(res,
					max({ zeroindex, oneindex, twoindex })
						- min({ zeroindex, oneindex, twoindex }));
	}

	// In case if there is no substring that contains 0,1 and 2
	if (res == INT_MAX)
		return -1;
	return res + 1;
}

// Driver Code
int main()
{
	string S = "01212";

	// Function call
	cout << smallestSubstring(S);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
Time Complexity: O(N), as we are using a loop to traverse N times.
Auxiliary Space: O(1), as we are not using any extra space.

*/

// 2. Optimal: Sliding window

int n=s.length();
        int i=0;
        int j=0;
        int ans =0;
        int mn=INT_MAX;
        int a[3]={0,0,0};

        while(j<n){      
            
            a[s[j]-'0']++;
            ans++;
                while(a[0]>0&&a[1]>0&&a[2]>0&&i<j){
                mn=min(ans,mn);
                    a[s[i]-'0']--;
                    ans--;
                    i++;
            }
            j++;
        }
        return mn==INT_MAX?-1:mn;


// Time Complexity: O(N)
// Auxiliary Space: O(1) 


