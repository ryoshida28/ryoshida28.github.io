#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef std::unordered_map<int,std::unordered_set<int>> Graph;

ull counts[26][26] = {0};


bool dfs(int cand, Graph& g, int n) {
    std::bitset<26> visited;
    std::stack<int> stk;
    stk.push(cand);
    while (!stk.empty()) {
        int cur = stk.top();
        stk.pop();
        if (!visited[cur]) {
            visited.set(cur);
            for (const int c : g[cur]) {
                if (!visited[c]) {
                    stk.push(c);
                }
            }
        }
    }

    return visited.count() == n;
}

int main() {
    
    int n,m; std::scanf("%d %d", &n, &m);
    for (int x = 0; x < m; ++x) {
        std::string ballot;
        int ballot_count;
        std::cin >> ballot_count >> ballot;

        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                counts[ballot[i]-'A'][ballot[j]-'A'] += ballot_count;
            }
        }
    }

    // Make Graph
    Graph g;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (counts[i][j] > counts[j][i]) {
                g[i].insert(j);
            } else {
                g[j].insert(i);
            }
        }
    }
    

    // for (int r = 0; r < 26; ++r) {
    //     for (int c = 0; c < 26; ++c) {
    //         std::printf("%d ", counts[r][c]);
    //     }
    //     std::printf("\n");
    // }

    for (int i = 0; i < n; ++i) {
        if (dfs(i, g, n)) {
            std::printf("%c: can win\n", i+'A');
        } else {
            std::printf("%c: can't win\n", i+'A');
        }
    }

    
    return 0;
}