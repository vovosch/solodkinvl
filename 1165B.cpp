#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++)
    	std::cin >> a[i];

    std::sort(a.begin(), a.end());
    int ans = 0;
    int k = 1;
    for (int i = 0; i < n; i++) {
    	if (k <= a[i]) {
    		ans++;
    		k++;
    	}
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