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


const int MAX = 3030;
const lld mod = 998244353;
bool can[MAX][MAX];
int arr[MAX];
lld dp[MAX][MAX],dp2[MAX][MAX];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	for(int e=1;e<=n;e++){
		int lx = -1;
		for(int p=e;p<=n;p++){
			if(arr[p]>lx){
				can[e][p] = true;
			}else{
				break;
			}
			lx = arr[p];
		}
	}
	dp[0][0] = 1;
	for(int e=1;e<MAX;e++){
		for(int p=0;p<=e;p++){
			dp[e][p] = (dp[e-1][p]+dp[e-1][p-1])%mod;
		}
	}
	dp2[0][0] = 1;
	for(int e=1;e<=m;e++){
		for(int p=1;p<=e;p++){
			dp2[e][p] = (dp2[e-1][p]*2*p + dp2[e-1][p-1])%mod;
		}
	}
	lld ans = 0;
	for(int e=0;e<=n;e++){
		for(int p=n+1;p>e;p--){
			if(e+1>p-1||can[e+1][p-1]){
				ans = (ans + dp2[m][e+n-p+1]*dp[e+n-p+1][e])%mod;
			}
		}
	}
	printf("%lld\n",ans);
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