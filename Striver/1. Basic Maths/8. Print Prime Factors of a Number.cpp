// Link: https://www.geeksforgeeks.org/problems/prime-factors5052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Prime-Factors

// video: https://www.youtube.com/watch?v=LT7XhVdeRyg

/*
Better
vector <int> ret;
        for(int i=2;i<=N;i++)
        {
            if(N%i == 0)
            {
                ret.push_back(i);
                while(N%i == 0)
                    N/=i;
            }
        }
        return ret;
Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
*/

// Optimal
class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    vector<int> vec;
	    for(int i=2; i<=sqrt(N); i++)
	    {
	        if(N%i==0){
	            vec.push_back(i);
	            while(N%i == 0)
	            {
	                N/=i;
	            }
	        }
	    }
	    if(N!=1)vec.push_back(N);
	    return vec;
	}
};

// Expected Time Complexity: O(sqrt(N))
// Expected Space Complexity: O(N)
