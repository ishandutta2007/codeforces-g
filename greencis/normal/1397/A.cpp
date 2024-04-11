#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<int> cnt(256);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (char c : s)
                ++cnt[c];
        }
        int bad = 0;
        for (int x : cnt)
            bad |= x % n;
        cout << (bad ? "NO\n" : "YES\n");
    }
}