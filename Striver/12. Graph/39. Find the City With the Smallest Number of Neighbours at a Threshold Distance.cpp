// Link : https://takeuforward.org/data-structure/find-the-city-with-the-smallest-number-of-neighbours-at-a-threshold-distance-g-43/

// video : https://www.youtube.com/watch?v=PwMVNSJ5SLI&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=43

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findCity(int n, int m, vector<vector<int>>& edges,
	             int distanceThreshold) {
		vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
			dist[it[0]][it[1]] = it[2];
			dist[it[1]][it[0]] = it[2];
		}
		for (int i = 0; i < n; i++) dist[i][i] = 0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
						continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (dist[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;

	}
};


int main() {

	int n = 4;
	int m = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

	Solution obj;
	int cityNo = obj.findCity(n, m, edges, distanceThreshold);
	cout << "The answer is node: " << cityNo << endl;

	return 0;
}
// Output: The answer is node: 3

// Time Complexity: O(V3), as we have three nested loops each running for V times, where V = no. of vertices.

// Space Complexity: O(V2), where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.