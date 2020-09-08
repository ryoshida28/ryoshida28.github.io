#include <bits/stdc++.h>

const int BASE = 65;
const int WIDTH = 26;

int main() {

	std::string crypt,key;
	std::cin >> crypt >> key;

	std::string decrypt;

	for (int i = 0; i < crypt.length(); ++i) {
		int a = crypt[i] - BASE;
		int b = key[i] - BASE;

		if (i%2==0) {
			// Move backwards
			int c = (a-b+WIDTH)%WIDTH;
			char d = (c+BASE);
			decrypt += d;
		} else {
			// Move forwards
			int c = (a+b)%WIDTH;
			char d = (c+BASE);
			decrypt += d;
		}
	}
	std::cout << decrypt << std::endl;

	return 0;
}
