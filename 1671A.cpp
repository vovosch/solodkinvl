#include <iostream>
#include <string>

void solve() {

	std::string s;
	std::cin >> s;
	for (int i = 0; i < s.size(); i++) {
        if ((i == 0 || s[i] != s[i - 1]) && (i == s.size() - 1 || s[i] != s[i + 1])) {
        	std::cout << "NO" << '\n';
        	return;
        }
	}
    std::cout << "YES" << '\n';
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