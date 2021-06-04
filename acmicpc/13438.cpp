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

const lld mod = 1e9 + 9;
const int MAX = 111;
lld dp[MAX][MAX][MAX];
int fail[MAX];
void solve(int tc){
	memset(fail,-1,sizeof(fail));
	int n;
	string a;
	cin >> n >> a;
	int j = -1;
	for(int p=1;p<sz(a);p++){
		while(a[j+1]!=a[p]&&j!=-1) j = fail[j];
		if(a[j+1]==a[p]) fail[p] = ++j;
	}
	dp[0][0][0] = 1;
	for(int e=1;e<=n;e++){
		for(int p=0;p<=n;p++){
			for(int q=1;q<=sz(a);q++){
				if(a[q-1]=='D'){
					dp[e][p][q] = (dp[e][p][q]+dp[e-1][p+1][q-1])%mod;
					if(p&&q>=1){
						int x = q - 2;
						while(a[x+1]!='U'&&x!=-1) x = fail[x];
						if(a[x+1]=='U') x++;
						dp[e][p][x+1] = (dp[e][p][x+1]+dp[e-1][p-1][q-1])%mod;
					}
				}else{
					if(p) dp[e][p][q] = (dp[e][p][q]+dp[e-1][p-1][q-1])%mod;
					if(q>=1){
						int x = q - 2;
						while(a[x+1]!='D'&&x!=-1) x = fail[x];
						if(a[x+1]=='D') x++;
						dp[e][p][x+1] = (dp[e][p][x+1]+dp[e-1][p+1][q-1])%mod;
					}
				}
				if(q==sz(a)){
					dp[e][p][q] = (dp[e][p][q]+dp[e-1][p+1][q])%mod;
					if(p) dp[e][p][q] = (dp[e][p][q]+dp[e-1][p-1][q])%mod;
				}
			}
		}
	}
	lld ans = dp[n][0][sz(a)];
	printf("%lld\n",ans);
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