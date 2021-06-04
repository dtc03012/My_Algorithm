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

const lld mod = 1e9 + 7;
const int MAX = 2020;
int arr[MAX],cnt[MAX],B[MAX],Y[MAX];
void solve(int tc){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int e=0;e<n;e++) scanf("%d",&arr[e]);
	for(int e=n-1;e>=0;e--){
		for(int p=e+1;p<n;p++){
			if(arr[e]>arr[p]) B[e]++;
		}
		for(int p=0;p<n;p++){
			if(e!=p&&arr[e]>arr[p]) Y[e]++;
		}
	}
	lld ans = 0;
	lld kk = (1ll*k*k)%mod;
	lld k2 = (1ll*k*(k+1))/2;
	k2 %= mod;
	for(int e=0;e<n;e++){
		lld xx = (1ll*kk*Y[e])%mod;
		xx = (xx - k2*Y[e])%mod;
		xx = (xx+mod)%mod;
		xx = (xx + 1ll*k*B[e])%mod;
		ans = (ans+xx)%mod;
	}
	printf("%lld\n",ans);
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