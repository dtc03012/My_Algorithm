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

const int MAX = 5050;
pl arr[MAX];
int vis[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++) scanf("%lld%lld",&arr[e].x,&arr[e].y);
	vector<int> ans;
	ans.push_back(1);
	vis[1] = 1;
	int lx = 1;
	for(int e=0;e<n-1;e++){
		lld vv = 0;
		int wh = -1;
		for(int p=1;p<=n;p++){
			if(vis[p]) continue;
			lld dist = (arr[p].x-arr[lx].x)*(arr[p].x-arr[lx].x) + (arr[p].y-arr[lx].y)*(arr[p].y-arr[lx].y);
			if(dist>vv){
				wh = p;
				vv = dist;
			}
		}
		if(wh==-1) break;
		ans.push_back(wh);
		vis[wh] = 1;
		lx = wh;
	}
	for(int e=0;e<sz(ans);e++) printf("%d ",ans[e]);
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