#include <bits/stdc++.h>
 
#define f first
#define s second
#define _ << " " <<
 
using namespace std;
using ll = long long;
using ld = long double;
using pInt = pair<int, int>;
 
void solve() {
    
    int n, k, r, c;
    cin >> n >> k >> r >> c;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << ((i + j) % k == (r + c) % k ? 'X':'.');
        cout << '\n';
    }
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