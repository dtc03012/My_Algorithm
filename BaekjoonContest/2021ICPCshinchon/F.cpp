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

const int MAX =202020;
vector<pi> v[MAX];
lld f1,f2;
void dfs(int x,int lx,int ty,lld vv,int rt){
	int kk = 1;
	if(x==rt) kk = 0;
	if(ty==0){
		if(sz(v[x])==0+kk){
			f1 = vv;
			return;
		}else if(sz(v[x])>=2+kk){
			f1 = vv;
			for(int e=0;e<sz(v[x]);e++){
				int nx = v[x][e].x;
				int dd = v[x][e].y;
				if(nx!=lx){
					dfs(nx,x,1,dd,rt);
				}
			}
		}else{
			for(int e=0;e<sz(v[x]);e++){
				int nx = v[x][e].x;
				int dd = v[x][e].y;
				if(nx!=lx){
					dfs(nx,x,ty,vv+dd,rt);
				}
			}
		}
	}else{
		if(sz(v[x])==0+kk){
			f2 = max(f2,vv);
		}else{
			for(int e=0;e<sz(v[x]);e++){
				int nx = v[x][e].x;
				int dd = v[x][e].y;
				if(nx!=lx) dfs(nx,x,ty,vv+dd,rt);
			}
		}
	}
}
void solve(int tc){
	int n,rt;
	scanf("%d%d",&n,&rt);
	for(int e=0;e<n-1;e++){
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		v[a].push_back(mk(b,d));
		v[b].push_back(mk(a,d));
	}
	dfs(rt,-1,0,0,rt);
	printf("%lld %lld\n",f1,f2);
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