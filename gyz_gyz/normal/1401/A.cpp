#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=1e9;
const int mo=998244353;
void sol(){int n,k;
	scanf("%d%d",&n,&k);
	if(n<k)printf("%d\n",k-n);
	else printf("%d\n",(k&1)^(n&1));
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}