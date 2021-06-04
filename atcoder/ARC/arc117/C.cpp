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

const int MAX = 404040;
const int mod = 3;
int dp[MAX],dp2[MAX];
int nCk(int n,int k){
	int f1 = dp[n];
	int f2 = dp[k] + dp[n-k];
	if(f1>f2) return 0;
	int k1 = dp2[n];
	int k2 = (dp2[k]*dp2[n-k])%mod;
	return (k1*k2)%mod;
}
void solve(int tc){
	dp[0] = 0;
	dp2[0] = 1;
	for(int e=1;e<MAX;e++){
		dp[e] = dp[e-1];
		dp2[e] = dp2[e-1];
		if(e%3==0){
			int ty = e;
			while(ty%3==0){
				ty/=3;
				dp[e]++;
			}
			if(ty) dp2[e] = (dp2[e]*ty)%mod;
		}
		else dp2[e] = (dp2[e]*e)%mod;
	}
	int n;
	cin >> n;
	string a;
	cin >> a;
	int ans = 0;
	for(int e=0;e<n;e++){
		int ty = 0;
		if(a[e]=='W') ty = 1;
		if(a[e]=='R') ty = 2;
		ans = (ans+ty*nCk(n-1,e))%mod;
	}
	if(n%2==0) ans = (3- ans)%mod;
	if(ans==0) cout << 'B';
	if(ans==1) cout << 'W';
	if(ans==2) cout << 'R';
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}