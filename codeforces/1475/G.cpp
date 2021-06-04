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
int arr[MAX],cnt[MAX],dp[MAX],sz[MAX];
vector<int> v[MAX],g[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<MAX;e++){
		cnt[e] = 0;
		dp[e] = 0;
		sz[e] = 0;
		g[e].clear();
	}
	for(int e=0;e<n;e++){
		scanf("%d",&arr[e]);
		cnt[arr[e]]++;
	}
	int ans = 0;
	for(int e=MAX-1;e>=1;e--){
		for(int p=0;p<sz(v[e]);p++){
			int nx = v[e][p];
			if(cnt[nx]){
				g[e].push_back(nx);
				sz[nx]++;
			}
		}
	}
	queue<int> q;
	for(int e=1;e<MAX;e++) if(sz[e]==0) q.push(e);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		dp[x] += cnt[x];
		ans = max(ans,dp[x]);
		for(int e=0;e<sz(g[x]);e++){
			int nx = g[x][e];
			sz[nx]--;
			dp[nx] = max(dp[nx],dp[x]);
			if(sz[nx]==0) q.push(nx);
		}
	}
	printf("%d\n",n-ans);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	for(int e=2;e<MAX;e++){
		int lim = sqrt(e);
		v[e].push_back(1);
		for(int p=2;p<=lim;p++){
			if(e%p==0){
				int f1 = p;
				int f2 = e/p;
				v[e].push_back(f1);
				if(f1!=f2){
					v[e].push_back(f2);
				}
			}
		}
	}
	int tc = 1;
	
		scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}