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
int dp[MAX];
int f(vector<int>& a,vector<int>& b){
	memset(dp,0,sizeof(dp));
	for(int e=sz(a)-1;e>=0;e--){
		dp[e] = dp[e+1];
		if(binary_search(all(b),a[e])) dp[e]++;
	}
	int ans = dp[0];
	for(int e=0;e<sz(b);e++){
		int xx = upper_bound(all(a),b[e]) - a.begin();
		int yy = upper_bound(all(b),b[e]-xx) - b.begin();
		int cnt = (e-yy+1);
		ans = max(ans,min(xx,cnt)+dp[xx]);
	}
	return ans;
}
void solve(int tc){
	int n,m;
	cin >> n >> m;
	vector<int> posa,posb,nega,negb;
	for(int e=0;e<n;e++){
		int r;
		cin >> r;
		if(r<0) nega.push_back(-r);
		else posa.push_back(r);
	}
	for(int e=0;e<m;e++){
		int r;
		cin >> r;
		if(r<0) negb.push_back(-r);
		else posb.push_back(r);
	}
	sort(all(nega));
	sort(all(negb));
	int ans = f(posa,posb) + f(nega,negb);
	cout << ans << "\n";
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}