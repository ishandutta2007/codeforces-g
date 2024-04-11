/**
                      alex256                   
   
   Contest CodeForces Round 402 (Div. 1)         
   
   Task    B                                     
   
   Date    26.02.2017                            
   **/
/// Global defines
#ifndef ONLINE_JUDGE
	#define LOCAL
#endif
//#define USE_LONGLONG
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

struct Variable {
	string name;
	string val;
	string op;
	string val2;
	int id1;
	int id2;
	int value;
	bool counted;
};

int n = get<int>(), m = get<int>();
vector<Variable> vars(n);
map<string, int> mp;

signed main() {
	for (int i = 0; i < n; i++) {
		vars[i].name = get<string>();
		get<string>();
		vars[i].val = get<string>();
		if (vars[i].val[0] != '0' && vars[i].val[0] != '1') {
			vars[i].op = get<string>();
			vars[i].val2 = get<string>();
			vars[i].id1 = mp[vars[i].val];
			vars[i].id2 = mp[vars[i].val2];
		} else {
			vars[i].op = "=";
		}
		mp[vars[i].name] = i;
	}
	string minS(m, '0');
	string maxS(m, '0');
	for (int bit = 0; bit < m; bit++) {
		int vals[2];
		for (int val = 0; val < 2; val++) {
			vals[val] = 0;
			for (int i = 0; i < n; i++) {
				if (vars[i].op == "=") {
					vars[i].value = vars[i].val[bit] - '0';
				} else {
					int lVal = (vars[i].val  == "?") ? val : (vars[vars[i].id1].value);
					int rVal = (vars[i].val2 == "?") ? val : (vars[vars[i].id2].value);
					if (vars[i].op == "OR") {
						vars[i].value = lVal | rVal;
					} else if (vars[i].op == "AND") {
						vars[i].value = lVal & rVal;
					} else if (vars[i].op == "XOR") {
						vars[i].value = lVal ^ rVal;
					}
				}
				vals[val] += vars[i].value;
			}
		}
		if (vals[0] > vals[1]) {
			minS[bit] = '1';
			maxS[bit] = '0';
		} else if (vals[0] == vals[1]) {
			minS[bit] = '0';
			maxS[bit] = '0';	
		} else {
			minS[bit] = '0';
			maxS[bit] = '1';
		}
	}
	putLn(minS);
	putLn(maxS);
	return 0;
}