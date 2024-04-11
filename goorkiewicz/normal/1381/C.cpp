//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
namespace debug {
template <class c> struct rge { c b, e; }; template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> char elo(...); template <class c> auto elo(c* a) -> decltype(cerr << *a, 0);
struct stream { ~stream() { cerr << endl; }
template <class c> typename enable_if <sizeof elo<c>(0) != 1, stream&>::type operator<<(c i) { cerr << boolalpha << i; return *this; }
template <class c> typename enable_if <sizeof elo<c>(0) == 1, stream&>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
template <class a, class b> stream& operator<<(pair <a,b> p) { return *this << "(" << p.first << ", " << p.second << ")"; }
template <class c> stream& operator<<(rge<c> d) { *this << "["; for (auto it=d.b; it!=d.e; it++) *this << ", " + 2 * (it == d.b) << *it; return *this << "]"; }
stream& _dbg(const string& s, int i, int b) {} template <class c, class ... cs> stream& _dbg(const string& s, int i, int b, c arg, cs ... args) {
if (i == s.size()) return (*this << ": " << arg << ""); b += (s[i] == '(') + (s[i] == '[') + (s[i] == '{'); b -= (s[i] == ')') + (s[i] == ']') + (s[i] == '}');
if (s[i] == ',' && b == 0) return (*this << ": " << arg << "     ")._dbg(s, i+1, b, args...); return (s[i] == ' ' ? *this : *this << s[i])._dbg(s, i+1, b, arg, args...); } };}
#define dout debug::stream()
#define dbg(...) ((dout << ">> ")._dbg(#__VA_ARGS__, 0, 0, __VA_ARGS__))
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
#define f first
#define s second
#define sc scanf
#define pr printf
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define ss(x) ((int)((x).size()))
#define rep(i, a, b) for(int (i)=(a);i<=(b);(i)++)
#define per(i, a, b) for(int (i)=(b);i>=(a);(i)--)
#define lowb(v, x) (lower_bound(all(v),(x))-(v).begin())
#define uppb(v, x) (upper_bound(all(v),(x))-(v).begin())
#define upgrade ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define erase_duplicates(x) {sort(all(x));(x).resize(distance((x).begin(), unique(all(x))));}
template <class p, class q> pair<p,q> operator-(pair<p,q> a, pair<p,q> b) { return mp(a.f-b.f, a.s-b.s); }
template <class p, class q> pair<p,q> operator+(pair<p,q> a, pair<p,q> b) { return mp(a.f+b.f, a.s+b.s); }
template <class p, class q> void umin(p& a, const q& b) { if (a > b) a = b; }
template <class p, class q> void umax(p& a, const q& b) { if (a < b) a = b; }
using lf=long double;
using ll=long long;
using cll=const ll;
using cint=const int;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

const int N = 1000005;
int n, i, j, x, y;
int out [N];
vector <int> v [N];
map <int, int> M;
multiset < pair<int,int> > S;

void solve ()
	{
	scanf ("%d%d%d", &n, &x, &y);
	
	for (i=0; i<=n+1; i++)
		v[i].clear();
	
	M.clear();
	S.clear();
	
	for (i=0; i<n; i++)
		out[i] = 0;
	
	for (i=0; i<n; i++)
		{
		int a;
		scanf ("%d", &a);
		v[a].pb(i);
		M[a]++;
		}

	for (i=1; i<=n+1; i++)
		if (v[i].empty())
			break;

	assert(i <= n+1);
	int unused = i;

	for (pair <int, int> p : M)
		S.insert({p.s, p.f});
	
	for (i=0; i<x; i++)
		{
		auto it = prev(S.end());
		S.erase(it);
		pair <int,int> p = *it;
		out[v[p.s].back()] = p.s;
		v[p.s].pop_back();
		p.f--;
		S.insert(p);
		}

	n -= x;
	y -= x;

	if (n == 0)
		{
		printf ("YES\n");
		for (i=0; i<n+x; i++)
			printf ("%d ", out[i]);
		printf ("\n");
		return;
		}

	vector <int> A, B;

	assert(S.empty() == false);
	
	int shift = (*prev(S.end())).f;
	
	for (pair <int,int> p : S)
		while (p.f--)
			A.pb(p.s);

	assert(ss(A) == n);
	B.resize(n);
	
	for (i=0; i<n; i++)
		B[i] = A[(i+shift)%n];
	
	int cnt = 0;
	
	for (i=0; i<n; i++)
		if (A[i] != B[i])
			cnt++;
	
	if (cnt < y)
		{
		printf ("NO\n");
		return;
		}
	
	cnt -= y;

	for (i=0; i<n && cnt > 0; i++)
		if (A[i] != B[i])
			{
			B[i] = unused;
			cnt--;
			}
	
	for (i=0; i<n; i++)
		if (A[i] == B[i])
			B[i] = unused;
	
	for (i=0; i<n; i++)
		{
		out[v[A[i]].back()] = B[i];
		v[A[i]].pop_back();
		}

	printf ("YES\n");
	for (i=0; i<n+x; i++)
		printf ("%d ", out[i]);
	printf ("\n");
	}

int main ()
	{
	int q;
	scanf ("%d", &q);
	while (q--)
		solve();
	return 0;
	}