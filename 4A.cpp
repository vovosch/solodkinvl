#include <bits/stdc++.h>
 
#define f first
#define s second
#define _ << " " <<
 
using namespace std;
using ll = long long;
using ld = long double;
using pInt = pair<int, int>;
 
 
void solve() {
    
    int w;
    cin >> w;
 
    if (w == 2 || w % 2)
        cout << "NO";
    else
        cout << "YES";
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