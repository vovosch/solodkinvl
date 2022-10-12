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
    cin >> n >> k;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?' && s[i % k] != '?' && s[i] != s[i % k]) {
            cout << "NO" << '\n';
            return;
        }
        if (s[i] != '?') 
            s[i % k] = s[i];
    }
    //cout << s << endl;
    for (int i = 0; i < k; i++) {
        a += (s[i] == '0');
        b += (s[i] == '1');
    }
    //cout << a _ b << endl;
    if (a > k / 2 || b > k / 2) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
 
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