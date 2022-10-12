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
    
    cout << (n / 2) * 2 + (n / 3) * 2 + n << endl;
}
 
int main() {
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
