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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,m,a[1000002],b[1000002],ans,t;
char s[1000002];
int main(){
	t=read();
	while(t--){
		scanf("%s",s+1),n=strlen(s+1);
		re bool i0=1,i1=1;
		for(re int i=1;i<=n;++i)i0&=(s[i]=='1');
		if(i0){
			puts("0");
			continue;
		}
		re int ss=0;
		s[0]='1';
		s[n+1]='1';
		for(re int i=1;i<=n+1;++i)ss+=(s[i]!=s[i-1]);
		if(ss<=2)puts("1");
		else puts("2");
	}
}