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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
map<mp ,int> have; 
vector<mp > each;
int main(){
	int n,m;
	cin>>n>>m;
	rep(i,m){
		int ai,bi;
		scanf("%d %d",&ai,&bi);
		if(ai>bi) swap(ai,bi);
		have[{ai,bi}]=true;
		each.PB({ai,bi}); 
	}
	rb(i,1,n-1){
	
	if(n%i==0){
	int OK=true;
	for(auto it:each){
		int nex1=it.FIR+i,nex2=it.SEC+i;
		if(nex1>n) nex1-=n;
		if(nex2>n) nex2-=n;
		if(nex1>nex2) swap(nex1,nex2);
		if(!have[{nex1,nex2}]) {
			OK=false;
			break;
		}
	}
	if(OK){
		puts("YES");
		return 0;
	}	
	}
		
	}
	puts("NO");
	return 0;
}