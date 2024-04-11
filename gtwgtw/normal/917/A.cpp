#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define REP(i, x, y) for(int i = (int)x; i <= (int)y; i ++)
#define FOR(i, x, y) for(int i = (int)x; i <  (int)y; i ++)
#define PER(i, x, y) for(int i = (int)x; i >= (int)y; i --)
#define trace(x) cerr << #x << " " << x << endl;
#define dprintf(...) fprintf(stderr, __VA__ARGS__)
#define dln()        fprintf(stderr, "\n")
using namespace std;
typedef double db;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<PII> VPI;
typedef vector<long long> VL;
const	int N = 5005;
const	int P = 1e9 + 7;
const	int inf = 1e9;
const	LL Inf = 1e18;

inline int IN(){
	char ch = getchar(); int x = 0, f = 0;
	while(ch < '0' || ch > '9') ch = getchar(), f = (ch == '-');
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - 48;
		ch = getchar();
	}
	return f ? (-x) : x;
}

inline int Pow(int x, int y, int p){
	int an = 1;
	for(; y; y >>= 1, x = (LL)x * x % p) if(y & 1) an = (LL)an * x % p;
	return an;
}

void renew(int &x, int y){
	x += y;
	if(x < 0) x += P;
	else if(x >= P) x -= P;
}

void setIO(string a){
#ifndef LOCAL
	freopen((a + ".in").c_str(), "r", stdin);
	freopen((a + ".out").c_str(), "w", stdout);
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

int n;
bool ok[N][N];
char s[N];

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%s",s+1);
	n=strlen(s+1);
	REP(i,1,n) REP(j,i,n) ok[i][j]=1;
	REP(l,1,n)
	{
		int top=0;
		bool fg=0;
		REP(r,l,n)
		{
			if(s[r]=='?'||s[r]=='(') ++top; else --top;
			if(top<0)
			{
				fg=1;
			}
			if(fg) ok[l][r]=0;
		}
	}

	REP(r,1,n)
	{
		int top=0;
		bool fg=0;
		PER(l,r,1)
		{
			if(s[l]=='?'||s[l]==')') ++top; else --top;
			if(top<0)
			{
				fg=1;
			}
			if(fg) ok[l][r]=0;
		}
	}

	int ans=0;
	REP(l,1,n) for(int r=l+1;r<=n;r+=2) if(ok[l][r])++ans;
	printf("%d\n",ans);


	return 0;
}