#include <iostream>
#include <vector>

void solve() {
    
    int n, k;
    std::cin >> n >> k;
    std::vector<char> a(n);

    for (int i = 0; i < n; i++)
    	std::cin >> a[i];

    int ans = k;
    int cur = 0;
    int i = 0;
    int j = 0;

    while (j < n) {

    	cur += (a[j] == 'W');

    	if (j - i + 1 == k) {
    		//std::cout << i << " " << j << '\n';
    		ans = std::min(ans, cur);
    		cur -= (a[i] == 'W');
    		i++;
    	}
    	j++;
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