/*
AuThOr GaRyMr
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
#define FREO freopen("check.out","w",stdout)//
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int res[200000+1];
int maxi[26];
int main(){
	fastio;
	int n;
	cin>>n;
	string s;
	cin>>s;
	rep(i,n){
		int Key=s[i]-'a';
		int M=0;
		rb(j,Key+1,25){
			M=max(M,maxi[j]);
		}
		res[i]=M+1;
		maxi[Key]=max(maxi[Key],res[i]);
	}
	int Res=-1;
	rep(i,n)
		Res=max(Res,res[i]);
		cout<<Res<<endl;
	rep(i,n)
		cout<<res[i]<<" ";
	return 0;
}