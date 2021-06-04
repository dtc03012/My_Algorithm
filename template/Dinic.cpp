struct Dinic {
	struct Edge {
		int to, c, f, r;
		Edge() : Edge(-1, 0, -1) {}
		Edge(int to, int c, int r) : to(to), c(c), f(0), r(r) {}

		int spare() {
			return c - f;
		}
	};

	vector<vector<Edge>> adj;
	vector<int> depth, work;

	bool bfs(int S, int E) {
		fill(all(depth), -1);

		queue<int> Q;
		Q.push(S);
		depth[S] = 0;

		while (!Q.empty()) {
			int now = Q.front(); Q.pop();
			for (auto &e : adj[now]) {
				if (e.spare() > 0 && depth[e.to] == -1) {
					depth[e.to] = depth[now] + 1;
					Q.push(e.to);
				}
			}
		}

		return depth[E] != -1;
	}
	int dfs(int now, int dst, int flow) {
		if (now == dst) return flow;

		for (int &i = work[now]; i < sz(adj[now]); ++i) {
			auto &e = adj[now][i];
			if (depth[e.to] == depth[now] + 1 && e.spare() > 0) {
				int f = dfs(e.to, dst, min(flow, e.spare()));
				if (f > 0) {
					e.f += f;
					adj[e.to][e.r].f -= f;
					return f;
				}
			}
		}

		return 0;
	}

	Dinic(int n) {
		adj.resize(n);
		depth.resize(n);
		work.resize(n);
	}
	void add_edge(int u, int v, int cap) {
		adj[u].emplace_back(v, cap, sz(adj[v]));
		adj[v].emplace_back(u, 0, sz(adj[u]) - 1);
	}
	int max_flow(int S, int E) {
		int flow = 0;
		while (bfs(S, E)) {
			fill(all(work), 0);
			while (1) {
				int f = dfs(S, E, 0x3f3f3f3f);
				if (f == 0) break;
				flow += f;
			}
		}
		return flow;
	}
};