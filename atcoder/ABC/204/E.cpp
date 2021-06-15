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
vector<pair<int,pl> > v[MAX];
lld vis[MAX];
int n,m;
bool can(int x){
	if(x==n) return true;
	vis[x] = 1;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e].x;
		if(vis[nx]==0){
			if(can(nx)) return true;
		}
	}
	return false;
}
lld f(lld x){
	for(int e=1;e<=n;e++) vis[e] = 1e18;
	vis[1] = 0;
	priority_queue<pl> q;
	q.push(mk(0,1));
	while(!q.empty()){
		lld dist = -q.top().x;
		int x = q.top().y;
		q.pop();
		if(vis[x]!=dist) continue;
		for(int e=0;e<sz(v[x]);e++){
			int nx = v[x][e].x;
			if(v[x][e].y.y==0){
				lld ddist = dist + v[x][e].y.x;
				if(vis[nx]>ddist){
					vis[nx] = ddist;
					q.push(mk(-ddist,nx));
				}
			}else{
				lld rt = sqrt(v[x][e].y.y);
				if(rt*rt<v[x][e].y.y) rt++;
				rt--;
				lld ddist = max(dist,rt);
				ddist = ddist + v[x][e].y.x + (v[x][e].y.y/(ddist+1));
				if(vis[nx]>ddist){
					vis[nx] = ddist;
					q.push(mk(-ddist,nx));
				}
			}
		}
	}
	return vis[n];	
}
void solve(int tc){
	cin >> n >> m;
	for(int e=0;e<m;e++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		v[a].push_back(mk(b,mk(c,d)));
		v[b].push_back(mk(a,mk(c,d)));
	}
	if(!can(1)){
		cout << "-1";
		return;
	}
	cout << f(0) << "\n";
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
