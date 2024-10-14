// Link: https://www.geeksforgeeks.org/the-celebrity-problem/

/*
Brute

// C++ program to find celebrity
#include <bits/stdc++.h>
#include <list>
using namespace std;

// Max # of persons in the party
#define N 8

// Person with 2 is celebrity
bool MATRIX[N][N] = { { 0, 0, 1, 0 },
                      { 0, 0, 1, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 1, 0 } };

bool knows(int a, int b) { return MATRIX[a][b]; }

// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n)
{
    // the graph needs not be constructed
    // as the edges can be found by
    // using knows function

    // degree array;
    int indegree[n] = { 0 }, outdegree[n] = { 0 };

    // query for all edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = knows(i, j);

            // set the degrees
            outdegree[i] += x;
            indegree[j] += x;
        }
    }

    // find a person with indegree n-1
    // and out degree 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == n - 1 && outdegree[i] == 0)
            return i;

    return -1;
}

// Driver code
int main()
{
    int n = 4;
    int id = findCelebrity(n); id == -1 ? cout << "No celebrity": cout << "Celebrity ID " << id;
    return 0;
}

Time Complexity: O(N2), A nested loop is run traversing the array
Auxiliary Space: O(N), Since extra space of size N is required.

*/

/*
Better

// C++ program to find celebrity
#include <bits/stdc++.h>
#include <list>
using namespace std;

// Max # of persons in the party
#define N 8

// Person with 2 is celebrity
bool MATRIX[N][N] = { { 0, 0, 1, 0 },
                      { 0, 0, 1, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 1, 0 } };

bool knows(int a, int b) { return MATRIX[a][b]; }

// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n)
{

    stack<int> s;

    // Celebrity
    int C;

    // Push everybody to stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // Extract top 2

    // Find a potential celebrity
    while (s.size() > 1) {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B)) {
            s.push(B);
        }
        else {
            s.push(A);
        }
    }

    // Potential candidate?
    C = s.top();
    s.pop();

    // Check if C is actually
    // a celebrity or not
    for (int i = 0; i < n; i++) {
        // If any person doesn't
        // know 'C' or 'C' doesn't
        // know any person, return -1
        if ((i != C) && (knows(C, i) || !knows(i, C)))
            return -1;
    }

    return C;
}

// Driver code
int main()
{
    int n = 4;
    int id = findCelebrity(n); id == -1 ? cout << "No celebrity" : cout << "Celebrity ID " << id;
    return 0;
}

Time Complexity: O(N), The total number of comparisons is 3(N-1).
Auxiliary Space: O(N), n extra space is needed to store the stack.
*/

// C++ program to find celebrity
// in the given Matrix of people
#include <bits/stdc++.h>
using namespace std;
#define N 4
int celebrity(int M[N][N], int n)
{
    // This function returns the celebrity
    // index 0-based (if any)

    int i = 0, j = n - 1;
    while (i < j) {
        if (M[j][i] == 1) // j knows i
            j--;
        else // j doesnt know i so i cant be celebrity
            i++;
    }
    // i points to our celebrity candidate
    int candidate = i;

    // Now, all that is left is to check that whether
    // the candidate is actually a celebrity i.e: he is
    // known by everyone but he knows no one
    for (i = 0; i < n; i++) {
        if (i != candidate) {
            if (M[i][candidate] == 0 || M[candidate][i] == 1)
                return -1;
        }
    }
    // if we reach here this means that the candidate
    // is really a celebrity
    return candidate;
}

int main()
{
    int M[N][N] = { { 0, 0, 1, 0 },
                    { 0, 0, 1, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 1, 0 } };

    int celebIdx = celebrity(M, 4);

    if (celebIdx == -1)
        cout << ("No Celebrity");
    else {
        cout << "Celebrity ID " << celebIdx;
    }
    return 0;
}

// Time Complexity: O(N), Iterating two times the array of size N.
// Auxiliary Space: O(1) No extra space is required.

