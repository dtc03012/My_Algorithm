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
const int MAX = 1010;
lld dp[MAX][MAX],dp2[MAX][MAX];
void solve(int tc){
	memset(dp,0,sizeof(dp));
	int n,k;
	scanf("%d%d",&n,&k);
	if(n==1){
		if(k==1) printf("1\n");
		else printf("2\n");
	}else{
		if(k==1) printf("1\n");
		else{
			n--;
			lld ans = 1;
			dp[k][1] = 1;
			for(int e=k-1;e>=1;e--){
				if((k-e)%2){
					lld tot = 0;
					for(int p=1;p<=n;p++){
						tot = (tot+dp[e+1][p])%mod;
						dp[e][p] = tot;
						ans = (ans+tot)%mod;
					}
				}else{
					lld tot = 0;
					for(int p=n;p>=1;p--){
						tot = (tot+dp[e+1][p])%mod;
						dp[e][p] = tot;
						ans = (ans+tot)%mod;
					}
				}
			} 
			ans = (ans+1)%mod;
			printf("%lld\n",ans);
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
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}