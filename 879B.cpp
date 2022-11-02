#include <iostream>
#include <vector>
#include <queue>

using ll = long long;

void solve() {
    
    int n;
    ll k;
    std::cin >> n >> k;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++)
    	std::cin >> a[i];

    int p = a[0];
    ll cur = 0;

    for (int i = 1; i < n; i++) {

    	if (a[i] < p) cur++;
    	else {
    		cur = 1;
    		p = a[i];
    	}
    	if (cur >= k)
    		break;
    }

    std::cout << p << '\n';
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