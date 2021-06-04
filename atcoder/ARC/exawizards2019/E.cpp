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
const lld mod = 1e9 + 7;
lld dp[MAX],two[MAX];
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
lld divs(lld a,lld b){
	return (a*calc(b,mod-2));
}
lld nCr(lld a,lld b){
	lld f1 = dp[a];
	lld f2 = (dp[b]*dp[a-b])%mod;
	return (f1*calc(f2,mod-2))%mod;
}
void solve(int tc){
	dp[0] = 1;
	for(int e=1;e<MAX;e++) dp[e] = (dp[e-1]*e)%mod;
	two[0] = 1;
	for(int e=1;e<MAX;e++) two[e] = (two[e-1]*2)%mod;
	int B,W;
	scanf("%d%d",&B,&W);
	lld nk = 0;
	lld xx = 1;
	for(int e=1;e<=B+W;e++){
		if((e-1)>=W){
			lld xx = divs(1,2);
			lld n1 = nCr(e-1,W);
			lld n2 = nCr(e-2,W-1);
			printf("%d : %lld %lld\n",e,n2,n1);
			n2 = divs(n2,n1);
			nk = (nk+n2)%mod;
			xx = (xx+divs(nk,2))%mod;
			printf("%lld\n",xx);
		}else{
			printf("%lld\n",divs(1,2));
		}
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