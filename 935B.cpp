#include <iostream>
#include <string>

void solve() {
    
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int i = 0;
    int j = 0;
    int f = 1;
    int ans = 0;

    for (auto m : s) {

    	if (m == 'U')
    		i++;
    	else
    		j++;

    	if ((f && i > j) || (!f && i < j)) {
    		ans++;
    	}
    	if (i != j)
    		f = (i < j);

    	//std::cout << m << '\n';
    }

    std::cout << ans - (s[0] == 'U');
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