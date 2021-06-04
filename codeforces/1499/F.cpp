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
const int mod = 998244353;
int dp[MAX][MAX],dp2[MAX][MAX];
int len[MAX];
int n,k;
vector<int> v[MAX];
int dfs(int x,int lx){
	dp[x][0] = 1;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			int f = dfs(nx,x);
			for(int p=0;p<=len[x];p++) dp2[x][p] = 0;
			for(int p=len[x];p>=0;p--){
				for(int q=len[nx];q>=0;q--){
					if(p+q>=k) continue;
					int now = (1ll*dp[x][p]*dp[nx][q])%mod;
					dp2[x][max(p,q+1)] = (dp2[x][max(p,q+1)]+now)%mod;
					len[x] = max(len[x],max(p,q+1));
				}
				int now = (1ll*dp[x][p]*f)%mod;
				dp2[x][p] = (dp2[x][p]+now)%mod;
			}
			for(int q=0;q<=len[x];q++) dp[x][q] = dp2[x][q];
		}
	}
	len[x] = min(len[x],k);
	int tot = 0;
	for(int e=0;e<=k;e++) tot = (tot+dp[x][e])%mod;
	return tot;
}
void solve(int tc){
	scanf("%d%d",&n,&k);
	for(int e=0;e<n-1;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,-1);
	int ans = 0;
	for(int e=0;e<=k;e++) ans = (ans+dp[1][e])%mod;
	printf("%d\n",ans);
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