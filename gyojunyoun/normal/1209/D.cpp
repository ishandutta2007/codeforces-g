#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
//#define rf(x) (x)=0;while(*p<48)im=*p++=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
#define pb push_back
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define clv(V) (V).clear()
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define rb(x) ((x)&(-(x)))
#define cb(x) (x)=(!(x))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
#define INFST (0x7f7f7f7f)
#define INFLLST (0x7f7f7f7f7f7f7f7fll)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
typedef complex<ld> base;
const ld EPS = (ld)1e-7;
const ld PI = acos(0) * 2;
bool isZero(const ld& x) { return abs(x) <= EPS; }
int sign(const ld& x) { return isZero(x) ? 0 : (0 < x ? 1 : -1); }
ll gcd(ll a, ll b) { for(;b;a%=b,swap(a,b)){} return abs(a); }
pll operator + (const pll& a, const pll& b) { return pll(a.first+b.first, a.second+b.second); }
pll operator - (const pll& a, const pll& b) { return pll(a.first-b.first, a.second-b.second); }
pll operator * (const pll& a, const ll& b) { return pll(a.first*b, a.second*b); }
ll operator * (const pll& a, const pll& b) { return a.first*b.second - b.first*a.second; }
ll ccw(const pll& a, const pll& b, const pll& c) { return a*b + b*c + c*a; }
void fg(vector<int> G[], int a, int b) { G[a].eb(b); G[b].eb(a); }
void fg(vector<pii> G[], int a, int b, int c) { G[a].eb(b, c); G[b].eb(a, c); }

const int MAXN = 100055;
const int MAXK = 100055;

vector<int> G[MAXK];

int A[MAXN], B[MAXN];
bitset<MAXN> C;
bitset<MAXK> isd, visited;

int N, K, Ans;

void dfs(int color) {
	if(visited[color]) return;
	vector<int> V;
	V.eb(color);
	visited[color] = true;
	for(int col; !V.empty();) {
		col = V.back(); V.pop_back();
		for(int v : G[col]) if(!C[v]) {
			C[v] = true;
			if(isd[A[v]] && isd[B[v]]) continue;
			Ans++;
			isd[A[v]] = isd[B[v]] = true;
			if(!visited[A[v]]) {
				visited[A[v]] = true;
				V.eb(A[v]);
			}
			if(!visited[B[v]]) {
				visited[B[v]] = true;
				V.eb(B[v]);
			}
		}
		G[col].clear();
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> K >> N;
	for(int i = 1; i <= N; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].eb(i);
		G[B[i]].eb(i);
	}

	for(int i = 1; i <= N; i++) if(!C[i]) {
		C[i] = true;
		if(isd[A[i]] && isd[B[i]]) continue;
		Ans++;
		isd[A[i]] = isd[B[i]] = true;
		dfs(A[i]);
		dfs(B[i]);
	}

	cout << N-Ans << endl;
	return 0;
}