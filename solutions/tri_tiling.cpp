#include <bits/stdc++.h>

long tile_odd(int from, int w);
long tile_2(int from, int w);


long tile_odd(int from, int w) {
    if (from == w) {
        return 0;
    } else if (from == w-2) {
        return 1;
    } else {
        return tile_2(from+2,w) + tile_odd(from+2,w);
    }
}

long tile_2(int from, int w) {
    if (from == w) {
        return 0;
    } else if (from == w-2) {
        return 3;
    } else {
        return 3*(tile_2(from+2, w)) + 2*tile_odd(from+2, w);
    }
}

long tile(int w) {
    if (w%2 == 1) {
        return 0;
    } else if (w == 0) {
        return 1;
    }

    return tile_2(0,w);
}


int main() {

    int i;
    std::cin >> i;
    while (i != -1) {

        std::cout << tile(i) << std::endl;

        std::cin >> i;
    }

    return 0;
}