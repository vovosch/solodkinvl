#include <bits/stdc++.h>
 
#define f first
#define s second
#define _ << " " <<
 
using namespace std;
using ll = long long;
using ld = long double;
using pInt = pair<int, int>;
 
void solve() {
    
    int n, x, a;
    cin >> n >> x;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.insert(a);
    }
 
    int v = 0;
    while (x >= 0) {
        v++;
        if (s.count(v))
            continue;;
        x--;
    }
 
    cout << v - 1 << '\n';
 
}
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    //freopen("input.in", "r", stdin);
 
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}