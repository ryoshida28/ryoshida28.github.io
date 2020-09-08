#include <bits/stdc++.h>

#include <cmath>

typedef std::pair<double, double> PolCoord; // theta, r

const double PI = std::acos(-1);

struct Compare {
    bool operator() (const PolCoord& a, const PolCoord& b) const {
        return a.first < b.first;
    }
};

double distance(unsigned long x, unsigned long y) {
    return std::sqrt(x*x + y*y);
}

/**
 * phi - angle between coordinate and apothem
 * r - distance of coordinate from origin
 */
double calcApothem(double phi, double r) {
    // std::printf("r=%f\n",r);
    return r*std::cos(phi);
}

double calc(const std::vector<PolCoord>& coords, int n) {
    double omega = PI/n;    // Half-angle between each triangle
    double theta = 2*omega; // Angle between each triangle
    double cumAngle = theta;
    int cursor = 0;
    double max_apothem=0, min_apothem=std::numeric_limits<double>::max();
    for (int i = 0; i < n; ++i) {
        while (cursor < coords.size() && coords[cursor].first <= cumAngle) {
            double phi = std::abs(coords[cursor].first - (cumAngle-omega));
            double apothem = calcApothem(phi, coords[cursor].second);
            // std::printf("calculated apothem = %f\n", apothem);

            max_apothem = std::max(max_apothem, apothem);
            min_apothem = std::min(min_apothem, apothem);
            ++cursor;
        }
        cumAngle += theta;
    }

    // std::printf("%f %f\n", min_apothem, max_apothem);

    // double maxS = 2*max_apothem*std::tan(omega);
    // double minS = 2*min_apothem*std::tan(omega);

    // double maxArea = n*max_apothem*max_apothem*std::tan(omega);
    // double minArea = n*min_apothem*min_apothem*std::tan(omega);
    // return (min_apothem*min_apothem)/(max_apothem*max_apothem);

    return (min_apothem/max_apothem)*(min_apothem/max_apothem);
}

int main() {
    std::vector<PolCoord> coords;
    coords.reserve(1000);

    int n; std::scanf("%d", &n);
    while (n--) {
        int x,y; std::scanf("%d %d", &x, &y);

        double theta = std::atan2(y,x);
        coords.push_back({(theta < 0 ? 2*PI + theta : theta), distance(x,y)});
    }

    std::sort(coords.begin(), coords.end(), Compare());

    double maxScore = 0;
    int answer = 3;
    for (int nsides = 3; nsides <= 8; ++nsides) {
        double score = calc(coords, nsides);
        if (score > maxScore) {
            answer = nsides;
            maxScore = score;
        }
    }

    std::printf("%d %f\n", answer, maxScore);

    return 0;
}