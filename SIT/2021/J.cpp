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

const int MAX = 111;
const int NMAX = 11;
int dp[MAX*5][NMAX][NMAX][NMAX][NMAX];
pi arr[NMAX];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int p=1;p<=m;p++) scanf("%d%d",&arr[p].x,&arr[p].y);
	for(int e=0;e<MAX*4;e++) for(int p=0;p<NMAX;p++){
		for(int q=0;q<NMAX;q++) for(int r=0;r<NMAX;r++) for(int t=0;t<NMAX;t++) dp[e][p][q][r][t] = -1;
	}
	dp[0][0][0][0][0] = 0;
	int cnt = 1;
	while(true){
		for(int e=0;e<=m;e++){
			for(int p=0;p<=m;p++){
				for(int q=0;q<=m;q++){
					for(int t=0;t<=m;t++){
						for(int x=0;x<=m;x++){
							if(dp[cnt-1][e][p][q][t]==-1) continue;
							if(arr[x].y==1){
								if(t==x) continue;
							}else if(arr[x].y==2){
								if(t==x||q==x) continue;
							}else if(arr[x].y==3){
								if(t==x||q==x||p==x) continue;
							}else if(arr[x].y==4){
								if(t==x||q==x||p==x||e==x) continue;
							}
							dp[cnt][p][q][t][x] = max(dp[cnt][p][q][t][x],dp[cnt-1][e][p][q][t]+arr[x].x);
							if(dp[cnt][p][q][t][x]>=n){
								printf("%d\n",cnt);
								return;
							}
						}
					}
				}
			}
		}
		cnt++;
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