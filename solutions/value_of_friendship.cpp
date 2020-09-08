#include <bits/stdc++.h>

class EqCl {
public:
    int parent_map[100001] = {0};
    unsigned long long root_sizes[100001] = {0};

    void add_singleton(int new_singleton) {
        if (parent_map[new_singleton] == 0) {
            parent_map[new_singleton] = new_singleton;
            root_sizes[new_singleton] = 1;
        }
    }

    void merge(int a, int b) {
        while (parent_map[a] != a) {
            a = parent_map[a];
        }
        while (parent_map[b] != b) {
            b = parent_map[b];
        }

        if (a != b) {
            if (root_sizes[a] < root_sizes[b]) {
                parent_map[b] = a;
                root_sizes[a] += root_sizes[b];
                root_sizes[b] = 0;
            } else {
                parent_map[a] = b;
                root_sizes[b] += root_sizes[a];               
                root_sizes[a] = 0;
            }
        }
    }

    unsigned long long get_max(long m) {
        std::sort(root_sizes, root_sizes+100001, std::greater<unsigned long long>());
        unsigned long long total = 0;
        unsigned long long last = 0;
        for (int i = 0; i < 100001 && root_sizes[i] > 0; ++i) {
            unsigned long long n = root_sizes[i]-1;
            unsigned long long temp = (n*(n+1)*(2*n+1))/6 + (n*n + n)/2;
            total += n*last + temp;
            m -= n;
            last += n*(n+1);
        }
        return total+(last*m);
    }
};

int main() {

    int q; std::scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        long n,m; std::scanf("%ld %ld", &n, &m);

        EqCl eq_cl;
        for (long j = 0; j < m; ++j) {
            int a,b; std::scanf("%d %d", &a, &b);
            eq_cl.add_singleton(a);
            eq_cl.add_singleton(b);
            eq_cl.merge(a,b);
        }
        std::printf("%llu\n", eq_cl.get_max(m));
    }
    return 0;
}
