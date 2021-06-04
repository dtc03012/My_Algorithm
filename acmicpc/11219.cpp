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

lld dp[40],dp2[40];
void solve(int tc){
	lld n,ans = 0,res = 0;
	dp[0] = dp2[0] = 1;
	for(int e=1;e<40;e++){
		lld tot = 0;
		for(int p=e-1;p>=0;p--) tot += dp[p];
		dp[e] = tot * 2;
		dp2[e] = dp[e] + dp2[e-1];
	}
	cin >> n;
	for(int e=39;e>=0;e--){
		if(n<=(1ll<<(e+1))&&n>(1ll<<e)){
			ans += (1ll<<res)*dp2[e];
			n -= (1ll<<e);
			res++;
		}
	}
	ans += (1ll<<res);
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