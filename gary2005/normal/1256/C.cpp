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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int c[1001];
int main(){
	int n,m,d;
	cin>>n>>m>>d;
	int tot=0;
//	cin>>n>>m>>d	;	
	rb(i,1,m) cin>>c[i],tot+=c[i];
	int maxi=(m+1)*(d-1);
//	cout<<maxi<<endl;
	if(tot+maxi>=n) {
		cout<<"YES"<<endl;
		int need=tot+maxi-n;
		need=max(need,0);
//		cout<<need<<endl;
		rb(i,1,m)
		{
//			if(need){
			int is=max(0,d-1-need);
			need-=d-1-is;
			rb(j,1,is){
				cout<<"0 ";
			}	
			//} 
//			else{
//				rb(j,1,d-1)
//				{
//					
//				}
//			}
			rb(j,1,c[i]) cout<<i<<" " ; 
		} 
		int is=max(0,d-1-need);
			need-=d-1-is;
		rb(j,1,is){
				cout<<"0 ";
		}	
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;	
}