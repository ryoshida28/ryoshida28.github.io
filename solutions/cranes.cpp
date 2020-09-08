#include <bits/stdc++.h>


typedef unsigned long long ull;
struct Crane {
    ull x, y, r;
};

bool intersects(const Crane& a, const Crane& b) {
    ull dx = a.x - b.x;
    ull dy = a.y - b.y;
    ull dr = a.r + b.r;
    return (dx*dx + dy*dy) <= dr*dr;
}

ull area(const Crane& c) {
    return c.r*c.r;
}

int main() {

    int tc; std::scanf("%d", &tc);
    while(tc--) {
        int c; std::scanf("%d", &c);

        std::vector<Crane> cranes(c);
        std::vector<int> intersections(c);
        for (int i = 0; i < c; ++i) {
            ull x, y, r;
            std::scanf("%llu %llu %llu", &x, &y, &r);
            cranes[i] = {x,y,r};
            for (int j = 0; j < i; ++j) {
                if (intersects(cranes[i], cranes[j])) {
                    intersections[i] |= (1 << j);
                    intersections[j] |= (1 << i);
                }
            }
        }

        // 011 = state
        // 110
        std::queue<std::pair<int,ull>> q;   // queue[{bitmask, area}]
        q.push({0,0});
        for (int i = 0; i < c; ++i) {
            int to_pop = q.size();
            for (int j = 0; j < to_pop; ++j) {
                std::pair<int,ull> popped = q.front(); q.pop();

                if ((popped.first & intersections[i]) == 0) {
                    // No intersections occured
                    q.push({popped.first | (1 << i), popped.second + area(cranes[i])});
                }
                q.push({popped.first, popped.second});
            }
        }

        ull max = 0;
        while (!q.empty()) {
            max = std::max(q.front().second, max);
            q.pop();
        }

        std::printf("%llu\n", max);
    }

    return 0;
}