#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int mo=1e9+7;
const int inf=1e9;
const ll Inf=1e18;
int a[4];
int main(){
	rep(i,0,3)scanf("%d",&a[i]);
	sort(a,a+4);
	rep(i,0,2)printf("%d ",a[3]-a[i]);
}