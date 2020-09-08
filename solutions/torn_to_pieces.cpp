#include <bits/stdc++.h>


typedef std::unordered_map<std::string, std::unordered_set<std::string>> Graph;
typedef std::pair<std::string, std::vector<std::string>> q_item;

std::vector<std::string> bfs(Graph& g, const std::string& init, const std::string& dest) {
    std::unordered_set<std::string> visited({init});
    std::queue<q_item> queue({q_item(init, std::vector<std::string>({init}))});

    while (queue.size() > 0) {
        q_item popped = queue.front();
        queue.pop();

        for (const std::string& s : g[popped.first]) {
            if (s == dest) {
                popped.second.push_back(s);
                return popped.second;
            }
            if (visited.find(s) == visited.end()) {
                visited.insert(s);
                std::vector<std::string> copy_vector(popped.second);
                copy_vector.push_back(s);
                queue.push(q_item(s, copy_vector));
            }
        }

    }
    return std::vector<std::string>();
}


int main() {

    int n; std::cin >> n;

    Graph graph;

    std::string line;
    getline(std::cin, line);
    for (int i = 0; i < n; ++i) {
        getline(std::cin, line);
        std::istringstream iss(line);
        std::string station;
        getline(iss, station, ' ');
        std::string init = station;
        while(getline(iss, station, ' ')) {
            graph[station].insert(init);
            graph[init].insert(station);
        }
    }

    std::string start, dest;
    std::cin >> start >> dest;

    std::vector<std::string> path = bfs(graph, start, dest);

    if (path.size() == 0) {
        std::cout << "no route found" << std::endl;
    } else {
        std::cout << path[0];
        for (int i = 1; i < path.size(); ++i) {
            std::cout << ' ' << path[i];
        }
        std::cout << std::endl;
    }

    return 0;
}