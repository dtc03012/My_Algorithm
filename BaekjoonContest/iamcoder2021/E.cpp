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

const int MAX = 303030;

vector<int> v[MAX];
vector<pi> g[MAX];
int sz[MAX],start = 1,n,q;
pil seg[MAX*4];
lld ans[MAX];
void upd(int x,int v){
	x += start;
	seg[x].x += v;
	seg[x].y += (x-start)*v;
	for(int e=(x/2);e>=1;e/=2){
		seg[e].x = seg[e*2].x + seg[e*2+1].x;
		seg[e].y = seg[e*2].y + seg[e*2+1].y;
	}
}
int getsz(int x,int lx){
	sz[x] = 1;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx) sz[x] += getsz(nx,x);
	}
	return sz[x];
}
lld getn(int node,int ns,int ne,int cnt){
	if(ns+1==ne) return ns*cnt;
	int mid = (ns+ne)/2;
	if(seg[node*2+1].x>=cnt) return getn(node*2+1,mid,ne,cnt);
	else{
		return getn(node*2,ns,mid,cnt-seg[node*2+1].x)+seg[node*2+1].y;
	}
}
void dfs(int x,int lx){
	upd(sz[x],-1);
	lld tot = seg[1].y * 2;
	for(int p=0;p<sz(g[x]);p++){
		int cnt = g[x][p].x;
		int wh = g[x][p].y;
		ans[wh] = tot - getn(1,0,start,cnt);
	}
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			upd(n-sz[nx],1);
			dfs(nx,x);
			upd(n-sz[nx],-1);
		}
	}
	upd(sz[x],1);
}
void solve(int tc){
	while(start<MAX) start *= 2;
	scanf("%d%d",&n,&q);
	for(int e=0;e<n-1;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}	
	for(int e=0;e<q;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(mk(b,e));
	}
	getsz(1,-1);
	for(int e=1;e<=n;e++) upd(sz[e],1);
	dfs(1,-1);
	for(int e=0;e<q;e++) printf("%lld\n",ans[e]);
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