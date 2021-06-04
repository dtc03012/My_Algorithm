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

const int MAX = 111;
lld arr[MAX],dp[MAX][MAX][MAX],dp2[MAX][MAX][MAX];
void solve(int tc){
	for(int e=0;e<MAX;e++){
		for(int p=0;p<MAX;p++){
			for(int q=0;q<MAX;q++){
				dp[e][p][q] = -1;
			}
		}
	}
	int n;
	lld x;
	scanf("%d%lld",&n,&x);
	for(int p=0;p<MAX;p++) dp[p][0][0] = 0;
	for(int e=1;e<=n;e++){
		int v;
		scanf("%d",&v);
		for(int p=1;p<=n;p++) for(int q=0;q<=p;q++) for(int r=0;r<p;r++) dp2[p][q][r] = dp[p][q][r];
		for(int p=1;p<=n;p++){
			for(int q=1;q<=p;q++){
				for(int r=0;r<p;r++){
					if(dp[p][q-1][((r-v)%p+p)%p]==-1) continue;
					dp2[p][q][r] = max(dp2[p][q][r],dp[p][q-1][((r-v)%p+p)%p] + v);
				}
			}
		}
		for(int p=1;p<=n;p++) for(int q=0;q<=p;q++) for(int r=0;r<p;r++) dp[p][q][r] = dp2[p][q][r];
	}
	lld ans = 1e18;
	for(int e=1;e<=n;e++){
		lld k = (x%e);
		lld xx = dp[e][e][k];
		if(xx==-1) continue;
		lld vv = (x-xx)/e;
		ans = min(ans,vv);
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