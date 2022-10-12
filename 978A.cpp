#include <bits/stdc++.h>
 
#define f first
#define s second
#define _ << " " <<
 
using namespace std;
using ll = long long;
using ld = long double;
using pInt = pair<int, int>;
 
 
void solve() {
 
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), cnt(1001);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!cnt[a[i]])
            ans++;
        cnt[a[i]]++;
    }
    cout << ans << '\n';
    for (auto i : a) {
        if (cnt[i] == 1)
            cout << i << ' ';
        cnt[i]--;
    }
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