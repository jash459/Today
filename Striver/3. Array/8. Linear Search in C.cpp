// Link : https://takeuforward.org/data-structure/linear-search-in-c/

// video : https://www.youtube.com/watch?v=wvcQg43_V8U

#include<stdio.h>

int search(int arr[],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==num)
        return i;
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5};
    int num = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = search(arr,n,num);
    printf("%d",val);
}
// Output: 3
// Time Complexity: O(n), where n is the length of the array.
// Space Complexity: O(1)