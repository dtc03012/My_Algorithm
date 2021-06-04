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
vector<int> v[MAX],leaf,rv[MAX];
int vis[MAX],sz[MAX],rsz[MAX],n,k,tmp[MAX],dp[MAX],depx;
void dfs(int x,int lx,int ty){
	depx = max(depx,ty);
	dp[ty]++;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			dfs(nx,x,ty+1);
		}
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
	if(n==k){
		cout << "0";
		return;
	}
	dfs(1,-1,0);
	int ll = 1,rr = n,mid,ans = n;
	while(ll<=rr){
		mid = (ll+rr)/2;
		int tot = 1e9;
		for(int p=0;p<=mid;p++){
			int xx = 0,lastx = n;
			for(int q=depx-p;q>=0;q-=2*mid){
				xx += dp[q];
				lastx = min(lastx,q);
			}
			tot = min(tot,xx);
		}
		if(tot<=k){
			ans = min(ans,mid);
			rr = mid - 1;
		}else ll = mid + 1;
	}
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