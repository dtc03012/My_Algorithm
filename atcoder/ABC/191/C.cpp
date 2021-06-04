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

char arr[12][12];
int vis[12][12],n,m,tot,ck[12][12];
void dfs(int y,int x,int col){
	vis[y][x] = col;
	for(int e=0;e<4;e++){
		int nx = x + dx[e];
		int ny = y + dy[e];
		if(isrange(ny,nx,n,m)&&vis[ny][nx]==0&&arr[y][x]==arr[ny][nx]){
			dfs(ny,nx,col);
		}
	}
	for(int e=0;e<4;e++){
		int nx = x + dx[e];
		int ny = y + dy[e];
		if(isrange(ny,nx,n,m)&&ck[ny][nx]==0&&arr[y][x]!=arr[ny][nx]){
			ck[ny][nx] = 1;
			if(dy[e]){
				if(isrange(ny,x+1,n,m)&&ck[ny][x+1]) continue;
				if(isrange(ny,x-1,n,m)&&ck[ny][x-1]) continue;
			}
			if(dx[e]){
				if(isrange(y+1,nx,n,m)&&ck[y+1][nx]) continue;
				if(isrange(y-1,nx,n,m)&&ck[y-1][nx]) continue;
			}
			tot++;
		}
	}
}
void solve(int tc){
	scanf("%d%d",&n,&m);
	for(int e=0;e<=n+1;e++){
		for(int p=0;p<=m+1;p++) arr[e][p] = '.';
	}
	for(int e=1;e<=n;e++){
		string c;
		cin >> c;
		for(int p=1;p<=m;p++) arr[e][p] = c[p-1];
	}
	n += 2;
	m += 2;
	int mx = 1,ans = 0;
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++){
			if(vis[e][p]==0&&arr[e][p]=='#'){
				memset(ck,0,sizeof(ck));
				tot = 0;
				dfs(e,p,mx++);
				ans = max(ans,tot);
			}
		}
	}
	printf("%d\n",ans);
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