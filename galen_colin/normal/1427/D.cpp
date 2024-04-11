#include <bits/stdc++.h>
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
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
 
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 2047;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

vector<pair<ll, ll>> construct (vector<pair<ll, ll>> v) {
	vector<pair<ll, ll>> x;
	pair<ll, ll> targ = v[0];
	for (ll i = 1; i < v.size(); i++) {
		if (v[i].f == targ.s + 1) {
			targ = make_pair(targ.f, v[i].s);
		} else {
			x.push_back(targ);
			targ = v[i];
		}
	}
	x.push_back(targ);
	return x;
}

vector<pair<ll, ll>> apply (vector<pair<ll, ll>> v, vector<ll> op) {
	vector<pair<ll, ll>> x(v.size());
	
	ll lpt = 0, rpt = n;
	for (ll y: op) {
		rpt -= y;
		for (ll i = 0; i < y; i++) x[rpt + i] = v[lpt + i];
		lpt += y;
	}
	
	return x;
}

vector<ll> ops[55];

void end() {
	cout << ans << '\n';
	for (ll i = 0; i < ans; i++) {
		cout << ops[i].size();
		for (ll x: ops[i]) cout << " " << x;
		cout << '\n';
	}
	
	exit(0);
}

void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	if (n == 1) {
		cout << "0\n";
		return;
	}
	
	vector<pair<ll, ll>> v; // (l, r)
	for (ll i = 0; i < n; i++) {
		v.push_back(make_pair(a[i], a[i]));
	}
	
	vector<pair<ll, ll>> orig = v;
	
	ans = 0;
	
	for (ll i = 0; i < n; i++) {
		v = construct(orig);
		// cout << orig << '\n';
		
		if (v.size() == 1) {
			end();
		}
		
		// cout << v << " " << orig << '\n';
		
		++ans;
		
		pair<ll, ll> t;
		for (ll j = 0; j < v.size(); j++) {
			for (ll k = j + 1; k < v.size(); k++) {
				if (v[j].f == v[k].s + 1) {
					t = make_pair(j, k);
				}
			}
		}
		
		// cout << t << '\n';
		
		if (t.f > 0) {
			ll s = 0;
			for (ll j = 0; j < t.f; j++) s += v[j].s - v[j].f + 1;
			ops[i].push_back(s);
		}
		
		ll s = 0;
		for (ll j = t.f; j < t.s; j++) s += v[j].s - v[j].f + 1;
		ops[i].push_back(s);
		
		ops[i].push_back(v[t.s].s - v[t.s].f + 1);
		
		if (t.s + 1 < v.size()) {
			s = 0;
			for (ll j = t.s + 1; j < v.size(); j++) s += v[j].s - v[j].f + 1;
			ops[i].push_back(s);
		}
		
		// cout << ops[i] << '\n';
		
		orig = apply(orig, ops[i]);
	}
		
	end();
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("moop");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 
	
	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}