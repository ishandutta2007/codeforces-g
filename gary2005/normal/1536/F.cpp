/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MOD=1e9+7;
const int MAXN=2e6+7;
int fact[MAXN],ifact[MAXN];
int n;
int quick(int A,int B){
	int ret=1;
	while(B){
		if(B&1) ret=1ll*ret*A%MOD;
		B>>=1;
		A=1ll*A*A%MOD;
	}
	return ret;
}
int inv(int A){return quick(A,MOD-2);}
int C(int A,int B){
	return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
}
int main(){
	scanf("%d",&n);
	fact[0]=1;
	rb(i,1,2e6) fact[i]=1ll*fact[i-1]*i%MOD;
	rb(i,0,2e6) ifact[i]=inv(fact[i]);
	int ans=0;
	rb(i,0,n/2){
		if(i%2==n%2){
			int tot=C(n-i,i);
			if(i>=1){
				(tot+=C(n-i,i-1))%=MOD;
				if(i>=2){
					(tot+=MOD-C(n-i-1,i-2))%=MOD;
				}
			}
			(ans+=2ll*tot*fact[n-i]%MOD)%=MOD;
		}
	}
	printf("%d\n",ans);
	return 0;
}