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
int dp[MAX][MAX][2],arr[MAX],n,wh = -1;
int dfs(int l,int r,int x){
	if(dp[l][r][x]!=-1) return dp[l][r][x];
	dp[l][r][x] = 0;
	bool suc2 = false;
	for(int e=l;e<=r;e++){
		if(e+arr[e]>r) continue;
		bool suc = true;
		suc2 = true;
		for(int t=0;t<=1;t++){
			if((1^t^x)){
				int x1 = dfs(l,e-1,1);
				int x2 = dfs(e+arr[e]+1,r,t); 
				if(x1&&!x2) suc = false;
				int y1 = dfs(l,e-1,t);
				int y2 = dfs(e+arr[e]+1,r,1);
				if(y2&&!y1) suc = false;
			}
			if(!(0^t^x)){
				int x1 = dfs(l,e-1,0);
				int x2 = dfs(e+arr[e]+1,r,t);
				if(x1&&x2) suc = false;
				int y1 = dfs(l,e-1,t);
				int y2 = dfs(e+arr[e]+1,r,0);
				if(y1&&y2) suc = false;
			}
		}
		if(suc){
			dp[l][r][x] = 1;
			if(l==1&&r==n&&wh==-1) wh = e;
		}
	}
	if(!suc2){
		if(x==0) dp[l][r][x] = 1;
		else dp[l][r][x] = 0;
	}
	return dp[l][r][x];
}
void solve(int tc){
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	dfs(1,n,1);
	printf("%d\n",wh);
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