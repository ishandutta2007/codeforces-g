
 #include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 200000
#define mo 1000000007
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,ans,d[N];double s;
int main(){
	scanf("%d%lf",&n,&s);ans=n;
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		if(++d[x]==2)--ans;
		if(++d[y]==2)--ans;
	}
	printf("%.15lf\n",s/ans*2);
}