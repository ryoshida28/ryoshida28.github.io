#include <bits/stdc++.h>

typedef std::vector<std::vector<int>> AdjList;
const int MAX_N = 5e5;
const int UNVISITED = -1;

int N, M;
AdjList adj;
int dfsCounter;
std::vector<int> dfs_num, dfs_low, dfs_parent;
std::vector<std::vector<int>> cc_verts;
std::vector<int> cc_edges;	

std::vector<std::pair<int,int>> signs;
std::vector<int> edgeCount;


void dfs(int u) {

	dfs_num[u] = dfsCounter++;
	cc_verts[cc_verts.size()-1].push_back(u);
	cc_edges[cc_edges.size()-1] += adj[u].size();
	for (int j = 0; j < adj[u].size(); ++j) {
		int v = adj[u][j];
		if (dfs_num[v] == UNVISITED) {
			dfs_parent[v] = u;
			dfs(v);
		} 
	}
}



int main() {

	std::scanf("%d %d", &N, &M);
	adj.resize(N+1);
	dfs_num.assign(N+1, UNVISITED);
	dfs_low.assign(N+1, 0);
	dfs_parent.assign(N+1, 0);
	edgeCount.resize(N+1);
	for (int i = 0; i < M; ++i) {
		int v, w; std::scanf("%d %d", &v, &w);
		adj[v].push_back(w);
		adj[w].push_back(v);
		edgeCount[v] += 1;
		edgeCount[w] += 1;
	}
	
	dfsCounter = 0;
	for (int i = 1; i <= N; ++i) if (dfs_num[i] == UNVISITED) {
		cc_verts.push_back(std::vector<int>());
		cc_edges.push_back(0);
		dfs(i);
		cc_edges[cc_edges.size() - 1] /= 2;
	}

	for (int cci = 0; cci < cc_verts.size(); ++cci) {
		if (cc_verts[cci].size() == cc_edges[cci]+1) {
			// This is a tree
			// Every edge from leaf must have a sign
			for (const int u : cc_verts[cci]) if (adj[u].size() == 1) {
				signs.push_back({u, adj[u][0]});
			}

		} else {
			// Component is cyclical
			
			std::unordered_set<int> component(cc_verts[cci].begin(), cc_verts[cci].end());
			std::queue<int> toRemove;
			for (const int v : cc_verts[cci]) {
				if (edgeCount[v] == 1) {
					toRemove.push(v);
				}
			}

			while (!toRemove.empty()) {
				int v = toRemove.front(); toRemove.pop();
				component.erase(v);
				for (const int u : adj[v]) {
					if (--edgeCount[u] == 1) {
						toRemove.push(u);
					}
				}
			}


			for (const int v : component) {
				for (const int u : adj[v]) if (component.count(u) == 0) {
					signs.push_back({v,u});
				}
			}


		}
	}

	std::printf("%d\n", (int) signs.size());
	std::sort(signs.begin(), signs.end());
	for (const std::pair<int,int>& street : signs) {
		std::printf("%d %d\n", street.first, street.second);
	}

	return 0;
}
