https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

video: https://www.youtube.com/watch?v=OOdrmcfZXd8&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=3

int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int cnt = 0;
        
        while(ans != 0){
            ans = ans & (ans -1);
            cnt = cnt +1;
        }
        
        return cnt;
    }

T.C: O(ans) , worst case : o(31)
s.c: o(1)