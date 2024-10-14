// Link: https://www.geeksforgeeks.org/minimum-number-stops-given-path/

// C++ program to find minimum number of points 
// in a given path
#include <bits/stdc++.h>
using namespace std;

// method returns minimum number of points in given path
int numberOfPointInPath(string path)
{
int N = path.length();

// Map to store last occurrence of direction
map<char, int> dirMap;

// variable to store count of points till now, 
// initializing from 1 to count first point
int points = 1;

// looping over all characters of path string
for (int i = 0; i < N; i++) {

// storing current direction in curDir 
// variable
char curDir = path[i];

// marking current direction as visited
dirMap[curDir] = 1;

// if at current index, we found both 'L'
// and 'R' or 'U' and 'D' then current 
// index must be a point
if ((dirMap['L'] && dirMap['R']) || 
(dirMap['U'] && dirMap['D'])) {
	
// clearing the map for next segment
dirMap.clear();

// increasing point count
points++;

// revisiting current direction for next segment
dirMap[curDir] = 1;
}
}

// +1 to count the last point also
return (points + 1);
}

// Driver code to test above methods
int main()
{
string path = "LLUUULLDD";
cout << numberOfPointInPath(path) << endl;
return 0; 
}


// Time Complexity: O(n*logn).
// Auxiliary Space: O(n)