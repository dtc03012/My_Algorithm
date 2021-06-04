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

const int MAX = 10101;
int arr[MAX],sz[MAX],dp[MAX];
vector<int> v[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++){
		scanf("%d",&arr[e]);
		int k;
		scanf("%d",&k);
		for(int p=0;p<k;p++){
			int x;
			scanf("%d",&x);
			sz[e]++;
			v[x].push_back(e);
		}
	}
	int mx = 0;
	queue<int> q;
	for(int e=1;e<=n;e++){
		if(sz[e]==0){
			q.push(e);
			dp[e] = arr[e];
		}
	}
	while(!q.empty()){
		int tt = q.front();
		q.pop();
		mx = max(mx,dp[tt]);
		for(int e=0;e<sz(v[tt]);e++){
			int nx = v[tt][e];
			sz[nx]--;
			dp[nx] = max(dp[nx],dp[tt]+arr[nx]);
			if(sz[nx]==0) q.push(nx);
		}
	}
	printf("%d\n",mx);
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