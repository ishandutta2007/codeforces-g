#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
void sol(){int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",m*2>n?n:m*2);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}