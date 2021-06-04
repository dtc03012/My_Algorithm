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

const int MAXN = 500050, MAXM = 500050;
vector<int> v[MAXN];
int col[MAXN],check[MAXN],ans = 0,rcheck[MAXN],vis[MAXN];
pair<bool,int> can(int x,int n){
	for(int e=1;e<=n;e++) check[e] = 0;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		check[nx] = 1;
	}
	bool suc = true;
	int xx = 1e9;
	for(int e=1;e<=n;e++){
		if(check[e]==0){
			xx = min(xx,e);
			if(sz(v[e])!=sz(v[x])){
				suc = false;
				break;
			}
			for(int p=0;p<sz(v[e]);p++){
				if(v[e][p]!=v[x][p]) suc = false;
			}
		}
	}
	if(suc){
		for(int e=1;e<=n;e++) rcheck[e] = check[e];
	}
	return mk(suc,xx);
}
void dfs(int x){
	col[x] = 1;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(col[nx]==0) dfs(nx);
	}
}
void fail(int n){
	cout << "0\n";
	for(int e=0;e<n;e++) cout << "0";
	cout << "\n";
}
void solve(int tc){
	int n,m;
	cin >> n >> m;
	for(int e=1;e<=n;e++){
		col[e] = -1;
		check[e] = 0;
		rcheck[e] = 0;
		vis[e] = 0;
		v[e].clear();
	}
	for(int e=0;e<m;e++){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int cnt = 0;
	for(int e=1;e<=n;e++){
		if(col[e]==0){
			dfs(e);
			cnt++;
		}
	}
	if(cnt>1){
		fail(n);
		return;
	}
	int mx = 1e9,wh = -1;
	for(int e=1;e<=n;e++){
		sort(all(v[e]));
		if(mx>sz(v[e])){
			mx = sz(v[e]);
			wh = e;
		}
	}
	ans = 0;
	pi kk = can(wh,n);
	if(kk.x) ans++;
	for(int e=0;e<sz(v[wh]);e++){
		int nx = v[wh][e];
		pi kk = can(nx,n);
		if(kk.x){
			if(vis[kk.y]) continue;
			ans++;
			vis[kk.y]++;
		}
	}
	if(ans==0){
		fail(n);
		return;
	}else{
		cout << ans << "\n";
		for(int e=1;e<=n;e++) cout << (rcheck[e]^1);
		cout << "\n";
	}
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
	cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}