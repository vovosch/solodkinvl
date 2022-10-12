#include <bits/stdc++.h>
 
#define f first
#define s second
#define _ << " " <<
 
using namespace std;
using ll = long long;
using ld = long double;
using pInt = pair<int, int>;
 
void solve() {
 
    int a, b, q = 0;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.size();
 
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == '0') {
            if (s[n - 1 - i] == '1') {
                cout << -1 << '\n';
                return;
            }
            if (s[n - 1 - i] == '?')
                s[n - 1 - i] = '0';
            a -= 2;
        }
        else if (s[i] == '1') {
            if (s[n - 1 - i] == '0') {
                cout << -1 << '\n';
                return;
            }
            if (s[n - 1 - i] == '?')
                s[n - 1 - i] = '1';
            b -= 2;
        }
        if (s[i] == '?') {
            if (s[n - 1 - i] != '?') {
                s[i] = s[n - 1 - i];
                if (s[i] == '0')
                    a -= 2;
                else
                    b -= 2;
            }
            else
                q += 2;
        }
    }
    bool f = false;
    if (n % 2) {
        if (s[n / 2] == '0')
            a--;
        else if(s[n / 2] == '1')
            b--;
        else {
            q++;
            f = true;
        }
    }
    //cout << a _ b _ q << endl;
    if ((a < 0 || b < 0 || a + b != q) || (f && a % 2 == 0 && b % 2 == 0) || (a % 2 && b % 2) ||
        (!f && (a % 2 || b % 2))) {
        cout << -1 << '\n';
        return;
    }
 
    if (f) {
        s[n / 2] = (a % 2 ? '0' : '1');
        if (a % 2)
            a--;
        else
            b--;
    }
 
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == '?') {
            if (a > 0) {
                s[i] = s[n - 1 - i] = '0';
                a -= 2;
            }
            else {
                s[i] = s[n - 1 - i] = '1';
                b -= 2;
            }
        }
    }
 
    cout << s << '\n';
 
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