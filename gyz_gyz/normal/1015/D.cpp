#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int m,x;ll n,k;
int main(){
	scanf("%I64d%d%I64d",&n,&m,&k);
	if(((n-1)*m<k)||(m>k)){printf("NO");return 0;}
	printf("YES\n");x=1;
	for(;m;m--){
		if(m-1>k-n+1)break;
		x=n+1-x;k-=n-1;printf("%d ",x);
	}
	for(;m>1;m--){k--;
		if(x==n)x--;
		else if(x==n-1)x++;
		else if(x==2)x--;
		else if(x==1)x++;
		printf("%d ",x);
	}
	if(k){if(x>k)x-=k;else x+=k;printf("%d",x);}
}