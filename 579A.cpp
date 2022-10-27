#include <iostream>

void solve() {
    
    int n;
    std::cin >> n;
    int ans = 0;
    while (n > 0) {
    	ans += (n & 1);
    	n = n >> 1;
    }
    std::cout << ans << '\n';
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