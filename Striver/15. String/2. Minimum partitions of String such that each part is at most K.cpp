// Link: https://www.geeksforgeeks.org/minimum-partitions-of-string-such-that-each-part-is-at-most-k/

// C++ program for above implementation

class Solution {
public:
    int minimumPartition(string s, int k) {
        int n=s.size();
        long long num=0,cnt=0;
        for(int i=0;i<n;i++){
            num=(s[i]-'0'); // initializing the variable num as s[i]
            if(num>k) return -1; // if the num is greater than k then we simply return -1
            // if the num variable is not less than k then we check for the next index of the current index. If it satisfies then we increment i else we break out from the loop.
            while((i+1)<n){
                num=num*10+(s[i+1]-'0');
                if(num>k) break;
                i++;
            }
            cnt++;// we will get our first substring so increment the value of cnt
        }
        return cnt;
    }
};
// Time Complexity: O(N)
// Auxiliary Space: O(1)