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

const int MAX = 202020;
int dp[MAX][3];
char S[MAX];
void solve(int tc){
	scanf("%s",S+1);
	int len = strlen(S+1);
	memset(dp,-1,sizeof(dp));
	dp[0][0] = 0;
	for(int e=1;e<=len;e++){
		int xx = S[e] - '0';
		xx %= 3;
		for(int q=0;q<3;q++){
			int nx = (xx + q)%3;
			if(dp[e-1][q]!=-1){
				if(nx==0){
					dp[e][nx] = max(dp[e][nx],dp[e-1][q]+1);
				}else{
					dp[e][nx] = max(dp[e][nx],dp[e-1][q]);
				}
			}
		}
		int mx = 0;
		for(int q=0;q<3;q++) mx = max(mx,dp[e-1][q]);
		if(xx){
			dp[e][xx] = max(dp[e][xx],mx);
		}else{
			dp[e][xx] = max(dp[e][xx],mx+1);
		}
	}
	int mx = 0;
	for(int e=0;e<3;e++) mx = max(mx,dp[len][e]);
	printf("%d\n",mx);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}