// Link : https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-topological-sort-kahns-algorithm-g-23/

// video : https://www.youtube.com/watch?v=iTBaI90lpDQ&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=23

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		int cnt = 0;
		// o(v + e)
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cnt++;
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (cnt == V) return false;
		return true;
	}
};


int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {2}, {3}, {4, 5}, {2}, {}};
	int V = 6;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);
	if (ans) cout << "True";
	else cout << "Flase";
	cout << endl;
	return 0;
}
// Output: True

// Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.

// Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the in-degree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).