/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
8. CSPday2 meal
9.-or
10.
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int p[400000+10],sum[400000+10];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum1=n;
		vector<int> v;
		rb(i,1,n) scanf("%d",&p[i]);
		int cnt=0,las=-1;
		rb(i,1,n){
			cnt++;
			if(p[i]!=las){
				if(las!=-1)
				{
					v.PB(cnt-1);
				}
				cnt=1;
			}
			las=p[i];
		}
		v.PB(cnt);
		n=v.size();
		rep(i,n){
			if(i==0){
				sum[0]=v[i];
			}
			else{
				sum[i]=sum[i-1]+v[i];
			}
		}
		int g=0,s=0,b=0;
		rb(i,1,n-1){
			if(sum[i]-sum[0]>sum[0]){
				s=i;
				break;
			}
		}
		if(s==0){
			puts("0 0 0");
			continue;
		}
		rb(i,1,n-1){
			if(sum[i]-sum[s]>sum[0])
			{
				b=i;
				break;
			}
		}
		if(b==0){
			puts("0 0 0");
			continue;
		}
		if(sum[b]*2>sum1){
			puts("0 0 0");
			continue;
		}
		while(sum[b+1]*2<=sum1){
			b++;
		}
		printf("%d %d %d\n",sum[0],sum[s]-sum[0],sum[b]-sum[s]);
	}
	return 0;
}