#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 100010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,a[N];ll tot,k,m;double ans;
int main(){
	scanf("%d%lld%lld",&n,&k,&m);
	rep(i,1,n){
		scanf("%d",&a[i]);tot+=a[i];
	}
	sort(a+1,a+n+1);
	rep(i,1,n){
		if(i>m+1)break;
		ans=max(ans,1.*(tot+min((n-i+1)*k,m-i+1))/(n-i+1));
		tot-=a[i];
	}
	printf("%.18lf\n",ans);
}