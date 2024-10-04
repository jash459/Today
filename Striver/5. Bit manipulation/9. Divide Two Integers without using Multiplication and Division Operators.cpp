// link: https://leetcode.com/problems/divide-two-integers/

//video: https://www.youtube.com/watch?v=pBD4B1tzgVc&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=9

/*
1. brute
int cnt=0, sum=0;
while(sum+divisor <=  dividend){
    cnt++;
    sum=+divisor;
}
return cnt 
t.c: o(dividend)
s.c: o(1)
*/

// optimal on coding nijas

int divideTwoInteger(int dividend, int divisor) {
	int count = 0;
	int flag = -1;
	if((dividend<0 && divisor<0)||(dividend>0 && divisor>0))
	    flag = 1;
	int n = abs(dividend);
	int m = abs(divisor);
	
	while(n >= m)
	{
		count++;
		n = n - m;
	}
	return count*flag;
} 


// striver video
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)
            return 1;
        bool sign = true;
        if((dividend<0 && divisor>0) || (divisor<0 && dividend>=0))
            sign = false;
        long int n = abs(dividend);
        long int d = abs(divisor);
        long int ans = 0;
        while(n>=d){
            int count=0;
            while(n >= (d<<(count+1)))
                count++;
            ans += (1<<count);
            n = n - (d<<count);
        }
        if(ans == (1<<31) and sign)
            return INT_MAX;
        return (sign?(ans):(-1*(ans)));
    }
};

t.c: o(logn)*2
s.c: o(1)
