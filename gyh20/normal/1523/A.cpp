#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
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
int t,n,m,ans,cnt,head[1000002],b[1000002];
char s[100002],a[1000002];
inline void work(){
	for(re int i=1;i<=n;++i){
		if(s[i]=='1'||((s[i-1]=='1')+(s[i+1]=='1')==1))a[i]='1';
		else a[i]='0';
	}
	for(re int i=1;i<=n;++i)s[i]=a[i];
}
signed main(){
	t=read();
	while(t--){
		n=read(),m=read();
		scanf("%s",s+1),m=min(m,n);s[n+1]=0;
		for(re int i=1;i<=m;++i)work();
		for(re int i=1;i<=n;++i)putchar(s[i]);
		puts("");
	}
}