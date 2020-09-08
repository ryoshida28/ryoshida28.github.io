#include <bits/stdc++.h>

bool is_vowel(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}


int main() {

    std::string s;
    std::cin >> s;

    unsigned long long total = 1;

    for (unsigned int i = 0; i < s.length(); ) {
        unsigned int lookahead = i+1;
        unsigned int count = 0;
        while (lookahead+1 < s.length()) {
            if (!is_vowel(s[i]) && s[lookahead] == 'o' && s[i] == s[lookahead+1]) {
                ++count;
                lookahead += 2;
            } else {
                break;
            }
        }
        if (count == 1) {
            total = (total*2)%1000009;
        } else if (count > 1) {
            int thing = (count+1)/2 + 1;
            total = (total*thing)%1000009;
        }
        i = lookahead;
    }

    std::cout << total << std::endl;

    return 0;
}