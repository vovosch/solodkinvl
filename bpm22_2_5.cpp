#include <iostream>
#include <vector>

#define f first
#define s second

void solve() {

    std::vector<int> a;
    int tmp;
    while (std::cin >> tmp) { a.push_back(tmp); }
    int n = a.size();
    	
    a.push_back((int)1e9);

    int b = 0;
    std::vector<std::pair<int, int> > ans;
    for (int i = 0; i < n + 1; i++) {
    	if (a[i] <= a[i + 1]){

    		//std::cout << a[i] << " " << a[i + 1] << '\n';
    		
    		if (b != i)
    			ans.push_back(std::make_pair(b, i));
    		b = i + 1;
    	}
    }


    std::cout << ans.size() << '\n';
   	for (auto i : ans) {
   		std::cout << i.f << " " << i.s << '\n';
   	}
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