#include <iostream>
#include <vector>

void solve() {
    
    int n;
    std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    	std::cin >> a[i];

    int ans = 1 + (a[0] == 1);
    for (int i = 1; i < n; i++) {

    	if (a[i - 1] == 0 && a[i] == 0) {
    		ans = -1;
    		break;
    	}
    	if(a[i] == 0)
    		continue;
    	ans += (a[i] == 1 && a[i - 1] == 1) ? 5:1;
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