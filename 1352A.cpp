#include <bits/stdc++.h>
 
#define f first
#define s second
#define _ << " " <<
 
using namespace std;
using ll = long long;
using ld = long double;
using pInt = pair<int, int>;
 
 
void solve() {
    
    string s;
    cin >> s;
    int n = s.size(), cnt = 0;
    vector<string> a;
 
    for (int i = 0; i < n; i++) {
        if (s[i] != '0') {
            a.push_back(s[i] + string(n - 1 - i, '0'));
            cnt++;
        }
    }
 
    cout << cnt << '\n';
    for (auto i : a)
        cout << i << ' ';
    cout << '\n';
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    //freopen("input.in","r",stdin);
 
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}