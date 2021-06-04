const int MAX = 10000;
const int INF = 1000000000;

struct Hopcroft_Karp{
    int N, A[MAX], B[MAX], dist[MAX];
    bool used[MAX]; 
    vector<int> adj[MAX];

    Hopcroft_Karp(int N){
        this->N = N;
        memset(A,-1,sizeof(A));
        memset(B,-1,sizeof(B));
        memset(used,0,sizeof(used));
    }
    void add_edge(int x,int y){
        adj[x].push_back(y);
    }
    void bfs(){
        queue<int> Q;
        for(int i=1; i<=N; i++){
            if(!used[i]){
                dist[i] = 0;
                Q.push(i);
            }
            else dist[i] = INF;
        }
        while(!Q.empty()){
            int a = Q.front();
            Q.pop();
            for(int b: adj[a]){
                if(B[b] != -1 && dist[B[b]] == INF){
                    dist[B[b]] = dist[a] + 1;
                    Q.push(B[b]);
                }
            }
        }
    }
    bool dfs(int a){
        for(int b: adj[a]){
            if(B[b] == -1 || dist[B[b]] == dist[a]+1 && dfs(B[b])){
                used[a] = true;
                A[a] = b;
                B[b] = a;
                return true;
            }
        }
        return false;
    }
    int flow(){
        int match = 0;
        while(1){
            bfs();
            int flow = 0;
            for(int i=1; i<=N; i++)
                if(!used[i] && dfs(i)) flow++;
            if(flow == 0) break;
            match += flow;
        }
        return match;
    }
};
