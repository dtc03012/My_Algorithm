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

const lld mod = 998244353;
const int MAX = 1005;
int dp[MAX][MAX][2][2][2];
void solve(int tc){
	string a,b;
	cin >> a >> b;
	int ans = 0;
	for(int e=0;e<=sz(a);e++){
		for(int p=0;p<=sz(b);p++){
			// a
			if(e){
				int lxf = -1,lxs = -1;
				if(e-1){
					lxf = a[e-2] - 'a'; 
				}
				if(p){
					lxs = b[p-1] - 'a';
				}
				int ch = a[e-1] - 'a';
				if(ch!=lxf){
					for(int r=0;r<2;r++){
						for(int t=0;t<2;t++){
							dp[e][p][0][1][t] = (dp[e][p][0][1][t]+dp[e-1][p][0][r][t])%mod;
						}
					}
				}
				if(ch!=lxs){
					for(int r=0;r<2;r++){
						for(int t=0;t<2;t++){
							dp[e][p][0][1][t] = (dp[e][p][0][1][t]+dp[e-1][p][1][r][t])%mod;
						}
					}
				}
				dp[e][p][0][1][0] = (dp[e][p][0][1][0]+1)%mod;
			}
			// b
			if(p){
				int lxf = -1,lxs = -1;
				if(e){
					lxf = a[e-1] - 'a'; 
				}
				if(p-1){
					lxs = b[p-2] - 'a';
				}
				int ch = b[p-1] - 'a';
				if(ch!=lxf){
					for(int r=0;r<2;r++){
						for(int t=0;t<2;t++){
							dp[e][p][1][r][1] = (dp[e][p][1][r][1]+dp[e][p-1][0][r][t])%mod;
						}
					}
				}
				if(ch!=lxs){
					for(int r=0;r<2;r++){
						for(int t=0;t<2;t++){
							dp[e][p][1][r][1] = (dp[e][p][1][r][1]+dp[e][p-1][1][r][t])%mod;
						}
					}
				}
				dp[e][p][1][0][1] = (dp[e][p][1][0][1]+1)%mod;
			}
			ans = (ans+dp[e][p][0][1][1])%mod;
			ans = (ans+dp[e][p][1][1][1])%mod;
		}
	}
	printf("%d\n",ans);
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