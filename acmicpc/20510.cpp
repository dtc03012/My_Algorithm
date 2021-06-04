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

const int NMAX = 1010;
const int MMAX = 20;
const int MAX = 1e4 + 100;
const int INF = 1e9;

struct Hopcroft_Karp{
    int N, A[MAX], B[MAX], dist[MAX];
    bool used[MAX];
    vector<int> adj[MAX];

    Hopcroft_Karp(){
        this->N = MAX-1;
        memset(A,-1,sizeof(A));
        memset(B,-1,sizeof(B));
        memset(used,0,sizeof(used));
        memset(dist,0,sizeof(dist));
        for(int e=0;e<MAX;e++) adj[e].clear();
    }
    void add_edge(int x,int y){
        adj[x].push_back(y);
    }
    void bfs(){
        queue<int> Q;
        for(int i=0; i<=N; i++){
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
            for(int i=0; i<=N; i++)
                if(!used[i] && dfs(i)) flow++;
            if(flow == 0) break;
            match += flow;
        }
        return match;
    }
};

char S[NMAX][MMAX];
int co[NMAX][MMAX],ro[NMAX][MMAX];
Hopcroft_Karp gh;
set<int> s;
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=0;e<n;e++) scanf("%s",S[e]);
    int tot1 = 0,tot2 = 0;
	for(int e=0;e<n;e++){
        for(int p=0;p<m;p++){
            if(S[e][p]=='.'){
                if(p<m-1&&S[e][p+1]=='.') s.insert(e*m+p);
                tot1++;
                if(e<n-1&&S[e+1][p]=='.'){
                    int f1 = e*m + p;
                    tot2++;
                    if(p>0&&S[e][p-1]=='.'){
                        int s1 = e*m + p - 1;
                        gh.add_edge(f1,s1);
                    }
                    if(p>0&&S[e+1][p-1]=='.'){
                        int s1 = (e+1)*m + p - 1;
                        gh.add_edge(f1,s1);
                    }
                    if(p<m-1&&S[e][p+1]=='.'){
                        int s1 = e*m + p;
                        gh.add_edge(f1,s1);
                    }
                    if(p<m-1&&S[e+1][p+1]=='.'){
                        int s1 = (e+1)*m + p;
                        gh.add_edge(f1,s1);
                    }
                }
            }
        }
    }
    int xx = tot2 + sz(s) - gh.flow();
	printf("%d",tot1-xx);
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