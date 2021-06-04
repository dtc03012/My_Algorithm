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
const lld mod = 1e9 + 7;
vector<pil> v[MAX];
lld val[MAX];
lld cnt[MAX];
void dfs(int x,int lx,lld w){
	val[x] = w;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e].x;
		lld nw = w ^ v[x][e].y;
		if(nx!=lx){
			dfs(nx,x,nw);
		}
	}
}
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<n;e++){
		int x,y;
		lld w;
		cin >> x >> y >> w;
		v[x].push_back(mk(y,w));
		v[y].push_back(mk(x,w));
	}
	dfs(1,-1,0);
	for(int e=1;e<=n;e++){
		for(int p=0;p<60;p++){
			if(val[e]&(1ll<<p)) cnt[p]++;
		}
	}
	lld ans = 0;
	for(int e=1;e<=n;e++){
		for(int p=0;p<60;p++){
			lld xx = (1ll<<p);
			xx %= mod;
			if(val[e]&(1ll<<p)){
				lld ncnt = n - e + 1 - cnt[p];
				xx = (xx*ncnt)%mod;
				ans = (ans+xx)%mod;
			}else{
				lld ncnt = cnt[p];
				xx = (xx*ncnt)%mod;
				ans = (ans+xx)%mod;
			}
			if(val[e]&(1ll<<p)) cnt[p]--;
		}
	}
	cout << ans;
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}