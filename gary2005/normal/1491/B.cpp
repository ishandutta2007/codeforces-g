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
int a[101];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		int u,v;
		scanf("%d%d",&u,&v);
		rb(i,1,n) scanf("%d",&a[i]);
		int ans=INF;
		bool ok=0;
		rb(i,2,n){
			if(abs(a[i]-a[i-1])>1){
				ans=0;
				break;
			}
			if(abs(a[i]-a[i-1])==1){
				ok=1;
			}
		}
		if(ans==0){
			puts("0");
		}
		else{
			if(ok){
				printf("%d\n",min(u,v));
			}
			else{
				printf("%d\n",v+min(u,v));
			}
		}
	}
	return 0;
}