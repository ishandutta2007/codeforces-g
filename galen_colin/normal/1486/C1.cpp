#include <bits/stdc++.h>
using namespace std;

/* 
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks 
*/
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
// mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;



ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
// string s, t;
ll ans = 0;	

ll query(ll l, ll r) {
	cout << "? " << l + 1 << " " << r + 1 << endl;
	ll x; cin >> x;
	return x - 1;
}

void solve(int tc = 0) {
	cin >> n;
	
	ll p = query(0, n - 1);
	
	ll llv = 0, lrv = p, rlv = p + 1, rrv = n;
	for (ll it = 0; it < 18; it++) {
		ll lmv = (llv + lrv) / 2;
		ll rmv = (rlv + rrv) / 2;
		
		// cout << llv << " " << lrv << " " << rlv << " " << rrv << endl;
		
		lmv = max(0LL, lmv);
		rmv = min(rmv, n - 1);
		ll v = query(lmv, rmv);
		
		if (v == p) {
			if (llv < lrv) llv = lmv + 1;
			if (rlv < rrv) rrv = rmv;
		} else {
			if (llv < lrv) lrv = lmv;
			if (rlv < rrv) rlv = rmv + 1;
		}
	}
	
	llv = max(0LL, llv);
	rlv = min(n - 1, rlv);
	if (llv == rlv || query(llv, rlv) == p) cout << "! " << rlv + 1 << endl;
	else cout << "! " << llv << endl;
}

// two pointers? maybe
// xor tricks (or general bitwise)
// tutorial on my template

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("code");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc.cpp", "w", stdout);
 		
	cout << setprecision(12) << fixed;
					
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}