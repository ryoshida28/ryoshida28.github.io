#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef std::vector<ull>::iterator Iterator;

int T;
int main() {
	std::scanf("%d", &T);

	while (T--) {
		int N,M; std::scanf("%d %d", &N, &M);

		std::vector<ull> removed(N);
		char* binaryStr = new char[M];	// dont deallocate, will cause runtime error
		for (int i = 0; i < N; ++i) {
			std::scanf("%s\n", binaryStr);
			removed[i] = std::strtoull(binaryStr, nullptr, 2);
		}

		std::sort(removed.begin(), removed.end());



		ull desired_index = ((((ull)1)<<M) - N - 1)/2;
		ull l = 0, h = (((ull)1)<<M);
		while (l < h) {
			ull m = (h-l)/2 + l;

			Iterator it = std::lower_bound(removed.begin(), removed.end(), m);

			ull index = it - removed.begin();

			ull to_the_left = m - index;	// how many are to the left of m

			if (to_the_left == desired_index) {
				if (std::binary_search(removed.begin(), removed.end(), m)) {
					l = m;
					continue;
				}
				l = m;
				break;
			} else if (to_the_left < desired_index) {
				l = m+1;
			} else {
				h = m;
			}
		}

		for (int i = M-1; i >= 0; --i) {
			if (l & (((ull)1)<<i)) {
				std::printf("1");
			} else {
				std::printf("0");
			}
		} std::printf("\n");
	}

	return 0;
}
