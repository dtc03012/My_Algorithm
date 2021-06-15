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

const int MAX = 101010;
const lld mod = 1e9 + 7;
pl dp[MAX][2];
lld arr[MAX];
void modv(lld& x){
	x %= mod;
	x = ((x%mod)+mod)%mod;
}
void solve(int tc){
	int n;
	cin >> n;
	for(int e=1;e<=n;e++) cin >> arr[e];
	dp[1][0] = mk(arr[1],1);
	for(int e=2;e<=n;e++){
		dp[e][0].x = dp[e-1][0].x + dp[e-1][1].x + arr[e] * (dp[e-1][0].y+dp[e-1][1].y);
		dp[e][0].y = dp[e-1][0].y + dp[e-1][1].y;
		dp[e][1].x = dp[e-1][0].x - arr[e] * (dp[e-1][0].y);
		dp[e][1].y = dp[e-1][0].y;
		modv(dp[e][0].x);
		modv(dp[e][0].y);
		modv(dp[e][1].x);
		modv(dp[e][1].y);
	}
	lld xx = (dp[n][0].x+dp[n][1].x);
	modv(xx);
	cout << xx;
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