#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
char s[N][N];
int main(){int n,ans=0;
	scanf("%d",&n);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,n)
		if(s[i][j]=='X'&&s[i-1][j-1]=='X'&&s[i+1][j-1]=='X'&&s[i-1][j+1]=='X'&&s[i+1][j+1]=='X')++ans;
	printf("%d\n",ans);
}