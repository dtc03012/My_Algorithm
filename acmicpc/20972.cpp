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
int gx[4] = {0,1,0,1},gy[4] = {0,0,1,1};
const int MAX = 1010;
int A[2][MAX],B[2][MAX],dp[MAX][4],n;
int getn(int K[2][MAX]){
	for(int q=0;q<4;q++) dp[0][q] = 0;
	for(int e=1;e<=n;e++){
		for(int q=0;q<4;q++){
			dp[e][q] = 0;
			for(int r=0;r<4;r++){
				int tot = r + q*4;
				int vv = 0;
				for(int t=0;t<4;t++) if(tot&(1<<t)) vv++;
				if(vv==2){
					int xx = 0;
					if(q==1) xx = K[0][e];
					if(q==2) xx = K[1][e];
					if(q==3) xx = K[0][e] + K[1][e];
					dp[e][q] = max(dp[e][q],dp[e-1][r]+xx);
				}
			}
		}
	}
	int ans = 0;
	for(int e=0;e<4;e++) ans = max(ans,dp[n][e]);
	return ans;
}
void solve(int tc){
	cin >> n;
	for(int e=0;e<n;e++){
		for(int p=0;p<n;p++){
			int r;
			cin >> r;
			A[e%2][p+1] += r;
			B[p%2][e+1] += r;
		}
	}
	cout << max(getn(A),getn(B));
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