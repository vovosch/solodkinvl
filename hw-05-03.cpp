#include <iostream>
#include <cmath>
#include <iomanip>

double fact(int n) {
    return (n == 0) || (n == 1) ? 1:n * fact(n - 1);
}

void solve() {
    
    const double EPS = 1e-4;
	const int INF = 1e9;

	double s = 0;
	double a = 0;
	double b = 1;
	double delta = 0.1;
	double tmp;
	double y;

	std::cout << std::fixed << std::setprecision(6);

	for (double x = 0; x - b < delta / 10; x += delta) {

		std::cout << x << '\t';
		s = 0;

		for (int i = 0; i < INF; i++) {

			tmp = std::pow(2 * x, i) / fact(i);
			if (fabs(tmp) < EPS)
				break;
			s += tmp;
		}
		y = std::pow(exp(1), 2 * x);
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