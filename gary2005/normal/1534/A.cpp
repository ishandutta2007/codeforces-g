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
int t;
int n,m;
char c[55][55];
char one[55][55];
bool eq(){
	rb(i,1,n) rb(j,1,m) if(c[i][j]!='.') if(one[i][j]!=c[i][j]) return false;
	return true;
}
void solve(){
	scanf("%d%d",&n,&m);
	rb(i,1,n) rb(j,1,m) cin>>c[i][j];
	rb(i,1,n) rb(j,1,m) if((i+j)&1) one[i][j]='R';else one[i][j]='W';
	if(eq()){
		cout<<"YES"<<endl;
		rb(i,1,n){
			rb(j,1,m){
				cout<<one[i][j];
			}
			cout<<endl;
		}
		return ;
	}
	rb(i,1,n) rb(j,1,m) if((i+j)&1) one[i][j]='W';else one[i][j]='R';
	if(eq()){
		cout<<"YES"<<endl;
		rb(i,1,n){
			rb(j,1,m){
				cout<<one[i][j];
			}
			cout<<endl;
		}
		return ;
	}
	cout<<"NO"<<endl;
}
int main(){
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}