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
vector<int> v[MAX];
lld val[MAX],od[MAX],ev[MAX],sz[MAX],ans,n;
void dfs(int x,int lx){
	sz[x] = 1;
	ev[x] = 1;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			dfs(nx,x);
			sz[x] += sz[nx];
			ev[x] += od[nx];
			od[x] += ev[nx];
		}
	}
}
lld nod,nev,nsz;
void add(lld x){
	ans += x;
	ans %= mod;
	ans = (ans+mod)%mod;
}
lld mult(lld x,lld y){
	lld kk = (x*y);
	kk %= mod;
	kk = (kk+mod)%mod;
	return kk;
}
void go(int x,int lx){
	add(val[x]);
	lld lv = n - nsz;
	add(mult(mult(lv,nod),val[x]));
	add(mult(mult(lv,nev),-val[x]));
	lld tev = nod + 1,tod = nev;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			lv = n - sz[nx];
			tev += od[nx];
			tod += ev[nx];
			add(mult(mult(lv,od[nx]),val[x]));
			add(mult(mult(lv,ev[nx]),-val[x]));
		}
	}
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			lld osz = nsz,ood = nod,oev = nev;
			nsz = n - sz[nx];
			nev = tev - od[nx];
			nod = tod - ev[nx];
			go(nx,x);
			nsz = osz;
			nev = oev;
			nod = ood;
		}
	}
}
void solve(int tc){
	scanf("%lld",&n);
	for(int e=1;e<=n;e++){
		 scanf("%lld",&val[e]);
	}
	for(int e=0;e<n-1;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,-1);
	go(1,-1);
	printf("%lld\n",ans);
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