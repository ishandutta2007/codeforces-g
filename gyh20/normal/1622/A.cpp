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
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans,A,B,C;
char s[1000002];
inline bool calc(re int x,re int y,re int z){
	if(x+y==z)return 1;
	if(x^y)return 0;
	return z%2==0;
}
int main(){ 
	t=read();//fzworz
	while(t--){
		ans=0;
		A=read(),B=read(),C=read();
		ans|=calc(A,B,C);
		ans|=calc(B,C,A);
		ans|=calc(A,C,B);
		puts(ans?"YES":"NO");
	}
}