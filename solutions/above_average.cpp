#include <bits/stdc++.h>


int main() {

    int c; std::cin >> c;
    std::cout << std::fixed << std::setprecision(3);

    for (int i = 0; i < c; ++i) {
        int n; std::cin >> n;
        int sum = 0;
        std::vector<int> grades;
        for (int j = 0; j < n; ++j) {
            int val; std::cin >> val;
            sum += val;
            grades.push_back(val);
        }

        float average = sum/((float) n);

        int count = 0;
        for (int g : grades) {
            if (g > average) {
                ++count;
            }
        }
        float above_avg = 100*count/((float) n);
        std::cout << above_avg << '%' << std::endl;
        
    }
    return 0;
}