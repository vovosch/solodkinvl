#include <bits/stdc++.h>
 
#define f first
#define s second
#define _ << " " <<
 
using namespace std;
using ll = long long;
using ld = long double;
using pInt = pair<int, int>;
 
 
void solve() {
    
    int n;
    cin >> n;
 
    int ans = 0;
    if (n >= 5) {
        ans += n / 5;
        n %= 5;
    }
    if (n >= 4) {
        ans += n / 4;
        n %= 4;
    }
    if (n >= 3) {
        ans += n / 3;
        n %= 3;
    }
    if (n >= 2) {
        ans += n / 2;
        n %= 2;
    }
    ans += n;
 
    cout << ans;
}
 
int main() {
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