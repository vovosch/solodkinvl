#include <iostream>
#include <string>
#include <vector>

void solve() {
    
    int n;
    std::cin >> n;
    std::vector<std::string> a;
    std::string s = "";
    char tmp;

    for (int i = 0; i < n; i++) {
    	std::cin >> tmp;
    	if (tmp == 'W' && s.size()) {
    		a.push_back(s);
    		s = "";
    	}
    	else if (tmp != 'W')
    		s += tmp;
    }
    if (s.size())
    	a.push_back(s);
    if (!a.size()) {
    	std::cout << "YES" << '\n';
    	return;
    }

    for (auto str : a) {
    	int blue = 0;
    	int red = 0;
    	for (int i = 0; i < str.size(); i++) {
    		blue += (str[i] == 'B');
    		red += (str[i] == 'R');
    	}
    	if (!blue || !red) {
    		//std::cout << str << '\n';
    		std::cout << "NO" << '\n';
    		return;
    	}
    }
    std::cout << "YES" << '\n';	
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