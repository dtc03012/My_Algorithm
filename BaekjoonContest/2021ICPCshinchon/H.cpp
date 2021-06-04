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

const int MAX = 505;
string arr[MAX];
int dp[MAX][MAX];
set<int> h[MAX],r[MAX];
set<int> dh[MAX],dr[MAX];
int hh[MAX][MAX],rr[MAX][MAX];
void solve(int tc){
	for(int e=0;e<MAX;e++){
		for(int q=0;q<MAX;q++){
			dp[e][q] = 1e9;
		}
	}
	int n,m;
	cin >> m >> n;
	int sy,sx;
	int ey,ex;
	for(int e=0;e<n;e++) {
		cin >> arr[e];
		for(int p=0;p<m;p++){
			if(arr[e][p]=='T'){
				sy = e+1;
				sx = p+1;
			}else if(arr[e][p]=='E'){
				ey = e+1;
				ex = p+1;
			}else if(arr[e][p]=='R'){
				h[e+1].insert(p+1);
				r[p+1].insert(e+1);
			}else if(arr[e][p]=='H'){
				dh[e+1].insert(p+1);
				dr[p+1].insert(e+1);
			}
		}
	}
	for(int e=1;e<=n;e++){
		for(int p=1;p<=m;p++){
			int xx = 0;
			if(arr[e-1][p-1]>='0'&&arr[e-1][p-1]<='9') xx = arr[e-1][p-1] - '0';
			hh[e][p] = hh[e-1][p] + xx;
			rr[p][e] = rr[p-1][e] + xx;
		}
	}
	priority_queue<pair<int,pi> > q;
	q.push(mk(0,mk(sy,sx)));
	dp[sy][sx] = 0;
	while(!q.empty()){
		int dist = -q.top().x;
		int y = q.top().y.x;
		int x = q.top().y.y;
		q.pop();
		if(dp[y][x]!=dist) continue;
		set<int>::iterator it1 = h[y].lower_bound(x);
		set<int>::iterator it2 = r[x].lower_bound(y);
		set<int>::iterator it3 = dh[y].lower_bound(x);
		set<int>::iterator it4 = dr[x].lower_bound(y);
		int yl=-1,yr=1e9,xl=-1,xr=1e9;
		if(it1!=h[y].end()){
			xr = *it1;
		}
		if(it1!=h[y].begin()){
			it1--;
			xl = *it1;
		}
		if(it2!=r[x].end()){
			yr = *it2;
		}
		if(it2!=r[x].begin()){
			it2--;
			yl = *it2;
		}
		int dyl = -1,dyr = 1e9,dxl = -1,dxr = 1e9;
		if(it3!=dh[y].end()){
			dxr = *it3;
		}
		if(it3!=dh[y].begin()){
			it3--;
			dxl = *it3;
		}
		if(it4!=dr[x].end()){
			dyr = *it4;
		}
		if(it4!=dr[x].begin()){
			it4--;
			dyl = *it4;
		}
		if(dyl<yl&&yl+1!=y){
			int gg = hh[y-1][x] - hh[yl][x];
			if(dp[yl+1][x]>gg+dist){
				dp[yl+1][x] = gg + dist;
				q.push(mk(-(gg+dist),mk(yl+1,x)));
			}
		}
		if(x==ex&&max(yl,dyl)<ey&&ey<y){
			dp[ey][ex] = min(dp[ey][ex],dist + hh[y-1][x]-hh[ey][x]);
		}
		if(yr<dyr&&yr-1!=y){
			int gg = hh[yr-1][x] - hh[y][x];
			if(dp[yr-1][x]>gg+dist){
				dp[yr-1][x] = gg + dist;
				q.push(mk(-(gg+dist),mk(yr-1,x)));
			}
		}
		if(x==ex&&y<ey&&ey<min(yr,dyr)){
			dp[ey][ex] = min(dp[ey][ex],dist + hh[ey-1][x]-hh[y][x]);
		}
		if(dxl<xl&&xl+1!=x){
			int gg = rr[x-1][y] - rr[xl][y];
			if(dp[y][xl+1]>gg+dist){
				dp[y][xl+1] = gg + dist;
				q.push(mk(-(gg+dist),mk(y,xl+1)));
			}
		}
		if(y==ey&&max(xl,dxl)<ex&&ex<x){
			dp[ey][ex] = min(dp[ey][ex],dist+rr[x-1][y]-rr[ex][y]);
		}
		if(xr<dxr&&xr-1!=x){
			int gg = rr[xr-1][y] - rr[x][y];
			if(dp[y][xr-1]>gg+dist){
				dp[y][xr-1] = gg + dist;
				q.push(mk(-(gg+dist),mk(y,xr-1)));
			}
		}
		if(y==ey&&x<ex&&ex<min(xr,dxr)){
			dp[ey][ex] = min(dp[ey][ex],dist + rr[ex-1][y]-rr[x][y]);
		}
	}
	int xx = dp[ey][ex];
	if(xx==1e9) xx = -1;
	printf("%d",xx);
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