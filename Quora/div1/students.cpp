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
const int MAXN = 202020, MAXM = 202020;
vector<int> gph[MAXN];
int dis[MAXN], l[MAXN], r[MAXM], vis[MAXN];
void clear(){ for(int i=0; i<MAXN; i++) gph[i].clear(); }
void add_edge(int l, int r){ gph[l].push_back(r); }
bool bfs(int n){
queue<int> que;
bool ok = 0;
memset(dis, 0, sizeof(dis));
for(int i=0; i<n; i++){
if(l[i] == -1 && !dis[i]){
que.push(i);
dis[i] = 1;
}
}
while(!que.empty()){
int x = que.front();
que.pop();
for(auto &i : gph[x]){
if(r[i] == -1) ok = 1;
else if(!dis[r[i]]){
dis[r[i]] = dis[x] + 1;
que.push(r[i]);
}
}
}
return ok;
}
bool dfs(int x){
if(vis[x]) return 0;
vis[x] = 1;
for(auto &i : gph[x]){
if(r[i] == -1 || (!vis[r[i]] && dis[r[i]] == dis[x] + 1 && dfs(r[i]))){
l[x] = i; r[i] = x;
return 1;
}
}
return 0;
}
int match(int n){
memset(l, -1, sizeof(l));
memset(r, -1, sizeof(r));
int ret = 0;
while(bfs(n)){
memset(vis, 0, sizeof(vis));
for(int i=0; i<n; i++) if(l[i] == -1 && dfs(i)) ret++;
}
return ret;
}
vector<int> v1,v2;
int n,m;
int get_idx(int x,int ty){
	if(ty==0){
		return lower_bound(all(v1),x) - v1.begin();
	}else{
		return lower_bound(all(v2),x) - v2.begin();
	}
}
void solve(int tc){
	scanf("%d%d",&n,&m);
	vector<pi> v;
	for(int e=0;e<m;e++){
		int sy,sx,ey,ex;
		scanf("%d%d%d%d",&sy,&sx,&ey,&ex);
		sx--;sy--;ex--;ey--;
		int f1 = sy*n + sx + 1;
		int f2 = ey*n + ex + 1;
		if(sy%2==sx%2){
			v.push_back(mk((f1+1)/2,(f2+1)/2));
		}else{
			v.push_back(mk((f2+1)/2,(f1+1)/2));
		}
	}
	for(int e=0;e<sz(v);e++){
		v1.push_back(v[e].x);
		v2.push_back(v[e].y);
	}
	sort(all(v1));
	v1.erase(unique(all(v1)),v1.end());
	sort(all(v2));
	v2.erase(unique(all(v2)),v2.end());
	for(int e=0;e<sz(v);e++){
		v[e].x = get_idx(v[e].x,0);
		v[e].y = get_idx(v[e].y,1);
		add_edge(v[e].x,v[e].y);
	}
	int vv = match(sz(v1));
	printf("%d",n*n-vv);
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