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

const int MMAX = 22;
const int NMAX = 1010;
string arr[NMAX];
int vis[NMAX*MMAX];
vector<pi> v[NMAX*MMAX];
void solve(int tc){
	int n,m;
	cin >> m >> n;
	for(int e=0;e<n;e++) cin >> arr[e];
	for(int e=0;e<n*m;e++) vis[e] = 1e9;
	deque<int> q;
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++){
			int now = e*m + p;
			for(int q=0;q<4;q++){
				if(q==2) continue;
				int ny = e + dy[q];
				int nx = p + dx[q];
				if(isrange(ny,nx,n,m)&&arr[ny][nx]=='.'){
					int nextv = ny*m + nx;
					if(q%2){
						v[now].push_back(mk(nextv,1));
					}else{
						v[now].push_back(mk(nextv,0));
					}
				}
			}
			if(arr[e][p]=='c'){
				vis[now] = 0;
				q.push_back(now);
			}
		}
	}
	while(!q.empty()){
		int x = q.front();q.pop_front();
		for(int e=0;e<sz(v[x]);e++){
			int nx = v[x][e].x;
			int vv = v[x][e].y;
			if(vis[nx]>vis[x]+vv){
				vis[nx] = vis[x] + vv;
				if(vv==1) q.push_back(nx);
				else q.push_front(nx);
			}
		}
	}
	int ans = 1e9;
	for(int e=0;e<m;e++){
		int now = m*(n-1) + e;
		ans = min(ans,vis[now]);
	}
	if(ans==1e9) ans =- 1;
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
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}