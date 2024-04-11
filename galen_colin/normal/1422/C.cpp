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
 
ll suf[100005];
ll suf_p10[100005];

void solve(int tc) {
    cin >> s;
	n = s.length();
	
	ll ans = 0;
	
	memset(suf, 0, sizeof(suf));
	
	ll cur_suf = 0;
	
	ll right_side = 0;
	ll p10 = 1;
	for (ll j = n - 1; j >= 0; j--) {
		right_side = (right_side + (s[j] - '0') * p10) % mod;
		p10 = (p10 * 10) % mod;
		
		cur_suf = (cur_suf + right_side) % mod;
		suf[j] = cur_suf;
	}
	
	ll sum_p10 = 0;
	p10 = 1;
	for (ll j = n - 1; j >= 0; j--) {
		sum_p10 = (sum_p10 + p10) % mod;
		suf_p10[j] = sum_p10;
		p10 = (p10 * 10) % mod;
	}
	
	ll left_side = 0;
	
	for (ll i = 0; i < n; i++) {
		ans = (ans + left_side * suf_p10[i]) % mod;
		
		left_side = (10 * left_side + (s[i] - '0')) % mod;
		
		if (i < n - 1) ans = (ans + suf[i + 1]) % mod;
	}
	
	cout << ans << '\n';
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