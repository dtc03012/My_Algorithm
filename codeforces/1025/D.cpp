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

const int MAX = 777;

int arr[MAX],dp[MAX][MAX][2],can[MAX][MAX],n;
int dfs(int l,int r,int ty){
	printf("%d %d\n",l,r);
	if(l>r) return 1;
	if(l==r){
		if(ty==0){
			return can[l-1][l];
		}else{
			return can[l+1][l];
		}
	}
	if(dp[l][r][ty]!=-1) return dp[l][r][ty];
	dp[l][r][ty] = 0;
	for(int p=l;p<=r;p++){
		if(ty==0&&can[l-1][p]){
			if(dfs(l,p-1,1)&&dfs(p+1,r,0)){
				dp[l][r][ty] = 1;
			}
		}
		if(ty==1&&can[r+1][p]){
			if(dfs(l,p-1,1)&&dfs(p+1,r,0)){
				dp[l][r][ty] = 1;
			}
		}
	}
	return dp[l][r][ty];
}
void solve(int tc){
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	for(int e=1;e<=n;e++){
		can[0][e] = 1;
		for(int p=1;p<=n;p++){
			if(e==p) continue;
			int xx = __gcd(arr[e],arr[p]);
			if(xx>1){
				can[e][p] = 1;
			}
		}
	}
	bool suc = dfs(1,n,0);
	if(suc) printf("Yes\n");
	else printf("No\n");
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