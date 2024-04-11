/*-------------------( alex256 )--------------------\
|    Contest: Codeforces Round 345 (Div. 1)         |
|       Task: B                                     |
|       Date: 07. 03. 2016                          |
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
// Defines
#define ar(a) a[maxN]
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define debug(v) #v << " = \"" << v << "\""
#define here cout << "here"
#define endless for (;;)
// Other defines
#define Actually true
#define yes ;
#define alex256 2121
#define rating(n) n
using namespace std;
// Types
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
struct outFloat { int precision; LD value; outFloat(LD v, int p) : precision(p), value(v) {} };
typedef outFloat ofl;
// Constants
const int inf = 123456789;
const LL llInf = 123456789012345678;
const LD pi = 3.14159265358979323846;
const int maxN = 2000000;
// Input / Output
int init() { ios_base::sync_with_stdio(0); srand(time(NULL)); return 0; }
int initializer = init();
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
class outputer
{
    private: ostream* ostr; public:
    outputer(ostream &os) : ostr(&os) {}
    template <typename T> void put(const T &n) { (*ostr) << n; }
    template <typename T, typename... Args> void put(const T &n, const Args&... args) { put(n); put(args...); }
    template <typename... Args> void putLn(const Args&... args) { put(args...); putLn(); }
    template <typename T> outputer& operator=(const T &n) { put(n); return *this; }
    void putLn() { (*ostr) << endl; }
    template <typename T> void putv(vector <T> v, int size, string delim) { for (int i = 0; i < size; i++) { if (i != 0) (*ostr) << delim; (*ostr) << v[i]; } }
};
inputer in(cin);
outputer out(cout);
char getChar() { char c = 0; while (c <= ' ') cin >> c; return c; }
// Other methods
bool willItBeAC() { return Actually yes; }
int getMyRating() { return rating(alex256); }
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

int n = in, a = in, b = in, t = in;
string s = in;
vector <int> p(n), f(n);

int getAns(int l, int r)
{
	int ans = 0;
	if (l <= r)
	{
		ans += (r - l + 1);
		ans += p[r];
		ans += (r - l) * a;
		return ans;
	}
	else
	{
		ans += (n - l + 1 + r);
		ans += (n - l + r) * a;
		ans += min(r, n - l) * a;
		ans += f[l] + p[r];
		return ans;
	}
}

int cnt(int l, int r)
{
	if (l <= r) return r - l + 1; else return n - l + 1 + r;
}

int bSearch(int l, int r, int el)
{
	if (l == r)
		if (getAns(el, l) > t) return 0; else return cnt(el, l);
	if (l + 1 == r)
		if (getAns(el, r) > t)
		{
			if (getAns(el, l) > t) return 0; else return cnt(el, l);
		}
		else return cnt(el, r);
	int m = (l + r) / 2;
	if (getAns(el, m) > t) return bSearch(l, m, el);
		else return bSearch(m, r, el);
}

main()
{
    p[0] = (s[0] == 'w') ? b : 0;
    for (int i = 1; i < n; i++) p[i] = p[i - 1] + ((s[i] == 'w') ? b : 0);
    f[n - 1] = (s[n - 1] == 'w') ? b : 0;
    for (int i = n - 2; i >= 0; i--) f[i] = f[i + 1] + ((s[i] == 'w') ? b : 0);
    int res = 0;
    for (int i = 0; i < n; i++)
    	if (i == 0)
			res = max(res, bSearch(0, n - 1, i));
    	else
    		res = max(res, bSearch(0, i - 1, i));
	out = res;

    return 0;
}