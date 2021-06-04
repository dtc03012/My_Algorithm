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
vector<int> v[MAX];
int sz[MAX],pos[MAX],can[MAX],ans[MAX],ansv[MAX],dp1[MAX],dp2[MAX],top;
int dfs(int x,int lx){
	if(can[x]){
		sz[x] = 1;
		pos[x] = x;
	}
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			sz[x] += dfs(nx,x);
			if(pos[x]==-1){
				if(pos[nx]!=-1){
					pos[x] = pos[nx];
				}
			}
		}
	}
	return sz[x];
}
void go(int x,int lx,int num){
	if(sz[x]){
		ans[x] = num;
		ansv[x] = pos[x];
		dp1[num] = 1;
		dp2[num] = pos[x];
		top = num;
	}else{
		ans[x] = num - 2*(num-top);
		ansv[x] = dp2[top];	
	}
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			go(nx,x,num+1);
		}
	}
	dp1[num] = 0;
	dp2[num] = -1;
	while(dp1[top]==0) top--;
}
void solve(int tc){
	int n,k,rt;
	cin >> n >> k >> rt;
	for(int e=1;e<=n;e++){
		v[e].clear();
		sz[e] = 0;
		pos[e] = -1;
		can[e] = 0;
		dp1[e] = 0;
		dp2[e] = -1;
	}
	top = 0;
	for(int e=1;e<=k;e++){
		int r;
		cin >> r;
		can[r] = 1;
	}
	for(int e=0;e<n-1;e++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(rt,-1);
	go(rt,-1,0);
	for(int e=1;e<=n;e++) cout << ans[e]  << " ";
	cout << "\n";
	for(int e=1;e<=n;e++) cout << ansv[e] << " ";
	cout << "\n";
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