// Link : https://takeuforward.org/data-structure/floyd-warshall-algorithm-g-42/

// video : https://www.youtube.com/watch?v=YbY8cVwWAvw&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=42

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == -1) {
					matrix[i][j] = 1e9;
				}
				if (i == j) matrix[i][j] = 0;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][k] + matrix[k][j]);
				}
			}
		}




		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1e9) {
					matrix[i][j] = -1;
				}
			}
		}
	}
};


int main() {

	int V = 4;
	vector<vector<int>> matrix(V, vector<int>(V, -1));
	matrix[0][1] = 2;
	matrix[1][0] = 1;
	matrix[1][2] = 3;
	matrix[3][0] = 3;
	matrix[3][1] = 5;
	matrix[3][2] = 4;

	Solution obj;
	obj.shortest_distance(matrix);

	for (auto row : matrix) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}

	return 0;
}
// Output:

// 0 2 5 -1
// 1 0 3 -1
// -1 -1 0 -1
// 3 5 4 0

// Time Complexity: O(V3), as we have three nested loops each running for V times, where V = no. of vertices.

// Space Complexity: O(V2), where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.