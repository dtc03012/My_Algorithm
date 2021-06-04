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

const int MAX = 101010;
char S[MAX][4];
int dp[MAX*4][27],vis[MAX],sz[MAX],rt = 2;
vector<int> go[MAX*4];
vector<int> g[MAX];
void dfs(char *T,int now,int len,int pos,int xx){
	if(now==len){
		for(auto k: go[xx]){
			if(pos!=k){
				g[pos].push_back(k);
				sz[k]++;
			}
		}
		return;
	}
	int nx = T[now] - 'a';
	if(dp[xx][nx]!=-1) dfs(T,now+1,len,pos,dp[xx][nx]);
	if(dp[xx][26]!=-1) dfs(T,now+1,len,pos,dp[xx][26]);
}
void solve(int tc){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	memset(dp,-1,sizeof(dp));
	for(int e=1;e<=n;e++){
		scanf("%s",S[e]);
		int xx = 1;
		for(int p=0;p<k;p++){
			int nx = 26;
			if(S[e][p]!='_') nx = S[e][p] - 'a';
			if(dp[xx][nx]==-1) dp[xx][nx] = rt++;
			xx = dp[xx][nx];
		}
		go[xx].push_back(e);
	}
	bool suc = true;
	for(int e=0;e<m;e++){
		char T[4];
		int pos;
		scanf("%s%d",T,&pos);
		bool err = true;
		for(int p=0;p<k;p++){
			if(S[pos][p]=='_') continue;
			if(S[pos][p]!=T[p]){
				err = false;
				break;
			}
		}
		if(!err){
			suc = false;
			break;
		}
		dfs(T,0,k,pos,1);
	}
	if(!suc){
		printf("NO\n");
	}else{
		queue<int> q;
		vector<int> ans;
		for(int e=1;e<=n;e++){
			if(sz[e]==0) q.push(e);
		}
		while(!q.empty()){
			int x = q.front();q.pop();
			ans.push_back(x);
			vis[x] = 1;
			for(int e=0;e<sz(g[x]);e++){
				int nx = g[x][e];
				sz[nx]--;
				if(sz[nx]==0){
					if(vis[nx]){
						suc = false;
						break;
					}else{
						q.push(nx);
					}
				}
			}
		}
		for(int e=1;e<=n;e++) if(sz[e]) suc = false;
		for(int e=1;e<=n;e++) if(vis[e]==0) ans.push_back(e);
		if(!suc){
			printf("NO\n");
		}else{
			printf("YES\n");
			for(int e=0;e<sz(ans);e++) printf("%d ",ans[e]);
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
	
		// scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}