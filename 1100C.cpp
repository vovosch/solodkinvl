#include <bits/stdc++.h>
 
#define f first
#define s second
#define _ << " " <<
 
using namespace std;
using ll = long long;
using ld = long double;
using pInt = pair<int, int>;
 
const double PI = acos(-1);
 
void solve() {
 
    int n, r;
    cin >> n >> r;
 
    double a = PI / n;
    double x = sin(a);
 
    cout << setprecision(9) << r * x / (1 - x);
}
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    //freopen("input.in", "r", stdin);
 
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
