#include <iostream>

void solve() {
    
    int n;
    std::cin >> n;
    int x1, y1;
    int x2 = 0, y2 = 0;

    char s;

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {

    		std::cin >> s;
    		if (s == '*') {
    			x1 = x2;
    			y1 = y2;
    			x2 = i;
    			y2 = j;
    		}
    	}
    }

    if (x1 == x2) {
    	if (x1 == n - 1)
    		x1--;
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			if ((x1 == i || x1 + 1 == i) && (y1 == j || y2 == j))
    				std::cout << '*';
    			else
    				std::cout << '.';
    		}
    	    std::cout << '\n';
    	}
    }
    else if (y1 == y2) {
    	if (y1 == n - 1)
    		y1--;
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			if ((y1 == j || y1 + 1 == j) && (x1 == i || x2 == i))
    				std::cout << '*';
    			else
    				std::cout << '.';
    		}
    		std::cout << '\n';
    	}
    }
    else {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			if ((x1 == i || x2 == i) && (y1 == j || y2 == j))
    				std::cout << '*';
    			else
    				std::cout << '.';
    		}
    		std::cout << '\n';
    	}
    }
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