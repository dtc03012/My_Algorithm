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

const int MAX = 6010101;
const lld mod = 1e9 + 7;
lld dp[MAX];
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
lld divs(lld a,lld b){
	return (a*calc(b,mod-2))%mod;
}
lld nCr(int x,int y){
	lld f1 = dp[x];
	lld f2 = (dp[y]*dp[x-y])%mod;
	return (f1*calc(f2,mod-2))%mod;
}
void solve(int tc){
	int n,m,k;
	cin >> n >> m >> k;
	dp[0] = 1;
	for(int e=1;e<MAX;e++) dp[e] = (dp[e-1]*e)%mod;
	lld ans1 = divs(dp[n+m],(dp[n]*dp[m])%mod);
	lld ans2 = 0;
	for(int e=0;e<=n+m;e++){
		int now = e + k;
		if(now%2==0){
			now /= 2;
			if(e>=now&&n>=now+1&&m>=e-now){
				lld k1 = divs(nCr(2*now,now),now+1);
				lld res = n + m - (e + 1);
				lld N = n - (now + 1);
				lld M = res - N;
				if(res < 0 || N < 0 || M < 0) continue;
				k1 = (k1 * divs(dp[res],(dp[N]*dp[M])%mod))%mod;
				ans2 = (ans2 + k1)%mod;
			}
		}
	}
	ans1 -= ans2;
	ans1 = (ans1%mod+mod)%mod;
	cout << ans1;
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