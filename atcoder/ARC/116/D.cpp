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
lld dp[12][MAX],fact[MAX],nCr[MAX][MAX];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=0;e<MAX;e++){
		nCr[e][0] = nCr[e][e] = 1;
	}
	for(int e=2;e<MAX;e++){
		for(int p=1;p<e;p++){
			nCr[e][p] = (nCr[e-1][p]+nCr[e-1][p-1])%mod;
		}
	}
	lld ans = 0;
	for(int e=0;e<=m;e+=2) dp[0][e] = nCr[n][e];
	for(int e=1;e<12;e++){
		for(int p=0;p<=m;p+=(1<<e)*2){
			for(int q=0;q<=m-p;q++){
				dp[e][q+p] = (dp[e][q+p]+dp[e-1][q]*nCr[n][p/(1<<e)])%mod;
			}
		}
	}
	printf("%lld\n",dp[11][m]);
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