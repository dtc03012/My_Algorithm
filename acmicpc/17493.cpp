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

const int MAX = 202020;

vector<int> v[MAX];
int dp[MAX][3],vis[MAX];
void dfs(int x,int lx){
	vis[x] = 1;
	bool suc = false;
	bool can = true;
	vector<pi> k;
	int f0 = 0,f2 = 0,fv1 = 0,f1 = 1e9;
	for(auto nx : v[x]){
		if(nx!=lx){
			dfs(nx,x);
			suc = true;
			int mm = 1e9;
			for(int e=0;e<3;e++){
				mm = min(mm,dp[nx][e]);
			}
			f0 += mm;
			if(dp[nx][1]==1e9) can = false;
			else f2 += dp[nx][1];
			fv1 += min(dp[nx][0],dp[nx][1]);
		}
	}
	for(auto nx : v[x]){
		if(nx!=lx){
			f1 = min(f1,fv1-min(dp[nx][0],dp[nx][1])+dp[nx][0]);
		}
	}
	dp[x][0] = f0 + 1;
	dp[x][1] = f1;
	if(can) dp[x][2] = f2;
}
void solve(int tc){
	for(int e=0;e<MAX;e++) for(int p=0;p<3;p++) dp[e][p] = 1e9;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans = 0;
	for(int e=1;e<=n;e++){
		if(vis[e]==0){
			dfs(e,-1);
			ans += min(dp[e][0],dp[e][1]);
		}
	}
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