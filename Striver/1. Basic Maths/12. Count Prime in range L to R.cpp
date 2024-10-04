// Video: https://www.youtube.com/watch?v=os82DjD2-MA&t=8s

const int MAX_N = 1e6 + 1; // Maximum value for R (1,000,000)

class Solution {
public:
    vector<int> getSieve(int n) {
        int cnt = 0;
        vector<int> prime(n + 1, 1);
        prime[0] = prime[1] = 0;
        for (int i = 2; i * i <= (n); i++) {
            if (prime[i]) {
                cnt++;
                for (int j = i * i; j < n; j = j + i) {
                    prime[j] = 0;
                }
            }
        }
        return prime;
    }

    void (vector<int> queries){
        vector<int> prime = getSieve(MAX_N);
        int cnt = 0;
        for(int i =2 ; i < MAX_N ; i++){
           cnt = cnt + prime[i];
           prime[i] = cnt; 	
        }
        int n = queries.size();
        for(int i = 0; i < n ; i++){
            int l = queries[i][0], r = queries[i][1];
            cout << (prime[r] -  prime[l-1]);
        }
    }
};