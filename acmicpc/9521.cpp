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

const int MAX = 1e6 + 100;
const lld mod = 1e9 + 7;
vector<int> v[MAX];
int vis[MAX],ck[MAX],num = 0;
stack<int> s;
int cyc = 0;
int getsz(int x,int c){
	int tot = 1;
	vis[x] = c;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(vis[nx]==0) tot += getsz(nx,c+1);
		else if(vis[x]>vis[nx]&&vis[x]-vis[nx]>1){
			 cyc = vis[x] - vis[nx] + 1;
		}
	}
	return tot;
}
lld c1[MAX],dp[MAX];
void solve(int tc){
	lld n,k;
	cin >> n >> k;
	dp[1] = k;
	dp[2] = (k*(k-1))%mod;
	dp[3] = (k*(k-1)*(k-2))%mod;
	for(int e=4;e<MAX;e++){
		lld x = ((k-2)*(k-2)+(k-1))%mod;
		dp[e] = (dp[e-2]*x)%mod;
	}
	c1[0] = 1;
	for(int e=1;e<MAX;e++) c1[e] = (c1[e-1]*(k-1))%mod;
	for(int e=1;e<=n;e++){
		int k;
		cin >> k;
		v[e].push_back(k);
		v[k].push_back(e);
	}
	lld ans = 1;
	for(int e=1;e<=n;e++){
		if(vis[e]==0){
			cyc = 1;
			int tot = getsz(e,1);
			lld vv1 = (c1[tot-cyc] * dp[cyc])%mod;
			ans = (ans * vv1)%mod;
		}
	}
	cout << ans;
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}