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
lld dp[MAX][2][2],dist[MAX][2];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++){
		dist[e][0] = 1e18;
		dist[e][1] = -1e18;
		for(int p=0;p<2;p++){
			for(int q=0;q<2;q++){
				dp[e][p][q] = 1e18;
			}
		}
	}
	for(int e=1;e<=n;e++){
		int x,y;
		scanf("%d%d",&x,&y);
		dist[y][0] = min(dist[y][0],1ll*x);
		dist[y][1] = max(dist[y][1],1ll*x);
	}
	int lx = 0;
	for(int e=1;e<=n;e++){
		if(dist[e][0]==1e18) continue;
		for(int p=0;p<2;p++){
			for(int q=0;q<2;q++){
				for(int r=0;r<2;r++){
					for(int k=0;k<2;k++){
						lld f = abs(dist[lx][k]-dist[e][p]);
						if(p==q) f += 1ll*abs(dist[e][0]-dist[e][1])*2;
						else f += 1ll*abs(dist[e][0]-dist[e][1]);
						dp[e][p][q] = min(dp[e][p][q],dp[lx][r][k]+f);
					}
				}
			}
		}
		lx = e;
	}
	lld ans = 1e18;
	for(int e=0;e<2;e++){
		for(int p=0;p<2;p++) ans = min(ans,dp[lx][e][p]+abs(dist[lx][p]));
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
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}