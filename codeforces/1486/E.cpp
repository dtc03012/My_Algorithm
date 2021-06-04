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

const int MAX = 101010;
int n,m;
vector<pi> v[MAX];
lld vis[MAX][2][51];
struct inf{
	lld dist;
	int x,ty,vv;
};
bool operator<(const inf& a,const inf& b){
	return a.dist < b.dist;
}
void dik(){
	for(int e=0;e<MAX;e++){
		for(int p=0;p<51;p++){
			vis[e][0][p] = vis[e][1][p] = 1e18;
		}
	}
	vis[1][0][0] = 0;
	priority_queue<inf> q;
	q.push({0,1,0,0});
	while(!q.empty()){
		lld dist = -q.top().dist;
		int x = q.top().x;
		int ty = q.top().ty;
		int vv = q.top().vv;
		q.pop();
		if(vis[x][ty][vv]!=dist) continue;
		for(int p=0;p<sz(v[x]);p++){
			int nx = v[x][p].x;
			int nv = v[x][p].y;
			if(ty==0){
				if(vis[nx][1][nv]>dist){
					vis[nx][1][nv] = dist;
					q.push({-dist,nx,1,nv});
				}
			}else{
				lld ddist = dist + (vv+nv)*(vv+nv);
				if(vis[nx][0][0]>ddist){
					vis[nx][0][0] = ddist;
					q.push({-ddist,nx,0,0});
				}
			}
		}
	}
	for(int e=1;e<=n;e++){
		if(vis[e][0][0]==1e18) printf("-1 ");
		else printf("%lld ",vis[e][0][0]);
	}
}
void solve(int tc){
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back(mk(b,c));
		v[b].push_back(mk(a,c));
	}
	dik();
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