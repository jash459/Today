// Link: https://leetcode.com/problems/valid-parenthesis-string/

// video: https://www.youtube.com/watch?v=cHT6sG_hUZI&list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea&index=11 


/*
1. Brute

f(s, ind, cnt){
if(cnt < 0) return false;
if(ind ==  n){
return (cnt == 0)
}
if(s[i] == '(') return f(s, ind+1, cnt+1)
if(s[i] == ')') return f(s, ind+1, cnt-1)
return f(s, ind+1, cnt+1) || f(s, ind+1, cnt-1) || f(s, ind+1, cnt);
}

t.c: o(3^n)
s.c: o(n)
*/

// 2. Optimal

bool checkValidString(string s) {
        int n = s.size();
        int min = 0, max = 0;
        for (int i = 0 ; i < n ; i++){
            if (s[i] == '('){
                min++;
                max++;
            }
            else if (s[i] == ')'){
                min--;
                max--;
            }
            else {
                min--;
                max++;
            }
            if (min < 0) min = 0;
            if (max < 0) return false;
        }
        return min == 0;
    }

t.c. : o(n)
s.c: O(1)