#include <bits/stdc++.h>
 
#define f first
#define s second
#define _ << " " <<
 
using namespace std;
using ll = long long;
using ld = long double;
using pInt = pair<int, int>;
 
void solve() {
 
    int n, k;
    cin >> n;
    string s;
    cin >> s;
    cin >> k;
    set<char> a;
    for (int i = 0; i < k; i++) {
        char tmp;
        cin >> tmp;
        a.insert(tmp);
    }
 
    int ans = 0;
    int prv = 0;
 
    for (int i = 0; i < n; i++) {
        if (a.count(s[i])) {
            ans = max(ans, i - prv);
            prv = i;
        }
    }
 
    cout << ans << '\n';
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
