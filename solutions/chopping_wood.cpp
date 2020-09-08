#include <bits/stdc++.h>


int main() {

	int N; std::scanf("%d", &N);

	std::set<int, std::greater<int>> available;
	std::set<int> leaves;
	std::vector<int> V(N);

	available.insert(N+1);
	for (int i = 0; i < N; ++i) {
		available.insert(i+1);
		int v;
		std::scanf("%d", &v);
		V[i] = v;
	}

	available.erase(V[N-1]);
	leaves.insert(V[N-1]);
	std::vector<int> answer(N);
	bool failed = false;
	for (int i = N-1; i >= 0; --i) {
		if (i == 0) {
			auto last = available.begin();
			// should be guarenteed to be in the set
			leaves.erase(V[i]);

			if (*last < *(leaves.begin())) {
				// all good
				answer[i] = *last;
				available.erase(last);
			} else {
				failed = true;
				break;
			}
		} else if (V[i] != V[i-1]) {
			if (available.count(V[i-1])) {
				// Must add V[i-1]
				if (i != N-1)
					leaves.erase(V[i]);

				if (V[i-1] < *(leaves.begin())) {
					// all good
					leaves.insert(V[i-1]);
					answer[i] = V[i-1];
					available.erase(V[i-1]);
				} else {
					failed = true;
					break;
				}
			} else {
				// Greedily add highest available number
				leaves.erase(V[i]);
				auto new_leaf = available.upper_bound(*leaves.begin());
				if (new_leaf == available.end()) {
					failed = true;
					break;
				} else {
					leaves.insert(*new_leaf);
					answer[i] = *new_leaf;
					available.erase(new_leaf);
				}
			}
		} else {
			// Greedily add highest available number
			leaves.erase(V[i]);
			auto new_leaf = available.upper_bound(*leaves.begin());
			if (new_leaf == available.end()) {
				failed = true;
				break;
			} else {
				leaves.insert(*new_leaf);
				answer[i] = *new_leaf;
				available.erase(new_leaf);
			}
		}
	}


	if (failed) {
		std::printf("Error\n");
	} else {
		for (int i = 0; i < N; ++i) {
			std::printf("%d\n", answer[i]);
		}
	}
					
	return 0;
}
