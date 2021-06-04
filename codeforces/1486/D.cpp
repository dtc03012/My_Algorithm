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
int n,k,arr[MAX],dp[MAX],dp2[MAX];
bool can(int x){
	memset(dp,0,sizeof(dp));
	memset(dp2,0,sizeof(dp2));
	for(int e=1;e<=n;e++){
		if(arr[e]>=x){
			dp[e] = dp[e-1] + 1;
			dp2[e] = dp2[e-1] + 1;
		}
		else{
			dp[e] = dp[e-1] - 1;
			dp2[e] = max(0,dp2[e-1]-1);
		}
		if(e>=k){
			int xx = dp[e] - dp[e-k] + dp2[e-k];
			if(xx>0) return true;
		}
	}
	return false;
}
void solve(int tc){
	scanf("%d%d",&n,&k);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	int ll = 1,rr = n,mid,ans=0;
	while(ll<=rr){
		mid = (ll+rr)/2;
		if(can(mid)){
			ans = max(ans,mid);
			ll = mid + 1;
		}else rr = mid - 1;
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