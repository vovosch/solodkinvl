#include <iostream>
#include <vector>

void solve() {
    
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1, 0);
    std::vector<int> b(n + 1, 0);
    std::vector<int> t(n + 1, 0);
    for (int i = 1; i <= n; i++)
    	std::cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++)
    	std::cin >> t[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
    	ans = std::max(ans + (b[i] - a[i] + 1) / 2, b[i]);
    	ans += a[i + 1] - b[i] + t[i + 1];
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