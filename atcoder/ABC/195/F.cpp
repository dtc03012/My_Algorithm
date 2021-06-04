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

const int MAX = 22;
lld dp[(1<<MAX)];
void solve(int tc){
	lld f1,f2;
	scanf("%lld%lld",&f1,&f2);
	vector<int> v;
	for(int e=2;e<=73;e++){
		bool can = false;
		for(int p=2;p*p<=e;p++){
			if(e%p==0) can = true;
		}
		if(!can) v.push_back(e);
	}
	lld ans = 1;
	dp[0] = 1;
	for(lld e=f1;e<=f2;e++){
		int bit = 0;
		for(int p=0;p<sz(v);p++) if(e%v[p]==0) bit ^= (1<<p);
		int xx = ((1<<MAX)-1)^bit,rt = xx;
		for(;;xx=(xx-1)&rt){
			ans += dp[xx];
			dp[xx^bit] += dp[xx];
			if(xx==0) break;
		}
	}
	printf("%lld",ans);
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