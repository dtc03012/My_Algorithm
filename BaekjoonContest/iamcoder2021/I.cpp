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

const int MAX = 500100;
struct SCC_cl{
	// 1 based SCC
	int V, E, cnt, dfsn[MAX], SN, sn[MAX],tsat[MAX];
	vector<int> adj[MAX],g[MAX];
	bool finished[MAX];
	int uf[MAX],wh[MAX],kk[MAX],sz2[MAX];
	stack<int> S;
	map<pi,int> mm;
	vector<vector<int> > SCC;
	int find(int x){
		if(uf[x]!=x) return uf[x] = find(uf[x]);
		return x;
	}
	SCC_cl(){
		memset(dfsn,0,sizeof(dfsn));
		memset(sn,0,sizeof(sn));
		memset(finished,false,sizeof(finished));
		memset(uf,0,sizeof(uf));
		memset(wh,0,sizeof(wh));
		memset(kk,0,sizeof(kk));
		memset(sz2,0,sizeof(sz2));
		cnt = 0;
		SN = 0;
	}
	void Set(int V){
		this->V = V;
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
	bool can(int x){
		queue<int> q;
		q.push(x);
		while(!q.empty()){
			if(sz(q)>1) return false;
			int x = q.front();q.pop();
			for(int e=0;e<sz(g[x]);e++){
				int nx = g[x][e];
				sz2[nx]--;
				if(sz2[nx]==0) q.push(nx);
			}
		}
		return true;
	}
	bool isTwoSat(){
		for(int e=1;e<=V;e+=2){
			if(sn[e]==sn[e+1]) return false;
		}
		return true;
	}
	pair<bool,bool> x1(){
		bool suc2 = true;
		for(int e=1;e<=V;e++){
			for(int p=0;p<sz(adj[e]);p++){
				int nx = adj[e][p];
				wh[sn[e]]++;
				if(sn[nx]!=sn[e]){
					if(mm[mk(sn[e],sn[nx])]==0){
						sz2[sn[nx]]++;
						g[sn[e]].push_back(sn[nx]);
						mm[mk(sn[e],sn[nx])] = 1;
					}
					kk[sn[e]]++;
					if(kk[sn[e]]>1) suc2 = false;
					uf[sn[nx]]++;
				}
			}
		}
		bool suc1 = true;
		int cnt = 0,cnt2 = 0;
		for(int e=0;e<SN;e++){
			if(uf[e]==0){
				if(!can(e)) suc1=  false;
				cnt++;
				if(wh[e]) cnt2++;
			}
		}
		if(cnt>1){
			suc1 = false;
			if(cnt2>1) suc2 = false;
		} 
		return mk(suc1,suc2);
	}
};
SCC_cl gh;
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	gh.Set(n);
	for(int e=0;e<m;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		gh.add_edge(a,b);
	}
	gh.goSCC();
	pair<bool,bool> suc = gh.x1();
	bool suc1 = suc.x;
	bool suc2 = suc.y;
	bool suc3 = suc1&suc2;
	printf("%d\n",suc1?1:0);
	printf("%d\n",suc2?1:0);
	printf("%d\n",suc3?1:0);
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