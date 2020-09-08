#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<ll,ll> Vector;


ll dotProduct(const Vector& u, const Vector& v) {
	return u.first*v.first + u.second*v.second;
}

Vector subtract(const Vector& u, const Vector& v) {
	return {u.first - v.first, u.second-v.second};
}

int main() {


	int x1,y1; std::scanf("%d %d", &x1, &y1);
	int x2,y2; std::scanf("%d %d", &x2, &y2);
	int x3,y3; std::scanf("%d %d", &x3, &y3);

	Vector v1({x2-x1,y2-y1});
	Vector v2({x3-x2,y3-y2});
	Vector v3({x1-x3,y1-y3});

	if (dotProduct(v1,v2) == 0) {
		// p2 is the pivot
		Vector answer = subtract({x3,y3}, v1);
		std::printf("%lld %lld\n", answer.first, answer.second);
	} else if (dotProduct(v2,v3) == 0) {
		// p3 is the pivot
		Vector answer = subtract({x1,y1}, v2);
		std::printf("%lld %lld\n", answer.first, answer.second);
	} else {
		Vector answer = subtract({x2,y2}, v3);
		std::printf("%lld %lld\n", answer.first, answer.second);
	}

	return 0;
}

