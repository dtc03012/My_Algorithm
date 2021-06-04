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

const int MAX = 50505*10;
struct SCC_cl{
	// 1 based SCC
	int V, E, cnt, dfsn[MAX], SN, sn[MAX],tsat[MAX];
	vector<int> adj[MAX];
	bool finished[MAX]; 
	stack<int> S;
	vector<vector<int> > SCC;
	SCC_cl(){
	}
	void init(int V){
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
int arr[MAX];
SCC_cl gh;
void Union1(int x,int y){
	int rf1 = x;
	int f1 = x - 1;
	int rs1 = y;
	int s1 = y - 1;
	gh.add_edge(rf1,s1);
	gh.add_edge(rs1,f1);
	gh.add_edge(f1,rs1);
	gh.add_edge(s1,rf1);
}
void Union2(int x,int y){
	int rf1 = x;
	int f1 = x - 1;
	int rs1 = y;
	int s1 = y - 1;
	gh.add_edge(rf1,s1);
	gh.add_edge(rs1,f1);
	gh.add_edge(rf1,rs1);
	gh.add_edge(rs1,rf1);
	gh.add_edge(f1,s1);
	gh.add_edge(s1,f1);
}
void Union3(int x,int y){
	int rf1 = x;
	int f1 = x - 1;
	int rs1 = y;
	int s1 = y - 1;
	gh.add_edge(f1,rs1);
	gh.add_edge(s1,rf1);
}
void Union4(int x,int y){
	int rf1 = x;
	int f1 = x - 1;
	int rs1 = y;
	int s1 = y - 1;
	gh.add_edge(rf1,s1);
	gh.add_edge(rs1,f1);
}
void Union5(int x,int y){
	int rf1 = x;
	int f1 = x - 1;
	int rs1 = y;
	int s1 = y - 1;
	gh.add_edge(f1,rs1);
	gh.add_edge(s1,rf1);
	gh.add_edge(rf1,rs1);
	gh.add_edge(rs1,rf1);
	gh.add_edge(f1,s1);
	gh.add_edge(s1,f1);
}
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	gh.init(n*5*2);
	for(int e=1;e<=n;e++){
		if(arr[e]==0){
			Union1(10*(e-1)+5*2,10*(e-1)+4*2);
			Union3(10*(e-1)+5*2,10*(e-1)+3*2);
		}else{
			for(int q=0;q<5;q++){
				int rf1 = 10*(e-1) + (q+1)*2;
				int f1 = 10*(e-1) + (q+1)*2 - 1;
				if(arr[e]&(1<<q)){
					gh.add_edge(rf1,f1);
				}else{
					gh.add_edge(f1,rf1);
				}
			}
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		char a[2];
		int x,y,z;
		scanf("%s%d%d%d",a,&x,&y,&z);
		for(int e=0;e<5;e++){
			if(a[0]=='&'){
				if(z&(1<<e)){
					Union2(10*(x-1)+(e+1)*2,10*(y-1)+(e+1)*2);
				}else{
					Union3(10*(x-1)+(e+1)*2,10*(y-1)+(e+1)*2);
				}
			}else{
				if(z&(1<<e)){
					Union4(10*(x-1)+(e+1)*2,10*(y-1)+(e+1)*2);
				}else{
					Union5(10*(x-1)+(e+1)*2,10*(y-1)+(e+1)*2);
				}
			}
		}
	}
	gh.goSCC();
	if(!gh.isTwoSat()) printf("0");
	else{
		gh.getTwoSat();
		printf("1\n");
		for(int e=1;e<=n;e++){
			int ans = 0;
			for(int q=0;q<5;q++){
				if(gh.tsat[5*(e-1)+(q+1)]) ans += (1<<q);
			}
			printf("%d ",ans);
		}
	}
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}