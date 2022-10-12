#include <iostream>
#include <cmath>
#include <iomanip>

void solve() {

	const double EPS = 1e-3;
	const double PI_4 = acos(-1) / 4;
	const double SIN_PI_4 = sin(PI_4);
	const double COS_PI_4 = cos(PI_4);
	const int INF = 1e9;
	const double SIN[4] = {0, SIN_PI_4, 1, -SIN_PI_4};

	double s = 0;
	double a = 0;
	double b = 1;
	double delta = 0.05;
	double tmp;
	double y;

	std::cout << std::fixed << std::setprecision(6);

	for (double x = a; x < b + delta; x += delta) {

		std::cout << x << '\t';
		s = 0;
		double curX = x;

		for (int i = 1; i < INF; i++) {
			
			tmp = curX * sin(i * PI_4);
			//std::cout << tmp << '\n';
			if (std::abs(tmp) < EPS && i % 4 != 0)
				break;
			s += tmp;
			curX *= x;
		}
		y = (x * SIN_PI_4) / (1 - 2 * x * COS_PI_4);
		std::cout << s << '\t' << y << '\n';
	}
}

int main() {

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    freopen("input.in", "r", stdin);

    int t = 1;
    //std::cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}