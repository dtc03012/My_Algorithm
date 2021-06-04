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
set<int> s[MAX];
int par[MAX][20],dep[MAX],par2[MAX][20],ans[MAX],num = 1,suc[MAX];
pi len[MAX];
vector<int> v[MAX],v2[MAX];
vector<pi> g[MAX];
vector<pair<pi,int> > z[MAX];
void dfs(int x,int lx,int k){
	dep[x] = k;
	par[x][0] = lx;
	len[x].x = num;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx) dfs(nx,x,k+1);
	}
	len[x].y = num++;
}
int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	int diff = dep[y] - dep[x];
	for(int num=0;diff;diff/=2,num++) if(diff%2) y = par[y][num];
	if(x!=y){
		for(int e=19;e>=0;e--){
			if(par[x][e]!=-1&&par[x][e]!=par[y][e]){
				x = par[x][e];
				y = par[y][e];
			}
		}
		x = par[x][0];
	}
	return x;
}
int go(int x,int lx){
	for(int e=0;e<sz(g[x]);e++){
		int ll = g[x][e].x;
		int rr = g[x][e].y;
		if(par2[ll][0]==-1) par2[ll][0] = x;
		else{
			if(dep[par2[ll][0]]>dep[x]) par2[ll][0] = x;
		}
		if(par2[rr][0]==-1) par2[rr][0] = x;
		else{
			if(dep[par2[rr][0]]>dep[x]) par2[rr][0] = x;
		}
	}
	int gg = par2[x][0];
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			int nn = go(nx,x);
			if(nn!=-1&&dep[x]>dep[nn]){
				if(gg==-1) gg = nn;
				else{
					if(dep[gg]>dep[nn]) gg = nn;
				} 
			}
		}
	}
	par2[x][0] = gg;
	return par2[x][0];
}
void go2(int x,int lx){
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			go2(nx,x);
			if(sz(s[x])<sz(s[nx])) swap(s[nx],s[x]);
			for(auto k : s[nx]) s[x].insert(k);
			s[nx].clear();
		}
	}
	for(int e=0;e<sz(v2[x]);e++){
		int nx = v2[x][e];
		s[x].insert(len[nx].y);
	}
	for(int e=0;e<sz(z[x]);e++){
		int ll = z[x][e].x.x,rr = z[x][e].x.y,pos = z[x][e].y;
		set<int>::iterator it = s[x].lower_bound(ll);
		if(*it>=ll&&*it<=rr) suc[pos] = 1;
	}
}
void solve(int tc){
	memset(par,-1,sizeof(par));
	memset(par2,-1,sizeof(par2));
	int n;
	scanf("%d",&n);
	for(int e=2;e<=n;e++){
		int r;
		scanf("%d",&r);
		v[r].push_back(e);
	}
	dfs(1,-1,0);
	for(int e=1;e<20;e++){
		for(int p=1;p<=n;p++){
			if(par[p][e-1]!=-1){
				par[p][e] = par[par[p][e-1]][e-1];
			}
		}
	}
	int m;
	scanf("%d",&m);
	for(int e=0;e<m;e++){
		int l,r;
		scanf("%d%d",&l,&r);
		v2[l].push_back(r);
		v2[r].push_back(l);
		int rt = lca(l,r);
		g[rt].push_back(mk(l,r));
	}
	go(1,-1);
	for(int e=1;e<20;e++){
		for(int p=1;p<=n;p++){
			if(par2[p][e-1]!=-1){
				par2[p][e] = par2[par2[p][e-1]][e-1];
			}
		}
	}
	int que;
	scanf("%d",&que);
	for(int y=1;y<=que;y++){
		int a,b;
		scanf("%d%d",&a,&b);
		int rt = lca(a,b);
		int tot = 0;
		if(a!=rt){
			for(int e=19;e>=0;e--){
				if(par2[a][e]!=-1&&dep[par2[a][e]]>dep[rt]){
					tot += (1<<e);
					a = par2[a][e];
				}
			}
		}
		if(b!=rt){
			for(int e=19;e>=0;e--){
				if(par2[b][e]!=-1&&dep[par2[b][e]]>dep[rt]){
					tot += (1<<e);
					b = par2[b][e];
				}
			}
		}
		if(a==rt||b==rt){
			if(a==rt&&(par2[b][0]==-1||dep[par2[b][0]]>dep[rt])) ans[y] = -1;
			else if(b==rt&&(par2[a][0]==-1||dep[par2[a][0]]>dep[rt])) ans[y] = -1;
			else ans[y] = tot + 1;
			continue;
		}else{
			if(par2[a][0]==-1||par2[b][0]==-1||dep[par2[a][0]]>dep[rt]||dep[par2[b][0]]>dep[rt]){
				ans[y] = -1;
				continue;
			}
		}
		tot += 2;
		z[a].push_back(mk(mk(len[b].x,len[b].y),y));
		z[b].push_back(mk(mk(len[a].x,len[a].y),y));
		ans[y] = tot;
	}
	go2(1,-1);
	for(int e=1;e<=que;e++){
		if(ans[e]!=-1) ans[e] -= suc[e];
		printf("%d\n",ans[e]);
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