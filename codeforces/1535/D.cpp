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

lld dp[(1<<20)];
void solve(int tc){
	int n;
	cin >> n;
	string a;
	cin >> a;
	reverse(all(a));
	int start = (1<<n);
	for(int p=start;p<(1<<(n+1));p++) dp[p] = 1;
	for(int p=start-1;p>=1;p--){
		if(a[p-1]=='1') dp[p] = dp[p*2];
		else if(a[p-1]=='0') dp[p] = dp[p*2+1];
		else dp[p] = dp[p*2] + dp[p*2+1];
	}
	int q;
	cin >> q;
	while(q--){
		int x;
		char s[2];
		cin >> x >> s;
		x = (1<<n) - x;
		if(s[0]=='1'){
			if(a[x-1]=='0'){
				dp[x] -= dp[x*2+1];
				dp[x] += dp[x*2];
			}else if(a[x-1]=='?'){
				dp[x] -= dp[x*2+1];
			}
		}else if(s[0]=='0'){
			if(a[x-1]=='1'){
				dp[x] -= dp[x*2];
				dp[x] += dp[x*2+1];
			}else if(a[x-1]=='?'){
				dp[x] -= dp[x*2];
			}
		}else{
			if(a[x-1]=='1'){
				dp[x] += dp[x*2+1];
			}else if(a[x-1]=='0'){
				dp[x] += dp[x*2];
			}
		}
		for(int p=(x/2);p>=1;p/=2){
			if(a[p-1]=='1') dp[p] = dp[p*2];
			else if(a[p-1]=='0') dp[p] = dp[p*2+1];
			else dp[p] = dp[p*2] + dp[p*2+1];
		}
		a[x-1] = s[0];
		cout << dp[1] << "\n";
	}
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}