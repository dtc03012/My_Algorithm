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

const int MAX = 1000100;
struct SCC_cl{
	// 1 based SCC
	int V, E, cnt, dfsn[MAX], SN, sn[MAX],tsat[MAX];
	vector<int> adj[MAX];
	bool finished[MAX]; 
	stack<int> S;
	vector<vector<int> > SCC;
	SCC_cl(){
		memset(dfsn,0,sizeof(dfsn));
		memset(sn,0,sizeof(sn));
		memset(finished,false,sizeof(finished));
		cnt = 0;
		SN = 0;
	}
	void init(int V){
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
	int get_ans(int n,int m){
		set<int> s1,s2;
		for(int e=1;e<=n;e++){
			s1.insert(sn[e]);
		}
		for(int e=n+1;e<=n+m;e++){
			s2.insert(sn[e]);
		}
		return min(sz(s1)-1,sz(s2)-1);
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
SCC_cl gh;
string a[1010];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	gh.init(n+m);
	gh.add_edge(1,n+m);
	gh.add_edge(1,n+1);
	gh.add_edge(n,n+1);
	gh.add_edge(n,n+m);
	gh.add_edge(n+1,1);
	gh.add_edge(n+1,n);
	gh.add_edge(n+m,1);
	gh.add_edge(n+m,n);
	for(int e=1;e<=n;e++) cin >> a[e];
	for(int p=1;p<=m;p++){
		vector<int> v;
		for(int e=1;e<=n;e++){
			if(a[e][p-1]=='#') v.push_back(e);
		}
		if(sz(v)){
			for(int q=0;q<sz(v);q++){
				gh.add_edge(v[q],p+n);
			}
		}
	}
	for(int e=1;e<=n;e++){
		vector<int> v;
		for(int p=1;p<=m;p++){
			if(a[e][p-1]=='#') v.push_back(p);
		}
		if(sz(v)){
			for(int q=0;q<sz(v);q++){
				gh.add_edge(v[q]+n,e);
			}
		}
	}
	gh.goSCC();
	printf("%d\n",gh.get_ans(n,m));
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