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

const int MAX = 1010;
const lld mod = 1e9 + 7;
lld dp[MAX][8];
void solve(int tc){
	int n;
	scanf("%d",&n);
	dp[1][0] = 1;
	for(int e=2;e<=n+1;e++){
		dp[e][0] = (dp[e-1][0]+dp[e-1][2]+dp[e-1][3])%mod;
		dp[e][1] = (dp[e-1][1]+dp[e-1][4]+dp[e-1][5]+dp[e-1][6]+dp[e-1][7])%mod;
		dp[e][2] = dp[e-1][0];
		dp[e][3] = dp[e-1][2];
		dp[e][4] = dp[e-1][1];
		dp[e][5] = (dp[e-1][4]+dp[e-1][6])%mod;
		dp[e][6] = (dp[e-1][0]+dp[e-1][1])%mod;
		dp[e][7] = (dp[e-1][2]+dp[e-1][4])%mod;
	} 
	printf("%lld",dp[n+1][1]);
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