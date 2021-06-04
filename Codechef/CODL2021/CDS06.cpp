#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
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

const int MAX = 101010;
vector<int> v[MAX];
lld tmi[MAX],tpl[MAX],mi[MAX],pl[MAX],arr[MAX],ans = 1e18;
void dfs(int x,int lx){
	tpl[x] = 0;
	pl[x] = arr[x];
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			dfs(nx,x);
			tpl[x] += tmi[nx] + mi[nx];
			tmi[x] += tpl[nx] + pl[nx];
			pl[x] += mi[nx];
			mi[x] += pl[nx];
		}
	}
}
void dfs2(int x,int lx){
	ans = min(ans,tpl[x]-tmi[x]);
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			lld f1 = tpl[x],f2 = tmi[x],f3 = pl[x],f4 = mi[x];
			lld s1 = tpl[nx],s2 = tmi[nx],s3 = pl[nx],s4 = mi[nx];
			tpl[x] -= (tmi[nx]+mi[nx]);
			tmi[x] -= (tpl[nx]+pl[nx]);
			pl[x] -= mi[nx];
			mi[x] -= pl[nx];
			tpl[nx] += (tmi[x]+mi[x]);
			tmi[nx] += (tpl[x]+pl[x]);
			pl[nx] += mi[x];
			mi[nx] += pl[x];
			dfs2(nx,x);
			tpl[x] = f1;
			tmi[x] = f2;
			pl[x] = f3;
			mi[x] = f4;
			tpl[nx] = s1;
			tmi[nx] = s2;
			pl[nx] = s3;
			mi[nx] = s4;
		}
	}
}
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n-1;e++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int e=1;e<=n;e++) scanf("%lld",&arr[e]);
	dfs(1,-1);
	dfs2(1,-1);
	printf("%lld",ans);
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