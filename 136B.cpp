#include <iostream>

void solve() {

	int a, c;
	int b = 0;
	int t = 1;
	std::cin >> a >> c;
	
	while (a || c) {

		b += (c % 3 - a % 3 + 3) % 3 * t;
		t *= 3;
		a /= 3;
		c /= 3;
	}
	std::cout << b;
}

int main() {

	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

    freopen("input.in", "r", stdin);

    int t = 1;
    //std::cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}