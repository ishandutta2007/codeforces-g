#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
 
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) p[0] = a[0]; for (int i = 1; i < n; i++) p[i] = a[i] + p[i-1];
#define all(v) v.begin(), v.end()
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);};
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
 
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
// template<typename A, typename B> ll max(A x, B y) {
//   return x > y ? x : y;
// }
// template<typename A, typename B> ll min(A x, B y) {
//   return x < y ? x : y;
// }

const ll mod = 5;

ll madd(ll a, ll b) {
  return (a + b) % mod;
}

ll msub(ll a, ll b) {
  return (((a - b) % mod) + mod) % mod;
}

ll mmul(ll a, ll b) {
  return (a % mod * b % mod) % mod;
}

ll mpow(ll base, ll exp) {
  ll res = 1;
  while (exp) {
    if (exp % 2 == 1){
        res = (res * base) % mod;
    }
    exp >>= 1;
    base = (base * base) % mod;
  }
  return res;
}
ll minv(ll base) {
  return mpow(base, mod - 1);
}

ll mdiv(ll a, ll b) {
  return mmul(a, minv(b));
}
 
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
 
bool prime[100006]; 
void sieve(int n) { 
  ms(prime, 1);
  for (int p = 2; p * p <= n; p++) { 
    if (prime[p] == true) { 
      for (int i = p * p; i <= n; i += p) 
        prime[i] = false; 
    } 
  } 
  prime[1] = prime[0] = 0;
} 

ll n, q, Q, T, m, k, r, x, y, z, g;
ll a[100001];
int mk[1001];
bool vis[1001];
vi on[75];
int ans = 10000;
int cn = 0;

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> n;
  f0r(i, n) cin >> a[i];
  f0r(i, n) cn += !!a[i];
  if (cn > 120) {
    cout << 3 << endl; exit(0);
  }
  sort(a, a + n);
  reverse(a, a + n);
  n = cn;
  queue<pii> q;
  f0r(i, n) {
    f0r(j, n) mk[j] = -1;
    ms(vis, 0);
    q.push(mp(i, -1));
    while (!q.empty()) {
      pii x = q.front();
      q.pop();
      if (vis[x.f]) continue;
      vis[x.f] = 1;

      f0r(j, n) {
        if (j == x.s || j == x.f) continue;
        bool f = 0;
        f0r(k, 61) if (a[j] & a[x.f] & (1 << k)) {f = 1; break;}
        if (!f) continue;
        int v;
        if (x.s == -1) v = 1;
        else v = mk[x.s] + 2;
        if (mk[j] > -1) ans = min(ans, mk[j] + v);
        else { 
          q.push(mp(j, x.f));
          mk[j] = v;
        }
      }

      if (x.s == -1) mk[x.f] = 0;
      else mk[x.f] = mk[x.s] + 1;
    }
  }
  cout << (ans == 10000 ? -1 : ans) << endl;
}