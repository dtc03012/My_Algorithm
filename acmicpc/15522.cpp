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
vector<int> v[MAX];
int sz[MAX];
int getsz(int x,int lx){
	sz[x] = 1;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx) sz[x] += getsz(nx,x);
	}
	return sz[x];
}
int ans,dp[MAX],n,k;
void dfs(int x,int lx){
	int lv = sz[1] - sz[x];
	int cnt = 0,cnt2 = 0;
	pi mx = mk(0,0);
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			dfs(nx,x);
			if(sz[nx]<k){
				cnt++;
			}else{
				cnt2++;
				if(dp[nx]>=0){
					if(dp[nx]>mx.x){
						mx.y = mx.x;
						mx.x = dp[nx];
					}else if(dp[nx]>mx.y) mx.y = dp[nx];
				}
			}
		}
	}
	int xx = (int)(lv>=k);
	if(sz[x]<k){
		if(cnt>=1) ans = max(ans,xx);
	}else{
		if(cnt) ans = max(ans,cnt2+xx);
		int tot = mx.x,vk = 1;
		if(mx.y){
			tot += mx.y;
			vk++;
		}
		ans = max(ans,tot+cnt2-vk+xx);
		dp[x] = max(cnt2,mx.x+cnt2-1);
	}
}
void solve(int tc){
	scanf("%d%d",&n,&k);
	for(int e=0;e<n-1;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	getsz(1,-1);
	dfs(1,-1);
	printf("%d\n",ans);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		// scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}