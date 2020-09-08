#include <bits/stdc++.h>

typedef unsigned long long ull;
const int MAX_N = 2e5;
const ull mod = 1e9 + 7;

ull dp[3][MAX_N+1] = {0};
ull ways[3] = {0};

int N;
ull L,R;

int main() {

	std::scanf("%d %llu %llu", &N, &L, &R);

	dp[0][0] = 1;
	ways[0] = (R+3)/3 - (L+2)/3;
	ways[1] = (R+2)/3 - (L+1)/3;
	ways[2] = (R+1)/3 - L/3;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				dp[(j+k)%3][i+1] = (dp[(j+k)%3][i+1] + (dp[j][i] * ways[k])%mod)%mod;
			}
		}
	}

	std::printf("%llu\n", dp[0][N]);


	return 0;
}
