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

const int MAX_N = 1e9;
const int MAX = 505;
int dp[2][MAX][MAX*2];
int arr[MAX],n,k,B,C;
void solve(int tc){
	scanf("%d%d%d%d",&n,&k,&B,&C);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	for(int e=0;e<MAX;e++) for(int p=0;p<MAX;p++) dp[0][e][p] = dp[1][e][p] = MAX_N;
	dp[0][0][0] = 0;
	for(int e=1;e<=n;e++){
		int x = e&1;
		int nx = (e+1)&1;
		for(int p=0;p<=e;p++) for(int q=MAX-e;q<=MAX+e;q++) dp[x][p][q] = MAX_N;
		for(int p=0;p<e;p++){
			for(int q=MAX-(e-1);q<MAX+e;q++){
				dp[x][p][q] = min(dp[x][p][q],dp[nx][p][q]+arr[e]);
				if(p&&e-p+1<=k){
					dp[x][p][q] = min(dp[x][p][q],dp[nx][p][q]);
					dp[x][p][q+1] = min(dp[x][p][q+1],dp[nx][p][q]+arr[e]+C);
				}else{
					dp[x][p][q-1] = min(dp[x][p][q-1],dp[nx][p][q]+C);
				}
				if(q){
					dp[x][p][q-1] = min(dp[x][p][q-1],dp[nx][p][q]);
					dp[x][e][q-1] = min(dp[x][e][q-1],dp[nx][p][q]+arr[e]+B);
				}
				dp[x][e][q] = min(dp[x][e][q],dp[nx][p][q]+B);
				dp[x][e][q+1] = min(dp[x][e][q+1],dp[nx][p][q]+B+arr[e]+C);
			}
		}
	}
	int ans = 1e9;
	for(int e=0;e<=n;e++) ans = min(ans,dp[n&1][e][MAX]);
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
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}