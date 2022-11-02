#include <iostream>
#include <vector>

void solve() {
    
    int n;
    std::cin >> n;
    std::vector<int> p(n);

    for (int i= 0; i < n; i++)
    	std::cin >> p[i];

    for (int j = 1; j < n - 1; j++) {
    	if (p[j - 1] < p[j] && p[j] > p[j + 1]) {
    		std::cout << "yes" << '\n';
    		std::cout << j << " " << j + 1 << " " << j + 2 << '\n';
    		return;
    	}
    }
    std::cout << "no" << '\n';
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