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
int A[MAX][MAX],B[MAX][MAX];
lld dp[MAX][MAX][2];
set<int> s[MAX];
void solve(int tc){
	int n,m;
	cin >> n >> m;
	for(int e=0;e<n;e++){
		for(int p=0;p<m-1;p++) cin >> A[e][p];
	}
	for(int e=0;e<n-1;e++){
		for(int p=0;p<m;p++) cin >> B[e][p];
	}
	for(int e=0;e<n;e++) for(int p=0;p<m;p++) dp[e][p][0] = dp[e][p][1] = 1e18;
	dp[0][0][0] = 0;
	priority_queue<pair<pair<lld,int> ,pi> > q;	
	q.push(mk(mk(0,0),mk(0,0)));
	while(!q.empty()){
		lld dist = -q.top().x.x;
		int ty = q.top().x.y;
		int y = q.top().y.x;
		int x = q.top().y.y;
		q.pop();
		if(dp[y][x][ty]!=dist) continue;
		if(x<m-1){
			if(dist+A[y][x]<dp[y][x+1][0]){
				dp[y][x+1][0] = dist + A[y][x];
				q.push(mk(mk(-(dist+A[y][x]),0),mk(y,x+1)));
			}
		}
		if(x>0){
			if(dist+A[y][x-1]<dp[y][x-1][0]){
				dp[y][x-1][0] = dist + A[y][x-1];
				q.push(mk(mk(-(dist+A[y][x-1]),0),mk(y,x-1)));
			}
		}
		if(y<n-1){
			if(dist+B[y][x]<dp[y+1][x][0]){
				dp[y+1][x][0] = dist + B[y][x];
				q.push(mk(mk(-(dist+B[y][x]),0),mk(y+1,x)));
			}
		}
		if(y>=1){
			int ny = y - 1;
			if(dist+(2-ty)<dp[ny][x][1]){
				dp[ny][x][1] = dist + (2-ty);
				q.push(mk(mk(-dp[ny][x][1],1),mk(ny,x)));
			}
			if(dist+(2-ty)<dp[ny][x][0]){
				dp[ny][x][0] = dist + (2-ty);
				q.push(mk(mk(-dp[ny][x][0],0),mk(ny,x)));
			}
		}
	}
	cout << min(dp[n-1][m-1][0],dp[n-1][m-1][1]);
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