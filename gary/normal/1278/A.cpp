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
11.
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
void solve(){
	string s,h;
	cin>>s>>h;
	map<char ,int > cnt;

	int len=s.length(),len2=h.length();
	rep(i,len) cnt[s[i]]++;
	rb(i,0,len2-len){
		map<char,int > cnt2;
		rep(j,len){
			cnt2[h[i+j]]++;
		}
		if(cnt==cnt2)
		{
			cout<<"YES\n";
			return ;
		}
	}
	cout<<"NO\n";
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}