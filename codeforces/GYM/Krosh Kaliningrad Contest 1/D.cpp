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
const int MAX = 5050;
lld dp[MAX];
lld nCr[MAX][MAX];
void solve(int tc){
	nCr[0][0] = 1;
	for(int e=1;e<MAX;e++){
		nCr[e][0] = 1;
		for(int p=1;p<=e;p++){
			nCr[e][p] = (nCr[e-1][p]+nCr[e-1][p-1])%mod;
		}
	}
	dp[0] = 2;
	dp[1] = 2;
	for(int e=2;e<MAX;e++){
		for(int p=1;p<=e;p++){
			lld xx = nCr[e][p];
			dp[e] = (dp[e]+dp[e-p]*xx)%mod;
		}
	}
	int k;
	scanf("%d",&k);
	printf("%lld\n",dp[k]);
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