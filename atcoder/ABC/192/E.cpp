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
struct inf{
	int y,k,t;
};
vector<inf> v[MAX];
lld vis[MAX];
int n,m,x,y;
lld dik(){
	for(int e=1;e<=n;e++) vis[e] = 1e18;
	vis[x] = 0;
	priority_queue<pli> q;
	q.push(mk(0,x));
	while(!q.empty()){
		lld dist = -q.top().x;
		int x = q.top().y;
		q.pop();
		if(vis[x]!=dist) continue;
		for(int e=0;e<sz(v[x]);e++){
			int nx = v[x][e].y;
			lld ndist = dist;
			if(dist%v[x][e].k) ndist += (v[x][e].k - (dist%v[x][e].k));
			ndist += v[x][e].t;
			if(vis[nx]>ndist){
				vis[nx] = ndist;
				q.push(mk(-ndist,nx));
			}
		}
	}
	if(vis[y]==1e18) return -1;
	return vis[y];
}
void solve(int tc){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int e=0;e<m;e++){
		int a,b,t,k;
		scanf("%d%d%d%d",&a,&b,&t,&k);
		v[a].push_back({b,k,t});
		v[b].push_back({a,k,t});
	}
	printf("%lld",dik());
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