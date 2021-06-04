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
const int MMAX = 101010;
const lld MID = 100000;
struct inf{
	int t;
	lld x;
	int y;
};
int vis[NMAX][MMAX];
inf que[NMAX];
int n,m,loc[MMAX];
void dfs(int x,lld k){
	vis[x][k] = 1;
	vector<lld> go;
	lld now = k;
	for(int e=0;e<=que[x].y;e++){
		if(vis[x+1][now]&&que[x].t==1) break;
		lld lnow = now;
		go.push_back(now);
		if(que[x].t==1){
			lld now2 = (que[x].x/MID);
			if(que[x].x%MID) now2++;
			now += now2;
		}else{
			now = (now*que[x].x);
			lld now2 = (now/MID);
			if(now%MID) now2++;
			now = now2;
		}
		if(now>1ll*m||now==lnow) break;
	}
	for(int e=sz(go)-1;e>=0;e--){
		if(loc[go[e]]==-1) loc[go[e]] = x;
		if(x+1<=n&&vis[x+1][go[e]]==0) dfs(x+1,go[e]);
	}
}
void solve(int tc){
	memset(loc,-1,sizeof(loc));
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++){
		int a,c;
		lld b;
		scanf("%d%lld%d",&a,&b,&c);
		que[e] = {a,b,c};
	}
	dfs(1,0);
	for(int e=1;e<=m;e++) printf("%d ",loc[e]);
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