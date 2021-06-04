#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
typedef pair<lld,lld> pl;
typedef pair<int,lld> pil;
typedef pair<lld,int> pli;
typedef vector<int> vit;
typedef vector<vit> vitt;
typedef vector<lld> vlt;
typedef vector<vlt> vltt;
typedef vector<pi> vpit;
typedef vector<vpit> vpitt;
typedef long double ld;
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
bool isrange(int y,int x,int n,int m){
	 if(0<=y&&y<n&&0<=x&&x<m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};

const int MAX = 404;
lld mod;
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod; 
}
lld dp[MAX][MAX];
lld dp2[MAX],dp3[MAX],dp4[MAX];
void solve(int tc){
	int n;
	cin >> n >> mod;
	dp2[0] = 1;
	dp3[0] = 1;
	for(int e=1;e<MAX;e++){
		dp2[e] = (dp2[e-1]*e)%mod;
		dp3[e] = calc(dp2[e],mod-2);
	}
	dp4[1] = 1;
	dp4[2] = 2;
	dp4[3] = 4;
	for(int e=4;e<MAX;e++){
		for(int p=1;p<=e;p++){
			int ll = p - 1;
			int rr = e - p;
			lld xx = (dp2[ll]*dp2[rr])%mod;
			lld vv = (dp2[ll+rr]*calc(xx,mod-2))%mod;
			dp4[e] = (dp4[e]+vv)%mod;
		}
	}
	dp[0][0] = 1;
	lld ans = dp4[n];
	for(int e=2;e<=n;e++){
		for(int p=e-2;p>=0;p--){
			int diff = e - p - 1;
			lld xx = dp4[diff];
			for(int q=0;q<=n;q++){
				lld vv = dp[p][q];
				vv = (vv*xx)%mod;
				vv = (vv*dp3[diff])%mod;
				dp[e][q+1] = (dp[e][q+1]+vv)%mod;
			}
		}
		if(e<n){
			lld xx = dp4[n-e];
			for(int q=0;q<=n;q++){
				lld vv = dp[e][q];
				vv = (vv*xx)%mod;
				vv = (vv*dp3[n-e])%mod;
				vv = (vv*dp2[n-q])%mod;
				ans = (ans+vv)%mod;
			}
		}
	}
	cout << ans << "\n";
}
void init(){
}
int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc = 1;
	init();
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}