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
vector<int> v[MAX];
int cost[MAX],go[MAX],can[MAX],where[MAX];
int mx = -1,wh = -1;
void dfs(int x,int lx,int val){
	if(val>mx){
		mx = val;
		wh = x;
	}
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx) dfs(nx,x,val+1);
	}
}
int dfs2(int x,int lx){
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			go[x] = max(go[x],dfs2(nx,x)+1);
		}
	}
	return go[x];
}
void paint(int x,int lx,int lim){
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			if(go[nx]+1==lim){
				can[nx] = 1;
				where[x] = nx;
				paint(nx,x,lim-1);
				return;
			}
		}
	}
}
int gogo(int x,int lx,int val){
	cost[x] = val;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			if(nx!=where[x]){
				int kk = gogo(nx,x,val+1);
				val = max(val,kk+1);
			}
		}
	}
	if(where[x]) gogo(where[x],x,val+1);
	return val;
}
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n-1;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,-1,0);
	int f1 = wh;
	wh = -1;
	mx = -1;
	dfs(f1,-1,0);
	int f2 = wh;
	dfs2(f1,-1);
	paint(f1,-1,mx);
	gogo(f1,-1,1);
	for(int e=1;e<=n;e++) printf("%d ",cost[e]);
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