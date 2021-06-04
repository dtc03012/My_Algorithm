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

const int MAX = 202020;
vector<pi> v[MAX];
lld dp[MAX][4];
void dik(){
	for(int e=0;e<MAX;e++){
		for(int p=0;p<4;p++) dp[e][p] = 1e18;
	}
	dp[1][0] = 0;
	priority_queue<pair<lld,pi> > q;
	q.push(mk(0,mk(1,0)));
	while(!q.empty()){
		lld dist = -q.top().x;
		int x = q.top().y.x;
		int ty = q.top().y.y;
		q.pop();
		if(dp[x][ty]!=dist) continue;
		for(int e=0;e<sz(v[x]);e++){
			int nx = v[x][e].x;
			lld ddist = dist + v[x][e].y;
			if(dp[nx][ty]>ddist){
				dp[nx][ty] = ddist;
				q.push(mk(-ddist,mk(nx,ty)));
			}
		}
		if(ty==0){
			for(int e=0;e<sz(v[x]);e++){
				int nx = v[x][e].x;
				lld ddist = dist + v[x][e].y*2;
				if(dp[nx][1]>ddist){
					dp[nx][1] = ddist;
					q.push(mk(-ddist,mk(nx,1)));
				}
				lld ddist2 = dist + v[x][e].y;
				if(dp[nx][2]>ddist2){
					dp[nx][2] = ddist2;
					q.push(mk(-ddist2,mk(nx,2)));
				}
				lld ddist3 = dist;
				if(dp[nx][3]>ddist3){
					dp[nx][3] = ddist3;
					q.push(mk(-ddist3,mk(nx,3)));
				}
			}
		}else if(ty==1){
			for(int e=0;e<sz(v[x]);e++){
				int nx = v[x][e].x;
				lld ddist = dist;
				if(dp[nx][2]>ddist){
					dp[nx][2] = ddist;
					q.push(mk(-ddist,mk(nx,2)));
				}
			}
		}else if(ty==3){
			for(int e=0;e<sz(v[x]);e++){
				int nx = v[x][e].x;
				lld ddist = dist + v[x][e].y*2;
				if(dp[nx][2]>ddist){
					dp[nx][2] = ddist;
					q.push(mk(-ddist,mk(nx,2)));
				}
			}
		}
	}
}
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back(mk(b,c));
		v[b].push_back(mk(a,c));
	}
	dik();
	for(int e=2;e<=n;e++) printf("%lld ",dp[e][2]);
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