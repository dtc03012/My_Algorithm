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

const int MAX = 1000101;
vector<int> v[MAX][2];
int dep[MAX][2],ans;
void dfs(int x,int lx,int ty,int val){
	dep[x][ty] = val;
	for(int e=0;e<sz(v[x][ty]);e++){
		int nx = v[x][ty][e];
		if(nx!=lx) dfs(nx,x,ty,val+1);
	}
}
void dfs2(int x,int lx,int dt){
	if(dep[x][0]==dep[x][1]) dt++;
	ans = max(ans,dt);
	for(int e=0;e<sz(v[x][0]);e++){
		int nx = v[x][0][e];
		if(nx!=lx) dfs2(nx,x,dt);
	}
}
void solve(int tc){
	int n;
	scanf("%d",&n);
	ans = 0;
	for(int e=1;e<=n;e++){
		v[e][0].clear();
		v[e][1].clear();
		dep[e][0] = dep[e][1] = 0;
	}
	int rt1 = -1,rt2 = -1;
	for(int e=1;e<=n;e++){
		int r;
		scanf("%d",&r);
		if(r==-1) rt1 = e;
		v[r][0].push_back(e);
	}
	for(int e=1;e<=n;e++){
		int r;
		scanf("%d",&r);
		if(r==-1) rt2 = e;
		v[r][1].push_back(e);
	}
	dfs(rt1,-1,0,1);
	dfs(rt2,-1,1,1);
	dfs2(rt1,-1,0);
	printf("%d\n",ans);
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