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
 
    for (int i = n + 1; i <= 9999; i++) {
 
        if (((i % 10) != (i / 10) % 10) && ((i % 10) != (i / 100) % 10) &&
        ((i % 10) != (i / 1000)) && ((i / 10) % 10 != (i / 100) % 10) &&
        ((i / 10) % 10 != (i / 1000)) && ((i / 100) % 10 != i / 1000))
        {
            cout << i;
            return;
        }
    }
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