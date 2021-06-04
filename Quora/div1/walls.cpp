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
const int MAX = 30101;
int isin[3][MAX];
lld ans;
lld cost[3][MAX][2];
lld sum[MAX][3][3];
lld dp[3][MAX];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=0;e<3;e++){
		for(int p=1;p<n;p++){
			int r;
			scanf("%d",&r);
			cost[e][p][0] = r;
		}
	}
	for(int e=0;e<2;e++){
		for(int p=1;p<=n;p++){
			int r;
			scanf("%d",&r);
			cost[e][p][1] = r;
		}
	}
	for(int p=1;p<=n;p++){
		sum[p][0][1] = cost[0][p][1];
		sum[p][1][2] = cost[1][p][1];
		sum[p][0][2] = cost[0][p][1] + cost[1][p][1];
	}
	int mx = 0;
	for(int e=0;e<m;e++){
		int y,x;
		scanf("%d%d",&y,&x);
		y--;
		isin[y][x] = 1;
		mx = max(mx,x);
	}
	for(int e=0;e<3;e++) for(int p=1;p<=n;p++) dp[e][p] = 1e18;
	int rx = -1;
	for(int e=1;e<=n;e++){
		int ly = 2,ry = 0,cnt = 0;
		for(int p=0;p<3;p++){
			if(isin[p][e]){
				ly = min(ly,p);
				ry = max(ry,p);
				cnt++;
			}
		}
		if(rx==-1&&cnt){
			for(int p=0;p<3;p++){
				int ll = min(ly,p),rr = max(ry,p);
				dp[p][e] = sum[e][ll][rr];
			}
			rx = e;
		}else if(rx!=-1){
			lld dist[3],ndp[3],gg[3][3];
			memset(dist,0,sizeof(dist));
			memset(gg,0,sizeof(gg));
			for(int e=0;e<3;e++) ndp[e] = 1e18;
			for(int p=e-1;p>=rx;p--){
				for(int q=0;q<3;q++){
					dist[q] += cost[q][p][0];
					ndp[q] = min(ndp[q],dist[q]+dp[q][p]);
				}
			}
			for(int e=0;e<3;e++){
				for(int p=e;p<3;p++){
					lld xx = 1e18;
					for(int q=e;q<=p;q++) xx = min(xx,ndp[q]);
					gg[e][p] = xx;
				}
			}
			for(int p=0;p<=ly;p++){
				for(int q=ry;q<3;q++){
					lld vv = gg[min(p,q)][max(p,q)] + sum[e][min(p,q)][max(p,q)];
					for(int t=p;t<=q;t++) dp[t][e] = min(dp[t][e],vv);
				}
			}
			rx = e;
		}
		if(e==mx){
			lld ans = 1e18;
			for(int p=0;p<3;p++) ans = min(ans,dp[p][e]);
			printf("%lld\n",ans);
			return ;
		}
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