#include <bits/stdc++.h>

int main() {

    int tc; std::scanf("%d", &tc);
    while(tc--) {
        int n,m,l; std::scanf("%d %d %d", &n, &m, &l);

        std::vector<std::vector<int>> adjList(n+1);
        std::vector<bool> used(n+1);
        for (int i = 0; i < m; ++i) {
            int x,y; std::scanf("%d %d", &x, &y);
            adjList[x].push_back(y);
        }

        int count = 0;
        for (int i = 0; i < l; ++i) {
            std::queue<int> q;
            int z; std::scanf("%d", &z);
            q.push(z);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (used[u]) {
                    continue;
                }
                used[u] = true;
                ++count;
                for (int j = 0; j < adjList[u].size(); ++j) {
                    q.push(adjList[u][j]);
                }
            }
        }

        std::printf("%d\n", count);
    }

    return 0;
}