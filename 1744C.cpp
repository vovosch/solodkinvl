#include <iostream>
#include <string>

void solve() {

	int n;
	char cur;
	std::cin >> n >> cur;
	std::string s;
	std::cin >> s;
	s += s;
	int f = 0;
	int ind = 0;
	int ans = 0;

	for (int i = 0; i < 2 * n; i++) {

		if (!f && i >= n)
			break;

		if (s[i] == cur && !f) {
			f = 1;
			ind = i;
		}
		if (s[i] == 'g' && f) {

			f = 0;
			ans = std::max(ans, i - ind);
		}
	}
	std::cout << ans << '\n';
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