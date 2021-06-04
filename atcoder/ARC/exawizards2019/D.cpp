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
const int MAX = 202;
const lld mod = 1e9 + 7;
const int NMAX = 101010;
lld vv[MAX],dp[MAX][NMAX],nCr[MAX][MAX];
int n,x,arr[MAX];
lld dfs(int n,int x){
	if(n==0) return x;
	if(dp[n][x]!=-1) return dp[n][x];
	dp[n][x] = 0;
	for(int e=n;e>=1;e--){
		lld lv = (nCr[n-1][n-e]*vv[n-e])%mod;
		lld rv = dfs(e-1,x%arr[e]);
		dp[n][x] = (dp[n][x]+lv*rv)%mod;
	}
	return dp[n][x];
}
void solve(int tc){
	memset(dp,-1,sizeof(dp));
	nCr[0][0] = 1;
	for(int e=1;e<MAX;e++){
		nCr[e][0] = 1;
		for(int p=1;p<=e;p++){
			nCr[e][p] = (nCr[e-1][p]+nCr[e-1][p-1])%mod; 
		}
	}
	vv[0] = 1;
	for(int e=1;e<MAX;e++) vv[e] = (vv[e-1]*e)%mod;
	scanf("%d%d",&n,&x);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	sort(arr+1,arr+1+n);
	printf("%lld\n",dfs(n,x));
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}