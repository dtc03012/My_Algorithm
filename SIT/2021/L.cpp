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

const int MAX = 2020;
lld dist[MAX][MAX],tot,sz[MAX],ck[MAX],now;
vector<pi> v[MAX];
int par[MAX];
void dfs(int x,int lx,int val,int rt){
	dist[rt][x] = val;
	tot += val; 
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e].x;
		int nval = val + v[x][e].y;
		if(nx!=lx) dfs(nx,x,nval,rt);
	}
}
bool go(int x,int lx,int sx,int ex){
	if(x==sx||x==ex){
		ck[x] = 2;
	}
	if(x==ex) return true;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e].x;
		if(nx!=lx){
			if(go(nx,x,sx,ex)){
				if(x!=sx) ck[x] = 1;
				return true;
			}
		}
	}
	return false;
}
void go2(int x,int lx,int ty){
	if(ck[x]==1) ty = 1;
	if(ty==1&&ck[x]==0) ck[x] = 1;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e].x;
		if(nx!=lx){
			if(ty==0&&ck[nx]==1) go2(nx,x,ty);
			else if(ty==1&&ck[nx]==0) go2(nx,x,ty);
		}
	}
}
int go3(int x,int lx){
	int f1 = 1;
	ck[x] = 2;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e].x;
		if(nx!=lx&&ck[nx]==0){
			f1 += go3(nx,x);
		}
	}
	return f1;
}
void go4(int x,int lx,int rt,lld d,int rrt){
	if(x!=rt&&x!=rrt){
		printf("asdf %d\n",x);
		lld xx = max(0ll,dist[rt][x]-(d+dist[rrt][x])) * 2;
		now -= xx;
	}
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e].x;
		if(nx!=lx&&ck[nx]==1) go4(nx,x,rt,d,rrt);
	}
}
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n-1;e++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back(mk(b,c));
		v[b].push_back(mk(a,c));
	}
	for(int e=1;e<=n;e++) dfs(e,-1,0,e);
	int m;
	scanf("%d",&m);
	while(m--){
		int x,y;
		lld d;
		scanf("%d%d%lld",&x,&y,&d);
		memset(ck,0,sizeof(ck));
		go(x,-1,x,y);
		go2(x,-1,0);
		lld f1 = go3(x,-1);
		lld f2 = go3(y,-1);
		now = tot - max(0ll,(dist[x][y]-d)*f1*f2*2);
		printf("fff %lld\n",now/2);
		go4(x,-1,x,d,y);
		go4(y,-1,y,d,x);
		printf("%lld\n",now/2);
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