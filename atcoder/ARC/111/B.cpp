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

const int MAX = 400200;
const int INF = 1000000000;

struct Hopcroft_Karp{
    int N, A[MAX], B[MAX], dist[MAX];
    bool used[MAX]; 
    vector<int> adj[MAX];

    Hopcroft_Karp(){
        memset(A,-1,sizeof(A));
        memset(B,-1,sizeof(B));
        memset(used,0,sizeof(used));
    }
    void Set(int N){
    	this->N = N;
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

Hopcroft_Karp gh;
void solve(int tc){
	int n;
	scanf("%d",&n);
	gh.Set(n);
	for(int e=1;e<=n;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		gh.add_edge(e,a);
		gh.add_edge(e,b);
	}
	printf("%d\n",gh.flow());
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