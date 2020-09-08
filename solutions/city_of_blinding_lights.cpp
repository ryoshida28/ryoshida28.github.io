#include <bits/stdc++.h>

const int MAX_VERT = 400;
const int INF = std::numeric_limits<int>::max();

typedef std::vector<std::unordered_map<int,int>> AdjList;   // node->{node:weight}
typedef std::pair<int,int> Position;                         // {node, weight}


AdjList graph;
int dp[MAX_VERT+1][MAX_VERT+1] = {0};
bool used[MAX_VERT+1][MAX_VERT+1] = {0};
// int N;



int main() {

    for (int i = 0; i < MAX_VERT+1; ++i) {
        for (int j = 0; j < MAX_VERT+1; ++j) {
            dp[i][j] = INF;
        }
    }


    int n,m; std::scanf("%d %d", &n, &m);
    // graph.resize(n+1);
    // N = n;

    for (int i = 0; i < m; ++i) {
        int x,y,r; std::scanf("%d %d %d", &x, &y, &r);
        // graph[x][y] = r;
        dp[x][y] = r;
        used[x][y] = true;
    }

    // intermediate
    for (int k = 1; k < n+1; ++k) {
        // source
        for (int u = 1; u < n+1; ++u) {
            // dest
            for (int v = 1; v < n+1; ++v) {
                if (!used[u][k] || !used[k][v])
                    continue;

                if (dp[u][k] + dp[k][v] < dp[u][v]) {
                    dp[u][v] = dp[u][k] + dp[k][v];
                    used[u][v] = true;
                }
            }
        }
    }

    int q; std::scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int a,b; std::scanf("%d %d", &a, &b);

        if (!used[a][b]) {
            std::printf("-1\n");
        } else {
            std::printf("%d\n", dp[a][b]);
        }
    }

    return 0;
}