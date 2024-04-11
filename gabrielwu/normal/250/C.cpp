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

	int k, n;
	cin >> n >> k;
	vector<int> v(n);
	forn(i, n){
		cin >> v[i];
		v[i]--;
	}

	int bef = -1;
	vector<int> u;
	// cout << v << "\n";
	forn(i, n) {
		if(v[i] != bef) {
			u.pb(v[i]);
		}
		bef = v[i];
	}
	// cout << u << "\n";

	vector<int> cnt(k);
	cnt[u[0]]++;
	cnt[u.back()]++;
	n = u.size();
	for(int i=1; i<n-1; i++) {
		if(u[i-1] == u[i+1]) {
			cnt[u[i]]+=2;
		} else {
			cnt[u[i]]++;
		}
	}

	pii best = mp(-1,-1);
	forn(i, k) {
		ckmax(best, mp(cnt[i], -i));
	}

	cout << -best.s + 1 << "\n";
}