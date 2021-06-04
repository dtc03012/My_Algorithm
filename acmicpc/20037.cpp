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

const int mod = 1e9 + 7;
const int MAX = 10101;
int fail[2][MAX],go[2][MAX];
vector<vector<vector<int> > > dp;
int dp2[2][MAX];
void solve(int tc){
	int n,k1,k2;
	string a[2];
	cin >> n >> k1 >> k2 >> a[0] >> a[1];
	if(k1==0){
		a[1] = a[0];
		a[0] = "";
	}
	if(k1>n){
		cout << "0";
		return;
	}
	memset(fail,-1,sizeof(fail));
	for(int e=0;e<2;e++){
		int j = -1;
		for(int p=1;p<sz(a[e]);p++){
			while(a[e][p]!=a[e][j+1]&&j!=-1) j = fail[e][j];
			if(a[e][p]==a[e][j+1]) fail[e][p] = ++j;
		}
	}
	for(int e=0;e<2;e++){
		for(int p=1;p<sz(a[e]);p++){
			int j = p - 1;
			while(a[e][j+1]==a[e][p]&&j!=-1) j = fail[e][j];
			if(a[e][j+1]!=a[e][p]) j++;
			go[e][p+1] = j + 1;
		}
	}
	if(k2>n){
		dp2[0][0] = 1;
		for(int e=1;e<=n;e++){
			int x = e&1;
			int lx = (e+1)&1;
			for(int p=0;p<=k1;p++) dp2[x][p] = 0;
			for(int p=1;p<=k1;p++){
				dp2[x][p] = (dp2[x][p]+dp2[lx][p-1])%mod;
				dp2[x][go[0][p]] = (dp2[x][go[0][p]]+dp2[lx][p-1])%mod;
			}
			dp2[x][k1] = (dp2[x][k1]+dp2[lx][k1])%mod;
			dp2[x][k1] = (dp2[x][k1]+dp2[lx][k1])%mod;
		}
		cout << dp2[n&1][k1];
		return;
	}
	dp = vector<vector<vector<int> > >(2,vector<vector<int> >(k1+1,vector<int>(k2+1,0)));
	dp[0][0][0] = 1;
	for(int e=1;e<=n;e++){
		int x = e&1;
		int lx = (e+1)&1;
		for(int p=0;p<=k1;p++) for(int q=0;q<=k2;q++) dp[x][p][q] = 0;
		for(int p=1;p<=k1;p++){
			for(int q=1;q<=k2;q++){
				if(a[0][p-1]==a[1][q-1]){
					dp[x][p][q] = (dp[x][p][q]+dp[lx][p-1][q-1])%mod;
					dp[x][go[0][p]][go[1][q]] = (dp[x][go[0][p]][go[1][q]]+dp[lx][p-1][q-1])%mod;
				}else{
					dp[x][go[0][p]][q] = (dp[x][go[0][p]][q]+dp[lx][p-1][q-1])%mod;
					dp[x][p][go[1][q]] = (dp[x][p][go[1][q]]+dp[lx][p-1][q-1])%mod;
				}
			}
		}
		for(int q=1;q<=k2;q++){
			dp[x][k1][q] = (dp[x][k1][q]+dp[lx][k1][q-1])%mod;
			dp[x][k1][go[1][q]] = (dp[x][k1][go[1][q]]+dp[lx][k1][q-1])%mod;
		}
	}
	int ans = 0;
	for(int e=0;e<k2;e++) ans = (ans+dp[n&1][k1][e])%mod;
	cout << ans;
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