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
int arr[MAX],dp[MAX][MAX];
void solve(int tc){
	memset(dp,0,sizeof(dp));
	int n;
	cin >> n;
	for(int e=1;e<=n;e++) cin >> arr[e];
	sort(arr+1,arr+n+1);
	dp[0][0] = 1;
	for(int e=1;e<=n;e++){
		for(int p=1;p<=arr[e];p++){
			for(int q=0;q<=p;q++){
				dp[e][p] = (dp[e][p]+dp[e-1][q])%mod;
			}
		}
	}
	lld ans = 0;
	for(int e=1;e<=arr[n];e++) ans = (ans+dp[n][e])%mod;
	ans = (ans*n)%mod;
	printf("%lld\n",ans);
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}