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

const int MAX = 202020;
vector<pi> v[MAX],g[MAX];
int vis[MAX],n,m,k,ck[MAX],vis2[MAX];
vector<string> ans;
void dfs(int x){
	if(!k) return;
	if(x==1) dfs(x+1);
	else if(x==n+1){
		string vv = "";
		for(int e=0;e<m;e++) vv += char('0'+ck[e]);
		ans.push_back(vv);
		k--;
	}else{
		for(int p=0;p<sz(g[x]);p++){
			int nx = g[x][p].y;
			ck[nx] = 1;
			dfs(x+1);
			ck[nx] = 0;
			if(!k) return;
		}
	}
}
void solve(int tc){
	cin >> n >> m >> k;
	for(int e=0;e<m;e++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(mk(b,e));
		v[b].push_back(mk(a,e));
	}
	memset(vis,-1,sizeof(vis));
	vis[1] = 0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int x = q.front();q.pop();
		for(int e=0;e<sz(v[x]);e++){
			int nx = v[x][e].x;
			if(vis[nx]==-1){
				vis[nx] = vis[x] + 1;
				q.push(nx);
			}
		}
	}
	for(int e=1;e<=n;e++){
		for(int p=0;p<sz(v[e]);p++){
			int nx = v[e][p].x;
			int ty = v[e][p].y;
			if(vis[e]-1==vis[nx]){
				g[e].push_back(mk(nx,ty));
			}
		}
	}
	dfs(1);
	cout << sz(ans) << "\n";
	for(int e=0;e<sz(ans);e++) cout <<ans[e] << "\n";
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}