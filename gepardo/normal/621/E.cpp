/*-------------------( alex256 )--------------------\
|    Contest: Codeforces Round 341 (Div. 2)         |
|       Task: E                                     |
|       Date: 31. 01. 2016                          |
\--------------------------------------------------*/
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
#define INF 123456789
#define LLINF 123456789012345678
#define PI 3.14159265358979323846
#define MAXN 2000000
#define LL long long
#define ULL unsigned long long
#define ar(a) a[MAXN]
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define sz(x) (int)x.size()
#define ldout(v, prec) setprecision(prec) << v
#define debug(v) #v << " = \"" << v << "\""
#define endless for (;;)
#define fenint fenwick <int>
#define fenll fenwick <LL>
#define Actually true
#define yes ;
#define fr(i, n) for (int i = 0; i < n; i++)
#define ft(i, f, t) for (int i = f; i < t; i++)
#define here cout << "here"
#define alex256 2016
#define rating(n) n
#define int long long
using namespace std;
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
    template <typename... Args> void getln(Args&... args) { get(args...); ln(); }
    template <typename T> operator T() { T n; get(n); return n; }
    void ln() { string s; getline(cin, s); }
    template <typename T> void getv(vector <T> &v, int size) { v.resize(size); (*istr) >> v; }
};
#define endl "\n"
string delim = " ";
template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2> &p) { os << p.first << delim << p.second; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T> &p) { for (int i = 0; i < p.size(); i++) { if (i != 0) os << delim; os << p[i]; } return os; }
class outputer
{
    private: ostream* ostr; public:
    outputer(ostream &os) : ostr(&os) {}
    template <typename T> void put(const T &n) { (*ostr) << n; }
    template <typename T, typename... Args> void put(const T &n, const Args&... args) { put(n); put(args...); }
    template <typename... Args> void putln(const Args&... args) { put(args...); ln(); }
    template <typename T> outputer& operator=(const T &n) { put(n); return *this; }
    void ln() { (*ostr) << endl; }
    template <typename T> void putv(vector <T> v, int size) { for (int i = 0; i < size; i++) { if (i != 0) (*ostr) << delim; (*ostr) << v[i]; } }
};
inputer in(cin);
outputer out(cout);
// Other methods
bool will_it_be_AC() { return Actually yes; }
int get_my_rating() { return rating(alex256); }
bool prime(LL n) { for (LL i = 2; i * i <= n; i++) if (n % i == 0) return false; return true; }
vector <LL> divs(LL n) { vector <LL> v; LL i = 2; while (i * i <= n) if (n % i == 0) { n /= i; v.pb(i); } else i++; v.pb(n); return v; }
LL gcd(LL a, LL b) { return b ? gcd (b, a % b) : a; }
LL extgcd(LL a, LL b, LL &x, LL &y) { if (a == 0) { x = 0; y = 1; return b; } LL x1, y1, d = extgcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return d; }
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

const int MOD = (int)1e9 + 7;

int n = in, b = in, k = in, x = in;
vector<int> v;
vector<int> num(x), q(x);

int pow10(int n)
{
    int res = 1;
    int a = 10;
	while (n)
    {
		if (n & 1) res = (res * a) % x;
		a = (a * a) % x;
		n >>= 1;
	}
	return res;
}

void mul(vector<int> a, int nca, vector<int> b, int ncb, vector<int> &c, int &ncc)
{
    if (ncb == 0)
    {
        c = a;
        ncc = nca;
        return;
    }
    if (nca == 0)
    {
        c = b;
        ncc = ncb;
        return;
    }
    int q = pow10(ncb);
    c.assign(x, 0);
    ncc = nca + ncb;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < x; j++)
        {
            int u = (i * q + j) % x;
            c[u] = (c[u] + a[i] * b[j]) % MOD;
        }
}

void powit(vector<int> a, int n, vector<int> &c)
{
    int nca = 1;
    vector<int> res(x); int ncres = 0;
    vector<int> tmp(x); int nctmp = 0;
	while (n)
    {
		if (n & 1)
        {
            mul(res, ncres, a, nca, tmp, nctmp);
            res = tmp;
            ncres = nctmp;
        }
            mul(a, nca, a, nca, tmp, nctmp);
            a = tmp;
            nca = nctmp;
		n >>= 1;
	}
	c = res;
}

main()
{
    in.getv(v, n);
    for (int i = 0; i < n; i++) num[v[i] % x]++;
    powit(num, b, q);
    out = q[k];
}