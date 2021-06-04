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

const int MAX = 1010;
int arr[MAX];
bool tmr(int a,int b){
	return a > b;
}
const lld mod = 1e9 + 7;
int cnt[MAX];
lld dp[MAX];
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
lld nCr(int a,int b){
	lld f1 = dp[a];
	lld f2 = (dp[b]*dp[a-b])%mod;
	return (f1*calc(f2,mod-2))%mod;
}
void solve(int tc){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int e=0;e<=n;e++) cnt[e] = 0;
	for(int e=0;e<n;e++){
		scanf("%d",&arr[e]);
		cnt[arr[e]]++;
	}
	sort(arr,arr+n,tmr);
	int last = arr[k-1];
	int tot = 0;
	for(int e=0;e<k;e++) if(arr[e]==last) tot++;
	printf("%lld\n",nCr(cnt[last],tot));
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		scanf("%d",&tc);
	
	dp[0] = 1;
	for(int e=1;e<MAX;e++) dp[e] = (dp[e-1]*e)%mod;
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}