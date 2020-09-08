#include <bits/stdc++.h>

int main () {
    int n; std::cin >> n;
    std::string s; std::cin >> s;

    if (n%2 == 1 || s[0] == ')' || s[n-1] == '(') {
        std::cout << ":(" << std::endl;
        return 0;
    }

    s[0] = '(';
    s[n-1] = ')';

    int l=0, r=0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++l;
        } else if (s[i] == ')') {
            ++r;
        }
    }

    int a = n/2 - l;
    int b = n/2 - r;

    int count = 1;
    for (int i = 1; i < n-1; ++i) {
        if (count == 0) {
            std::cout << ":(" << std::endl;
            return 0;
        }

        if (s[i] == '(') {
            ++count;
        } else if (s[i] == ')') {
            --count;
        } else {
            if (a == 0) {
                s[i] = ')';
                --b;
                --count;
            } else {
                s[i] = '(';
                --a;
                ++count;
            }
        }
    }

    if (count == 1) {
        s[n-1] = ')';
        std::cout << s << std::endl;
    } else {
        std::cout << ":(" << std::endl;
    }

    return 0;
}