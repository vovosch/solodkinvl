#include <iostream>
#include <cmath>

void solve() {

	const double EPS = 1e-3;
	const double PI_4 = acos(-1) / 4;
	const int INF = 1e9;

	double s = 0;
	double a = 0;
	double b = 1;
	double delta = 0.01;
	double tmp;
	double y;

	for (double x = a; x - b < delta / 10; x += delta) {

		std::cout << x << " ";

		for (int i = 0; i < INF; i++) {
			
			tmp = std::pow(x, i) * sin(i * PI_4);
			if (tmp < EPS)
				break;
			s += tmp;
		}
		y = (x * sin(PI_4)) / (1 - 2 * x * cos(PI_4));
		std::cout << s << " " << y << '\n';
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