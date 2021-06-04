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
	 if(1<=y&&y<=n&&1<=x&&x<=m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};

const int MAX = 2020;
int arr[MAX][MAX],vis[MAX][MAX],n,m,w;
pl go(int y,int x){
	memset(vis,-1,sizeof(vis));
	queue<pair<int,pi> > q;
	q.push(mk(0,mk(y,x)));
	vis[y][x] = 0;
	lld ans = 1e18;
	while(!q.empty()){
		int st = q.front().x;
		int y = q.front().y.x;
		int x = q.front().y.y;
		if(arr[y][x]) ans = min(ans,1ll*w*st+arr[y][x]);
		q.pop();
		for(int e=0;e<4;e++){
			int ny = y + dy[e];
			int nx = x + dx[e];
			if(isrange(ny,nx,n,m)&&vis[ny][nx]==-1&&arr[ny][nx]!=-1){
				vis[ny][nx] = st + 1;
				q.push(mk(st + 1,mk(ny,nx)));
			}
		}
	}
	lld xx = -1;
	if(vis[1][1]!=-1&&vis[n][m]!=-1){
		if(y==n&&x==m) xx = 1ll*vis[1][1]*w;
		else xx = 1ll*vis[n][m]*w;
	}
	return mk(xx,ans);
}
void solve(int tc){
	cin >> n >> m >> w;
	for(int e=1;e<=n;e++){
		for(int p=1;p<=m;p++){
			cin >> arr[e][p];
		}
	}
	pl f1 = go(1,1);
	pl f2 = go(n,m);
	lld ans = 1e18;
	if(f1.x!=-1) ans = f1.x;
	ans = min(ans,f1.y+f2.y);
	if(ans==1e18) ans = -1;
	cout << ans << "\n";
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