#include<algorithm>
using namespace std;long long k,l,r,t,x,y;int main(){if(scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&k,&l,&r,&t,&x,&y),r-=l,k-=l,x<y)for(t-=min(t,k/x),l=k%=x,r<k+y?k=l:(t-=min(t,(k+=y)/x),t*=(k%=x)!=l);t&&k!=l; r<k+y?k=l:(t-=min(t,(k+=y)/x),t*=(k%=x)!=l));else r<k+y?k-=y:0,t=k<0||k/t+y<x;printf(t?"No\n":"Yes\n");}