#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string c;
		cin >> c;
		bool ok = false;
		rep(i,0,sz(s)) {
			if (s[i] == c[0] && i%2 == 0) {
				ok = true;
			}
		}
		puts(ok?"YES":"NO");
	}
}