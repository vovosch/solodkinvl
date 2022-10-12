#include <iostream>

void solve() {
    
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < i + 1; j++) {
    		std::cout << (j == 0 || i == j) ? 1:0;
    		std::cout << " ";
    	}
    	std::cout << '\n';
    }
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