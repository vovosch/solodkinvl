#include <iostream>
#include <vector>

void solve() {
    
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char> > a(n, std::vector<char>(m));
    int x = n, y = m;

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		std::cin >> a[i][j];
    		if (a[i][j] == 'R') {
    			x = std::min(x, i);
    			y = std::min(y, j);
    		}
    	}
    }

    if (a[x][y] == 'R')
    	std::cout << "YES";
    else
    	std::cout << "NO";
    std::cout << '\n';
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