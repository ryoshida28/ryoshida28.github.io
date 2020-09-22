#include <bits/stdc++.h>

int main() {

    int t; scanf("%d", &t);

    for (int c = 0; c < t; ++c) {
        int n,m; scanf("%d %d", &n, &m);    // n people/fridges, m chains
        
        int weights = 0;
        for (int cc = 0; cc < n; ++cc) {
            int w; scanf("%d", &w);
            weights += w;
        }

        if (m < n || n <= 2) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << weights*2 << std::endl;
            for (int i = 1; i < n; ++i) {
                std::cout << i << " " << i+1 << std::endl;
            }
            std::cout << n << " " << 1 << std::endl;
        }
    }



    return 0;
}