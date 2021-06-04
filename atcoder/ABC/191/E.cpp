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

vector<pi> v[2222];
pli vis[2222];
int n,m;
lld dik(int r){
	for(int e=1;e<=n;e++) vis[e] = mk(1e18,-1);
	priority_queue<pli> q;
	q.push(mk(0,r));
	while(!q.empty()){
		int x = q.top().y;
		lld dist = -q.top().x;
		q.pop();
		if(vis[x].x<=dist){
			if(vis[x].y!=x) continue;
		}
		for(int e=0;e<sz(v[x]);e++){
			int nx = v[x][e].x;
			lld ddist = dist + v[x][e].y;
			if(vis[nx].x>ddist){
				vis[nx] = mk(ddist,nx);
				q.push(mk(-ddist,nx));
			}
		}
	}
	return vis[r].x;
}
void solve(int tc){
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back(mk(b,c));
	}
	for(int e=1;e<=n;e++){
		lld xx = dik(e);
		if(xx==1e18) xx = -1;
		printf("%lld\n",xx);
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
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}