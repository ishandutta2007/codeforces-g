/*-------------------( alex256 )--------------------\
|    Contest: Codeforces Round 389 (Div. 2)         |
|       Task: D                                     |
|       Date: 25. 12. 2016                          |
\--------------------------------------------------*/
// Includes
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdint>
// Defines
#define ar(a) a[maxN]
#define pb push_back
#define F first
#define S second
#define sz(x) (int)x.size()
#define debug(v) makeDebugInfo(#v, v)
#define dbg(v) out.put(makeDebugInfo(#v, v)), cout.flush()
#define here out = "here"; cout.flush()
#define endless for (;;)
// Other defines
#define Actually true
#define yes ;
#define alex256 2048
#define rating(n) n
using namespace std;
// Types
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
struct outFloat { int precision; LD value; outFloat(LD v, int p) : precision(p), value(v) {} }; typedef outFloat ofl;
template <typename T> struct debugInfo { string name; T val; debugInfo(const char* n, T v) : name(n), val(v) {}; };
template <typename T> debugInfo<T> makeDebugInfo(const char* n, T v) { return debugInfo<T>(n, v); }
// Constants
const int inf = 123456789;
const LL llInf = 123456789012345678LL;
const LD pi = 3.14159265358979323846;
const int maxN = 2000000;
// Input / Output
int init() { ios_base::sync_with_stdio(0); srand(time(NULL)); return 0; } int initializer = init();
template <typename T1, typename T2> istream& operator>>(istream& is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template <typename T> istream& operator>>(istream& is, vector<T> &p) { for (int i = 0; i < p.size(); i++) is >> p[i]; return is; }
class inputer
{
    private: istream* istr; public:
    inputer(istream &is) : istr(&is) {}
    template <typename T> void get(T &n) { (*istr) >> n; }
    template <typename T, typename... Args> void get(T &n, Args&... args) { get(n); get(args...); }
    template <typename... Args> void getLn(Args&... args) { get(args...); getLn(); }
    template <typename T> operator T() { T n; get(n); return n; }
    void getLn() { string s; getline(cin, s); }
    template <typename T> void getv(vector <T> &v, int size) { v.resize(size); (*istr) >> v; }
};
#define endl "\n"
string delim = " ";
template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2> &p) { os << p.first << delim << p.second; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T> &p) { for (int i = 0; i < p.size(); i++) { if (i != 0) os << delim; os << p[i]; } return os; }
ostream& operator<<(ostream& os, const outFloat &of) { os << setprecision(of.precision) << of.value; return os; }
template <typename T> ostream& operator<<(ostream& os, const debugInfo<T> &dbg) { os << "\"" << dbg.name << "\" = \"" << dbg.val << "\"" << endl; }
class outputer
{
    private: ostream* ostr; public:
    outputer(ostream &os) : ostr(&os) {}
    template <typename T> void put(const T &n) { (*ostr) << n; }
    template <typename T, typename... Args> void put(const T &n, const Args&... args) { put(n); put(args...); }
    template <typename... Args> void putLn(const Args&... args) { put(args...); putLn(); }
    template <typename T> outputer& operator=(const T &n) { putLn(n); return *this; }
    void putLn() { (*ostr) << endl; }
    template <typename T> void putv(vector <T> v, int size, string delim) { for (int i = 0; i < size; i++) { if (i != 0) (*ostr) << delim; (*ostr) << v[i]; } }
};
inputer in(cin);
outputer out(cout);
char getChar() { char c = 0; while (c <= ' ') cin >> c; return c; }
// Other methods
bool willItBeAC() { return Actually yes; } int getMyRating() { return rating(alex256); }
bool prime(LL n) { for (LL i = 2; i * i <= n; i++) if (n % i == 0) return false; return true; }
vector <LL> divs(LL n) { vector <LL> v; LL i = 2; while (i * i <= n) if (n % i == 0) { n /= i; v.pb(i); } else i++; v.pb(n); return v; }
LL gcd(LL a, LL b) { return b ? gcd (b, a % b) : a; }
LL extGcd(LL a, LL b, LL &x, LL &y) { if (a == 0) { x = 0; y = 1; return b; } LL x1, y1, d = extGcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return d; }
template <typename T> class fenwick
{
    private: vector<T> t; int n; public:
    fenwick(int nn) { init(nn); }
    void init(int nn) { n = nn; t.assign(n, 0); }
    T sum(int r) { T result = 0; for (; r >= 0; r = (r & (r + 1)) - 1) result += t[r]; return result; }
    void inc(int i, T delta) { for (; i < n; i = (i | (i + 1))) t[i] += delta; }
    T sum(int l, int r) { return sum(r) - sum(l - 1); }
    T get(int i) { return sum(i, i); }
    void put(int i, T v) { inc(i, v - sum(i, i)); }
    int size() { return n; }
};
//End of template

typedef pair<int, int> Hash;

int n = in, m = in;
vector< pair<string, int> > v(n);
vector<string> rev(n); 
vector< pair<Hash, Hash> > hashes(n);
vector<char> isPalindome(n);
vector<char> used(n, false);
map<Hash, set< pair<int, int>, greater< pair<int, int> > > > frontHashes, backHashes;

const int pow1 = 257;
const int pow2 = 263;
const int mod1 = (int)1e9 + 7;
const int mod2 = (int)1e9 + 9;

int pows1[1000000], pows2[1000000];

inline void initHashes() {
	pows1[0] = pows2[0] = 1;
	for (int i = 1; i < 1000000; i++) {
		pows1[i] = (1LL * pows1[i-1] * pow1) % mod1;
		pows2[i] = (1LL * pows2[i-1] * pow1) % mod2;
	}
}

inline Hash getHash(const string& s) {
	Hash res {0, 0};
	for (int i = 0; i < (int)s.length(); i++) {
		res.F = (1LL * res.F + 1LL * s[i] * pows1[i]) % mod1;
		res.S = (1LL * res.S + 1LL * s[i] * pows2[i]) % mod2;
	}
	return res;
}

inline void del(int i) {
	used[i] = true;
	frontHashes[hashes[i].F].erase({v[i].S, i});
	backHashes[hashes[i].S].erase({v[i].S, i});
}

inline void add(int i) {
	used[i] = false;
	frontHashes[hashes[i].F].emplace(v[i].S, i);
	backHashes[hashes[i].S].emplace(v[i].S, i);	
}

main()
{
	initHashes();
	in.getv(v, n);
	for (int i = 0; i < n; i++) {
		rev[i] = v[i].F;
		reverse(rev[i].begin(), rev[i].end());
		hashes[i] = make_pair(getHash(v[i].F), getHash(rev[i]));
		isPalindome[i] = v[i].F == rev[i];
		add(i);
	}
	int ans = 0;
	int singlePal = 0;
	for (auto &it: frontHashes) {
		while (true) {
			if (it.S.empty()) break;	
			int id1 = it.S.begin()->S;
			del(id1);
			int id2 = -1;
			auto &ourSet = backHashes[hashes[id1].F];
			if (!ourSet.empty()) {
				id2 = ourSet.begin()->S;
			}
			int res = (id2 < 0) ? (-inf) : (v[id1].S + v[id2].S);
			if (res < 0) {
				add(id1);
				if (isPalindome[id1]) {
					singlePal = max(singlePal, v[id1].S); 
				}
				break;
			}
			del(id2);
			ans += res;
		}
	}
	int minPal = 0;
	for (int i = 0; i < n; i++)
		if (used[i] && isPalindome[i]) {
			minPal = min(minPal, v[i].S);
		}
	out = max(ans - minPal, ans + singlePal);
    return 0;
}