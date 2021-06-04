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

const int MAX = 555;
int cost[MAX][MAX],st;
vector<int> adj[MAX*MAX];
int wei[MAX*MAX];
void dfs(vector<int> v,int x,int lx){
	if(lx!=-1) adj[lx].push_back(x);
	int mx = 0;
	for(int e=0;e<sz(v);e++){
		for(int p=0;p<sz(v);p++){
			if(cost[v[e]][v[p]]>mx){
				mx = cost[v[e]][v[p]];
			}
		}
	}
	wei[x] = mx;
	int col[MAX];
	memset(col,0,sizeof(col));
	for(int e=0;e<sz(v);e++){
		if(col[v[e]]) continue;
		vector<int> k;
		k.push_back(v[e]);
		col[v[e]] = 1;
		for(int p=0;p<sz(v);p++){
			if(col[v[p]]==0&&cost[v[e]][v[p]]!=mx){
				col[v[p]] = 1;
				k.push_back(v[p]);
			}
		}
		if(sz(k)==1){
			adj[x].push_back(k[0]);
		}else{
			dfs(k,st++,x);
		}
	}
}
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++){
		for(int p=1;p<=n;p++){
			scanf("%d",&cost[e][p]);
			if(e==p) wei[e] = cost[e][p];
		}
	}
	vector<int> v;
	for(int e=1;e<=n;e++) v.push_back(e);
	st = n + 1;
	int rt = st;
	dfs(v,st++,-1);
	printf("%d\n",st-1);
	for(int e=1;e<=st-1;e++) printf("%d ",wei[e]);
	printf("\n%d\n",rt);
	for(int e=1;e<=st-1;e++){
		for(int p=0;p<sz(adj[e]);p++){
			printf("%d %d\n",adj[e][p],e);
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