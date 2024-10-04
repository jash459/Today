//link: https://www.naukri.com/code360/problems/l-to-r-xor_8160412?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

//video: https://www.youtube.com/watch?v=WqGb7159h7Q&list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7&index=8

/*
1. Brute

int ans=0;
for(int i=0;i<n;i++){
    ans=ansârr[i];
}
return ans;

t.c: o(n)
s.c: o(1)
*/

// optimal 
int XorTillN(int N){
    if(N%4==1) return 1;
    else if(N%4==2) return N+1;
     else if(N%4==3) return 0;
    else if(N%4==0) return N;
}
t.c: o(1)
s.c: o(1)

// follow-up , in range l to r
int findXOR(int L, int R){
    // Write your code here.
   return XorTillN(R) ^ XorTillN(L-1);
}
// t.c: o(1)
// s.c: o(1)

// for brute in range l to r
t.c: o(r-l+1)
s.c: o(1)