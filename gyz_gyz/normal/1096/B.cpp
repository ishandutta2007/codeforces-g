#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 2000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
char s[N];
int main(){int n;
	scanf("%d",&n);scanf("%s",s+1);
	ll s1=1,s2=1;
	rep(i,1,n)if(s[i]==s[1])++s1;else break;
	dep(i,n,1)if(s[i]==s[n])++s2;else break;	
	if(s[1]==s[n])printf("%lld\n",s1*s2%mo);
	else printf("%lld\n",s1+s2-1);
}