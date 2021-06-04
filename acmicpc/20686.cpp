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

const int NMAX = 1010;
const int MMAX = 11;
const int lim = 10050;
short dp[lim][NMAX][MMAX][2];
int A[NMAX],B[NMAX],C[NMAX];
main()
{
	short one = 1;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int e=1;e<=n;e++) cin >> A[e];
	for(int e=n;e>=1;e--) C[e] = C[e+1] + A[e];
	for(int e=1;e<=n;e++) cin >> B[e];
	memset(dp,-1,sizeof(dp));
	dp[1][1][1][0] = 0;
	dp[1][1][1][1] = 0;
	for(int e=1;e<lim-1;e++){
		for(int p=1;p<=n;p++){
			for(int q=1;q<=B[p];q++){
				if(dp[e][p][q][0]==-1) continue;
				short x = dp[e][p][q][0];
				short y = dp[e][p][q][1];
				if(B[p]==q&&A[x]==y){
					if(x+1>dp[e+1][p+1][1][0]){
						dp[e+1][p+1][1][0] = x + 1;
						dp[e+1][p+1][1][1] = one;
					}else if(x+1==dp[e+1][p+1][1][0]){
						dp[e+1][p+1][1][1] = max(dp[e+1][p+1][1][1],one);
					}
					if(p+2<=n){
						if(x+1>dp[e+1][p+2][1][0]){
							dp[e+1][p+2][1][0] = x + 1;
							dp[e+1][p+2][1][1] = 1;
						}else if(x+1==dp[e+1][p+2][1][0]){
							dp[e+1][p+2][1][1] = max(dp[e+1][p+2][1][1],one);
						}
					}
				}else if(B[p]==q&&y<A[x]){
					if(x>dp[e+1][p+1][1][0]){
						dp[e+1][p+1][1][0] = x;
						dp[e+1][p+1][1][1] = y + 1;
					}else if(x==dp[e+1][p+1][1][0]) dp[e+1][p+1][1][1] = max(dp[e+1][p+1][1][1],(short)(y+1));
					if(p+2<=n){
						if(x>dp[e+1][p+2][1][0]){
							dp[e+1][p+2][1][0] = x;
							dp[e+1][p+2][1][1] = y + 1;
						}else if(x==dp[e+1][p+2][1][0]) dp[e+1][p+2][1][1] = max(dp[e+1][p+2][1][1],(short)(y+1));
					}
				}else if(q<B[p]&&y==A[x]){
					if(x+1!=p){
						if(x+1>dp[e+1][p][q+1][0]){
							dp[e+1][p][q+1][0] = x + 1;
							dp[e+1][p][q+1][1] = 1; 
						}else if(x+1==dp[e+1][p][q+1][0]) dp[e+1][p][q+1][1] = min(dp[e+1][p][q+1][1],one);
					}
					if(x>dp[e+1][p][q+1][0]){
						dp[e+1][p][q+1][0] = x;
						dp[e+1][p][q+1][1] = y;
					}else if(x==dp[e+1][p][q+1][0]) dp[e+1][p][q+1][1] = min(dp[e+1][p][q+1][1],y);
				}else{
					if(x>dp[e+1][p][q+1][0]){
						dp[e+1][p][q+1][0] = x;
						dp[e+1][p][q+1][1] = y + 1;
					}else if(x==dp[e+1][p][q+1][0]) dp[e+1][p][q+1][1] = min(dp[e+1][p][q+1][1],(short)(y+1));
				}
			}
		}
	}
	int ans = 1e9;
	for(int p=0;p<lim;p++){
		if(dp[p][n+1][1][0]!=-1){
			int x = dp[p][n+1][1][0];
			int y = dp[p][n+1][1][1];
			int vv = A[x] - y + C[x+1];
			ans = min(ans,p+vv);
		}
	}
	cout << ans;
}