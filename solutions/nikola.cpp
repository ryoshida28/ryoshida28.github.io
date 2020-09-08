#include <bits/stdc++.h>

typedef std::array<int,3> CostStep; // {cost, last_step, location}

bool lt(const CostStep& a, const CostStep& b) { return a[0] > b[0]; }
size_t hash(std::pair<int,int> val) { std::hash<int> h; return h(val.first)*h(val.second); }

int main() {

    int n; scanf("%d", &n);
    std::vector<int> costs;
    for (int i = 0; i < n; ++i) {
        int c; scanf("%d", &c);
        costs.push_back(c);
    }

    
    std::priority_queue<CostStep,std::vector<CostStep>, std::function<bool(const CostStep&, const CostStep&)>> pq(lt);
    std::unordered_set<std::pair<int,int>, size_t(*)(std::pair<int,int>)> seen(10, hash);

    pq.push(CostStep({costs[1], 1, 1}));

    int min = std::numeric_limits<int>::max();
    while (!pq.empty()) {
        CostStep top = pq.top();
        pq.pop();

        if (top[2] == n-1) {
            std::cout << top[0] << std::endl;
            break;
        }

        if (seen.count(std::pair<int,int>(top[1], top[2]))) {
            continue;
        } else {
            seen.insert(std::pair<int,int>(top[1],top[2]));
        }

        int forward_index = top[2]+top[1]+1;
        if (forward_index < n) {
            CostStep next = {top[0]+costs[forward_index], top[1]+1, forward_index};
            pq.push(next);
            if (forward_index == n-1)
                continue;
        }

        int backward_index = top[2]-top[1];
        if (backward_index >= 0) {
            CostStep next = {top[0]+costs[backward_index], top[1], backward_index};
            pq.push(next);
        }
    }



    return 0;
}