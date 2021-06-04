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

const int MAX = 303030;
int dp[MAX][70],arr[MAX];
void solve(int tc){
	memset(dp,-1,sizeof(dp));
	int n,ans = 0;
	scanf("%d",&n);
	for(int e=0;e<n;e++){
		scanf("%d",&arr[e]);
		ans = max(ans,arr[e]);
	}
	dp[0][arr[0]] = 0;
	for(int e=1;e<n;e++){
		int st = e,val = arr[e];
		dp[e][arr[e]] = e;
		while(st>=1){
			ans = max(ans,val);
			if(dp[st-1][val]==-1) break;
			st = dp[st-1][val];
			val++;
			dp[e][val] = st;
		}
		ans = max(ans,val);
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
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}