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
const lld mod = 1e9 + 7;
lld dp[MAX];
void solve(int tc){
	int n,k;
	cin >> n >> k;
	lld ans = 0;
	dp[1] = 1;
	for(int e=2;e<=n;e++) dp[e] = (dp[e-1]*2)%mod;
	for(int p=k;p>=1;p--) dp[p] = (dp[p]-1+mod)%mod;
	for(int p=2;p<=n;p++) dp[p] = (dp[p]-1+mod)%mod;
	for(int e=1;e<=n;e++){
		ans = (ans+dp[e])%mod;
		for(int p=e+1;p<=n;p++){
			dp[p] = (dp[p]-dp[e]*2)%mod;
			if(dp[p]<0) dp[p] += mod;
		}
	}
	cout << ans;
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