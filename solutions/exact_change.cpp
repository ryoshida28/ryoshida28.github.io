#include <bits/stdc++.h>

const int MAX_PRICE = 20002;
const int MAX_NUM_COINS = 100;

int memo[MAX_PRICE];

int main() {
    
    int tc; std::scanf("%d", &tc);

    while(tc--) {
        memset(memo, -1, sizeof(memo));
        int price; std::scanf("%d", &price);
        int n; std::scanf("%d", &n);
        std::vector<int> coins(n);
        for (int i = 0; i < n; ++i) {
            std::scanf("%d", &coins[i]);
        }
        
        memo[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = price-1; j >= 0; --j) {
                if (memo[j] == -1) continue;
                if (memo[j+coins[i]] == -1 || memo[j+coins[i]] > memo[j] + 1) memo[j+coins[i]] = memo[j] + 1;
            }
        }

        int i = price;
        for (; memo[i] == -1; ++i);


        std::printf("%d %d\n", i, memo[i]);
    }

    return 0;
}