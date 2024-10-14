// Link : https://www.geeksforgeeks.org/cuckoo-hashing/

#include<iostream>
using namespace std;

int H1[11]={0},H2[11]={0}; //hash list 1 and hash list 2

void cuckoo(int a,int type)
{ int index,temp; 

  if(!type)   //type=0 means 1st hash list
  { 
  	 index=a%11;
  
   	if(!H1[index])
  	   H1[index]=a;
  
  	else
  	  { temp=H1[index];
  	  	H1[index]=a;
  	  	cuckoo(temp,1);

  	  } 
   }

   else    //type=1
   { 
	   	index=(a/11)%11;
	   	
	   	if(!H2[index])
	  	   H2[index]=a;
	  	
	  	else
	  	{  temp=H2[index];
	  		H2[index]=a;
	  	   cuckoo(temp,0);
	  	}
   }

 }

int main()
{   int A[]={20, 50, 53, 75, 100, 67, 105, 3, 36, 39};
     
     int n=sizeof(A)/sizeof(A[0]);
     for(int i=0;i<n;i++)
      { 
      	cuckoo(A[i],0);
        cout<<"\n"<<i<<"------------------------------------\n";
            
        for(int i=0;i<11;i++)
        {
     	  if(H1[i]) cout<<"\t"<<H1[i];
     	  else cout<<"\t_";
        }
     
        cout<<"\n";
        for(int i=0;i<11;i++)
        {
     	   if(H2[i]) cout<<"\t"<<H2[i];
     	   else cout<<"\t_";
        }
     }

     
	return 0;
}


/*
Time Complexity: O(N), the time complexity of the Cuckoo Hashing algorithm is O(N), where N is the number of keys to be stored in the hash table. This is because the algorithm requires only one pass over the list of keys to place them in the hash table.

Auxiliary Space: O(N), the space complexity of the Cuckoo Hashing algorithm is O(N), where N is the number of keys stored in the hash table. This is because the algorithm requires an auxiliary space of size equal to the hash table, where all the keys are stored.

Two Hash Functions
Cuckoo hashing typically uses two different hash functions to ensure that each key has two potential positions in the hash tables. In the provided code:

First Hash Function (h1):


index = a % 11;
This function computes the index by taking the remainder of the key a when divided by the table size (11 in this case).
Simple modulo operation: h1(a) = a % 11.
Second Hash Function (h2):


index = (a / 11) % 11;
This function first divides the key a by 11, then takes the remainder when divided by the table size (11).
This hash function is designed to be different from the first one to reduce the chance of collisions.
The rationale: h2(a) = (a / 11) % 11.
Why Different Hash Functions?
The purpose of using two distinct hash functions is to reduce the likelihood of both potential positions for a key being occupied simultaneously. If both hash functions were identical or very similar, they would likely hash many keys to the same indices, increasing the probability of collisions and cycles.
*/