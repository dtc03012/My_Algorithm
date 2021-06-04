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
lld arr[MAX],dp[MAX][MAX][2];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++){
		scanf("%lld",&arr[e]);
		dp[e][e][0] = dp[e][e][1] = arr[e];
	}
	for(int e=2;e<=n;e++){
		for(int p=1;p<=n-e+1;p++){
			int ll = p,rr = p + e - 1;
			dp[ll][rr][1] = dp[ll][rr-1][1] ^ dp[ll+1][rr][1];
			dp[ll][rr][0] = max({dp[ll][rr-1][0],dp[ll+1][rr][0],dp[ll][rr][1]});
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",dp[l][r][0]);
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
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}