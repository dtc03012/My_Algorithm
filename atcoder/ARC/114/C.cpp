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

const int MAX = 5050;
const lld mod = 998244353;
lld dp[MAX][MAX];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=m;e++){
		dp[e][0] = 1;
		for(int p=1;p<=n;p++) dp[e][p] = (dp[e][p-1]*e)%mod;
	}
	lld ans = 0;
	for(int e=1;e<=m;e++){
		for(int p=1;p<=n;p++){
			lld vv = dp[m-e+1][p];
			vv -= dp[m-e][p];
			vv =(vv%mod+mod)%mod;
			if(p==n){
				ans = (ans+vv)%mod;
			}else{
				lld xx = 0;
				lld f1 = vv;
				f1 = (f1*(e-1))%mod;
				f1 = (f1*dp[m][n-p-1])%mod;
				ans = (ans+f1)%mod;
				ans = (ans+f1)%mod;
				if(p<n-1){
					lld f2 = vv;
					f2 = (f2*(e-1))%mod;
					f2 = (f2*(e-1))%mod;
					f2 = (f2*dp[m][n-p-2])%mod;
					f2 = (f2*(n-p-1))%mod;
					ans = (ans+f2)%mod;
				}
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
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}