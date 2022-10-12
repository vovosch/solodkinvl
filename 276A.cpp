#include <bits/stdc++.h>
 
#define f first
#define s second
#define _ << " " <<
 
using namespace std;
using ll = long long;
using ld = long double;
using pInt = pair<int, int>;
 
 
void solve() {
    
    int n, k, ans = -1e9;
    cin >> n >> k;
    int f, t;
    for (int i = 0; i < n; i++) {
        cin >> f >> t;
        if (t > k)
            ans = max(ans, f - t + k);
        else
            ans = max(ans, f);
    }
    cout << ans;
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    //freopen("input.in","r",stdin);
 
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
