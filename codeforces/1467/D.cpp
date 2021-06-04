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
const int MAX = 5050;
const lld mod = 1e9 + 7;
lld dp[MAX][MAX],tot[MAX],val[MAX],kk[MAX];
void solve(int tc){
	int n,k,q;
	scanf("%d%d%d",&n,&k,&q);
	for(int e=1;e<=n;e++){
		dp[e][0] = 1;
		scanf("%lld",&val[e]);
	}
	for(int e=1;e<=k;e++){
		for(int p=1;p<=n;p++){
			lld xx = 0;
			if(p>1) xx = dp[p-1][e-1];
			if(p<n) xx = (xx+dp[p+1][e-1])%mod;
			dp[p][e] = xx;
		}
	}
	for(int e=1;e<=n;e++){
		for(int p=0;p<=k;p++){
			lld xx = 1;
			if(p) xx = (xx*dp[e][p])%mod;
			if(p<k) xx = (xx*dp[e][k-p])%mod;
			tot[e] = (tot[e]+xx)%mod;
		}
	}
	lld ans = 0;
	for(int e=1;e<=n;e++) ans = (ans+val[e]*tot[e])%mod;;
	while(q--){
		int x,v;
		scanf("%d%d",&x,&v);
		lld diff = v - val[x];
		diff %= mod;
		diff = (diff+mod)%mod;
		ans = (ans+diff*tot[x])%mod;
		val[x] = v;
		printf("%lld\n",ans);
	}
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}