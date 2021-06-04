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
const lld mod = 1e9 + 7;
char S[MAX][MAX];
int col[MAX][MAX];
lld dp[2][MAX][MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++) scanf("%s",S[e]);
	for(int e=0;e<n;e++){
		col[e][n-e-1] = e;
		dp[0][e][e] = 1;
	}
	for(int fx=n-2,sy=1,k=1;fx>=0&&sy<n;fx--,sy++,k^=1){
		for(int e=0;e<MAX;e++) for(int p=0;p<MAX;p++) dp[k][e][p] = 0;
		for(int x=fx,y=0,z=0;x>=0&&y<n;x--,y++,z++) col[y][x] = z;
		for(int x=n-1,y=sy,z=0;x>=0&&y<n;x--,y++,z++) col[y][x] = z;
		for(int x=fx,y=0;x>=0&&y<n;x--,y++){
			for(int nx=n-1,ny=sy;nx>=0&&ny<n;nx--,ny++){
				if(nx<x||ny<y||S[y][x]!=S[ny][nx]) continue;
				for(int q=0;q<2;q++){
					for(int r=2;r<4;r++){
						int gx = x + dx[q],gy = y + dy[q];
						int rx = nx + dx[r],ry = ny + dy[r];
						if(gx<=rx&&gy<=ry){
							dp[k][col[y][x]][col[ny][nx]] = (dp[k][col[y][x]][col[ny][nx]]+dp[k^1][col[gy][gx]][col[ry][rx]])%mod;
						}
					}
				}
			}
		}
	}
	printf("%lld\n",dp[(n-1)&1][0][0]);
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