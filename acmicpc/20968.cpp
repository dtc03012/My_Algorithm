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

const int MAX = 50505;
const int NMAX = 55;
int arr[MAX],res[NMAX],dp[MAX][NMAX],n,k;
char go[NMAX][NMAX];
vector<pair<int,pi> > v[MAX];
int dik(){
	for(int e=1;e<=n;e++){
		for(int p=1;p<=k;p++) dp[e][p] = 1e9;
	}
	dp[1][arr[1]] = 0;
	priority_queue<pair<int,pi> > q;
	q.push(mk(0,mk(1,arr[1])));
	while(!q.empty()){
		int dist = -q.top().x;
		int x = q.top().y.x;
		int ty = q.top().y.y;
		q.pop();
		for(int e=0;e<sz(v[x]);e++){
			int nx = v[x][e].x;
			int ndist = dist + v[x][e].y.x;
			int nty = v[x][e].y.y;
			if(go[ty][nty]=='1'){
				if(dp[nx][ty]>ndist){
					dp[nx][ty] = ndist;
					q.push(mk(-ndist,mk(nx,ty)));
				}
				if(dp[nx][nty]>ndist){
					dp[nx][nty] = ndist;
					q.push(mk(-ndist,mk(nx,nty)));
				}
			}
		}
	}
	int ans = 1e9;
	for(int e=1;e<=k;e++) ans = min(ans,dp[n][e]);
	if(ans==1e9) ans = -1;
	return ans;
}
void solve(int tc){
	cin >> n >> k;
	for(int e=1;e<=n;e++){
		cin >> arr[e];
	}
	for(int e=1;e<=k;e++){
		cin >> (go[e] + 1);
	}
	memset(res,-1,sizeof(res));
	for(int e=1;e<=n;e++){
		for(int p=1;p<=k;p++){
			if(res[p]==-1) continue;
			v[e].push_back(mk(res[p],mk(abs(e-res[p]),p)));
		}
		res[arr[e]] = e;
	}

	memset(res,-1,sizeof(res));
	for(int e=n;e>=1;e--){
		for(int p=1;p<=k;p++){
			if(res[p]==-1) continue;
			v[e].push_back(mk(res[p],mk(abs(e-res[p]),p)));
		}
		res[arr[e]] = e;
	}
	cout << dik();
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}