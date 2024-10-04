// Link : https://takeuforward.org/data-structure/course-schedule-i-and-ii-pre-requisite-tasks-topological-sort-g-24/

// video : https://www.youtube.com/watch?v=WAOfKpxYHR8&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=24

// 1. Prequist task:

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites)
	{
		vector<int> adj[V];
		for (auto it : prerequisites) {
			adj[it[0]].push_back(it[1]);
		}



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
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}
        // as Topo sort only work in DAG, so if cycle detect then return false, else true
		if (topo.size() == V) return true;
		return false;
	}
};
// 1. Course Schedule: here node are reversed, so it[1] -> it[0] and return topo sort else {} ( empty array)

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites)
	{
		vector<int> adj[V];
		for (auto it : prerequisites) {
			adj[it[1]].push_back(it[0]);
		}



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
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (topo.size() == V) return topo;
		return {};
	}
};


int main() {

	int N = 4;
	int M = 3;

	vector<vector<int>> prerequisites(3);
	prerequisites[0].push_back(0);
	prerequisites[0].push_back(1);

	prerequisites[1].push_back(1);
	prerequisites[1].push_back(2);

	prerequisites[2].push_back(2);
	prerequisites[2].push_back(3);

	Solution obj;
	vector<int> ans = obj.findOrder(N, M, prerequisites);

	for (auto task : ans) {
		cout << task << " ";
	}
	cout << endl;
	return 0;
}

// 2. Pre-requist

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isPossible(int V, vector<pair<int, int> >& prerequisites) {
		vector<int> adj[V];
		for (auto it : prerequisites) {
			adj[it.first].push_back(it.second);
		}



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
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (topo.size() == V) return true;
		return false;


	}
};

int main() {

	vector<pair<int, int>> prerequisites;
	int N = 4;
	prerequisites.push_back({1, 0});
	prerequisites.push_back({2, 1});
	prerequisites.push_back({3, 2});

	Solution obj;
	bool ans = obj.isPossible(N, prerequisites);

	if (ans) cout << "YES";
	else cout << "NO";
	cout << endl;

	return 0;
}
// Output: YES

// Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.

// Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes). Extra O(N) for storing the topological sorting. Total ~ O(3N).