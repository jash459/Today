// Link: https://www.geeksforgeeks.org/problems/prime-factorization-using-sieve/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prime-factorization-using-sieve

// video: https://www.youtube.com/watch?v=glKWkmKFlMw

void mySieve(vector<int>&prime, int n){
        for(int i=1; i<=n; i++){
            prime[i] = i;
        }
        for(int i=2; i*i<= n; i++){
            if(prime[i] == i){
                for(int j=i*i; j<=n; j += i){
                    if(prime[j] == j)
                        prime[j] = i;
                }
            }
        }
    }

    vector<int> findPrimeFactors(int N) {

        vector<int> prime(N+1);
        mySieve(prime, N);
        vector<int> ans;
        
        while(N != 1){
            ans.push_back(prime[N]);
            N = N / prime[N];
        }
        
        return ans;
    }
// Expected Time Complexity: O(Nlog(log(N))).
// Expected Auxiliary Space: O(N).