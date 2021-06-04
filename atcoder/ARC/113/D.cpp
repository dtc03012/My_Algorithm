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

const lld mod = 998244353;
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now%mod;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
void solve(int tc){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if(n==1||m==1){
		lld x = calc(k,max(n,m));
		printf("%lld\n",x);
	}else{
		lld ans = 0;
		for(int e=1;e<=k;e++){
			lld xx = (calc(e,n)-calc(e-1,n));
			xx = (xx%mod+mod)%mod;
			xx = (xx*calc(k-e+1,m))%mod;
			ans = (ans+xx)%mod;
		}
		printf("%lld\n",ans);
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
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}