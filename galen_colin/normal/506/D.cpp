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
 
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) {p[0] = a[0]; for (int i = 1; i < n; i++) p[i] = a[i] + p[i-1];}
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = lb; ele <= rb; ele++) { if (ele > lb) cout << " "; cout << a[ele]; } cout << '\n';}
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
 
// template<typename A, typename B> ll max(A x, B y) {
//   return x > y ? x : y;
// }
// template<typename A, typename B> ll min(A x, B y) {
//   return x < y ? x : y;
// }
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;

/* union by size */
struct dsu {
  int n;
  vector<int> sizes, marks;
  vector<vector<int> > graph;

  void init(int rn) {
    n = rn;
    sizes = vector<int>(n);
    fill(sizes.begin(), sizes.end(), 1);
    marks = vector<int>(n);
    for (int i = 0; i < n; i++) marks[i] = i;
    graph = vector<vector<int> >(n);
  }

  void mark(int m, int node) {
    if (marks[node] == m) return;

    marks[node] = m;

    for (int i: graph[node]) mark(m, i);
  }

  void merge(int a, int b) {
    if (marks[a] == marks[b]) return;
    graph[a].push_back(b);
    graph[b].push_back(a);

    if (sizes[marks[a]] > sizes[marks[b]]) swap(a, b);

    sizes[marks[b]] += sizes[marks[a]];
    sizes[marks[a]] = 0;
    mark(marks[b], a);
  }

  int find(int n) { return marks[n]; }
};

ll n, m, k, q, Q, T, l, r, x, y, z;
// ll a[1000005];
// ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

map<int, vi> edges[100005];
int res[100005];
const int C = 400;
map<int, vi> recs[100005];
set<int> nrecs[100005];
vpi bycol[100005];
dsu d;

int touched[100005];
int tcnt;
bool vis[100005];
void dfs_col(int src, int v, int c) {
  if (vis[v]) return;
  vis[v] = 1;
  touched[tcnt++] = v;

  for (int x: recs[src][v]) ++res[x];

  for (int x: edges[v][c]) dfs_col(src, x, c);
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");

  cin >> n >> m;
  f0r(i, m) {
    cin >> x >> y >> z;
    --x; --y;
    --z;
    edges[x][z].pb(y);
    edges[y][z].pb(x);
    bycol[z].pb(mp(x, y));
  }
  cin >> q;
  f0r(i, q) {
    cin >> x >> y;
    --x; --y;
    recs[x][y].pb(i);
    nrecs[x].insert(y);
  }

  ms(vis, 0);
  f0r(i, n) {
    if (recs[i].size() >= C) {
      f0r(j, m) {
        tcnt = 0;
        dfs_col(i, i, j);
        f0r(i, tcnt) vis[touched[i]] = 0;
      }
    }
  }

  d.init(n);
  f0r(i, m) {
    tcnt = 0;
    for (pii x: bycol[i]) {
      touched[tcnt++] = x.f;
      touched[tcnt++] = x.s;

      d.merge(x.f, x.s);
    }

    f0r(i, tcnt) {
      int x = touched[i];
      if (vis[x]) continue;
      vis[x] = 1;

      if (recs[x].size() < C) {
        for (int y: nrecs[x]) {
          if (d.marks[x] == d.marks[y]) {
            for (int z: recs[x][y]) ++res[z];
          }
        }
      }
    }

    f0r(i, tcnt) {
      int x = touched[i];
      vis[x] = 0;
      d.marks[x] = x;
      d.sizes[x] = 1;
      d.graph[x].clear();
    }
  }

  f0r(i, q) cout << res[i] << '\n';
}