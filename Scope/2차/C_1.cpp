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

const int MAX = 505050;
vector<int> v[MAX];
int sz[MAX],dep[MAX],par[MAX][21];
void dfs(int x,int lx,int k){
	dep[x] = k;
	par[x][0] = lx;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			dfs(nx,x,k+1);
		}
	}
}
int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	int diff = dep[y] - dep[x];
	for(int num=0;diff;num++,diff/=2) if(diff%2) y = par[y][num];
	if(x!=y){
		for(int e=20;e>=0;e--){
			if(par[x][e]!=par[y][e]&&par[x][e]!=-1){
				x = par[x][e];
				y = par[y][e];
			}
		}
		x = par[x][0];
	}
	return x;
}
void solve(int tc){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int e=0;e<n-1;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		sz[b]++;
	}
	int rt = -1;
	for(int e=1;e<=n;e++) if(sz[e]==0) rt = e;
	memset(par,-1,sizeof(par));
	dfs(rt,-1,0);
	for(int e=1;e<=20;e++){
		for(int p=1;p<=n;p++){
			if(par[p][e-1]!=-1){
				par[p][e] = par[par[p][e-1]][e-1];
			}
		}
	}
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		int x = lca(a,b);
		if(x==a) printf("yes\n");
		else printf("no\n");
	}
}


int main(void){
	
	// ios_base :: sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}