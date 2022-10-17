#include <iostream>

void solve() {
    
    int n, k, a;
    std::cin >> n >> k;
    int ans = 1e9;
    
    for (int i = 0; i < n; i++) {
    	std::cin >> a;
    	if (k % a == 0)
    		ans = std::min(ans, k / a);
    }
    std::cout << ans;
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