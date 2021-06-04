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
vector<pi> v[MAX];
pil par[MAX][20];
lld ans;
set<int> s;
int dfsn[MAX],num = 1,dep[MAX],org[MAX],topv;
void dfs(int x,int lx,int val,int dist){
	dep[x] = val;
	dfsn[x] = num;
	org[num] = x;
	num++;
	par[x][0] = mk(lx,dist);
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e].x;
		int ndist = v[x][e].y;
		if(nx!=lx) dfs(nx,x,val+1,ndist);
	}
}
pil lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	int diff = dep[y] - dep[x];
	lld dist = 0;
	for(int num=0;diff;diff/=2,num++) if(diff%2){
		dist += par[y][num].y;
		y = par[y][num].x;
	}
	if(x!=y){
		for(int p=19;p>=0;p--){
			if(par[x][p].x!=-1&&par[x][p].x!=par[y][p].x){
				dist += par[x][p].y;
				dist += par[y][p].y;
				x = par[x][p].x;
				y = par[y][p].x;
			}
		}
		dist += par[x][0].y;
		dist += par[y][0].y;
		x = par[x][0].x;
	}
	return mk(x,dist);
}
void upd(int k,int x,int y,int t){
	int s1 = lca(x,k).x;
	int s2 = lca(y,k).x;
	if(dep[s2]>dep[s1]) s1 = s2;
	ans += lca(s1,k).y*t;
}
void add(int x){
	if(sz(s)==0){
		s.insert(dfsn[x]);
		topv = x;
		return;
	}
	pil rt = lca(x,topv);
	if(rt.x!=topv){
		ans += rt.y;
		topv = rt.x;
	}else{
		set<int>::iterator it = s.lower_bound(dfsn[x]);
		if(it==s.begin()){
			upd(x,org[*it],topv,1);
		}else if(it==s.end()){
			upd(x,org[*prev(s.end())],topv,1);
		}
		else{
			upd(x,org[*prev(it)],org[*it],1);
		}
	}
	s.insert(dfsn[x]);
}
void del(int x){
	if(sz(s)==1){
		s.erase(dfsn[x]);
		return;
	}
	s.erase(dfsn[x]);
	int ntopv = lca(org[*s.begin()],org[*prev(s.end())]).x;
	if(topv!=ntopv){
		ans -= lca(ntopv,x).y;
		topv = ntopv;
	}else{
		set<int>::iterator it = s.lower_bound(dfsn[x]);
		if(it==s.begin()){
			upd(x,org[*it],topv,-1);
		}else if(it==s.end()){
			upd(x,org[*prev(s.end())],topv,-1);
		}
		else{
			upd(x,org[*prev(it)],org[*it],-1);
		}
	}
}
void solve(int tc){
	for(int e=0;e<MAX;e++){
		for(int p=0;p<20;p++){
			par[e][p] = mk(-1,0);
		}
	}
	int n;
	scanf("%d",&n);
	for(int e=0;e<n-1;e++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back(mk(b,c));
		v[b].push_back(mk(a,c));
	}
	dfs(1,-1,0,0);
	for(int e=1;e<20;e++){
		for(int p=1;p<=n;p++){
			if(par[p][e-1].x!=-1){
				par[p][e].x = par[par[p][e-1].x][e-1].x;
				par[p][e].y = par[p][e-1].y + par[par[p][e-1].x][e-1].y;
			}
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		char S[2];
		int x;
		scanf("%s%d",S,&x);
		if(S[0]=='+') add(x);
		else del(x);
		printf("%lld\n",ans);
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