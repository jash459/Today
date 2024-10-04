// Link : https://takeuforward.org/data-structure/stock-buy-and-sell-dp-35/

// video : https://www.youtube.com/watch?v=excAOvwF_Wk

#include <bits/stdc++.h>

using namespace std;

int maximumProfit(vector<int> &Arr){
    // Write your code here.
	int maxProfit = 0;
	int mini = Arr[0];
	
	for(int i=1;i<Arr.size();i++){
        int curProfit = Arr[i] - mini;
        maxProfit = max(maxProfit,curProfit);
        mini = min(mini,Arr[i]);
        }
	return maxProfit;
}

int main() {

  vector<int> Arr  ={7,1,5,3,6,4};

  cout<<"The maximum profit by selling the stock is "<<maximumProfit(Arr);
}
// Output:
// The maximum profit by selling the stock is 5
// Time Complexity: O(N)
// Reason: We are performing a single iteration
// Space Complexity: O(1)
// Reason: No extra space is used.
