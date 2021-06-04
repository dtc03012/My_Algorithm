#include <bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;


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

class EllysRansom{
public:
	string getRansom(string A, string B, string T){
		Hopcroft_Karp gh(sz(A));
		for(int e=0;e<sz(A);e++){
			for(int p=0;p<sz(T);p++){
				if(T[p]==A[e]||T[p]==B[e]){
					gh.add_edge(e+1,p+1);
				}
			}
		}
		int vv = gh.flow();
		if(vv!=sz(T)){
			return "NO SOLUTION";
		}
		string ans = "";
		for(int e=1;e<=sz(A);e++){
			if(gh.A[e]==-1){
				ans += "_";
			}else{
				int wh = gh.A[e] - 1;
				ans += T[wh];
			}
		}
		return ans;
	}
};

int main(void){
	EllysRansom gh;
	string f1 ="NEVERMINDTHENOISEYOUHEARD";
	string f2 = "DEBRUOYREDNUTSAEBATSUJSTI";
	string f3 = "ENTERSANDMANYEAH";
	cout << gh.getRansom(f1,f2,f3);
}