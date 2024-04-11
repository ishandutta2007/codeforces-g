#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t) {
		int n;
		cin >> n;
		vector<int> v(n);
		forn(i, n) cin >> v[i];
		v.pb(-1);

		vector<int> ans;
		int bef = v[0];
		int cnt = 1;
		bool works = true;
		for(int i=1; i<=n; i++) {
			if(v[i] != bef) {
				bef = v[i];
				if(cnt == 1) {
					works = false;
					break;
				}
				ans.pb(i-1);
				for(int j=i-cnt; j<i-1; j++) {
					ans.pb(j);
				}
				cnt = 1;
			} else {
				cnt++;
			}
		}

		// cout << ans << endl;

		if(works) {
			forn(i, n) {
				cout << ans[i]+1 << " ";
			}
			cout << "\n";
		} else {
			cout << -1 << "\n";
		}
	}
}