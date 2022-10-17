#include <iostream>

void solve() {

	int a;
	int ones = 0;
	for (int i = 0; i < 4; i++) {
		std::cin >> a;
		ones += (a == 1);
	}
	if (ones == 0) {
		std::cout << 0 << '\n';
		return;
	}
	if (ones < 4) {
		std::cout << 1 << '\n';
		return;
	}
	std::cout << 2 << '\n';
}

int main() {

	std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    freopen("input.in", "r", stdin);

    int t = 1;
    std::cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}