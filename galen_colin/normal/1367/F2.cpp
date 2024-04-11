#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define mp make_pair
#define f first
#define s second
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
 
// mt19937 rng(steady_clock::now().time_since_epoch().count());
mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;



ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

pll best[200009];
ll cc[200009];
vl poss[200009];

void solve(int tc) {
  cin >> n;

  ai(a, n);

  set<ll> pos;
  f0r(i, n) pos.insert(a[i]);
  ll c = 0;
  map<ll, ll> rev;
  for (ll x: pos) {
    rev[x] = c++;
  }
  f0r(i, n) a[i] = rev[a[i]];
  // ao(a, n);

  ans = 0;
  f0r(i, n + 3) {
    best[i] = mp(n + 5, -1);
    cc[i] = 0;
    poss[i].clear();
  }
  f0r(i, n) {
    best[a[i]].f = min(best[a[i]].f, i);
    best[a[i]].s = i;
    ++cc[a[i]];
    poss[a[i]].pb(i);
  }
  c = 0;
  ll r = 0, ri = -1;
  f0r(i, pos.size()) {
    ll cv = r;
    for (ll x: poss[i]) {
      if (x > ri) ++cv;
    }
    ans = max(ans, max(cv, cc[i]));
    if (ri < best[i].f) r = max(cv, cc[i]);
    else r = cc[i];
    ri = best[i].s;

    if (i) {
      ll v = 0;
      for (ll x: poss[i - 1]) {
        if (x < best[i].f) ++v;
      }
      r = max(r, v + cc[i]);

      ll run = 0;
      f0r(j, poss[i].size()) {
        while (run < poss[i - 1].size() && poss[i - 1][run] < poss[i][j]) ++run;
        ans = max(ans, (ll)(run + poss[i].size() - j));
      }
    }
    // cout << i << " " << best[i] << " " << ri << " " << r << " " << cv << endl;
  }

  reverse(a, a + n);
  f0r(i, n) a[i] = pos.size() - a[i] - 1;
  // ao(a, n);

  f0r(i, n + 3) {
    best[i] = mp(n + 5, -1);
    cc[i] = 0;
    poss[i].clear();
  }
  f0r(i, n) {
    best[a[i]].f = min(best[a[i]].f, i);
    best[a[i]].s = i;
    ++cc[a[i]];
    poss[a[i]].pb(i);
  }
  c = 0;
  r = 0, ri = -1;
  f0r(i, pos.size()) {
    ll cv = r;
    for (ll x: poss[i]) {
      if (x > ri) ++cv;
    }
    ans = max(ans, max(cv, cc[i]));
    if (ri < best[i].f) r = max(cv, cc[i]);
    else r = cc[i];
    ri = best[i].s;

    if (i) {
      ll v = 0;
      for (ll x: poss[i - 1]) {
        if (x < best[i].f) ++v;
      }
      r = max(r, v + cc[i]);

      ll run = 0;
      f0r(j, poss[i].size()) {
        while (run < poss[i - 1].size() && poss[i - 1][run] < poss[i][j]) ++run;
        ans = max(ans, (ll)(run + poss[i].size() - j));
      }
    }
    // cout << i << " " << best[i] << " " << ri << " " << r << " " << cv << endl;
  }

  cout << n - ans << '\n';
}
 
int main() {
  send help
 
  // usaco("file");

  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}