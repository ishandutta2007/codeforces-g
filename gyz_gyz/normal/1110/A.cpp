#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 3000010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int main(){
	int n,m;bool ans=0;
	scanf("%d%d",&n,&m);
	rep(i,1,m){int x;
		scanf("%d",&x);
		if((x&1)&&((n&1)||(i==m)))ans^=1;
	}
	printf("%s\n",ans?"odd":"even");
}