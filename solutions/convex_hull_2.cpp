#include <bits/stdc++.h>

typedef long long ll;

const int MAX_N = 1e5;

struct Point {
	ll x,y;
};

struct RadPoint {
	double r, theta;
	Point cartesian;
};

struct Compare {
	bool operator() (const RadPoint& a, const RadPoint& b) const {
		if (a.theta == b.theta) {
			return a.r < b.r;
		} else {
			return a.theta < b.theta;
		}
	}
};

struct Compare2 {
	bool operator() (const RadPoint& a, const RadPoint& b) const {
		return a.r > b.r;
	}
};

double dist(const Point& a, const Point& b) {
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;

	return std::sqrt(dx*dx + dy*dy);
}

double angle(const Point& axis, const Point& b) {
	ll dx = b.x - axis.x;
	ll dy = axis.y - b.y;

	return std::atan2(dx,dy);
}
	

int N, n;
Point points[MAX_N];
RadPoint rpoints[MAX_N];

int main() {


	std::scanf("%d", &N);
	int n = 0;
	int min_i = -1;
	while (N--) {
		char c;
		ll x, y;
		std::scanf("%lld %lld %c", &x, &y, &c);
		if (c == 'Y') {
			if (min_i < 0 || x < points[min_i].x || (x==points[min_i].x && y < points[min_i].y)) {
				min_i = n;
			}
			points[n++] = {x,y};
		}
	}


	if (n == 0) {
		std::printf("0\n");
		return 0;
	}

	Point& ref = points[min_i];
	int I = 0;
	for (int i = 0; i < n; ++i) if (i != min_i) {
		double r = dist(ref, points[i]);
		double theta = angle(ref, points[i]);
		rpoints[I++] = {r, theta, points[i]};
	}

	std::sort(rpoints, rpoints+I, Compare());

	int last = -1;
	std::queue<int> queue;
	queue.push(0);
	for (int i = 1; i < I; ++i) {
		if (std::abs(rpoints[queue.back()].theta - rpoints[i].theta) < 0.000001) {
			queue.push(i);
		} else if (queue.size() > 1) {
			if (last < -1 || rpoints[last].r < rpoints[queue.front()].r) {
				last = queue.back();
				while(!queue.empty()) {queue.pop();}
				queue.push(i);
				continue;	// should already be sorted correctly
			} else {
				last = queue.back();
				std::sort(rpoints + queue.front(), rpoints + i, Compare2());
				while (!queue.empty()) {queue.pop();}
				queue.push(i);
			}
		} else {
			last = queue.front();
			queue.pop();
			queue.push(i);
		}
	}


	if (queue.size() > 1) {
		if (last < -1 || rpoints[last].r < rpoints[queue.front()].r) {
			last = queue.back();
			while(!queue.empty()) {queue.pop();}
		} else {
			last = queue.back();
			std::sort(rpoints + queue.front(), rpoints + I, Compare2());
			while (!queue.empty()) {queue.pop();}
		}
	}

		

	std::printf("%d\n", n);
	std::printf("%lld %lld\n", ref.x, ref.y);
	for (int i = 0; i < I; ++i) {
		RadPoint& temp = rpoints[i];
		std::printf("%lld %lld\n", temp.cartesian.x, temp.cartesian.y);
	}




	return 0;
}
