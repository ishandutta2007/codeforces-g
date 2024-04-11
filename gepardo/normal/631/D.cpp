/*-------------------( alex256 )--------------------\
|    Contest: Codeforces Round 344 (Div. 2)         |
|       Task: D                                     |
|       Date: 03. 03. 2016                          |
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

#define int long long

inline pair<char,int> parse(string s)
{
    string s2 = s.substr(0, s.length() - 2);
    return {s[s.length() - 1], atoi(s2.c_str())};
}

main()
{
    int n = in, m = in;
    vector <string> a(n), b(m);
    in.getv(a, n); in.getv(b, m);
    vector < pair<char,int> > qa, qb;
    for (int i = 0; i < n; i++)
    {
        pair<char,int> p = parse(a[i]);
        bool ok = false;
        if (sz(qa))
            if (p.ff == qa[sz(qa) - 1].ff) ok = true;
        if (ok) qa[sz(qa) - 1].ss += p.ss; else qa.pb(p);
    }
    for (int i = 0; i < m; i++)
    {
        pair<char,int> p = parse(b[i]);
        bool ok = false;
        if (sz(qb))
            if (p.ff == qb[sz(qb) - 1].ff) ok = true;
        if (ok) qb[sz(qb) - 1].ss += p.ss; else qb.pb(p);
    }
    n = sz(qa), m = sz(qb);
    vector <int> da(n), db(m);
    for (int i = 0; i < n; i++) da[i] = qa[i].ff * 500 + qa[i].ss;
    for (int i = 0; i < m; i++) db[i] = qb[i].ff * 500 + qb[i].ss;
    //out = qa; out = endl;
    //out = qb; out = endl;
    int ans = 0;
    if (m == 1)
    {
        for (int i = 0; i < n; i++)
            if (qa[i].ff == qb[0].ff &&
                qa[i].ss >= qb[0].ss) ans += (qa[i].ss - qb[0].ss + 1);
    }
    else if (m == 2)
    {
        for (int i = 1; i < n; i++)
            if (qa[i - 1].ff == qb[0].ff && qa[i].ff == qb[1].ff &&
                qa[i - 1].ss >= qb[0].ss && qa[i].ss >= qb[1].ss)
                ans++;
    }
    else
    {
        vector <int> s;
        for (int i = 1; i < (m - 1); i++) s.pb(db[i]);
        s.pb(-1);
        for (int i = 0; i < n; i++) s.pb(da[i]);
        int sz = s.size();
        vector <int> z(sz);
        for (int i = 1, l = 0, r = 0; i < sz; i++)
        {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < sz && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }
        //out.putln(z);
        //out.putln(s);
        for (int i = 1; i < (n - 1); i++)
        {
            //out.putln(i, ' ', m - 1 + i);
            if (z[m - 1 + i] != m - 2) continue;
            //out.putln(i);
            if (qa[i - 1].ff == qb[0].ff && qa[i + m - 2].ff == qb[m - 1].ff &&
                qa[i - 1].ss >= qb[0].ss && qa[i + m - 2].ss >= qb[m - 1].ss)
                ans++;
        }
    }
    out = ans;
    return 0;
}