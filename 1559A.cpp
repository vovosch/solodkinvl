#include <iostream>

void solve() {
    
    int n;
    int x;
    int a;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
    	
    	std::cin >> a;
    	if (i == 0) x = a;
    	x &= a;
    }

    std::cout << x << '\n';
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