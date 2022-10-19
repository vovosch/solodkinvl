#include <iostream>
#include <string>

void solve() {
    
    std::string s;
    std::cin >> s;
    s += '0';
    if (s[0] == 0) {
    	std::cout << 1 << '\n';
    	return;
    }

    int ind1 = 0;
    int ind0 = s.size() - 1;

    for (int i = 0; i < s.size() - 1; i++) {
    	if (s[i] == '1')
    		ind1 = i;
    	else if (s[i] == '0' && ind0 == s.size() - 1)
    		ind0 = i;
    }

    std::cout << ind0 - ind1 + 1 - (ind0 == s.size() - 1) << '\n';
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