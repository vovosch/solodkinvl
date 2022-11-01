#include <iostream>

void solve() {
    
    int ans[4][4] = {{1, 0, 0, 1},
					 {0, 1, 1, 0},
					 {0, 1, 1, 0},
					 {1, 0, 0, 1}};

	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			std::cout << ans[i % 4][j % 4] << " ";
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