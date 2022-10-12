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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b;
    string s;
    for (int j = 0; j < n; j++) { 
        cin >> b >> s;
        for (char i : s) {
            if (i == 'U')
                a[j] = 0 == a[j] ? 9 : a[j] - 1;
            else
                a[j] = 9 == a[j] ? 0 : a[j] + 1;
        }
        cout << a[j] << ' ';
    }
    cout << '\n';
 
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
