const int MAX = 1000100;
struct SCC_cl{
	// 1 based SCC
	int V, E, cnt, dfsn[MAX], SN, sn[MAX],tsat[MAX];
	vector<int> adj[MAX];
	bool finished[MAX]; 
	stack<int> S;
	vector<vector<int> > SCC;
	SCC_cl(int V){
		this->V = V;
		memset(dfsn,0,sizeof(dfsn));
		memset(sn,0,sizeof(sn));
		memset(finished,false,sizeof(finished));
		cnt = 0;
		SN = 0;
	}
	int DFS(int curr){
	    dfsn[curr] = ++cnt;
	    S.push(curr);
	    int result = dfsn[curr];
	    for(int next: adj[curr]){
	        if(dfsn[next] == 0) result = min(result, DFS(next));
	        else if(!finished[next]) result = min(result, dfsn[next]);
	    }
	    if(result == dfsn[curr]){
	        vector<int> currSCC;
	        while(1){
	            int t = S.top();
	            S.pop();
	            currSCC.push_back(t);
	            finished[t] = true;
	            sn[t] = SN;
	            if(t == curr) break;
	        }
	        sort(currSCC.begin(), currSCC.end());
	        SCC.push_back(currSCC);
	        SN++;
	    }
	    return result;
	}
	void goSCC(){
		for(int i=1; i<=V; i++)
        	if(dfsn[i] == 0) DFS(i);
	}
	void add_edge(int a,int b){
		adj[a].push_back(b);
	}
	// two sat
	// A v B -> A^c -> B , B^c -> A
	// 1 based SCC -> i : 2*i - 1 , 2*i
	void getTwoSat(){
		memset(tsat,-1,sizeof(tsat));
		pi p[MAX];
	    for(int i=1;i<=V;i++)
	        p[i] = mk(sn[i], i);
	    sort(p+1, p+1+V);
	    for(int i=V; i>=1; i--){
	        int var = p[i].second;
	        if(tsat[(var+1)/2] == -1) tsat[(var+1)/2] = !(var%2);
	    }
	}
	bool isTwoSat(){
		for(int e=1;e<=V;e+=2){
			if(sn[e]==sn[e+1]) return false;
		}
		return true;
	}
};