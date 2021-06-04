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

const int  MAX = 5050;
const lld mod = 998244353;
lld dp[MAX][MAX];
int arr[MAX][MAX];
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
lld divs(lld x,lld y){
	return (x*calc(y,mod-2))%mod;
}
void solve(int tc){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int p=0;p<k;p++){
		int y,x;
		char s[2];
		scanf("%d%d%s",&y,&x,s);
		y--;x--;
		if(s[0]=='X') arr[y][x] = 1;
		else if(s[0]=='R') arr[y][x] = 2;
		else arr[y][x] = 3;
	}
	lld x = 1,rx = calc(3,mod-2);
	for(int e=0;e<n*m-k;e++) x = (x*3)%mod;
	dp[0][0] = x;
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++){
			if(e){
				if(arr[e-1][p]==3||arr[e-1][p]==1) dp[e][p] = dp[e-1][p];
				if(arr[e-1][p]==0){
					dp[e][p] = (((dp[e-1][p]*rx)%mod)*2)%mod;
				}
			}
			if(p){
				if(arr[e][p-1]==2||arr[e][p-1]==1) dp[e][p] = (dp[e][p]+dp[e][p-1])%mod;
				if(arr[e][p-1]==0) dp[e][p] = (dp[e][p]+(((dp[e][p-1]*rx)%mod)*2)%mod)%mod;
			}
		}
	}
	printf("%lld\n",dp[n-1][m-1]);
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