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

const int MAX = 303030;
vector<int> v[MAX];
int vis[MAX],ck[MAX];
vector<int> ans;
void dfs(int x){
	vis[x] = 1;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(vis[nx]==-1) dfs(nx);
	}
}
void dfs(int x,bool cnt){
	if(cnt){
		bool suc = true;
		for(int p=0;p<sz(v[x]);p++){
			int nx = v[x][p];
			if(ck[nx]==2) suc = false;
		}
		if(suc){
			ans.push_back(x);
			ck[x] = 2;
			for(int e=0;e<sz(v[x]);e++){
				int nx = v[x][e];
				if(ck[nx]==0) dfs(nx,false);
			}
		}else{
			ck[x] = 1;
			for(int e=0;e<sz(v[x]);e++){
				int nx = v[x][e];
				if(ck[nx]==0) dfs(nx,true);
			}
		}

	}else{
		ck[x] = 1;
		for(int e=0;e<sz(v[x]);e++){
			int nx = v[x][e];
			if(ck[nx]==0) dfs(nx,true);
		}
	}
}
void solve(){
	ans.clear();
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++){
		v[e].clear();
		vis[e] = -1;
		ck[e] = 0;
	}
	for(int e=0;e<m;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int cnt = 0;
	bool suc = true;
	for(int e=1;e<=n;e++){
		if(vis[e]==-1){
			dfs(e);
			cnt++;
		}
	}
	if(cnt>=2) suc = false;
	if(!suc) printf("NO\n");
	else{
		printf("YES\n");
		dfs(1,0);
		printf("%d\n",sz(ans));
		for(int e=0;e<sz(ans);e++) printf("%d ",ans[e]);
		printf("\n");
	}
}
int main(void){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}
	return 0;
}