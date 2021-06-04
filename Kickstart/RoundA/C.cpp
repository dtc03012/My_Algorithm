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

const int NMAX = 2e6 + 100;
const int MAX = 303;
int arr[MAX][MAX],vis[MAX][MAX];
set<pi> k[NMAX];
void solve(int tc){
	int n,m;
	cin >> n >> m;
	int mx = 0;
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++){
			cin >> arr[e][p];
			vis[e][p] = 0;
			mx = max(mx,arr[e][p]);
			k[arr[e][p]].clear();
		}
	}
	lld ans = 0;
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++){
			k[arr[e][p]].insert(mk(e,p));
		}
	}
	int now = mx;
	while(true){
		if(now<0) break;
		if(sz(k[now])==0) break;
		queue<pi> q1;
		for(auto x : k[now]){
			q1.push(x);
			vis[x.x][x.y] = 1;
		}
		k[now].clear();
		while(!q1.empty()){
			int y = q1.front().x;
			int x = q1.front().y;
			q1.pop();
			for(int e=0;e<4;e++){
				int ny = y + dy[e];
				int nx = x + dx[e];
				if(isrange(ny,nx,n,m)&&vis[ny][nx]==0){
					ans += (now-1-arr[ny][nx]);
					k[arr[ny][nx]].erase(mk(ny,nx));
					k[now-1].insert(mk(ny,nx));
					arr[ny][nx] = now - 1;
				}
			}
		}
		now--;
	}
	cout << "Case #" << tc << ": " << ans << "\n";
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