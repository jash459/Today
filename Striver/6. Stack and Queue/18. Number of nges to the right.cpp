// Link : https://practice.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

/*

1. Brute :

class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
       vector<int> ans;
       for(int i=0;i<queries;i++){
           int count=0;
           int y=indices[i];
           for(int j=y+1;j<n;j++){
               if(arr[y]<arr[j]){
                   count++;
               }
           }
           ans.push_back(count);
       }
       return ans;
    }
};

T.C - O(N*Q)
Space Complexity - O(1)
*/

class Solution
{
public:
    void merge(int low, int mid, int hig, vector<pair<int, int>> &v, vector<int> &ans)
    {
        int l = low, r = mid + 1;
        vector<pair<int, int>> temp;
        while (l <= mid && r <= hig)
        {
            if (v[l].first < v[r].first)
            {
                ans[v[l].second] += hig - r + 1;
                temp.push_back({v[l].first, v[l].second});
                l++;
            }
            else
            {
                temp.push_back({v[r].first, v[r].second});
                r++;
            }
        }
        while (l <= mid)
        {
            temp.push_back({v[l].first, v[l].second});
            l++;
        }
        while (r <= hig)
        {
            temp.push_back({v[r].first, v[r].second});
            r++;
        }
        for (int i = low; i <= hig; i++)
        {
            v[i] = temp[i - low];
        }
    }

    void f(int low, int hi, vector<pair<int, int>> &v, vector<int> &ans)
    {
        if (low == hi)
        {
            return;
        }
        int mid = (hi + low) / 2;
        f(low, mid, v, ans);
        f(mid + 1, hi, v, ans);
        merge(low, mid, hi, v, ans);
    }
    vector<int> count_NGE(int n, vector<int> &arr, int q, vector<int> &ind)
    {

        vector<pair<int, int>> v;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            v.push_back({arr[i], i});
        }
        f(0, n - 1, v, ans);

        vector<int> final;
        for (int i = 0; i < q; i++)
        {
            final.push_back(ans[ind[i]]);
        }
        return final;
    }
};

// O(NlogN) Time.

