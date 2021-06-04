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

const int MAX = 2020;
lld arr[MAX][MAX],dp[MAX][MAX],dp2[MAX][MAX],dp3[MAX],dp4[MAX],dp5[MAX][MAX];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++){
		for(int p=1;p<=n;p++){
			scanf("%lld",&arr[e][p]);
			arr[e][p] *= -1;
		}
	}
	for(int e=1;e<=n-m+1;e++){
		for(int p=1;p<=n-m+1;p++) dp2[e][p] = dp2[e-1][p];
		if(e-m>=0){
			for(int p=1;p<=n-m+1;p++){
				dp2[e][p] -= dp5[e-m][p];
			}
		}
		memset(dp3,0,sizeof(dp3));
		memset(dp4,0,sizeof(dp4));
		for(int p=1;p<=n-m+1;p++){
			dp3[p] = dp3[p-1];
			if(p-m>=0) dp3[p] -= dp4[p-m];
			dp[e+(m-1)/2][p+(m-1)/2] = arr[e][p] - dp2[e][p] - dp3[p];
			dp3[p] += dp[e+(m-1)/2][p+(m-1)/2];
			dp4[p] = dp[e+(m-1)/2][p+(m-1)/2];
		}
		for(int p=1;p<=n-m+1;p++){
			dp2[e][p] += dp3[p];
			dp5[e][p] = dp3[p];
		}
	}
	for(int e=1;e<=n;e++){
		for(int p=1;p<=n;p++) printf("%lld ",dp[e][p]);
		printf("\n");
	}
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