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

const int MAX = 1010;
int arr[MAX][MAX],dp[MAX][MAX][4];
void solve(int tc){
	int n,m;
	cin >> n >> m;
	for(int e=1;e<=n;e++) for(int p=1;p<=m;p++){
		cin >> arr[e][p];
	}
	for(int e=0;e<=n+1;e++){
		for(int p=0;p<=m+1;p++){
			for(int q=0;q<4;q++){
				dp[e][p][q] = 0;
			}
		}
	}
	for(int e=1;e<=n;e++){
		for(int p=1;p<=m;p++){
			if(arr[e][p]==1){
				dp[e][p][0] = dp[e-1][p][0] + 1;
			}else{
				dp[e][p][0] = 0;
			}
		}
	}
	for(int e=1;e<=n;e++){
		for(int p=1;p<=m;p++){
			if(arr[e][p]==1){
				dp[e][p][1] = dp[e][p-1][1] + 1;
			}else{
				dp[e][p][1] = 0;
			}
		}
	}
	for(int e=n;e>=1;e--){
		for(int p=m;p>=1;p--){
			if(arr[e][p]==1){
				dp[e][p][2] = dp[e+1][p][2] + 1;
			}else{
				dp[e][p][2] = 0;
			}
		}
	}
	for(int e=n;e>=1;e--){
		for(int p=m;p>=1;p--){
			if(arr[e][p]==1){
				dp[e][p][3] = dp[e][p+1][3] + 1;
			}else{
				dp[e][p][3] = 0;
			}
		}
	}
	lld ans = 0;
	for(int e=1;e<=n;e++){
		for(int p=1;p<=m;p++){
			for(int q=0;q<4;q++){
				for(int r=0;r<4;r++){
					if((q%2)==(r%2)) continue;
					int f1 = dp[e][p][q];
					int f2 = dp[e][p][r];
					ans += max(0,min(f1/2,f2)-1);
				}
			}
		}
	}
	cout << "Case #" << tc << ": " << ans << "\n";
}	


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}