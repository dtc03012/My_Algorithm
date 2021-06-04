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
const lld INF = 1e18;
struct MCMF{
	struct Edge{
		int to,r;
		lld c,cost;
		Edge() : Edge(0,0,0,0){
		}
		Edge(int a,lld b,int c,lld d) : to(a),c(b),r(c),cost(d){
		}
	};
	vector<vector<Edge> > adj;
	vector<pi> par;
	int N,S,E;
	MCMF(int n,int s,int e){
		this->N = n;
		this->S = s;
		this->E = e;
		adj.resize(n);
		par.resize(n);
	}
	void push_edge(int a,int b ,lld c,lld d){
		adj[a].push_back({b,c,sz(adj[b]),d});
		adj[b].push_back({a,0,sz(adj[a])-1,-d});
	}
	bool SPFA(){
		vector<int> inq;
		vector<lld> dst;
		inq.resize(N+5,0);
		dst.resize(N+5,INF);
		inq[S] = 1;
		dst[S] = 0;
		queue<int> q;
		q.push(S);
		while(!q.empty()){
			int x = q.front();q.pop();
			inq[x] = 0;
			for(int i=0;i<sz(adj[x]);i++){
				auto& e = adj[x][i];
				if(e.c<=0) continue;
				if(dst[x]<INF&&dst[e.to]>dst[x]+e.cost){
					dst[e.to] = dst[x] + e.cost;
					par[e.to] = mk(x,i);
					if(inq[e.to]==0){
						inq[e.to] = 1;
						q.push(e.to);
					}
				}
			}
		}
		return dst[E] != INF;
	}
	pl flow(){
		lld work = 0;
		lld money = 0;
		while(SPFA()){
			lld vv = 0;
			lld f = INF;
			for(int i = E;i!=S;i=par[i].x){
				auto& e = adj[par[i].x][par[i].y];
				f = min(f,e.c);
				vv += e.cost;
			}
			work += f;
			money += f*vv;
			for(int i = E;i!=S;i=par[i].x){
				auto& e = adj[par[i].x][par[i].y];
				e.c -= f;
				adj[e.to][e.r].c += f;
			}
		}
		return mk(work,money);
	}
};
const int MAX = 55;
int W[MAX],V[MAX],X[MAX];
void solve(int tc){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int e=1;e<=n;e++) scanf("%d%d",&W[e],&V[e]);
	for(int e=1;e<=m;e++) scanf("%d",&X[e]);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		lld ans = 0;
		for(int t=1;t<=m;t++){
			int st = 0,ed = n + m + 2;
			MCMF gh(n+m+3,st,ed);
			gh.push_edge(st,1,t,0);
			for(int e=1;e<=m;e++){
				if(e>=l&&e<=r){
					continue;
				}
				gh.push_edge(1,e+1,1,0);
				for(int p=1;p<=n;p++){
					if(X[e]>=W[p]){
						gh.push_edge(e+1,m+1+p,1,-V[p]);
					}
				}
			}
			for(int p=1;p<=n;p++) gh.push_edge(m+1+p,ed,1,0);
			pl now = gh.flow();
			ans = max(ans,-now.y);
		}
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
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}