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
const int NMAX = 101010;
const int EMAX = 202020;
set<int> s;
map<int,int> mm;
vector<pi> v[NMAX];
int col[NMAX],dist[EMAX],D[NMAX],num = 1,org[NMAX];
vector<pi> g;
bool dfs(int x){
	int xx = -1;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e].x;
		int pos = v[x][e].y;
		if(D[nx]<D[x]){
			xx = col[nx]^1;
			dist[pos] = org[D[x]];
			break;
		}else if(D[nx]==D[x]){
			if(col[nx]!=-1){
				xx = col[nx]^1;
			}else{
				xx = 0;
				col[nx] = 1;
			}
			dist[pos] = org[D[x]];
			break;
		}
	}
	col[x] = xx;
	if(xx==-1) return false;
	return true;
}
void solve(int tc){
	memset(col,-1,sizeof(col));
	for(int e=0;e<EMAX;e++) dist[e] = 1e9;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++){
		scanf("%d",&D[e]);
		s.insert(D[e]);
	}
	for(auto g : s){
		mm[g] = num;
		org[num] = g;
		num++;
	}
	for(int e=1;e<=n;e++){
		D[e] = mm[D[e]];
		g.push_back(mk(D[e],e));
	}
	sort(all(g));
	for(int e=0;e<m;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(mk(b,e));
		v[b].push_back(mk(a,e));
	}
	bool suc = true;
	for(int e=0;e<sz(g);e++){
		if(col[g[e].y]==-1){
			bool now = dfs(g[e].y);
			if(!now) suc = false;
		}
	}
	if(!suc){
		printf("-1");
	}else{
		for(int e=1;e<=n;e++){
			if(col[e]==0) printf("B");
			else printf("W");
		}
		printf("\n");
		for(int e=0;e<m;e++) printf("%d\n",dist[e]);
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