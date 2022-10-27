#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int getPowOfTwo(int n) {

	for (int i = (int)log2(n); i >= 0; i--) {
		//std::cout << i << '\n';
		if (n % (1 << i) == 0)
			return i;
	}
	return 0;
}

void solve() {
    
    int n, cnt = 0;
    std::cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
    	std::cin >> a;
    	cnt += getPowOfTwo(a);
    }

    int ans = 0;
    std::vector<int> pw(n, 0);
    for (int i = 1; i <= n; i++)
    	pw[i - 1] = getPowOfTwo(i);
    std::sort(pw.begin(), pw.end());
    std::reverse(pw.begin(), pw.end());
    for (int i = 0; i < n; i++) {
    	if (cnt >= n) {
    		std::cout << ans << '\n';
    		return;
    	}
    	ans++;
    	cnt += pw[i];
    }
    if (cnt >= n) {
		std::cout << ans << '\n';
		return;
	}

    std::cout << -1 << '\n';
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