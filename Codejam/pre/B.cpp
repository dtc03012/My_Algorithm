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

const int MAX = 1111;
int dp[MAX][2];
void solve(int tc){
	int x,y;
	string a;
	cin >> x >> y >> a;
	for(int e=0;e<sz(a);e++){
		dp[e][0] = dp[e][1] = 1e9;
	}
	if(a[0]=='C') dp[0][0] = 0;
	else if(a[0]=='J') dp[0][1] = 0;
	else{
		dp[0][0] = dp[0][1] = 0;
	}
	for(int e=1;e<sz(a);e++){
		if(a[e]=='C'){
			dp[e][0] = min(dp[e-1][0],dp[e-1][1]+y);
		}else if(a[e]=='J'){
			dp[e][1] = min(dp[e-1][1],dp[e-1][0]+x);
		}else{
			dp[e][0] = min(dp[e-1][0],dp[e-1][1]+y);
			dp[e][1] = min(dp[e-1][1],dp[e-1][0]+x);
		}
	}
	int ans = 1e9;
	if(dp[sz(a)-1][0]!=1e9) ans = dp[sz(a)-1][0];
	if(dp[sz(a)-1][1]!=1e9) ans = min(ans,dp[sz(a)-1][1]);
	cout << "Case #" << tc << ": " << ans << "\n";
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