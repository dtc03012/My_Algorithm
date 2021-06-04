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
const int MAX = 1000100;
pi dp[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	int mx = 0;
	vector<int> kv;
	for(int e=0;e<n;e++){
		int r;
		scanf("%d",&r);
		int xx = 1;
		int lim = sqrt(r),tot = r;
		for(int p=2;p<=lim;p++){
			if(tot%p==0){
				int nn = 0;
				while(tot%p==0){
					nn++;
					tot /= p;
				}
				if(nn%2) xx *= p;
			}
		}
		if(tot!=1) xx *= tot;
		if(dp[xx].y==tc){
			dp[xx].x++;
			mx = max(mx,dp[xx].x);
		}else{
			dp[xx].x = 1;
			dp[xx].y = tc;
			kv.push_back(xx);
			mx = max(mx,dp[xx].x);
		}
	}
	int xx = 0,mx2 = 0;
	for(int e=0;e<sz(kv);e++){
		if(kv[e]==1) xx += dp[kv[e]].x;
		else{
			if(dp[kv[e]].x%2==0) xx += dp[kv[e]].x;
			else mx2 = max(mx2,dp[kv[e]].x);
		}
	}
	xx = max(xx,mx2);
	int q;
	scanf("%d",&q);
	while(q--){
		lld x;
		scanf("%lld",&x);
		if(x==0) printf("%d\n",mx);
		else printf("%d\n",xx);
	}
}
int main(void){
	int tc;
	scanf("%d",&tc);
	for(int e=1;e<=tc;e++){
		solve(e);
	}

	return 0;
}