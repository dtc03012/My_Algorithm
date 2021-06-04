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
const lld mod = 1e9 + 7;
lld dp[MAX][MAX];
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
lld divs(lld a,lld b){
	return (a*calc(b,mod-2))%mod;
}
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	if(m==1){
		if(n==1) printf("1");
		else printf("0");
	}else if(m==2){
		printf("2");
	}else{
		dp[1][1] = m;
		for(int e=2;e<=n;e++){
			for(int p=2;p<=m;p++){
				dp[e][p] = (divs(dp[e-1][p-1],p-1)*((e-p)*2+2))%mod;
				lld xx = dp[e-1][p];
				xx = (xx*(e-p+1));
				xx = (xx*p)%mod;
				dp[e][p] = (dp[e][p]+xx)%mod;
				printf("%d - %d : %lld\n",e,p,dp[e][p]);
			}
		}
		printf("%lld\n",dp[n][m]);
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