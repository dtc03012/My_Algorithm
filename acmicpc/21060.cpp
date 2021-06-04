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
const lld mod = 1e9 + 7;
lld dp[MAX][MAX][2];
void solve(int tc){
	int a,b;
	cin >> a >> b;
	cout << (dp[a][b][0]+dp[a][b][1])%mod << "\n";
}

void init(){
	dp[1][0][1] = 1;
	for(int e=2;e<MAX;e++){
		for(int p=0;p<e;p++){
			if(p){
				dp[e][p][0] = (dp[e-1][p][0]+dp[e-1][p-1][0]+dp[e-1][p-1][1]*2)%mod;
			}
			dp[e][p][1] = (dp[e-1][p+1][0]*p + dp[e-1][p][1]*(e-p-2) + dp[e-1][p][0]*(e-p-1)+dp[e-1][p+1][1]*(p+1))%mod;
		}
	}
}
int main(void){
	init();
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