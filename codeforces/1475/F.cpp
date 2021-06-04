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

const int MAX = 5010;
string a[MAX],b[MAX];
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
void solve(int tc){
	int n;
	scanf("%d",&n);
	SCC_cl gh(4*n+100);
	int f1=0,f2=0;
	for(int e=1;e<=n;e++) cin >> a[e];
	for(int e=1;e<=n;e++) cin >> b[e];
	for(int e=1;e<=n;e++){
		for(int p=0;p<n;p++){
			if(a[e][p]!=b[e][p]){
				int x1 = e;
				int y1 = n + p + 1;
				gh.add_edge(x1*2-1,y1*2);
				gh.add_edge(y1*2-1,x1*2);
				gh.add_edge(x1*2,y1*2-1);
				gh.add_edge(y1*2,x1*2-1);
			}
			else{
				int x1 = e;
				int y1 = n + p + 1;
				gh.add_edge(x1*2-1,y1*2-1);
				gh.add_edge(y1*2-1,x1*2-1);
				gh.add_edge(x1*2,y1*2);
				gh.add_edge(y1*2,x1*2);
			}
		}
	}
	gh.goSCC();
	if(gh.isTwoSat()) printf("YES\n");
	else printf("NO\n");
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}