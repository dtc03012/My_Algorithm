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
int ck[MAX],lv[MAX],sz[MAX],no[MAX];
vector<int> v[MAX];
int getsz(int x,int lx){
	sz[x] = 1;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx&&no[nx]==0){
			sz[x] += getsz(nx,x);
		}
	}
	return sz[x];
}
pi find(int x,int lx,int tot){
	if(sz[x]==tot) return mk(x,lx);
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx&&no[nx]==0){
			pi xx = find(nx,x,tot);
			if(xx.x!=-1) return xx;
		}
	}
	return mk(-1,-1);
}
bool dfs(int x,int lx,int n){
	if(n<=1) return true;
	no[x] = 1;
	for(int e=n;e>=2;e=lv[e]){
		getsz(x,lx);
		pi where = find(x,lx,e);
		if(where.x==-1){
			int ee = lv[e];
			where = find(x,lx,ee);
			if(where.x==-1) return false;
			bool can = dfs(where.x,where.y,lv[ee]);
			if(!can) return false;
		}else{
			bool can = dfs(where.x,where.y,lv[e]);
			if(!can) return false;
			e = lv[e];
		}
	}
	return true;
}
void solve(int tc){
	int f1=1,f2=1;
	int tot = 1,ntot = 1;
	for(int e=0;e<50;e++){
		if(f1>=MAX) break;
		ck[f1] = 1;
		lv[f1] = f2;
		int tmp = f1;
		f1 += f2;
		f2 = tmp;
	}
	int n;
	scanf("%d",&n);
	for(int e=0;e<n-1;e++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if(ck[n]==0) printf("NO\n");
	else{
		bool suc = dfs(1,-1,lv[n]);
		if(suc) printf("YES\n");
		else printf("NO\n");
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