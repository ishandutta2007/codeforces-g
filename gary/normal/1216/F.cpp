//* AuThOr GaRyMr *//
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
set<pair<mp/*r_bound,l_bound*/,int> >  set_;
LL dp[200000+10];
int main(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	rep(i,n) {
		if(s[i]=='1'){
			int i_=i+1;
			set_.insert(II(II(min(n,i_+k),max(1,i_-k)),i_));
//			cout<<min(n,i_+k)<<" "<<max(1,i_-k)<<endl;
		}
	} 
	rb(i,1,n){
		dp[i]=dp[i-1]+i;
		set<pair<mp/*r_bound,l_bound*/,int> > :: IT ite=set_.lower_bound(II(II(i,-INF),-INF));
		if(ite!=set_.end()){
			int mid_bound=(*ite).SEC,l_bound=(*ite).FIR.SEC;
			if(l_bound>i) continue;
//			cout<<i<<" "<<" "<<mid_bound<<" "<<dp[1]<<endl; 
			dp[i]=min(dp[i],dp[l_bound-1]+mid_bound);
		}
	}
//	cout<<(set_.lower_bound(II(II(5,INF),INF))==set_.end())<<endl;
	cout<<dp[n]<<endl;
	return 0;
}