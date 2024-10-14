// Link : https://www.geeksforgeeks.org/game-replacing-array-elements/


// 1. Brute 

// CPP program for Game of Replacement
#include <bits/stdc++.h>
using namespace std;

// Function return which player win the game
int playGame(int arr[], int n)
{
	// Create hash that will stores
	// all distinct element
	unordered_set<int> hash;

	// Traverse an array element
	for (int i = 0; i < n; i++)
		hash.insert(arr[i]);

	return (hash.size() % 2 == 0 ? 1 : 2);
}

// Driver Function
int main()
{
	int arr[] = { 1, 1, 2, 2, 2, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Player " << playGame(arr, n) << " Wins" << endl;
	return 0;
}


// Time Complexity: O(n)

// Auxiliary Space: O(n)

/*
Game Explanation
The game involves two players, A and B. They take turns picking two distinct numbers, say a1 and a2, from the array. The player then replaces all instances of a2 with a1 or vice versa. The game ends when a player is unable to pick two distinct numbers, and that player loses. Player A always starts first.

Observations
The game continues until there are no distinct pairs of numbers left.
The outcome depends on the number of distinct elements in the array:
If the number of distinct elements is odd, player A (first player) will always be able to make the last move, making player B lose.
If the number of distinct elements is even, player B (second player) will always be able to make the last move, making player A lose.

 "The player then replaces all instances of a2 with a1 or vice versa" means that the player chooses two distinct numbers from the array, say a1 and a2, and then performs one of the following actions:

Replace every occurrence of the number a2 in the array with the number a1.
Alternatively, replace every occurrence of the number a1 in the array with the number a2.
Example 1
Consider the array arr[] = {1, 3, 3, 2, 2, 1}:

First Move (Player A):

Player A picks the distinct numbers 1 and 3.
Player A decides to replace all instances of 3 with 1.
The array now becomes: {1, 1, 1, 2, 2, 1}.
Second Move (Player B):

Player B picks the distinct numbers 1 and 2.
Player B decides to replace all instances of 1 with 2 (or vice versa, the result is the same since eventually, all numbers will be the same).
The array now becomes: {1, 1, 1, 1, 1, 1}.
At this point, Player A cannot make a move because there are no two distinct numbers left. Therefore, Player A loses, and Player B wins.
*/