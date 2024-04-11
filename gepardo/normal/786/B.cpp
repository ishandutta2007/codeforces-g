/**
                      alex256                   
   
   Contest CodeForces Round 406 (Div. 1)         
   
   Task    B                                     
   
   Date    23.03.2017                            
   **/
/// Global defines
#ifndef ONLINE_JUDGE
	#define LOCAL
#endif
#define USE_LONGLONG
//#define USE_UNORDERED
//#define FILE_IO
//#undef LOCAL
#ifdef FILE_IO
	#define TASK_NAME "taskname"
	#define INPUT_FILE TASK_NAME".in"
	#define OUTPUT_FILE TASK_NAME".out"
#endif
/// Includes 
#include <bits/stdc++.h>
using namespace std;
/// Defines
#ifdef USE_UNORDERED
	#define set unordered_set
	#define map unordered_map
#endif
#if defined(FILE_IO) && (!defined(LOCAL))
	#define cin __new_cin
	#define cout __new_cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#endif
#ifdef USE_LONGLONG
	#define int ll
	#define inf llInf
#endif
#define endl "\n"
#define sz(a) (int)(a.size())
#define here dbg("here!")
#define endless for (;;)
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
/// Types
typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
struct ofl { ld value; int precision; inline ofl(ld value, int precision) : value(value), precision(precision) {} };
/// Constants
const int seed = hash<string>()("alex256");
#ifndef USE_LONGLONG
	const int inf = (int)1e9 + 7;
#endif
const ll llInf = (ll)2e18 + 256;
const int mod = (int)1e9 + 7;
const ld pi = 3.141592653589793238462643383279502884197169399375105821;
const string luck = "";
const char* errText = "error :(";
/// Iostream extension
template<typename T1, typename T2> inline istream& operator>>(istream& is, pair<T1, T2>& p) { return is >> p.F >> p.S; } 
template<typename T1, typename T2> inline ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << p.F << " " << p.S; } 
template<typename T> inline istream& operator>>(istream& is, vector<T>& v) { for (int i = 0; i < sz(v); i++) { is >> v[i]; } return is; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (int i = 0; i < sz(v); i++) { if (i) { os << " "; } os << v[i]; } return os; }
inline ostream& operator<<(ostream& os, const ofl& o) { return os << fixed << setprecision(o.precision) << o.value; }
inline bool iosOptimize() { ios_base::sync_with_stdio(false); return true; }
bool iosOptimized = iosOptimize();
/// Input
template<typename T> inline T get() { T value; cin >> value; return value; }
template<> inline char get() { char c = '\0'; while (c <= ' ') { cin >> c; } return c; }
inline string getLn() { string s; getline(cin, s); return s; }
template<typename T, size_t Count> struct VectorPacker { typedef vector< typename VectorPacker<T, Count-1>::Type > Type; };
template<typename T> struct VectorPacker<T, 0> { typedef T Type; };
template<typename T> inline vector<T> getVector(int size) { vector<T> res(size); cin >> res; return res; }
template<typename T, typename U, typename... Args> inline typename VectorPacker<T, sizeof...(Args)+1>::Type getVector(U size, Args... sizes) { typename VectorPacker<T, sizeof...(Args)+1>::Type res(size); for (int i = 0; i < (int)size; i++) { res[i] = getVector<T>(sizes...); } return res; }
/// Output
inline void put() {}
template<typename T, typename... Args> inline void put(const T& value, const Args&... vals) { cout << value; put(vals...); }
template<typename... Args> inline void putLn(const Args&... vals) { put(vals...); cout << endl; }
/// Debug
#ifdef LOCAL
	template<typename... Args> inline void dbg(const Args&... vals) { putLn(vals...); cout.flush(); }
#else
	#define dbg(...)
#endif
/// Hash overload for pairs
namespace std { template<typename T1, typename T2> struct hash<pair<T1, T2> > { inline size_t operator()(const pair<T1, T2>& p) const { return hash<T1>()(p.F) ^ hash<T2>()(p.S); } }; };
/// Helpful methods
mt19937_64 rnd(seed);
inline void error(const char* text = errText) { dbg(text); exit(256); }
template <typename T1, typename T2> inline void umax(T1& a, const T2& b) { if (a < b) { a = b; } }
template <typename T1, typename T2> inline void umin(T1& a, const T2& b) { if (a > b) { a = b; } }
ll gcd(ll a, ll b) { return b ? gcd (b, a % b) : a; }
ll extGcd(ll a, ll b, ll& x, ll& y) { if (!a) { x = 0; y = 1; return b; } ll x1, y1, d = extGcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return d; }
inline int addMod(int a, int b, int m = mod) { return ((ll)a + b) % m; }
inline int subMod(int a, int b, int m = mod) { return ((ll)a + m - b) % m; }
inline int mulMod(int a, int b, int m = mod) { return ((ll)a * b) % m; }
inline int divMod(int a, int b, int m = mod) { ll x, y; ll g = extGcd(b, m, x, y); if (g != 1) { dbg("cannot eval ", a, " / ", b, " modulo ", m); exit(42); }  x = (x % m + m) % m; return mulMod(a, x, m); }
/// End of The Template

int n = get<int>(), q = get<int>(), s = get<int>() - 1;
int vCnt = n;

vector< vector<pii> > g(n);

template<typename Adder>
void buildIn(vector<int>& tree, int v, int tl, int tr, const Adder& adder) {
	if (tl == tr) {
		tree[v] = tl;
	} else {
		tree[v] = vCnt++;
		g.emplace_back();
		int tm = (tl + tr) / 2;
		buildIn(tree, v*2, tl, tm, adder);
		buildIn(tree, v*2+1, tm+1, tr, adder);
		adder(tree[v], tree[v*2]);
		adder(tree[v], tree[v*2+1]);
	}
}

template<typename Adder>
void addSeg(vector<int>& tree, int v, int tl, int tr, int l, int r, const Adder& adder) {
	if (l > r) {
		return;
	}
	if (l == tl && r == tr) {
		adder(tree[v]);
	} else {
		int tm = (tl + tr) / 2;
		addSeg(tree, v*2, tl, tm, l, min(r, tm), adder);
		addSeg(tree, v*2+1, tm+1, tr, max(tm+1, l), r, adder);
	}
}

vector<int> dijkstra(vector< vector<pii> > g, int src) {
	int n = g.size();
	vector<int> d(n, inf);
	priority_queue<pii, vector<pii>, greater<pii> > q;
	d[src] = 0;
	q.emplace(d[src], src);
	while (!q.empty()) {
		int way, v; tie(way, v) = q.top(); q.pop();
		if (d[v] != way) {
			continue;
		}
		for (auto edge: g[v]) {
			int to, len; tie(to, len) = edge;
			if (d[to] > way + len) {
				d[to] = way + len;
				q.emplace(d[to], to);
			}
		}
	}
	for (int& i: d) {
		if (i == inf) {
			i = -1;
		}
	}
	return d;
}

vector<int> inTree(4*n), outTree(4*n);

signed main() {
	buildIn(inTree, 1, 0, n-1, [&](int a, int b) { g[a].eb(b, 0); });
	buildIn(outTree, 1, 0, n-1, [&](int a, int b) { g[b].eb(a, 0); });
	for (int i = 0; i < q; i++) {
		int idx = get<int>();
		if (idx == 1) {
			int u = get<int>() - 1, v = get<int>() - 1, w = get<int>();
			g[u].eb(v, w);
		} else {
			int v = get<int>() - 1, l = get<int>() - 1, 
			    r = get<int>() - 1, w = get<int>();
			if (idx == 2) {
				addSeg(inTree, 1, 0, n-1, l, r, [&](int a){ g[v].eb(a, w); });
			} else {
				addSeg(outTree, 1, 0, n-1, l, r, [&](int a){ g[a].eb(v, w); });	
			}
		}
	}
	vi v = dijkstra(g, s);
	putLn(vi(v.begin(), v.begin() + n));
	return 0;
}