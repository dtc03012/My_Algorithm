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

const int NMAX = 1010;
const int MMAX = 101010;
struct inf{
	int y,pos,w;
};
priority_queue<pi> q;
vector<inf> v[NMAX];
int ck[MMAX],cnt,val[NMAX],use[NMAX],vis[NMAX],xx;
void go(int x){
	vis[x] = 1;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e].y;
		int pos = v[x][e].pos;
		int ty = v[x][e].w;
		if(ck[pos]==-1&&vis[nx]==0){
			ck[pos] = ty;
			use[nx]++;
			use[x]++;
			val[x]++;
			val[nx]--;
			cnt++;
			go(nx);
			break;
		}
	}
	vis[x] = 0;
	q.push(mk(-val[x],x));
}
void solve(int tc){
	int n,m;
	cin >> n >> m;
	q = priority_queue<pi>();
	for(int e=1;e<=n;e++){
		v[e].clear();
		use[e] = 0;
		val[e] = 0;
	}
	for(int e=1;e<=m;e++) ck[e] = -1;
	for(int e=1;e<=m;e++){
		int x,y;
		cin >> x >> y;
		v[x].push_back({y,e,0});
		v[y].push_back({x,e,1});
	}
	cnt = 0;
	for(int e=1;e<=n;e++) if(use[e]<sz(v[e])) q.push(mk(0,e));
	while(cnt!=m){
		int rt = -1;
		while(!q.empty()){
			int dist = -q.top().x;
			int pos = q.top().y;
			q.pop();
			if(use[pos]==sz(v[pos])) continue;
			if(val[pos]!=dist) continue;
			if(val[pos]<=0){
				rt = pos;
				break;
			}
		}
		if(rt==-1){
			assert(false);
			break;
		}
		go(rt);
	}
	for(int e=1;e<=m;e++){
		cout << ck[e];
	}
	cout << "\n";
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}