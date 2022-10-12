#include <bits/stdc++.h>
 
#define f first
#define s second
#define _ << " " <<
 
using namespace std;
using ll = long long;
using ld = long double;
using pInt = pair<int, int>;
 
void solve() {
    
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
 
    if ((sx - d <= 1 || sy + d >= m) && (sy - d <= 1 || sx + d >= n)) {
        cout << -1 << '\n';
        return;
    }
 
    cout << (n - 1) + (m - 1) << '\n';
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