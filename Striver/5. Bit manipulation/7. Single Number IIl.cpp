//link: https://www.naukri.com/code360/problems/two-numbers-with-odd-occurrences_8160466?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=DISCUSS

//video: https://www.youtube.com/watch?v=UA5JnV1J2sI&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=7
/*
Brute
vector<int> twoOddNum(vector<int> arr){
    vector<int> ans;
    unordered_map<int,int> mp;
    int N=arr.size();
    for(int i=0;i<N;i++){
        mp[arr[i]]++;
    }
    for(auto x:mp){
        if(x.second%2==1){
            ans.push_back(x.first);
        }
    }
    if (ans[0] < ans[1])
    {
        swap(ans[0], ans[1]);
    }
    return ans;
}*/

// optimal
vector<int> twoOddNum(vector<int> arr)
{
    long XORR= 0; // to handle the overflow, see at 23:00
    int n = arr.size();
    for (int i = 0; i < n; i++) XORR^=arr[i];
    int Rightmost = XORR & (~(XORR - 1));
    int b1 = 0;
    int b2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & Rightmost)
        {
            b1^=arr[i];
        }
        else
        {
            b2^=arr[i];
        }
    }
    if (b1 < b2) return {b2,b1};
    else return {b1,b2};
}

// t.c: o(2n)
// s.c: o(1)