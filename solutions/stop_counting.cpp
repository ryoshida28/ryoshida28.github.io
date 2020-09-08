#include <bits/stdc++.h>


int main() {
    
    long n; std::cin >> n;

    std::vector<long> vals(n);

    for (long i = 0; i < n; ++i) {
        long v; std::cin >> v;
        vals[i] = v;
    }

    std::vector<long> l_sums(n);
    std::vector<long> r_sums(n);
    for (long i = 0; i < n; ++i) {
        l_sums[i] = vals[i] + (i==0 ? 0 : l_sums[i-1]);
        r_sums[i] = vals[n-i-1] + (i==0 ? 0 : r_sums[i-1]);
    }

    long double max_l=0, max_r=0;
    for (long i = 0; i < n; ++i) {
        max_l = std::max(max_l, ((long double) l_sums[i])/(i+1));
        max_r = std::max(max_r, ((long double) r_sums[i])/(i+1));
    }
    
    std::cout.precision(10);
    std::cout << std::max(std::max(max_l, max_r), (long double) 0.0) << std::endl;

    return 0;
}