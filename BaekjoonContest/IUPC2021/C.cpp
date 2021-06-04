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
const int MAX = 1000100;
char F[MAX],S[MAX];
vector<vector<int> > dp;
void solve(int tc){
	int n,m;
	scanf("%d%d%s%s",&n,&m,F+1,S+1);
	dp = vector<vector<int> >(n+1,vector<int>(m+1,1e9));
	dp[0][0] = 0;
	for(int e=1;e<=n;e++) dp[e][0] = e;
	for(int e=1;e<=m;e++) dp[0][e] = e;
	for(int e=1;e<=n;e++){
		for(int p=1;p<=m;p++){
			if(F[e]==S[p]) dp[e][p] = dp[e-1][p-1]; // 그대로
			else{
				if(F[e]=='i'&&(S[e]=='i'||S[e]=='j'||S[e]=='l')) dp[e][p] = dp[e-1][p-1];
				else if(F[e]=='v'&(S[e]=='v'||S[e]=='w')) dp[e][p] = dp[e-1][p-1];
			}
			dp[e][p] = min(dp[e][p],min(dp[e-1][p],dp[e][p-1]) + 1); // 삭제 추가
			dp[e][p] = min(dp[e][p],dp[e-1][p-1]+1); //변환 
		}
	}
	printf("%d",dp[n][m]);
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