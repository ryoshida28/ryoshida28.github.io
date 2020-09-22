#include <bits/stdc++.h>

/**
 * If the values of two different bits on opposite ends of the array are known and are different
 * and another two bits on opposite ends of the array are known and the same
 * the type of operation can be determined.
 */


typedef std::bitset<100> Bitset;
typedef std::pair<int,int> KeyPair;


const int DIFF_TYPE_FLIP = 0;	// complement or reverse
const int DIFF_TYPE_SAME = 1;	// same or comp+reverse
const int SAME_TYPE_FLIP = 0;	// complement or comp+reverse
const int SAME_TYPE_SAME = 1;	// same or reverse


void flip(Bitset& set) {
	set.flip();
}

void reverse(Bitset& set, int B) {
	for (int i = 0; i < B/2; ++i) {
		bool a=set[i], b=set[B-i-1];
		set[i] = b;
		set[B-i-1] = a;
	}	
}
	
bool query(int i) {
	std::printf("%d\n", i+1);
	std::fflush(stdout);
	int resp; std::scanf("%d", &resp);
	return resp == 1;
}

int main() {
	int t, B; std::scanf("%d %d", &t, &B);
	for (int tc = 1; tc <= t; ++tc) {
		bool diff_set = false, same_set = false;	// Whether an occurence of that type of pair has occured
		KeyPair diff, same;
		Bitset array;
	
		int i = 0;
		while (i < B-i-1) {
			
			int available_queries = 10;
			int diff_type = -1;
			if (diff_set) {
				bool a = query(diff.first);
				bool a_old = array[diff.first];
				diff_type = a==a_old ? 1 : 0;
				available_queries -= 1;
			}
			int same_type = -1;
			if (same_set) {
				bool a = query(same.first);
				bool a_old = array[same.first];
				same_type = a==a_old ? 1 : 0;
				available_queries -= 1;
			}
	
			if (diff_type >= 0 && same_type >= 0) {
				if (diff_type == 0 && same_type == 0) {
					// Complement
					flip(array);
				} else if (diff_type == 0 && same_type == 1) {
					// Reverse
					reverse(array, B);
				} else if (diff_type == 1 && same_type == 0) {
					// Complement & Reverse
					flip(array);
					reverse(array, B);
				} // else keep the same
			} else if (diff_type >= 0) {
				if (diff_type == 0) {
					flip(array);
				} // keep same
			} else if (same_type >= 0) {
				if (same_type == 0) {
					flip(array);
				} // keep same
			}

	
			while (available_queries > 1 && i < B-i-1) {
				bool a = query(i);
				bool b = query(B-i-1);
	
				if (a == b && !same_set) {
					same = {i, B-i-1};
					same_set = true;
				} else if (a != b && !diff_set) {
					diff = {i, B-i-1};
					diff_set = true;
				}
	
				array[i] = a;
				array[B-i-1] = b;
				++i;
				available_queries -= 2;
			}

			if (available_queries == 1) {
				query(1);
			}
		}

		for (int x = 0; x < B; ++x) {
			std::printf("%c", (array[x] ? '1' : '0'));
		} std::printf("\n");

		std::fflush(stdout);
		char resp; std::cin >> resp;
		if (resp == 'N')
			break;
	}

	return 0;
}
