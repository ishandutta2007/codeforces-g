#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
#define int long long
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],A,B;
signed main(){
	t=read();
	while(t--){
		n=read(),A=read(),B=read();
		re bool ia1=1,ia2=1;
		for(re int i=1;i<=n;++i){
			a[i]=read();
		}
		for(re int i=1;i<n;++i)ia1&=(a[i]==a[i+1]),ia2&=(abs(a[i]-a[i+1])<=1);
		if(ia1){
			printf("%lld\n",B+min(A,B));
		}
		else if(ia2){
			printf("%lld\n",min(A,B));
		}
		else puts("0");
	}
}