//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
void solve(){
	int b,p,f;
	cin>>b>>p>>f;
	int h,c;
	cin>>h>>c;
	int res=0;
	if(h>c){
		int have=min(b/2,p);
		res+=have*h;
		b-=have*2;
		have=min(b/2,f);
		res+=have*c;
		b-=have*2;
	}
	else{
		int have=min(b/2,f);
		res+=have*c;
		b-=have*2;
		have=min(b/2,p);
		res+=have*h;
		b-=have*2;
		
	}
	cout<<res<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}