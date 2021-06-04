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

int ck[16][16],n,m,a,b;
lld ans = 0;
void dfs(int y,int x,int k1,int k2){
	if(y==n){
		bool suc = true;
		for(int e=0;e<n;e++){
			for(int p=0;p<m;p++){
				if(ck[e][p]==0) suc = false;
			}
		}
		if(suc) ans++;
		return;
	}
	int ny = y;
	int nx = x + 1;
	if(nx==m){
		nx = 0;
		ny++;
	}
	if(ck[y][x]){
		dfs(ny,nx,k1,k2);
		return;
	}
	if(k1){
		if(x+1<m&&ck[y][x+1]==0){
			ck[y][x] = 1;
			ck[y][x+1] = 1;
			dfs(ny,nx,k1-1,k2);
			ck[y][x] = 0;
			ck[y][x+1] = 0;
		}
		if(y+1<n&&ck[y+1][x]==0){
			ck[y][x] = 1;
			ck[y+1][x] = 1;
			dfs(ny,nx,k1-1,k2);
			ck[y][x] = 0;
			ck[y+1][x] = 0;
		}
	}
	if(k2){
		ck[y][x] = 1;
		dfs(ny,nx,k1,k2-1);
		ck[y][x] = 0;
	}
}
void solve(int tc){
	cin >> n >> m >> a >> b;
	dfs(0,0,a,b);
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
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}