const lld INF = 1e18;
struct MCMF{
	struct Edge{
		int to,rev,cap;
		lld cost;
		Edge(int to, int rev, int cap, lld cost):to(to),rev(rev),cap(cap),cost(cost){
		}
	};
	vector<vector<Edge>> graph;
	vector<pi> par;
	int n,src,snk;
	MCMF(int n, int src, int snk):n(n),src(src),snk(snk){
		graph.resize(n+5);
		par.resize(n+5);
	}
	void push_edge(int a, int b, int capa, lld cst){
		graph[a].pb(Edge(b,graph[b].size(),capa,cst));
		graph[b].pb(Edge(a,graph[a].size()-1,0,-cst));
	}
	bool SPFA(){
		vector<int> inq;
		vector<lld> dst;
		inq.resize(n+5,0);
		dst.resize(n+5,INF);
		queue<int> q;
		q.push(src); inq[src]=1; dst[src]=0;
		while(!q.empty()){
			int h=q.front(); q.pop();
			inq[h]=0;
			for(int i=0;i<(int)graph[h].size();i++){
				auto e=graph[h][i];
				if(e.cap<=0) continue;
				if(dst[h]<INF && dst[e.to]>dst[h]+e.cost){
					dst[e.to]=dst[h]+e.cost; par[e.to]={h,i};
					if(inq[e.to]==0){
						q.push(e.to);
						inq[e.to]=1;
					}
				}
			}
		}
		return dst[snk]!=INF;
	}
	pl flow(){
		lld work=0,money=0;
		while(SPFA()){
			lld c=0, f=INF;
			for(int i=snk;i!=src;i=par[i].x){
				auto &e=graph[par[i].x][par[i].y];
				f=min(f,(lld)e.cap);
				c+=e.cost;
			}
			work+=f;
			money+=f*c;
			for(int i=snk;i!=src;i=par[i].x){
				auto &e=graph[par[i].x][par[i].y];
				e.cap-=f;
				graph[e.to][e.rev].cap+=f;
			}
		}
		return {work,money};
	}
};