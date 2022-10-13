#include <iostream>
#include <vector>
#include <set>

void solve() {
    
    int n;
    int cnt = 0;
    bool f = 0;
    std::cin >> n;
    std::vector<int> a(n);
    std::set<int> s;
    std::set<int> prvs;
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    	cnt += (a[i] == 0);
    	if (!f) {
	    	s.insert(a[i]);
	    	if (s.size() == prvs.size())
	    		f = 1;
	    	prvs = s;
	    }
    }

    if (cnt) {

    	std::cout << n - cnt << '\n';
    	return;
    }

    if (f)
    	std::cout << n << '\n';
    else
    	std::cout << n + 1 << '\n';

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