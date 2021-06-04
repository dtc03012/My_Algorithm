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

const lld mod = 1e9 + 7;
const int MAX = (1<<16) + 100;
const int NMAX = (1<<8);
int W[MAX],n;
char a[5];
lld ans;
vector<int> v[MAX];
lld dp[NMAX][NMAX],tmp[MAX][NMAX];
int f(int x,int y){
	if(a[0]=='A') return x&y;
	if(a[0]=='O') return x|y;
	if(a[0]=='X') return x^y;
}
void dfs(int x){
	int A = (W[x]>>8), B = (W[x]%NMAX);
	lld xx = 0;
	for(int e=0;e<NMAX;e++) if(dp[e][B]!=-1) xx = max(xx,dp[e][B]+f(e,A)*NMAX);
	ans = (ans+1LL*(xx+W[x])*x)%mod;
	for(int e=0;e<NMAX;e++){
		tmp[x][e] = dp[A][e];
		dp[A][e] = max(dp[A][e],xx+f(e,B));
	}
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];dfs(nx);
	}
	for(int e=0;e<NMAX;e++) dp[A][e] = tmp[x][e];
}
void solve(int tc){
	scanf("%d%s",&n,a);
	for(int e=1;e<=n;e++) v[e].clear();
	for(int e=1;e<=n;e++) scanf("%d",&W[e]);
	for(int e=2;e<=n;e++){
		int k;
		scanf("%d",&k);
		v[k].push_back(e);
	}
	ans = 0;
	dfs(1);
	printf("%lld\n",ans);
}


int main(void){
	
	memset(dp,-1,sizeof(dp));
	int tc = 1;
	
	scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}