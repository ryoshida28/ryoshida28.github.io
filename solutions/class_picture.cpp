#include <bits/stdc++.h>

typedef std::unordered_set<std::string> Names;
typedef std::unordered_map<std::string, Names> Graph;
typedef std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> PQ;


struct Thing {
    bool valid;
    std::stack<std::string> stack;
};

Thing dfs(const Graph& g, Names& remaining, const std::string& init) {
    // std::cout << init << std::endl;
    // for (const auto& n : remaining) {
    //     std::cout << n << ", ";
    // }
    // std::cout << std::endl << std::endl;

    if (remaining.empty()) {
        return Thing{true};
    } else {
        PQ pq(remaining.begin(), remaining.end());
        while (!pq.empty()) {
            std::string next = pq.top();
            pq.pop();
            if (g.at(next).count(init) == 0) {
                remaining.erase(next);
                Thing t = dfs(g,remaining,next);

                if (t.valid) {
                    t.stack.push(next);
                    return t;
                } else {
                    remaining.insert(next);
                    continue;
                }
            }
        }

        return Thing{false};
    }
}


int main() {

    int n;
    while (std::cin >> n) {
        Names names;
        Graph graph;
        for (int i = 0; i < n; ++i) {
            std::string name; std::cin >> name;
            names.insert(name);
            graph[name];    // construct default value
        }

        int m; std::cin >> m;
        for (int i = 0; i < m; ++i) {
            std::string s1,s2; std::cin >> s1 >> s2;
            graph[s1].insert(s2);
            graph[s2].insert(s1);
        }

        // for (const auto& kv : graph) {
        //     std::cout << kv.first << ": ";

        //     for (const auto& n : kv.second) {
        //         std::cout << n << ", ";
        //     }

        //     std::cout << std::endl;
        // }

        Thing t = dfs(graph,names,"");

        if (!t.valid) {
            std::cout << "You all need therapy." << std::endl;
        } else {
            if (!t.stack.empty()) {
                std::cout << t.stack.top();
                t.stack.pop();
                while (!t.stack.empty()) {
                    std::cout << ' ' << t.stack.top();
                    t.stack.pop();
                }
                std::cout << std::endl;
            }
        }

    }

    return 0;
}