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

const int MAX = 10101;
lld dp[MAX][15];
void solve(int tc){
	int n;
	scanf("%d",&n);
	string a;
	cin >> a;
	int sz = sz(a);
	lld ans = 0;
	for(int e=0;e<sz;e++){
		for(int p=0;p<n;p++){
			if(e==0){
				dp[p][e] = 1;
				if(sz==1) ans += 1;
			}else{
				if(p&&e) dp[p][e] += dp[p-1][e-1];
				dp[p][e] += dp[p][e-1];
				if(e==sz-1) ans = ans + dp[p][e];
			}
		}
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