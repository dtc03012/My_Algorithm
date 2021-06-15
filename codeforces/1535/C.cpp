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
int dp[MAX][2][2];
void solve(int tc){
	string s;
	cin >> s;
	for(int e=1;e<=sz(s);e++){
		dp[e][0][0] = dp[e][0][1] = dp[e][1][0] = dp[e][1][1] = 0;
	}
	for(int e=1;e<=sz(s);e++){
		dp[e][0][0] = dp[e-1][0][0];
		dp[e][0][1] = dp[e-1][0][1];
		dp[e][1][0] = dp[e-1][1][0];
		dp[e][1][1] = dp[e-1][1][1];
		if(s[e-1]=='1'){
			dp[e][1][e%2]++;
		}else if(s[e-1]=='0'){
			dp[e][0][e%2]++;
		}
	}
	lld ans = 0;
	for(int e=1;e<=sz(s);e++){
		int ll = e,rr = sz(s),mid,ansk = e-1;
		while(ll<=rr){
			mid = (ll+rr)/2;
			int f1 = dp[mid][0][0] - dp[e-1][0][0];
			int f2 = dp[mid][0][1] - dp[e-1][0][1];
			int s1 = dp[mid][1][0] - dp[e-1][1][0];
			int s2 = dp[mid][1][1] - dp[e-1][1][1];
			if((f1&&f2)||(s1&&s2)||(f1&&s1)||(f2&&s2)){
				rr = mid - 1;
			}else{
				ll = mid + 1;
				ansk = max(ansk,mid);
			}
		}
		ans += (ansk-e+1);
	}
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