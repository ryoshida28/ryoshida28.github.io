#include <bits/stdc++.h>


struct Drink {
	std::string name;
	int cost;
	int units;
};


int main() {

	int m1,m2,u1,u2,d; std::scanf("%d.%d %d.%d %d", &m1, &m2, &u1, &u2, &d);

	int max_money = m1*100 + m2;
	int max_units = (u1*10 + u2)*6;

	std::vector<std::vector<int>> dp(max_money+1, std::vector<int>(max_units+1, -1));
	std::vector<Drink> drinks(d);
	for (int i = 0; i < d; ++i) {
		std::string name;
		int strength, size, cost1, cost2;
		std::cin >> name;
		std::scanf("%d 1/%d %d.%d", &strength, &size, &cost1, &cost2);

		int cost  = cost1*100 + cost2;
		int units = (6/size)*strength*10;
		drinks[i] = {name, cost, units};

		// Initialize to dp table
		if (units <= max_units && cost <= max_money) {
			dp[cost][units] = i;
		}

	}

	for (int i = 0; i <= max_money; ++i) {
		for (int j = 0; j <= max_units; ++j) if (dp[i][j] >= 0) {
			for (int k = 0; k < d; ++k) {
				Drink& d = drinks[k];
				int new_cost = d.cost + i;
				int new_units = d.units + j;
				if (new_cost <= max_money && new_units <= max_units) {
					dp[new_cost][new_units] = k;
				}
			}
		}
	}

	if  (dp[max_money][max_units] < 0) {
		std::printf("IMPOSSIBLE\n");
	} else {
		int cur_cost = max_money;
		int cur_units = max_units;
		std::vector<int> counts(d);
		while (cur_cost != 0 && cur_units != 0) {
			int drink = dp[cur_cost][cur_units];
			counts[drink] += 1;
			cur_cost -= drinks[drink].cost;
			cur_units -= drinks[drink].units;
		}

		for (int i = 0; i < d; ++i) {
			if (counts[i]) {
				std::cout << drinks[i].name << ' ' << counts[i] << std::endl;
			}
		}
	}
			


	return 0;
}
