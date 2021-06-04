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

const int MAX = 111;
int vis[MAX],ans[MAX*MAX],col[MAX],f[MAX*MAX],n,m;
vector<pi> v[MAX];
void dfs(int x){
	vis[x] = 1;
	for(int p=0;p<sz(v[x]);p++){
		int nx = v[x][p].x;
		int wh = v[x][p].y;
		if(col[x]>col[nx]){
			if(f[wh]==x) ans[wh] = 1;
			else ans[wh] = 2;
		}else if(col[x]<col[nx]){
			if(f[wh]==nx) ans[wh] = 1;
			else ans[wh] = 2;
		}else{
			if(f[wh]==x) ans[wh] = 1;
			else ans[wh] = 2;
			if(vis[nx]==0) dfs(nx);
		}
	}
}
void solve(int tc){
	scanf("%d%d",&n,&m);
	for(int e=1;e<=m;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		f[e] = a;
		v[a].push_back(mk(b,e));
		v[b].push_back(mk(a,e));
	}
	priority_queue<pi> q;
	for(int e=1;e<=n;e++){
		 scanf("%d",&col[e]);
		 q.push(mk(col[e],e));
	}
	while(!q.empty()){
		pi x = q.top();
		q.pop();
		if(vis[x.y]) continue;
		dfs(x.y);
	}
	for(int e=1;e<=m;e++){
		if(ans[e]==1) printf("->\n");
		else printf("<-\n");
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
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}