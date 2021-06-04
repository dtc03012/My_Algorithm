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

const int MAX = (1<<20);
lld dp[MAX][2];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<=n;e++) dp[e][0] = dp[e][1] = 0;
	for(int e=0;e<n;e++){
		int r;
		scanf("%d",&r);
		dp[r][0]++;
	}
	for(int p=0;p<20;p++){
		for(int q=n-1;q>=0;q--){
			if(q&(1<<p)){
				dp[q^(1<<p)][0] += dp[q][0];
			}
		}
	}
	lld ans = 0;
	for(int e=1;e<n;e++){
		for(int p=0;p<20;p++){
			if(e&(1<<p)){
				lld xx = dp[e^(1<<p)][1];
				xx += 1ll*(1<<p)*dp[e][0];
				dp[e][1] = max(dp[e][1],xx);
			}
		}
		ans = max(ans,dp[e][1]);
	}
	printf("%lld\n",ans);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}