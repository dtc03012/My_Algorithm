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

const int NMAX = 202;
const int MMAX = 1010;
int dp[NMAX][MMAX];
int go[NMAX][NMAX];
pair<pi,int> arr[NMAX];
bool tmr(pair<pi,int> a,pair<pi,int> b){
	if(a.x.x!=b.x.x) return a.x.x < b.x.x;
	return a.x.y > b.x.y;
}
void solve(int tc){
	memset(dp,-1,sizeof(dp));
	dp[0][0] = 0;
	int n,t;
	scanf("%d%d",&n,&t);
	for(int e=1;e<=n;e++){
		scanf("%d%d",&arr[e].x.x,&arr[e].x.y);
		arr[e].y = e;
	}
	for(int e=1;e<=n;e++) for(int p=1;p<=n;p++) scanf("%d",&go[e][p]);
	for(int e=1;e<=n;e++){
		for(int p=1;p<=n;p++){
			for(int q=1;q<=n;q++){
				go[p][q] = min(go[p][q],go[p][e]+go[e][q]);
			}
		}
	}
	sort(arr+1,arr+n+1,tmr);
	for(int e=1;e<=n;e++){
		for(int p=0;p<e;p++){
			for(int q=0;q<=t;q++){
				if(arr[e].x.x<=dp[p][q]){
					int xx = q + go[arr[p].y][arr[e].y];
					if(xx<=t) dp[e][xx] = max(dp[e][xx],dp[p][q]);
				}
			}
		}
		for(int q=1;q<=t;q++){
			if(dp[e][q-1]!=-1) dp[e][q] = max(dp[e][q],dp[e][q-1]+arr[e].x.y);
		}
	}
	int ans = 0;
	for(int e=1;e<=n;e++) ans = max(ans,dp[e][t]);
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