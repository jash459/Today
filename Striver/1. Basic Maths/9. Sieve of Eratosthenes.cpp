// Link: https://leetcode.com/problems/count-primes/

// video: https://www.youtube.com/watch?v=g5Fuxn_AvSk

// Sieve of Eratosthenes algorithm Approach
class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                cnt++;
                for (int j = i * 2; j < n; j = j + i) {
                    prime[j] = 0;
                }
            }
        }
        return cnt;
    }
};

// to print prime no.:

for(int i =2 ; i <= n; i++){
   if(prime[i]) cout<< i << endl;
}

// Time complexity: O(nloglogn)
// Space complexity: O(n)

// Optimal
class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= (n); i++) {
            if (prime[i]) {
                cnt++;
                for (int j = i * i; j < n; j = j + i) {
                    prime[j] = 0;
                }
            }
        }
        return cnt;
    }
};