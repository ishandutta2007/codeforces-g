/*
AuThOr Gwj
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;

#define PI 3.1415926535897932384626433832795
int main(){
//	fastio;
	int t;
	cin>>t;
	while(t--){
		double n;
		cin>>n;
		if(n==3.0)
		{
			
		n*=2.0;
		double an=PI/n;
		double side=0.5/tan(an);
		side+=0.5;
		side*=1.414213562373095;
		printf("%.10f\n",side);
		}
		else{
			n*=2.0;
			double an=PI/n;
			double side=0.5/sin(an);
			double r=side;
			double angle=360.0/n;
			double base=angle;
			while(angle<90.0){
				angle+=base;
			}
			angle-=90.0;
			angle/=2.0;
			angle*=PI;
			angle/=180.0;
			r*=2.0; 
			printf("%.10f\n",r*cos(angle));
		}
	}
	return 0;
}